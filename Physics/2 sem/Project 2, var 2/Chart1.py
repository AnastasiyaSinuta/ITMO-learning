#Аналитическое решение
import matplotlib.pyplot as plt
from mpl_toolkits import mplot3d
import numpy as np
import math

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
pi = math.pi

#Заполнение матрицы концентраций
C=[0]*k
for i in range(k):    C[i] = [0.0] * n
for j in range (k):
    for i in range (n):
        if j == 0:
            if (i+2) < (n//2):
                C[j][i] = C0
            else:
                C[j][i] = 0.0
        else:
            sum = 0
            for o in range(1,k):
                sinus = math.sin(o*pi*h/l)
                cosinus = math.cos(o*pi*i/l)
                exp = math.exp(-D*(o**2)*(pi**2)*j/(l**2))
                sum += (1/o) * sinus * cosinus * exp
            C[j][i] = 2*C0 * (h/(2*l) + (1/pi)*sum)

#Построение 3d графика
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set(title =  'Аналитическое решение', xlabel = 'x', ylabel = 't', zlabel = 'C')
x_val = np.linspace(0, l, n)
y_val = np.linspace(0, T, k)
X, Y = np.meshgrid(x_val, y_val)
C=np.array(C)
ax.plot_surface(X, Y, C);
plt.show()