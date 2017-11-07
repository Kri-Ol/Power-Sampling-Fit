import numpy
from scipy.optimize import curve_fit
import pylab

def funzione(x, a, b):
    return a * numpy.power(x, b)

num, freq = pylab.loadtxt("q.dat", unpack=True)

pars, covm =  curve_fit(funzione, num, freq, absolute_sigma=True)
pylab.plot(num, funzione(num, pars[0], pars[1]), color='red')
pylab.errorbar(num, freq, linestyle='', marker='.',color='black')
pylab.show()
print(pars)
