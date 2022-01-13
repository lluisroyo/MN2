#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double dx; /* step espacial en x i en y */
	double r; /* ratio step temporal / step espacial */
	double dt;
	double rho_old[1001][1001]; /* matriu de les densitats 1001x1001, dx=0.001 */
	double rho_new[1001][1001]; /* utilitzarem 2 matrius per estalviar memoria */
	double v_x[1001][1001]; /* camp de velcitats en x */
	double v_y[1001][1001]; /* camp de velcitats en y */
	double S[1001][1001]; /* densitat que la depuradora elimina */
	double J[1001][1001]; /* matriu corrents conducion */
	double coorX[1001];
	double coorY[1001]; 
	
	
	FILE* output;
	char filename[15];
	
	/* aquests vectors seran utils a l'hora d'imprimir a un arxiu les coordenades corrresponent a l'element j,i de la matriu. S'ha de tenir en compte que la fila 0 de la matriu correspon a y=1, mentre que la fila 1000 correspon a y=0. */

	int n,i,j; /* index temporal, espacial en x, espacial en y */
	
	dx = 0.001;
	r = 0.25;
	dt = r * dx;

	/* inicialitzem totes les matrius amb zeros */
	for(j=0;j<1001;j++){
		for(i=0;i<1001;i++){
			rho_old[j][i] = 0.0;
			rho_new[j][i] = 0.0;
			v_x[j][i] = 0.0;
			v_y[j][i] = 0.0;
			S[j][i] = 0.0;
		}
	}

	/* assignem els valors dels vectors de coordenades */

	for(i=0;i<1001;i++){
		coorX[i] = i * dx;
	}
	for(j=0;j<1001;j++){
		coorY[j] = 1.0 - j * dx;
	}

	/* Aleshores per saber les coordenades de l'element j,i de la matriu x=coorX[i], y=coorY[j] */
	
	/*Assignem les condicions inicials */

	for(i=401;i<600;i++){
		rho_old[0][i] = 2.0; /*rho1*/
	}
	for(j=801;j<1000;j++){
		rho_old[j][0] = 1.5; /*rho2*/
	}

	/* Definim la densitat que extrau la depuradora */

	for(i=401;i<600;i++){
		for(j=801;j<1000;j++){
			S[j][i] = -0.5;
		}
	}

	/* Definim el camp de velocitats */

	for(i=401;i<600;i++){
		for(j=0;j<801;j++){
			v_y[j][i] = 0.5;
		}
	}

	for(i=0;i<1001;i++){
		for(j=801;j<1000;j++){
			v_x[j][i] = 0.5;
		}
	}
	
	/* comencem el bucle temporal */
	for(n=0;n<1000;n++){
		for(j=0;j<801;j++){
			for(i=401;i<600;i++){ /* càlcul per a la columna vertical*/ 			 }
		}
		for(j=801;j<1000;j++){
			for(i=1;i<1000;i++){ /* càlcul per a la columna horitzontal */
			}
		}
		for(j=0;j<1001;j++){
			for(i=0;i<1001;i++){
				if(rho_new[j][i]<0.0){
					rho_new[j][i] = 0.0; /* El que fem aquí es fixar a 0 els punts on l'efecte de la depuradora ens dona una densitat negativa */
				}
			}
		}

		sprintf(filename,"pas%d.dat",n);
		output = fopen(filename, "w");

		for(j=0;j<1001;j++){ 
			for(i=0;i<1001;i++){
				fprintf(output,"%lf \t %lf \t %lf \n",coorX[i],coorY[j],rho_new[j][i]); /* imprimim els valors de cada iteracio a un arxiu */
				rho_old[j][i] = rho_new[j][i]; /* assignem rho_old per a la següent iteracio */ 
			}
		}
		fclose(output);
	}

	return 0;
}
