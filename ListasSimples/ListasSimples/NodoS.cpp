#include "NodoS.h"

NodoS::NodoS()
{
	this->dato = 0;
	this-> sgte = NULL;
}

NodoS::NodoS(int dat)
{
	this->dato = dat;
	this->sgte = NULL;
}

NodoS::~NodoS()
{
}

NodoS* NodoS::getSgte()
{
	return this->sgte;

}

int NodoS::getDato()
{
	return this->dato;
}

void NodoS::setDato(int dato)
{
	this->dato = dato;
}

void NodoS::setSgte(NodoS* nod)
{
	this->sgte = nod;
}
