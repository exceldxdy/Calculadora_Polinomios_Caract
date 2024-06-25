#include<cstdlib>
#include "Polinomio.h"

Polinomio::Polinomio() {
	
}

Polinomio::~Polinomio() {
	
}

void Polinomio::setGradoPol(unsigned int g){
	grado = g;
}

int Polinomio::getGradoPol(){
	return grado;
}

void Polinomio::setCoefPol(double *coef){
	coefs = coef;
}

void Polinomio::setCoefPol(double C){
	coefs = (double*)malloc(1*sizeof(double));
	coefs[0] = C;
}

double* Polinomio::getPolinomio(){
	return coefs;
}
