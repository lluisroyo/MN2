#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 7 /*nº de cuerpos */
#define h 0.00023080853  /*discr tep temporal 1 dia 0.00023080853*/

double f(double x1,double x2,double y1,double y2,double z1,double z2, double m){
	return  m * (x2 - x1) / pow(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2),1.5);
}


int main(){
	double m[N] = {39.45,0.0000065476249,0.000096543564,0.000118,0.0000127,0.0376494928,23.67120}; //Sol, mercuri, venus, terra, mart, jupiter, gliese

	double x[N] = {0.0,0.07440225,0.139021245,0.192204,0.29355343,1.0,0.0};
	double y[N] = {0.0,0.0,0.0,0.0,0.0,0.0,-3.0};
	double z[N] = {0.0,0.0,0.0,0.0,0.0,0.0,4.0};

	double v_x[N] = {0.0,0.0,0.0,0.0,0.0,0.0,-0.0};
	double v_y[N] = {0.0,2*M_PI*x[1]/0.020300118,2*M_PI*x[2]/0.051863092,2*M_PI*x[3]/0.084303,2*M_PI*x[4]/0.1585651,2*M_PI*x[5],8.0};
	double v_z[N] = {0.0,0.0,0.0,0.0,0.0,0.0,-4.0};


	double k1x[N],k2x[N],k3x[N],k4x[N],l1x[N],l2x[N],l3x[N],l4x[N];
	double k1y[N],k2y[N],k3y[N],k4y[N],l1y[N],l2y[N],l3y[N],l4y[N];
	double k1z[N],k2z[N],k3z[N],k4z[N],l1z[N],l2z[N],l3z[N],l4z[N];

	double x_1[N], y_1[N], z_1[N], v_x_1[N], v_y_1[N], v_z_1[N]; /* x'  v'*/
	double x_2[N], y_2[N], z_2[N], v_x_2[N], v_y_2[N], v_z_2[N]; /* x''  v''*/
	double x_3[N], y_3[N], z_3[N], v_x_3[N], v_y_3[N], v_z_3[N]; /* x'''  v'''*/

	double F_x, F_y, F_z;

	//calculo de la habitabilidad
	double Rjup=7.783278*pow(10,11); //radio jupiter
	double Ps=3.827*pow(10,26); //potencia sol
	double Pg=0.116*Ps; //Potencia Gliese
	double FlujoS=0.0;
	double FlujoG=0.0;
	double FlujoT=0.0;
	double max=0;
	double min=10000000000;

	
	FILE *output2;
	char filename2[100];
	sprintf(filename2,"habitabilidad.dat");
	output2 = fopen(filename2,"w");

	int i,j,n;

	
	for(n=1; n<50000; n++){
    		for(i=0; i<N; i++){

        		k1x[i] = v_x[i];
        		k1y[i] = v_y[i];
        		k1z[i] = v_z[i];

        		F_x = 0;
        		F_y = 0;
        		F_z = 0;

        		for(j=0; j<N; j++){
            			if(j==i){
            			}
            			else{
                			F_x += f(x[i],x[j],y[i],y[j],z[i],z[j],m[j]);
                			F_y += f(y[i],y[j],x[i],x[j],z[i],z[j],m[j]);
                			F_z += f(z[i],z[j],x[i],x[j],y[i],y[j],m[j]);
            			}
        		}		

       			l1x[i] = F_x;
       			l1y[i] = F_y;
       			l1z[i] = F_z;

        		x_1[i] = x[i] + 0.5*h*k1x[i];
        		y_1[i] = y[i] + 0.5*h*k1y[i];
        		z_1[i] = z[i] + 0.5*h*k1z[i];

        		v_x_1[i] = v_x[i] + 0.5*h*l1x[i];
        		v_y_1[i] = v_y[i] + 0.5*h*l1y[i];
        		v_z_1[i] = v_z[i] + 0.5*h*l1z[i];
    		}
    		for(i=0; i<N; i++){

        		k2x[i] = v_x_1[i];
        		k2y[i] = v_y_1[i];
        		k2z[i] = v_z_1[i];

        		F_x = 0;
        		F_y = 0;
        		F_z = 0;

        		for(j=0; j<N; j++){
            			if(j==i){
            			}
            			else{
                			F_x += f(x_1[i],x_1[j],y_1[i],y_1[j],z_1[i],z_1[j],m[j]);
                			F_y += f(y_1[i],y_1[j],x_1[i],x_1[j],z_1[i],z_1[j],m[j]);
                			F_z += f(z_1[i],z_1[j],x_1[i],x_1[j],y_1[i],y_1[j],m[j]);
            			}
        		}

        		l2x[i] = F_x;
        		l2y[i] = F_y;
        		l2z[i] = F_z;

        		x_2[i] = x[i] + 0.5*h*k2x[i];
        		y_2[i] = y[i] + 0.5*h*k2y[i];
        		z_2[i] = z[i] + 0.5*h*k2z[i];

        		v_x_2[i] = v_x[i] + 0.5*h*l2x[i];
        		v_y_2[i] = v_y[i] + 0.5*h*l2y[i];
			v_z_2[i] = v_z[i] + 0.5*h*l2z[i];
    		}
		for(i=0; i<N; i++){

        		k3x[i] = v_x_2[i];
        		k3y[i] = v_y_2[i];
        		k3z[i] = v_z_2[i];

        		F_x = 0;
        		F_y = 0;
        		F_z = 0;

        		for(j=0; j<N; j++){
            			if(j==i){
            			}
            			else{
                			F_x += f(x_2[i],x_2[j],y_2[i],y_2[j],z_2[i],z_2[j],m[j]);
                			F_y += f(y_2[i],y_2[j],x_2[i],x_2[j],z_2[i],z_2[j],m[j]);
                			F_z += f(z_2[i],z_2[j],x_2[i],x_2[j],y_2[i],y_2[j],m[j]);
            			}
        		}

        		l3x[i] = F_x;
        		l3y[i] = F_y;
        		l3z[i] = F_z;

        		x_3[i] = x[i] + h*k3x[i];
        		y_3[i] = y[i] + h*k3y[i];
        		z_3[i] = z[i] + h*k3z[i];

        		v_x_3[i] = v_x[i] + h*l3x[i];
        		v_y_3[i] = v_y[i] + h*l3y[i];
        		v_z_3[i] = v_z[i] + h*l3z[i];
    		}
    		for(i=0; i<N; i++){

        		k4x[i] = v_x_3[i];
        		k4y[i] = v_y_3[i];
        		k4z[i] = v_z_3[i];

        		F_x = 0;
        		F_y = 0;
        		F_z = 0;

        		for(j=0; j<N; j++){
            			if(j==i){
            			}
            			else{
                			F_x += f(x_3[i],x_3[j],y_3[i],y_3[j],z_3[i],z_3[j],m[j]);
                			F_y += f(y_3[i],y_3[j],x_3[i],x_3[j],z_3[i],z_3[j],m[j]);
                			F_z += f(z_3[i],z_3[j],x_3[i],x_3[j],y_3[i],y_3[j],m[j]);
            			}
        		}

        		l4x[i] = F_x;
        		l4y[i] = F_y;
        		l4z[i] = F_z;

        		x[i] += h*(k1x[i]+2.0*k2x[i]+2.0*k3x[i]+k4x[i])/6.0;
        		y[i] += h*(k1y[i]+2.0*k2y[i]+2.0*k3y[i]+k4y[i])/6.0;
        		z[i] += h*(k1z[i]+2.0*k2z[i]+2.0*k3z[i]+k4z[i])/6.0;

        		v_x[i] += h*(l1x[i]+2.0*l2x[i]+2.0*l3x[i]+l4x[i])/6.0;
        		v_y[i] += h*(l1y[i]+2.0*l2y[i]+2.0*l3y[i]+l4y[i])/6.0;
        		v_z[i] += h*(l1z[i]+2.0*l2z[i]+2.0*l3z[i]+l4z[i])/6.0;
    		}

		FILE *output;
		char filename[100];
		sprintf(filename,"pas%d.dat",n);
		output = fopen(filename,"w");
		
		for (i=0; i<N; i++){
			fprintf(output, "%lf \t %lf \t %lf \t",x[i],y[i],z[i]);
		}
	
		fclose(output);

	FlujoS=Ps/(4*M_PI*Rjup*Rjup*(pow(x[3]-x[0],2)+pow(y[3]-y[0],2)+pow(z[3]-z[0],2)));
	FlujoG=Pg/(4*M_PI*Rjup*Rjup*(pow(x[3]-x[6],2)+pow(y[3]-y[6],2)+pow(z[3]-z[6],2)));
	FlujoT=FlujoG+FlujoS;
	if (max<FlujoT){
		max=FlujoT;
	}
	if (min>FlujoT){
		min=FlujoT;
	}
	fprintf(output2,"%d \t %lf \n",n,FlujoT);
	
	}

fprintf(output2,"\n \n""Máximo: %lf \n""Mínimo: %lf",max,min);
fclose(output2);

	return 0;
}
