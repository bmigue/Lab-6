#pragma once
#include "NodoS.h"
using namespace std;
class listasSimple
{
private:
	NodoS *cab;
	int largo;

public:
	listasSimple();
	~listasSimple();
	int getLargo();	
	NodoS* getCab();
	void setLargo(int);
	void setCab(NodoS*);
	void desplegar();
	void agregarInicio(int);
	bool agregarAntesDe(int, int);
	bool esVacia();
	NodoS* dirNodo(int);
	NodoS* dirAnterior(int);
	NodoS* dirUltimo();
	bool agregarDespuesDe(int, int);
	void agregarFinal(int x);
	NodoS* dirNodoIndice(int n);
	int valorIndice(int n);
	bool agregarIndice(int agregado, int n);
	bool eliminarIndice(int n);
	bool eliminar(int x);
};

