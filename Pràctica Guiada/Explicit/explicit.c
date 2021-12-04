#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

double teoric(double x,double b,double t){  /* Aquesta funcio calcula el valor teoric donat x i beta */
	double T;
	double e;
	int n;
	n = 0;
	T = b;
	e = b;

	while(e>0.000001){
		e = T;
		T += 4.0*(1.0-exp(-(2.0*n+1.0)*(2.0*n+1.0)*M_PI*M_PI*t))*sin((2.0*n+1.0)*M_PI*x) / ((2.0*n+1.0)*(2.0*n+1.0)*(2.0*n+1.0)*M_PI*M_PI*M_PI);
		n +=1;
		e = T - e;
	}
	return T;
}


int main(){
	float dx;
	float gamma;
	float dt;
	int M;
	int N;
	float t_a;
	double kappa;
	double sigma;
	double volt;
	double T_c;
		
	N = 100;
	dx = 1.0/((float)N - 1);
	gamma = 0.49;
	dt = gamma * dx * dx;
	t_a = 0.025;

	kappa = 0.56;
	sigma = 0.472;
	volt = 40.0;
	T_c = (2 * kappa * 309.65) / (volt * volt * sigma);
	
	if (t_a == 0){
		M = (int)(t_a / dt) + 1;
	}
	else{
		M = (int)(t_a / dt) + 2;
	}

	double T[N][M];
	
	int i;
	int j;

	for (i=0; i<N; i++){
		T[i][0] = T_c;
	}
	for (j=0; j<M; j++){
		T[0][j] = T_c;
		T[99][j] = T_c;
	}

	for (j=1; j<M; j++){
		for (i=1; i<N-1;i++){
			T[i][j] = T[i][j-1] + gamma*( T[i+1][j-1] -2*T[i][j-1] + T[i-1][j-1]) + dt;
		}
	}


	/*Esta part imprimeix la matriu a un fitxer */

	FILE* output;
	output = fopen("matriu.dat","w");

	for (i=0; i<N; i++){
		for (j=0; j<M; j++){
			fprintf(output,"%lf ",T[i][j]);
		}
		fprintf(output,"\n");
	}
	
	fclose(output);
	
	/* Imprimim en un fitxer la Temperatura a t final */

	FILE* output2;
	output2 = fopen("tfinal.dat","w");
	
	double a;

	for (i=0; i<N; i++){
		a = (volt * volt * sigma * T[i][M-1])/ (2 * kappa) - 273.15;
		fprintf(output2, "%f \t %lf \n",(float)i * dx * 2 , a);
	}

	fclose(output2);
	
	/* Imprimim en un fitxer l'error */

	FILE* output3;
	output3 = fopen("error.dat","w");
	
	double err[N];
	double err_1[N]; /* err_1 es l'error en unitats del SI */
	for (i=0; i<N;i++){
		err[i] =fabs(T[i][M-1] - teoric(i*dx,T_c,(M-1)*dt));
		err_1[i] = (err[i] * volt *volt *sigma)/(2.0 * kappa);
		fprintf(output3, "%lf \t %lf \n",(float)i * dx * 2.0,err_1[i]);
	}
	
	fclose(output3);

	/* Ara imprimirem cada pas de la iteracio a un fitxer per poder fer l'animació */

	for(j=0; j<M; j++){
		FILE* output4;
		char filename[sizeof "pas100.dat"];
		sprintf(filename,"pas%d.dat",j);
		output4 = fopen(filename,"w");
		for (i=0; i<N; i++){
			a = (volt * volt *sigma * T[i][j]) / (2.0 * kappa) - 273.15;
			fprintf(output4, "%f \t %lf \n",(float)i *dx*2.0, a);
		}
		fclose(output4);
	}	

	return 0;
}
