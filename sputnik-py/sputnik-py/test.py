import matplotlib.pyplot as plt
import clr

clr.AddReference(r'C:\Users\motm\source\repos\N500_DSP\N500_DSP\bin\Debug\N500_DSP')

from N500_DSP import DSP

# Print first 10 values of an array
def printFirstValues(ar):
    for i in range(0, 10):
        print(ar[i])
    print("...")

# JSON file with DSP configuration
cfg_path = r'dsp_configuration.json'
cfg_json = ""
with open(cfg_path, mode='r') as f:
    cfg_json = f.read()
DSP.SetConfiguration(cfg_json)
DSP.SetDspFilters("N-500_FilterLaser.txt", "N-500_FilterDetector.txt", "N-500_FilterDetectorLP2.txt")
DSP.Init()

# Example Measurement data
paths = [
    r'C:\Temp\N-500\Data_20240301150547.bin', 
    r'C:\Temp\N-500\Data_20240301150548.bin',
    r'C:\Temp\N-500\Data_20240301150549.bin',
    r'C:\Temp\N-500\Data_20240301150550.bin',
]

scans = 2

DSP.StartMeasurement(scans)

fig, ax = plt.subplots()

for fpath in paths:
    raw_data = []
    with open(fpath, mode='rb') as f:
        raw_data = f.read()
        DSP.AddDataPackage(raw_data)

for i in range(scans):
    DSP.ReadDataPackage()
    DSP.FilterDataPackage()
    DSP.InterpolateAtZeroCrossings()
    DSP.FindScanWindows()
    DSP.GetSpeedVector()
    DSP.FindPeaks()
    DSP.IsolateScans()
    DSP.AverageScans()

ifg_forward = []
ifg_reverse = []
x_start = 0
spectrum_forward = []
spectrum_reverse = []
spectrum_average = []
wn_axis = []
res = DSP.Spectra(ifg_forward, ifg_reverse, x_start, spectrum_forward, spectrum_reverse, spectrum_average, wn_axis)
spectrum_average = res[5]
wn_axis = res[6]
ax.plot(wn_axis, spectrum_average)
plt.show()
