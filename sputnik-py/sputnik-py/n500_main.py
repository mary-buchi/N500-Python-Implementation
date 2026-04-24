import argparse
import matplotlib.pyplot as plt
import clr

clr.AddReference(r'C:\Users\motm\source\repos\N500_DSP\N500_DSP\bin\Debug\N500_DSP')

from N500_DSP import DSP

def printFirstValues(ar):
    for i in range(0, 10):
        print(ar[i])
    print("...")

# Example Measurement data
paths = [
    r'C:\Temp\N-500\Data_20240301150547.bin', 
    r'C:\Temp\N-500\Data_20240301150548.bin',
    r'C:\Temp\N-500\Data_20240301150549.bin',
    r'C:\Temp\N-500\Data_20240301150550.bin',
]

def init(scans_number, noise_test = False):
    # JSON file with DSP configuration
    cfg_path = r'dsp_configuration.json'
    cfg_json = ""
    with open(cfg_path, mode='r') as f:
        cfg_json = f.read()
    DSP.SetConfiguration(cfg_json)
    DSP.SetDspFilters("N-500_FilterLaser.txt", "N-500_FilterDetector.txt", "N-500_FilterDetectorLP2.txt")
    DSP.Init()
    DSP.StartMeasurement(scans_number, noise_test)

    for fpath in paths:
        raw_data = []
        with open(fpath, mode='rb') as f:
            raw_data = f.read()
            DSP.AddDataPackage(raw_data)

def speed(scans_number):
    #instrumentTemperature = 42 todo...

    fig, ax = plt.subplots()

    time_forward = []
    time_reverse = []
    speed_forward = []
    speed_reverse = []

    for i in range(scans_number):
        res = DSP.DoSpeedMeasurement(time_forward, time_reverse, speed_forward, speed_reverse)
        time_forward = res[0]
        time_reverse = res[1]
        speed_forward = res[2]
        speed_reverse = res[3]
        
        ax.plot(time_forward, speed_forward)
        ax.plot(time_reverse, speed_reverse)

    plt.show()

def spectra(scans_number):
    #instrumentTemperature = 42 todo...

    for i in range(scans_number):
        res = DSP.DoSpectraMeasurement()
    
    ifg_fwd = []
    ifg_rev = []
    x_start = 0
    spc_fwd = []
    spc_rev = []
    spc_avg = []
    wn_axis = []
    res = DSP.Spectra(ifg_fwd, ifg_rev, x_start, spc_fwd, spc_rev, spc_avg, wn_axis)
    spc_avg = res[5]
    wn_axis = res[6]

    fig, ax = plt.subplots()
    ax.plot(wn_axis, spc_avg)
    plt.show()

def noise_test(scans_number):
    #instrumentTemperature = 42 todo...

    for i in range(scans_number):
        DSP.DoNoiseTest()

    mean_fwd = []
    mean_rev = []
    mean_avg = []
    noise_fwd = []
    noise_rev = []
    noise_avg = []
    x_start = 0
    x_step = 0
    res = DSP.NoiseTest(mean_fwd, mean_rev, mean_avg, noise_fwd, noise_rev, noise_avg, x_start, x_step)
    noise_fwd = res[3]
    noise_rev = res[4]
    noise_avg = res[5]
    x_start = res[6]
    x_step = res[7]

    fig, ax = plt.subplots()
    ax.plot([x_start + x * x_step for x in range(len(noise_fwd))], noise_fwd)
    ax.plot([x_start + x * x_step for x in range(len(noise_rev))], noise_rev)
    ax.plot([x_start + x * x_step for x in range(len(noise_avg))], noise_avg)
    plt.show()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="N-500 Process data packages")
    parser.add_argument('type', type=str, help='speed, spectra, or noise')
    parser.add_argument('scans', type=int, help='number of scans requested')

    args = parser.parse_args()

    if args.type == 'speed':
        init(args.scans)
        speed(args.scans)        
    elif args.type == 'spectra':
        init(args.scans)
        spectra(args.scans)
    elif args.type == 'noise':
        init(args.scans, True)
        noise_test(args.scans)