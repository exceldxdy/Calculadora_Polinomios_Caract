#ifndef POLINOMIO_H
#define POLINOMIO_H

class Polinomio {
public:
	Polinomio();
	~Polinomio();
	
	void setGradoPol(unsigned int g);
	int getGradoPol();
	void setCoefPol(double *coef);
	void setCoefPol(double C);
	double* getPolinomio();
	
private:
	unsigned int grado;
	double *coefs;
	
};

#endif

