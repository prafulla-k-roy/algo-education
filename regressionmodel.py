import matplotlib.pyplot as plt
import numpy as np

def coefficients(x,y):

    #equation is y = mx + c
    mx = np.mean(x)                 #mean of independent variable
    my = np.mean(y)                 #mean of dependent variable
    l = np.size(x)                  #size of input
    ssxy = np.sum(y*x) - l*mx*my    #summation of x multiplied by y
    ssxx = np.sum(x*x) - l*mx*mx    #summation of x squared

    #coeffcients
    m = ssxy / ssxx                 # slope calculation
    c = my - m*mx                   # intercept of the equation 

    return (m,c)

def pltequation(x,y,coeff):         # graph

    plt.xlabel('independent variable')
    plt.ylabel('dependent variable')

    # scattering datapoints on graph
    plt.scatter(x,y, c = "red")

    # regression line on graph
    plt.plot(x,coeff[0]*x+coeff[1], c = "black")

    # plotting the final graph
    plt.show()

#you can change input to fit your own model.
x = np.array([4, 5, 2, 6, 3, 12, 9, 7, 1, 8])            #independent variable
y = np.array([1, 3, 2, 5, 7, 8, 8, 9, 10, 12])          #depent variable
coeff = coefficients(x,y)
pltequation(x,y,coeff)

# to predict value of y for any x
x_predict = int(input("Enter value of x :"))

print("predicted value of y is ",coeff[0]*x_predict+coeff[1])

#END