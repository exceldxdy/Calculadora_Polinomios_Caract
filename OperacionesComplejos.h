#ifndef OPERACIONESCOMPLEJOS_H
#define OPERACIONESCOMPLEJOS_H

Complejo sumaComplejos(Complejo u, Complejo v){
	
	Complejo w;
	double re = u.regParteReal() + v.regParteReal();
	double im = u.regParteIm() + v.regParteIm();
	w.obtComps(re, im);
	return w;
}
	
Complejo productoComplejos(Complejo u, Complejo v){
		
	Complejo w;
	double re = (u.regParteReal() * v.regParteReal()) - (u.regParteIm() * v.regParteIm());
	double im = (u.regParteIm() * v.regParteReal()) + (u.regParteReal() * v.regParteIm());
	w.obtComps(re, im);
	return w;
}
		
Complejo inversoMultiplicativo(Complejo u){
			
	Complejo uInv;
	double re = u.regParteReal() / ((u.regParteReal() * u.regParteReal()) + (u.regParteIm() * u.regParteIm()));
	double im = u.regParteIm() / ((u.regParteReal() * u.regParteReal()) + (u.regParteIm() * u.regParteIm()));
	uInv.obtComps(re, im);
	return uInv;
}
			
Complejo complejoConjugado(Complejo u){
				
	Complejo conj;
	double re = u.regParteReal();
	double im = - u.regParteIm();
	conj.obtComps(re, im);
	return conj;
}

#endif
