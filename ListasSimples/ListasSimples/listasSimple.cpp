#include "listasSimple.h"
#include <iostream>

listasSimple::listasSimple()
{
	this->cab = NULL;
	this->largo = 0;
}

listasSimple::~listasSimple()
{
}

int listasSimple::getLargo()
{
	return largo;
}

NodoS* listasSimple::getCab()
{
	return this->cab;
}


void listasSimple::setLargo(int c)
{
	this->largo = c;
}

void listasSimple::setCab(NodoS* c)
{
	this -> cab = c;
}

void listasSimple::desplegar()
{
	NodoS* aux = getCab();
	while (aux !=NULL)
	{
		cout << aux->getDato()<<endl;
		aux = aux->getSgte();
	}
}

void listasSimple::agregarInicio(int x)
{
	NodoS* nuevo = new NodoS(x); //Paso numero 1, crear el nodo
	nuevo->setSgte(getCab()); //Paso numero 2, enlazar el nuevo nodo a la lista
	setCab(nuevo); //Paso numero 3, reacomodar la lista con el nuevo nodo
	largo++;
}

bool listasSimple::agregarAntesDe(int x, int referencia)
{
	bool agregado = false;
	if (largo != 0) {
		if (getCab()->getDato()==referencia)
		{
			agregarInicio(x);
			agregado = true;
		}
		else
		{
			NodoS* ant = cab;
			while (ant->getSgte()!=NULL &&!agregado)
			{
				if (ant->getSgte()->getDato()==referencia)
				{
					NodoS* nuevo = new NodoS(x);//Crear nodo
					nuevo->setSgte(ant->getSgte());//Enlazar nodo
					ant->setSgte(nuevo);//Reacomodar con nuevo nodo
					largo++;
					agregado = true;
				}
				else
				{
					ant = ant->getSgte();
				}
			}
		}
	}

	return agregado;
}

bool listasSimple::esVacia()
{
	if (largo == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

NodoS* listasSimple::dirNodo(int x)
{
	NodoS* aux = getCab();
	bool encontrado = false;
	if (aux->getDato() == x) {
		encontrado = true;
		return aux;
	}
	else
	{
		while (aux->getSgte()!=NULL)
		{
			if (aux->getSgte()->getDato() == x) {
				return aux->getSgte();
				encontrado = true;
			}
			aux = aux->getSgte();
		}
	}
	if (encontrado==false)
	{
		return NULL;
	}

}

NodoS* listasSimple::dirAnterior(int x)
{
	bool encontrado = false;

	if (cab->getDato()==x)
	{
		return NULL;
	}
	else
	{
		NodoS *ant= cab;
		while (ant->getSgte() != NULL) {
			if (ant->getSgte()->getDato() == x)
			{
				return ant;
				encontrado = true;
			}
			ant = ant->getSgte();
		}
	}
	if (encontrado == false)
	{
		return NULL;
	}
}

NodoS* listasSimple::dirUltimo()
{
	if (largo == 0) {
		return NULL;
	}
	NodoS* aux = cab;

	while (aux->getSgte() != NULL) {
	
		aux = aux->getSgte();
	}
	return aux;
}

bool listasSimple::agregarDespuesDe(int x, int referencia)
{
	bool agregado = false;
	int contador = 1;
	if (cab->getDato() == referencia) {
		NodoS* nuevo = new NodoS(x);//Crear nodo
		nuevo->setSgte(cab->getSgte());
		cab->setSgte(nuevo);
		largo++;
		agregado = true;
	}
	else
	{
		NodoS* aux = cab;
		while (contador<=largo) {
			if (aux->getDato()==referencia)
			{
				NodoS* nuevo = new NodoS(x);//Crear nodo
				nuevo->setSgte(aux->getSgte());
				aux->setSgte(nuevo);
				largo++;
				agregado = true;
			}
			contador++;
			aux = aux->getSgte();
		}
	}
	return agregado;
}

void listasSimple::agregarFinal(int x)
{
	NodoS* nuevo = new NodoS(x);
	
	if (largo == 0) {
		cab = nuevo;
		largo++;
	}
	else {
		NodoS* aux = cab;

		while (aux->getSgte() != NULL) {

			aux = aux->getSgte();
		}
		aux->setSgte(nuevo);
	}
}

NodoS* listasSimple::dirNodoIndice(int n)
{	
	if (n > largo) {
		return NULL;
	}
	else
	{	
		int contador = 0;
		NodoS* aux = cab;
		while (contador!=n) {
			aux = aux->getSgte();
			contador++;
		}
		return aux;
	}
}

int listasSimple::valorIndice(int n)
{
	if (dirNodoIndice(n) == NULL) {
		return 0;
	}
	else
	{
		NodoS* nodito= dirNodoIndice(n);
		return nodito->getDato();
	}
}

bool listasSimple::agregarIndice(int agregado, int n)
{
	if (dirNodoIndice(n) == NULL) {
		return false;
	}
	else {
		NodoS* nodito = dirNodoIndice(n);
		agregarAntesDe(agregado, nodito->getDato());
		return true;
	}
}

bool listasSimple::eliminarIndice(int n)
{
	if (dirNodoIndice(n) == NULL) {
		return false;
	}
	else
	{
		NodoS* nodito = dirNodoIndice(n);
		eliminar(nodito->getDato());
		return true;
	}
}

bool listasSimple::eliminar(int x)
{
	bool removido = true;
	NodoS* aux;
	if (!esVacia())

		if (getCab()->getDato() == x) {
			aux = getCab();
			setCab(aux->getSgte());
			delete aux;
			largo--;
			removido = true;

		}
		else {
			NodoS* ant = dirAnterior(x);
			if (ant != NULL) {
				aux = ant->getSgte();
				ant->setSgte(aux->getSgte());
				delete aux;
				largo--;
				removido = true;
			}

		}

	return removido;

}






//listasSimple::dirNodo(int x)
//{
//	NodoS* aux = cab;
//	if (getCab()->getDato() == x) {
//		return aux;
//	}
//	else
//	{
//		while (aux->getSgte()->getSgte()==NULL) {
//			if (aux->getSgte()->getDato() == x)
//			{
//				return aux;
//			}
//			else
//			{
//				aux=
//			}
//		}
//	}
//}

/////bool ListaSimple::agregarAntesDe(int x, int referencia){
//bool agregado = false;
//if (getLargo() != 0) {
//	if (getCab()->getDato() == referencia) {
//		agregarInicio(x);
//		agregado = true;
//	}
//	else {
//		NodoS* ant = cab;
//		while (ant->getSgte() != NULL && !agregado)
//		{
//			if (ant->getSgte()->getDato() == referencia) {
//				NodoS* nuevo = new NodoS(x); //1. Crear nodo
//				nuevo->setSgte(ant->getSgte()); //2. Enlazar nuevo nodo a la lista
//				ant->setSgte(nuevo); //3. Reacomodar lista con nuevo nodo
//				largo++;
//				agregado = true;
//			}
//			else {
//				ant = ant->getSgte();
//			}
//		}
//
//	}
//}
//
//return agregado;

