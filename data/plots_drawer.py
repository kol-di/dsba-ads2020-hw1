import matplotlib
import csv
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt


x = []
graphGs = []
graphDac = []
graphKar = []

with open('ResultsTable.csv', 'r') as csvfile:
    data = csv.reader(csvfile, delimiter='\t')
    for elem in data:
        x.append(int(elem[0]))
        graphGs.append(float(elem[1]))
        graphDac.append(float(elem[2]))
        graphKar.append(float(elem[3]))
plt.plot(x, graphGs, label='Grade School ')
plt.plot(x, graphDac, label='Divide and Conquer')
plt.plot(x, graphKar, label='Karatsuba')
plt.xlabel('Number length')
plt.ylabel('Time (sec)')
plt.legend()
plt.show()