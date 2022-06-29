#Численное решение
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np

#Исходные данные
D = 0.25
l = 10
h = l // 2
T = 90
n = 10
k = 800
p = l/n
q = T/k
C0 = 100

#Заполнение матрицы концентраций
C=[0]*k
for i in range(k):    C[i] = [0.0] * n
for i in range(n):
    if (i+2) < (n // 2):
        C[0][i] = C0
    else:
        C[0][i] = 0.0
for j in range (1,k):
    for i in range (1,n-1):
        C[j][i] = C[j-1][i] + (D*q/(p*p))*(C[j-1][i+1] - 2*C[j-1][i] + C[j-1][i-1])
    C[j][0] = (C[j-1][0] + C[j][1])/2
    C[j][n-1] = (C[j-1][n-1] + C[j][n-2])/2

# Построение 3d графика
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set(title =  'Численное решение', xlabel = 'x', ylabel = 't', zlabel = 'C')
x_val = np.linspace(0, l, n)
y_val = np.linspace(0, T, k)
X, Y = np.meshgrid(x_val, y_val)
C=np.array(C)
ax.plot_surface(X, Y, C);
plt.show()