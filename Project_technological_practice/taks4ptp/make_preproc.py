import json
import os
import statistics
import math
os.chdir('./data')
files = os.listdir('./')
preproc_data = {'data1':{'idx':{}, 'ptr':{}, 'fi':{}}, 'data2':{'idx':{}, 'ptr':{}, 'fi':{}}, 'data3':{'idx':{}, 'ptr':{}, 'fi':{}}}

def statistic(data) -> tuple:
    """Возвращает статистику по данным"""
    quantiles = statistics.quantiles(data)
    mean = statistics.mean(data)
    maxim = max(data)
    minim = min(data)
    median = statistics.median(data)
    dispersion = statistics.variance(data)
    std_deviation = math.sqrt(dispersion)
    std_err = std_deviation / math.sqrt(len(data))
    return (mean, dispersion, std_deviation, std_err, maxim, minim, quantiles, len(data), median, data)


for filename in files:
    file = filename.replace('.txt', '')
    name, nmax, sort_type = file.split('_')
    with open(filename, 'r') as file:
        data = list(map(float, file.readlines()))
        preproc_data[name][sort_type][nmax] = statistic(data)


os.chdir('./../')
with open("./prepdata/data_file.json", "w") as write_file:
    json.dump(preproc_data, write_file, indent=4)
