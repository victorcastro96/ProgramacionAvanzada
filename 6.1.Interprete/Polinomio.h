#include <iostream>		/* cout, ostream*/
//#include <stdlib.h>	/* malloc() */
using namespace std;
#include "Rac.h"

#ifndef Polinomio_h
#define Polinomio_h
//si a>b entonces devuelve a sino devuelve b
#define maximo(a,b)	((a>b)?a:b) //operaci�n del operador ternario

struct Polinomio {

    Polinomio& operator+(Polinomio& PolObj);

    Polinomio& operator-(Polinomio& PolObj);

    Polinomio& operator*(Polinomio& PolObj);

//    FcnDTrans& operator/(Polinomio& PolObj);

    friend ostream& operator<<(ostream& ostreamObj, Polinomio& PolObj);

    Polinomio(int intGrado, Rac * RacPt);
    Polinomio(){ }
    Polinomio(int){ }

    int grado;
    Rac * A;
};//end struct Polinomio

#endif // Polinomio_h
//macro: especificaci�n de estandares, 
