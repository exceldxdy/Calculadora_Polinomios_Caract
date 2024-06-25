#include<cstdlib>
#include "Matriz.h"

Matriz::Matriz() {
	
}

Matriz::~Matriz() {
	
}

void Matriz::setTmn(unsigned int tmn){
	tMtz = tmn;
}

void Matriz::setMatriz(double **m){
	mtz = m;
}

void Matriz::setMatriz(double C){
	mtz = (double**)malloc(1*sizeof(double*));
	mtz[0] = (double*)malloc(1*sizeof(double));
	mtz[0][0] = C;
}

unsigned int Matriz::getTmn(){
	return tMtz;
}

double** Matriz::getMatriz(){
	return mtz;
}
