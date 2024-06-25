#include<iostream>

#include "Polinomio.h"
#include "OperacionesPolinomiales.h"
#include "Complejo.h"
#include "OperacionesComplejos.h"
#include "Matriz.h"

using namespace std;

Matriz pedirMatriz();
void imprimirComplejo(Complejo z);
void imprimirPolinomio(Polinomio p);
void imprimirMatriz(Matriz m);
Polinomio matrizToPolinomio(Matriz m);

int main (int argc, char *argv[]) {
	
	Matriz mtrz = pedirMatriz();
	cout << "La matriz ingresada es: \n" << endl;
	imprimirMatriz(mtrz);
	Polinomio pCaracteristico = matrizToPolinomio(mtrz);
	cout << "El polinomio caracteristico asociado a la matriz es: ";
	imprimirPolinomio(pCaracteristico);
	
	return 0;
}

void imprimirComplejo(Complejo z){
	
	if(z.regParteIm() >= 0){
		cout << z.regParteReal() << " + " << z.regParteIm() << "i" << endl;
	}
	else{
		cout << z.regParteReal() << " - " << -z.regParteIm() << "i" << endl;
	}
}

void imprimirPolinomio(Polinomio p){
	
	double *coefs = p.getPolinomio();
	if(p.getGradoPol() > 0){
		if(coefs[0] > 0 && coefs[0] != 1){
			cout << coefs[0] << "l^" << p.getGradoPol() << " ";
		}
		else if(coefs[0] < 0 && coefs[0] != -1){
			cout << coefs[0] << "l^" << p.getGradoPol() << " ";
		}
		else if(coefs[0] > 0 && coefs[0] == 1){
			cout << "l^" << p.getGradoPol() << " ";
		}
		else{
			cout << "-l^" << p.getGradoPol() << " ";
		}
		for(int i=1; i<p.getGradoPol()+1; i++){
			if(coefs[i] > 0 && coefs[i] != 1){
				if((p.getGradoPol() - i) != 1){
					if((p.getGradoPol()-i) != 0){
						cout << "+ " << coefs[i] << "l^" << (p.getGradoPol()-i) << " ";
					}
					else{
						cout << "+ " << coefs[i];
					}
				}
				else{
					cout << "+ " << coefs[i] << "l ";
				}
			}
			else if(coefs[i] > 0 && coefs[i] == 1){
				if((p.getGradoPol() - i) != 1){
					if((p.getGradoPol()-i) != 0){
						cout << "+ l^" << (p.getGradoPol()-i) << " ";
					}
					else{
						cout << "+ " << coefs[i];
					}
				}
				else{
					cout << "+ l ";
				}
			}
			else if(coefs[i] < 0 && coefs[i] != -1){
				if((p.getGradoPol() - i) != 1){
					if((p.getGradoPol()-i) != 0){
						cout << "- " << -coefs[i] << "l^" << (p.getGradoPol()-i) << " ";
					}
					else{
						cout << "- " << -coefs[i];
					}
					
				}
				else{
					cout << "- " << -coefs[i] << "l ";
				}
			}
			else if(coefs[i] < 0 && coefs[i] == -1){
				if((p.getGradoPol() - i) != 1){
					if((p.getGradoPol()-i) != 0){
						cout << "- l^" << (p.getGradoPol()-i) << " ";
					}
					else{
						cout << "- " << -coefs[i];
					}
				}
				else{
					cout << "- l ";
				}
			}
		}
	}
	else{
		cout << "La constante es: " << coefs[0] << endl;
	}
	cout << endl;
}
	
Matriz pedirMatriz(){
	unsigned int t;
	Matriz m;
	do{
		cout << "Ingrese el valor n de la matriz (nxn): " << endl;
		cin >> t;
	} while(t < 1 || t > 3);
	m.setTmn(t);
	if(t>1){
		double **mt;
		mt = (double**)malloc(t*sizeof(double*));
		for(unsigned int i=0; i<t; i++){
			mt[i] = (double*)malloc(t*sizeof(double));
		}
		cout<<"Ingresa los datos de la matriz:"<<endl;
		for(unsigned int i=0; i<t; i++)
		{
			for(unsigned int j=0; j<t; j++)
			{								
				cout << "matriz[" << i+1 << "][" << j+1 <<"]=";
				cin>>mt[i][j];							
			}
		}
		m.setMatriz(mt);
	}
	else{
		double mt;
		cout << "Ingrese el elemento en [1][1]: " << endl;
		cin >> mt;
		m.setMatriz(mt);
	}
	return m;
}
	
void imprimirMatriz(Matriz m){
	int t = m.getTmn();
	double **mt = m.getMatriz();
	for(int i=0; i<t; i++){
		for(int j=0; j<t; j++){
			cout << mt[i][j] << "\t";
		}
		cout << "\n";
	}
}

Polinomio matrizToPolinomio(Matriz m){
	unsigned int t = m.getTmn();
	double **mt = m.getMatriz();
	Polinomio polCaract;
	switch(t){
	case 1:
		{
			polCaract.setGradoPol(t);
			double *cf = (double*)malloc(2*sizeof(double));
			cf[0] = -1;
			cf[1] = mt[0][0];
			polCaract.setCoefPol(cf);
			break;
		}
	case 2:
		{
			double k = - (mt[1][0] * mt[0][1]);
			double *c1 = (double*)malloc(2*sizeof(double));
			double *c2 = (double*)malloc(2*sizeof(double));
			c1[0] = -1;
			c2[0] = -1;
			c1[1] = mt[0][0];
			c2[1] = mt[1][1];
			Polinomio subp[2];
			for(int i=0; i<2; i++){
				subp[i].setGradoPol(1);
			}
			Polinomio cnt;
			cnt.setGradoPol(0);
			cnt.setCoefPol(k);
			subp[0].setCoefPol(c1);
			subp[1].setCoefPol(c2);
			Polinomio rst = productoPolinomios(subp[0], subp[1]);
			polCaract = sumaPolinomios(rst, cnt);
			break;
		}
	case 3:
		{
			double k = -(mt[2][1]*mt[0][2]*mt[1][0]) + (mt[2][0]*mt[0][1]*mt[1][2]);
			double p[3];
			double *c1 = (double*)malloc(2*sizeof(double));
			double *c2 = (double*)malloc(2*sizeof(double));
			double *c3 = (double*)malloc(2*sizeof(double));
			Polinomio c;
			c.setGradoPol(0);
			c.setCoefPol(k);
			c1[0] = -1;
			c2[0] = -1;
			c3[0] = -1;
			c1[1] = mt[0][0];
			c2[1] = mt[1][1];
			c3[1] = mt[2][2];
			p[0] = -(mt[2][1]*mt[1][2]);
			p[1] = -(mt[0][2]*mt[2][0]);
			p[2] = (mt[0][1]*mt[1][0]);
			Polinomio subp[3];
			Polinomio subp2[3];
			for(int i=0; i<3; i++){
				subp2[i].setGradoPol(0);
				subp[i].setGradoPol(1);
				subp2[i].setCoefPol(p[i]);
			}
			subp[0].setCoefPol(c1);
			subp[1].setCoefPol(c2);
			subp[2].setCoefPol(c3);
			Polinomio kSubP[3];
			for(int i=0; i<3; i++){
				kSubP[i] = productoPolinomios(subp[i], subp2[i]);
			}
			Polinomio pPrC1;
			pPrC1 = productoPolinomios(subp[0], subp[1]);
			Polinomio pPrC2;
			pPrC2 = productoPolinomios(pPrC1, subp[2]);
			for(int i=0; i<3; i++){
				pPrC2 = sumaPolinomios(pPrC2, kSubP[i]);
			}
			polCaract = sumaPolinomios(pPrC2, c);
			break;
		}
	default:
			cout << "Eso si no te lo vengo manejando bro" << endl;
		break;
	}
	return polCaract;
}
