// ListasSimples.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "listasSimple.h"

using namespace std;

int main()
{
    cout << "Manejo de listas"<< endl;
    listasSimple* lis; // Creando puntero
    lis = new listasSimple(); //Contruyendo objeto
    cout << "Largo de la lista = " << lis->getLargo() << endl;
    lis->agregarInicio(7);
    lis->desplegar();
    cout << "Largo de la lista = " << lis->getLargo() << endl;
    lis->agregarInicio(15);
    lis->desplegar();
    cout << lis->dirNodo(7)<< endl;
    cout << lis->dirAnterior(7) << endl;
    cout << lis->dirUltimo() << endl;
    lis->agregarDespuesDe(8, 15);
    lis->desplegar();
    lis->agregarFinal(3);
    lis->desplegar();
    
 /*   cout << "Largo de la lista = " << lis->getLargo() << endl;
    lis->agregarInicio(16);
    lis->desplegar();
    cout << "Largo de la lista = " << lis->getLargo() << endl;
    lis->agregarAntesDe(5, 7);
    cout << "Largo de la lista = " << lis->getLargo() << endl;
    lis->desplegar();
    lis->agregarAntesDe(10, 16);
    cout << "Largo de la lista = " << lis->getLargo() << endl;
    lis->desplegar();
    lis->agregarAntesDe(12, 15);
    cout << "Largo de la lista = " << lis->getLargo() << endl;
    lis->desplegar();
    if (lis->agregarAntesDe(99,500))
    {
        lis->desplegar();
    }
    else
    {
        cout << "No se agrego, ";
    }*/

}

