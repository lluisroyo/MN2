#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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
	double dx;
	double dt;
	double gamma;
	int M;
	int N;
	double t_a;
	double kappa;
	double sigma;
	double volt;
	double T_c;
	double t_50;
	double T_50;

	bool bandera_50 = true;

	N = 100;
	dx = 1.0/((float)N - 1);
	gamma = 0.005;
	dt = gamma *  dx;
	t_a = 0.025;

	kappa = 0.56;
	sigma = 0.472;
	volt = 40.0;
	T_c = (2.0 * kappa * 309.65) / (volt * volt * sigma);
	T_50 = (2.0 * kappa * 323.15) / (volt * volt * sigma); 

	if (t_a ==0){
		M = (int)(t_a / dt) + 1;
	}
	else{
		M = (int)(t_a / dt) + 2;
	}

	double T[N][M];

	double T_old[N];
	double T_new[N];

	int i;
	int j;
    int j_opt;

	for (i=0; i<N; i++){
		T[i][0] = T_c;
	}

	for(j=1; j<M; j++){
		FILE* output;
		char filename[sizeof "pas100.dat"];
		sprintf(filename,"pas%d.dat",j);
		output = fopen(filename, "w");

		for (i=0;i<N;i++){  /* este bucle asigna el primer guess de cada columna */
			T_old[i] = T[i][j-1];
		}

		T_new[0] = T_c;  /* fixem les condicions de contorn a T_new */
		T_new[99] = T_c;

		bool bandera = true;
		
	       	int count;
		count =0;
		double max;

		while(bandera){		/* El while aplica l'algorisme de Gauss-Seidel fins que bandera sigui false */
			count = count + 1;

			max = 0.0;

			for(i=1;i<(N-1);i++){	/* Aquest bucle afecta els elements 1-98, es a dir, deixa fix els extrems */
				T_new[i] = (gamma * (T_old[i-1] + T_old[i+1])) / (dx + 2.0 * gamma) + (dt + T[i][j-1]) / (1.0 + (2.0 * gamma) / dx);
			       if(fabs(T_old[i]-T_new[i])>max){
				       max = fabs(T_old[i]-T_new[i]);
				}

			}
			for(i=0;i<N;i++){  /* Assignem el el vector new al vector old */
				T_old[i] = T_new[i];
			}
			
			if(max<0.000001){	/* Aquest condicional s'executa per per finalitzar el while */
				bandera = false;
				for (i=0; i<N;i++){
					fprintf(output,"%lf \t %lf \n",(float)i*dx*2.0,(T_new[i]*volt * volt * sigma) / (2.0 * kappa) - 273.15);
					T[i][j] = T_new[i]; /* Finalitzat el while, portem els valors a la matriu T */
				}
			fclose(output);

			}
		}
		printf("%d \t %lf \n",count,max);
		if(T[38][j]>T_50){
			while(bandera_50){
                j_opt = j-1;
				t_50 = (j-1)*dt;
				bandera_50 = false;
			}
		}

	}

	/* Ara avaluem l'error numeric */
	FILE* output1;
	output1 = fopen("errors.dat","w");

	double err[N];
	double err1[N];

	for(i=0; i<N; i++){
		err[i] =fabs(T[i][M-1] - teoric(i*dx, T_c, (M-1)*dt));
		err1[i] = (err[i] * volt * volt *sigma) / (2.0 * kappa); /* error en unitats SI */
		fprintf(output1, "%lf \t %lf \n",2.0*i*dx,err1[i]);
	}

	fclose(output1);

	printf("El temps optim es %lf,%lf,%d \n",t_50,0.02*0.02 *t_50*49807075.0/7.0,j_opt);
	return 0;
}
			


	
	
