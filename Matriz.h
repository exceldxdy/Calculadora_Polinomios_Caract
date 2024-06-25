#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
public:
	Matriz();
	~Matriz();
	
	void setTmn(unsigned int tmn);
	void setMatriz(double **m);
	void setMatriz(double C);
	unsigned int getTmn();
	double** getMatriz();
private:
	unsigned int tMtz;
	double **mtz;
};

#endif

