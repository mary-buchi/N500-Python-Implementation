#import argparse
import clr
from decimal import Decimal
import json
import matplotlib.pyplot as plt

clr.AddReference(r'D:\LocalRepos\N500_DSP\N500_DSP\bin\Debug\N500_DSP')
clr.AddReference(r'D:\LocalRepos\N500_DSP\Sputnik_DSP\bin\Debug\Sputnik_DSP')

from N500_DSP import DSP as N500_DSP
from Sputnik_DSP import DSP as Sputnik_DSP

#dsp = DSP()

# The DSP configuration parameters
dsp_configuration = {}
with open('dsp_configuration.json', mode='r') as f:
    dsp_configuration = json.loads(f.read())

# Use N500-DSP to read in the N-500 original data into double arrays, to get some test data.
scans_requested = 4

N500_DSP.Init()
N500_DSP.StartMeasurement(scans_requested)

def useful_points_per_scan():
    if dsp_configuration['fullScan']:
        return dsp_configuration['usefulPointsFullScan']

    return dsp_configuration['usefulPointsHalfScan']

def interferogram_size():
    if dsp_configuration['fullScan']:
        return dsp_configuration['interferogramSizeFullScan']

    return dsp_configuration['interferogramSizeHalfScan']

# Example Measurement data
paths = [
    r'D:\LocalRepos\N-500\Data_20240301150547.bin',
    r'D:\LocalRepos\N-500\Data_20240301150548.bin',
    r'D:\LocalRepos\N-500\Data_20240301150549.bin',
    r'D:\LocalRepos\N-500\Data_20240301150550.bin',
]

for fpath in paths:
    raw_data = []
    with open(fpath, mode='rb') as f:
        raw_data = f.read()
        N500_DSP.AddDataPackage(raw_data)

detector = []
laser = []
x_step = 0
reference_scan_fwd = []
reference_scan_rev = []
shifted_scans_fwd = []
shifted_scans_rev = []

for n in range(scans_requested):
    res = N500_DSP.ReadDataPackage(detector, laser, x_step)
    detector = res[0]
    laser = res[1]
    x_step = res[2]

    # Write the detector and laser data into text files (1 value per line)
    # path = r'C:\Temp\N-500\detector_' + str(n) + '.txt'
    # with open(path, "w") as file:
    #     for x in detector:
    #         file.write(str(x))
    #         file.write("\n")
    # path = r'C:\Temp\N-500\laser_' + str(n) + '.txt'
    # with open(path, "w") as file:
    #     for x in laser:
    #         file.write(str(x))
    #         file.write("\n")

    # Now use the Sputnik DSP library with the test data

    # Read the FIR filters for laser and detector data from files
    laser_fir_filter = []
    detector_fir_filter = []

    with open("N-500_FilterLaser.txt") as file:
        laser_fir_filter = [float(line.rstrip()) for line in file]

    with open("N-500_FilterDetector.txt") as file:
        detector_fir_filter = [float(line.rstrip()) for line in file]

    # Apply apodization to laser vector
    laser = Sputnik_DSP.ApplyApodization(laser, (len(laser_fir_filter) + 1) // 2)

    # Apply FIR filter to laser
    laser = Sputnik_DSP.ApplyFIRFilter(laser, laser_fir_filter)

    # Apply FIR filter to detector
    detector = Sputnik_DSP.ApplyFIRFilter(detector, detector_fir_filter)

    # Check the minimal peak to peak amplitude of the laser signal
    ok = Sputnik_DSP.CheckPeak2PeakAmplitude(laser)

    if not ok:
        print('peak to peak amplitude of laser signal is bad')
        exit(-1)

    # Detect the zero crossing points of the laser signal
    zero_crossings = []
    res = Sputnik_DSP.DetectZeroCrossings(laser, zero_crossings)
    zero_crossings = res

    print(f'zero crossing 1: {zero_crossings[1]}, zero crossing 2: {zero_crossings[2]}')
    print(f'Found {len(zero_crossings)} zero crossings in laser signal')

    # Interpolate the detector data at the laser zero crossings
    interferogram = []
    time_axis = []
    res = Sputnik_DSP.InterpolateDetectorData(
        zero_crossings,
        detector,
        time_axis,
        interferogram)

    time_axis = res[0]
    interferogram = res[1]

    # fig, ax = plt.subplots()
    # ax.plot(time_axis, interferogram)
    # plt.show()

    # Find the start and end indices of the forward and reverse scans
    start_fwd = 0
    end_fwd = 0
    start_rev = 0
    end_rev = 0
    res = Sputnik_DSP.FindScanWindows(zero_crossings, start_fwd, end_fwd, start_rev, end_rev)
    start_fwd = res[0]
    end_fwd = res[1]
    start_rev = res[2]
    end_rev = res[3]

    # Build the speed vector
    speed_vector = []
    res = Sputnik_DSP.BuildSpeedVector(len(interferogram), time_axis, speed_vector)
    speed_vector = res

    # fig, ax = plt.subplots()
    # ax.plot(time_axis, speed_vector)
    # plt.show()

    # Find the forward and reverse peaks (minimal value in interferogram)
    peak_fwd = 0;
    peak_rev = 0;
    res = Sputnik_DSP.FindPeaks(start_fwd, end_fwd, start_rev, end_rev, interferogram)
    peak_fwd = res[0]
    peak_rev = res[1]

    print(f'Forward peak at {peak_fwd}: {interferogram[peak_fwd]}')
    print(f'Reverse peak at {peak_rev}: {interferogram[peak_rev]}')

    # Isolate the forward scan
    # -------------------------

    # Are there enough points in the forward scan?
    if Sputnik_DSP.EnoughPoints(start_fwd, end_fwd, peak_fwd):
        print("Enough points in forward scan")
    else:
        print("Not enough points in forward scan")
        continue

    # Take first forward scan as reference scan
    if reference_scan_fwd == []:
        res = Sputnik_DSP.CreateReferenceScan(interferogram, peak_fwd, reference_scan_fwd)
        reference_scan_fwd = res
        print("Created forward reference scan")

    # Isolate the scan
    shifted_start = 0
    shifted_scan = []
    res = Sputnik_DSP.IsolateScan(interferogram, reference_scan_fwd, start_fwd, peak_fwd, shifted_start, shifted_scan)
    shifted_start = res[0]
    shifted_scan = res[1]

    # Check the speed of the shifted scan
    if Sputnik_DSP.IsSpeedOk(speed_vector, shifted_start):
        print("Speed of forward scan is OK")
    else:
        print("Speed of forward scan is not OK")
        continue

    shifted_scans_fwd.append(shifted_scan)
    print("Added shifted forward scan to store")

    # Isolate the reverse scan
    # ------------------------

    isReverseScan = True

    # Are there enough points in the reverse scan?
    if Sputnik_DSP.EnoughPoints(start_rev, end_rev, peak_rev, isReverseScan):
        print("Enough points in reverse scan")
    else:
        print("Not enough points in reverse scan")
        continue

    # Take first reverse scan as reference scan
    if reference_scan_rev == []:
        res = Sputnik_DSP.CreateReferenceScan(interferogram, peak_rev, reference_scan_rev, isReverseScan)
        reference_scan_rev = res
        print("Created reverse reference scan")

    # Isolate the scan
    shifted_start = 0
    shifted_scan = []
    res = Sputnik_DSP.IsolateScan(interferogram, reference_scan_rev, start_rev, peak_rev, shifted_start, shifted_scan, isReverseScan)
    shifted_start = res[0]
    shifted_scan = res[1]

    # Check the speed of the shifted scan
    if Sputnik_DSP.IsSpeedOk(speed_vector, shifted_start):
        print("Speed of reverse scan is OK")
    else:
        print("Speed of reverse scan is not OK")
        continue

    shifted_scans_rev.append(shifted_scan)
    print("Added shifted reverse scan to store")

# Calculate the average of the forward shifted scans
average_fwd = []
res = Sputnik_DSP.AverageScans(shifted_scans_fwd, average_fwd)
average_fwd = res
print("Calculated average of shifted forward scans")

# Calculate the average of the reverse shifted scans
average_rev = []
res = Sputnik_DSP.AverageScans(shifted_scans_rev, average_rev)
average_rev = res
print("Calculated average of shifted reverse scans")

# Center the averaged forward scans
centered_fwd = []
res = Sputnik_DSP.CenterAveraged(average_fwd, centered_fwd)
centered_fwd = res

# Center the averaged reverse scans
centered_rev = []
res = Sputnik_DSP.CenterAveraged(average_fwd, centered_rev)
centered_rev = res

# Do phase correction for forward interferogram
phasecorrected_ifg_fwd = []
res = Sputnik_DSP.PerformPhaseCorrection(centered_fwd, phasecorrected_ifg_fwd)
phasecorrected_ifg_fwd = res

# Do phase correction for reverse interferogram
phasecorrected_ifg_rev = []
res = Sputnik_DSP.PerformPhaseCorrection(centered_rev, phasecorrected_ifg_rev)
phasecorrected_ifg_rev = res

# Compute the raw forward and reverse spectra
raw_spectrum_fwd = []
res = Sputnik_DSP.ComputeRawSpectrum(phasecorrected_ifg_fwd, raw_spectrum_fwd)
raw_spectrum_fwd = res

raw_spectrum_rev = []
res = Sputnik_DSP.ComputeRawSpectrum(phasecorrected_ifg_rev, raw_spectrum_rev)
raw_spectrum_rev = res

# Compute the dispersion corrected forward and reverse spectra
spectrum_fwd = []
axis_fwd = []
res = Sputnik_DSP.DispersionCorrection(raw_spectrum_fwd, 30, spectrum_fwd, axis_fwd)
spectrum_fwd = res[0]
axis_fwd = res[1]

spectrum_rev = []
axis_rev = []
res = Sputnik_DSP.DispersionCorrection(raw_spectrum_rev, 30, spectrum_rev, axis_rev)
spectrum_rev = res[0]
axis_rev = res[1]

spectrum_avg = []
res = Sputnik_DSP.CalculateAverage(spectrum_fwd, spectrum_rev, spectrum_avg)
spectrum_avg = res

axis = [dsp_configuration['waveNumberStart'] + x * dsp_configuration['waveNumberStep'] for x in range(dsp_configuration['waveNumbers'])]
fig, ax = plt.subplots()
ax.plot(axis, spectrum_avg)
plt.show()
