#include "Complejo.h"

Complejo::Complejo() {
	
}

Complejo::~Complejo() {
	
}

void Complejo::obtComps(double re, double im){
	
	vectAsoc[0] = re;
	vectAsoc[1] = im;
}

double Complejo::regParteReal(){
	
	return vectAsoc[0];
}

double Complejo::regParteIm(){
	
	return vectAsoc[1];
}

bool Complejo::esRealPuro(){
	
	if(vectAsoc[1] == 0){
		return true;
	}
	return false;
}

bool Complejo::esImagPuro(){
	
	if(vectAsoc[0] == 0){
		return true;
	}
	return false;
}
