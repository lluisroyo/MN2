#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 2 /*nº de planetas */
#define h 0.1 /*step temporal*/

double f(double p_x[2][N],double p_y[2][N], double m[N],int i){
	double suma =0;
	int j;
	for (j=0; j<N; j++){
		if(j==i){
		}
		else{
			suma += m[j] * (p_x[0][j] - p_x[0][i]) / pow(pow(p_x[0][j]-p_x[0][i],2)+pow(p_y[0][j]-p_y[0][i],2),1.5);
		}
	}
	return suma;
}

double RK(double p_x[2][N],double p_y[2][N], double m[N],int i){
	double k1,k2,k3,k4,l1,l2,l3,l4;
	double p_aux[2][N];
	int a,b; /* a filas, b columnas */

	for(a=0; a<2; a++){
		for(b=0; b<N; b++){
			p_aux[a][b] = p_x[a][b];
		}
	}

	l1 = h * f(p_x, p_y, m, i);
	k1 = h * p_x[1][i];
	
	p_aux[0][i] = p_x[0][i] + 0.5*k1;

	l2 = h * f(p_aux,p_y,m, i);
	k2 = h * (p_x[1][i] + 0.5 * l1);

	p_aux[0][i] = p_x[0][i] + 0.5*k2;

	l3 = h * f(p_aux,p_y,m, i);	
	k3 = h * (p_x[1][i] + 0.5 * l2);
	
	p_aux[0][i] = p_x[0][i] + 0.5*k3;

	l4 = h * f(p_aux,p_y,m, i);	
	k4 = h * (p_x[1][i] + 0.5 * l3);
	
	p_x[0][i] = p_x[0][i] + (1.0/6.0) * (k1 + 2.0*k2 + 2.0*k3 +k4);
	p_x[1][i] = p_x[1][i] + (1.0/6.0) * (l1 + 2.0*l2 + 2.0*l3 +l4);

	return p_x;
}

int main(){
	return 0;
}
