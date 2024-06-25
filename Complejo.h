#ifndef COMPLEJO_H
#define COMPLEJO_H

class Complejo {
public:
	Complejo();
	~Complejo();
	
	void obtComps(double re, double im);
	double regParteReal();
	double regParteIm();
	bool esRealPuro();
	bool esImagPuro();
	
private:
	double vectAsoc[2];
};

#endif

