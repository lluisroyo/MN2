import numpy as np

def f(x,y):
    f = (1.0 /(2.0* np.pi)) * np.exp(-(((x-0.25)**2 + (y-0.75)**2)/0.0002)) 
    return f

def v(x,y):
    velocitat = (x-1)**2 - y
    return velocitat

dl = 0.01
r = 0.25
dt = r * dl

D = 1   #Coeficient de difusio

rho_old = np.zeros((101,101))
rho_new = np.zeros((101,101))

# CONDICIONS INICIALS #
for i in range(1,100,1):
    x = i*dl
    for j in range(1,100,1):
        y = j*dl
        
        rho_old[i][j] = f(x,y)

file = open("pas0.dat","w")

for i in range(0,101,1):
    x = i*dl
    for j in range(0,101,1):
        y = j*dl
        file.write("{} \t {} \t {} \n".format(x,y,rho_old[i][j]))

# Comprovació volum inicial = 1 #
volum = 0

for i in range(1,100,1):
    for j in range(1,100,1):
        volum += rho_old[i][j]
print("volum inicial: {}".format(volum))

for n in range(1,100,1):
    for i in range(1,100,1):
        x = i*dl
        for j in range(1,100,1):
            y = j*dl

            rho_new[i][j] = rho_old[i][j] - (r / 2.0) * ( v(x+dl,j)*rho_old[i+1][j] + v(x,y+dl)*rho_old[i][j+1] - v(x-dl,y)*rho_old[i-1][j] - v(x,y-dl)*rho_old[i][j-1]  )   +  (r**2 / 2) * ( v(x+dl/2,y)*(v(x+dl,y)*rho_old[i+1][j] - v(x,y)*rho_old[i][j]) + v(x,y+dl/2)*(v(x,y+dl)*rho_old[i][j+1] - v(x,y)*rho_old[i][j]) - v(x-dl/2,y)*(v(x,y)*rho_old[i][j] - v(x-dl,y)*rho_old[i-1][j]) - v(x,y-dl/2)*(v(x,y)*rho_old[i][j] - v(x,y-dl)*rho_old[i][j-1]))  + D * (r**2/ dt) * (rho_old[i-1][j] + rho_old[i+1][j] + rho_old[i][j-1] + rho_old[i][j+1] - 4 * rho_old[i][j])
        
    filename = "pas"+str(n)+".dat"
    
    file = open(filename,"w")

    for i in range(0,101,1):
        x = i*dl
        for j in range(0,101,1):
            y = j*dl
            file.write("{} \t {} \t {} \n".format(x,y,rho_new[i][j]))
            rho_old[i][j] = rho_new[i][j]

        

