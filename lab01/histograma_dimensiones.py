import numpy as np
import matplotlib.pyplot as plt

x = np.loadtxt("distancias_5000D.txt",skiprows=1)
plt.title("Histograma de las distancias entre puntos con dimension 5000")
plt.xlabel("Distancia")
plt.ylabel("Frecuencia")
plt.grid(True)

plt.hist(x,10,color="orange",ec="black")
plt.show()