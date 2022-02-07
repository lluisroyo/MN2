import numpy as np

def f(x,y):
    f = (1.0 /(2.0* np.pi)) * np.exp(-(((x-0.25)**2 + (y-0.75)**2)/0.0002)) 
    return f

def v_x(x):
    velocitat = -100*(x-1) 
    return velocitat
def v_y(y):
    velocitat = - 100 * y
    return velocitat


dl = 0.01
r = 0.001
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
file.close()

# Comprovació volum inicial = 1 #
volum_inicial = 0

for i in range(1,100,1):
    for j in range(1,100,1):
        volum_inicial += rho_old[i][j]
print("volum inicial: {}".format(volum_inicial))

err_file = open("error.dat","w")

for n in range(1,1000,1):
    for i in range(1,100,1):
        x = i*dl
        for j in range(1,100,1):
            y = j*dl

            rho_new[i][j] = rho_old[i][j] - (r / 2.0) * ( v_x(x+dl)*rho_old[i+1][j] + v_y(y+dl)*rho_old[i][j+1] - v_x(x-dl)*rho_old[i-1][j] - v_y(y-dl)*rho_old[i][j-1]  )   +  (r**2 / 2) * ( v_x(x+dl/2)*(v_x(x+dl)*rho_old[i+1][j] - v_x(x)*rho_old[i][j]) + v_y(y+dl/2)*(v_y(y+dl)*rho_old[i][j+1] - v_y(y)*rho_old[i][j]) - v_x(x-dl/2)*(v_x(x)*rho_old[i][j] - v_x(x-dl)*rho_old[i-1][j]) - v_y(y-dl/2)*(v_y(y)*rho_old[i][j] - v_y(y-dl)*rho_old[i][j-1]))  + D * (r**2/ dt) * (rho_old[i-1][j] + rho_old[i+1][j] + rho_old[i][j-1] + rho_old[i][j+1] - 4 * rho_old[i][j])
        
    filename = "pas"+str(n)+".dat"
    
    file = open(filename,"w")
    
    volum = 0

    for i in range(0,101,1):
        x = i*dl
        for j in range(0,101,1):
            y = j*dl
            file.write("{} \t {} \t {} \n".format(x,y,rho_new[i][j]))
            rho_old[i][j] = rho_new[i][j]
            volum += rho_new[i][j]
    file.close()
    
    #Les següents línies de codi serveixen per poder fer una representació de l'error
    err = np.abs(volum - volum_inicial) / volum_inicial *100 
    err_file.write("{} \t {} \n".format(n,err))

    print("{}/999".format(n))


err_file.close()

volum_final = 0
for i in range(1,100,1):
    for j in range(1,100,1):
        volum_final += rho_old[i][j]
print("volum final:{}".format(volum_final))
error = np.abs(volum_final - volum_inicial)/volum_inicial *100
print("error relatiu: {}%".format(error))
        

