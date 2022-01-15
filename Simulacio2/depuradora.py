import numpy as np

dl = 0.001
r = 0.25
N = 1001
k = 0.1

rho_old = np.zeros((N,N))
rho_new = np.zeros((N,N))
S = np.zeros((N,N))

#condicions inicals

for i in range(401,600,1):
    rho_old[0][i] = 2.0  #rho1
for j in range(801,1000,1):
    rho_old[j][0] = 1.5 #rho2

# Definim la densitat que extrau la depuradora

for i in range(401,600,1):
    for j in range(801,1000,1):
        S[j][i] = -1

#comencem el bucle temporal explicit

for n in range (1,10,1):

    for j in range(1,801,1):  #metode numeric per al flux vertical (J_y)
        for i in range(401,600,1):
            rho_new[j][i] = (1.0/4.0 - r/2.0 ) * (rho_old[j][i+1]-rho_old[j][i-1] + rho_old[j+1][i] - rho_old[j-1][i]) + (k*r/ dl) *(rho_old[j][i+1]+rho_old[j][i-1] + rho_old[j-1][i] + rho_old[j+1][i] -4.0*rho_old[j][i])
            if rho_new[j][i]<0.0: #comprovem que cap punt tingui densitat negativa
                rho_new[j][i] = 0.0
    for j in range(801,1000,1):
        for i in range(1,1000,1):
            rho_new[j][i] = (1.0/4.0 - r/2.0 ) * (rho_old[j][i+1]-rho_old[j][i-1] + rho_old[j+1][i] - rho_old[j-1][i]) + (k*r/ dl) *(rho_old[j][i+1]+rho_old[j][i-1] + rho_old[j-1][i] + rho_old[j+1][i] -4.0*rho_old[j][i]) + S[j][i]
            if rho_new[j][i]<0.0:
                rho_new[j][i] = 0.0

    rho_old = np.copy(rho_new)

    filename = "pas"+str(n)+".dat"

    f = open(filename,"w")

    for i in range(0,N,1):
        for j in range(0,N,1):
            f.write("{} \t {} \t {} \n".format(i*dl,1-j*dl,rho_new[j][i]))
    print(n)




