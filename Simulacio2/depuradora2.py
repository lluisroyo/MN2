import numpy as np
particion=0.1 #particion espacial
p=10*particion
dl = 0.001 
r = 0.024 #dt/dl
N = int(p*100+1) #longitud de las matrices
k = 0.1
tub11x=int(p*40+1) #inicio en x de la tuberia 1
tub12x=int(p*60)   #final en x de la tuberia 1
tub11y=0           #inicio en y de la tuberia 1
tub12y=int(p*80+1) #final en y de la tuberia 1
tub21x=0           #inicio en x de la tuberia 2
tub22x=tub11x-1    #final en x de la tuberia 2
tub21y=tub12y+1    #inicio en y de la tuberia 2
tub22y=N           #final en y de la tuberia 2
rho1=2.0   
rho2=1.5
rho_old = np.zeros((N,N))
rho_new = np.zeros((N,N))
S = np.zeros((N,N))

#condiciones inicales

for i in range(tub11x,tub12x,1):
    for j in range(tub11y,tub12y):
        rho_old[j][i] = rho1#rho1
for i in range(tub21x,tub22x,1):
    for j in range(tub21y,tub22y):
        rho_old[j][i] = rho2#rho2

# Definimos la densidad que extrae la depuradora

for i in range(tub11x,tub12x):
    for j in range(tub21y,tub22y,1):
        S[j][i] = -1.0

#comenzamos el bucle temporal explicito

for n in range (1,1000,1):
    for j in range(tub11y+1,tub12y+1,1):
        for i in range(tub11x,tub12x,1):
            rho_new[j][i] = rho_old[j][i] - (r/2.0)*(rho_old[j+1][i]-rho_old[j-1][i])+(r*r/2)*(rho_old[j+1][i]-rho_old[j][i]-rho_old[j][i]+rho_old[j][i-1])+(k*k*r/dl)*(rho_old[j+1][i]+rho_old[j-1][i]+rho_old[j][i+1]+rho_old[j][i-1]-4*rho_old[j][i])
            if rho_new[j][i]<0.0: #comprovem que cap punt tingui densitat negativa
                rho_new[j][i] = 0 #abs(rho_new[j][i])
    for j in range(tub21y,tub22y-1,1):
        for i in range(tub21x+1,int(p*100)-1,1):
            rho_new[j][i] = rho_old[j][i] - (r/2.0)*(rho_old[j+1][i]-rho_old[j-1][i])+(r*r/2)*(rho_old[j+1][i]-rho_old[j][i]-rho_old[j][i]+rho_old[j][i-1])+(k*k*r/dl)*(rho_old[j+1][i]+rho_old[j-1][i]+rho_old[j][i+1]+rho_old[j][i-1]-4*rho_old[j][i])+S[j][i]
            if rho_new[j][i]<0.0:
                rho_new[j][i] = 0 #abs(rho_new[j][i])
    for i in range(tub11x,tub12x):#ponemos las condiciones de contorno constantes
        rho_new[0][i]=rho1
    for j in range(tub21y,tub22y):
        rho_new[j][0]=rho2
    for j in range(tub11y,tub12y):
        rho_new[j][tub11x]=rho1
    for j in range(tub11y,tub12y):
        rho_new[j][tub12x]=rho1
    for i in range(tub21x,tub22x):
        rho_new[tub21y][i]=rho2
    for i in range(tub21x,tub22x):
        rho_new[tub22y-1][i]=rho2
    rho_old = np.copy(rho_new)

    filename = "pas"+str(n)+".dat"

    f = open(filename,"w")

    for i in range(0,N,1):
        for j in range(0,N,1):
            f.write("{} \t {} \t {} \n".format(i*dl/particion,1-j*dl/particion,rho_new[j][i]))
    f.close()
    print(n)
    