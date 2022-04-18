import numpy as np
import matplotlib.pyplot as plt

# read data
x, sinx = np.loadtxt("data.txt", unpack=True)

# plot data
plt.plot(x, sinx, '-o', label="data")
plt.legend()
#plt.show()
plt.xlabel(r"$x$")
plt.ylabel("$\sin(x)$")
plt.savefig("fig.pdf")
