import matplotlib.pyplot as plt
import clr
from System import Environment

clr.AddReference(r'C:\Users\motm\source\repos\N500_DSP\N500_DSP\bin\Debug\N500_DSP')

from N500_DSP import DSP

def printFirstValues(ar):
    for i in range(0, 10):
        print(ar[i])
    print("...")

# JSON file with DSP configuration
cfg_path = r'dsp_config.json'
cfg_json = ""
with open(cfg_path, mode='r') as f:
    cfg_json = f.read()
DSP.SetDspConfiguration(cfg_json)
DSP.SetDspFilters("N-500_FilterLaser.txt", "N-500_FilterDetector.txt", "N-500_FilterDetectorLP2.txt")

# Example Measurement data
paths = [
    r'C:\Temp\N-500\Data_20240223130221.bin', 
    r'C:\Temp\N-500\Data_20240223130227.bin',
    r'C:\Temp\N-500\Data_20240223131308.bin',
    r'C:\Temp\N-500\Data_20240223131312.bin',
]

DSP.StartMeasurement()

fig, ax = plt.subplots()

for fpath in paths:
    raw_data = []
    with open(fpath, mode='rb') as f:
        raw_data = f.read()

    time = []
    speed = []
    res = DSP.CalculateSpeedVector(raw_data, speed)
    ok = res[0]
    time = res[1]
    speed = res[2]
    if ok:
        print("Speed:")
        printFirstValues(speed)
    else:
        exit(-1)

    ax.plot(time, speed)

plt.show()
