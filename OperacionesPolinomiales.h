#include<cstdlib>
#ifndef OPERACIONESPOLINOMIALES_H
#define OPERACIONESPOLINOMIALES_H

Polinomio sumaPolinomios(Polinomio p1, Polinomio p2){
	
	Polinomio suma;
	unsigned int grd1 = p1.getGradoPol();
	unsigned int grd2 = p2.getGradoPol();
	double *coef1 = p1.getPolinomio();
	double *coef2 = p2.getPolinomio();
	double *cfs;
	
	if(grd1 >= grd2){
		int trm = grd1+1;
		cfs = (double*)malloc(trm*sizeof(double));
		for(int i=0; i<trm; i++){
			cfs[i] = coef1[i];
		}
		unsigned int difer = grd1-grd2;
		suma.setGradoPol(grd1);
		for(int i=difer; i<trm; i++){
			cfs[i] = cfs[i] + coef2[i-difer]; 
		}
	}
	else{
		int trm = grd2+1;
		cfs = (double*)malloc(trm*sizeof(double));
		for(int i=0; i<trm; i++){
			cfs[i] = coef2[i];
		}
		unsigned int difer = grd2-grd1;
		suma.setGradoPol(grd2);
		for(int i=difer; i<trm; i++){
			cfs[i] = cfs[i] + coef1[i-difer]; 
		}
	}
	suma.setCoefPol(cfs);
	
	return suma;
}

Polinomio productoPolinomios(Polinomio p1, Polinomio p2){
	
	Polinomio producto;
	unsigned int grd1 = p1.getGradoPol();
	unsigned int grd2 = p2.getGradoPol();
	double *coef1 = p1.getPolinomio();
	double *coef2 = p2.getPolinomio();
	unsigned int g = grd1 + grd2;
	producto.setGradoPol(g);
	int trm = g+1;
	double *cfs = (double*)malloc(trm*sizeof(double));
	for(int i=0; i<trm; i++){
		cfs[i] = 0;
	}
	for(int i=0; i<trm; i++){
		for(unsigned int j=0; j<grd1+1; j++){
			for(unsigned int k=0; k<grd2+1; k++){
				int s = j+k;
				if(s == i){
					double pCoef = coef1[j]*coef2[k];
					cfs[i] = cfs[i] + pCoef;
				}
			}
		}
	}
	producto.setCoefPol(cfs);
	return producto;
}

#endif
