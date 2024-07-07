import sys
import math
import statistics

def statistic(data) -> float:
    """Возвращает статистику по данным"""
    mean = statistics.mean(data)

    dispersion = statistics.variance(data)
    std_deviation = math.sqrt(dispersion)
    std_err = std_deviation / math.sqrt(len(data))

    return std_err / math.sqrt(len(data)) * 100
filename = sys.argv[1]
try:
    with open(filename, 'r') as file:
        data = list(map(float, file.readlines()))
except FileNotFoundError:
    exit(1)


if len(data) <= 1:
    exit(0)
if len(data) >= 250:
    exit(1)
if statistic(data) < 1 and len(data) >= 20:  
    exit(1)
else:
    exit(0)
