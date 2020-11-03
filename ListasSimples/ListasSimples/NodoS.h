#pragma once
#include <stdlib.h>
class NodoS
{
private:
	int dato;
	NodoS *sgte;
public:
	NodoS();
	NodoS(int);
	~NodoS();

	NodoS *getSgte();
	int getDato();

	void setDato(int);
	void setSgte(NodoS*);
};

