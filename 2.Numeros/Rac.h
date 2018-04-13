/*RAc (int intnum, int intden) constructor (se llama igual que la clase, pero sin un tipo de retorno)
friend ()
<<operador de insercci�n de flujo
*/
#include <iostream>
using namespace std;
#ifndef Rac_h
#define Rac_h
struct Rac{
	int calc_mcd();
	void set_mcd(int MCD);
	Rac& operator+(Rac& RacObj);
	Rac& operator-(Rac& RacObj);
	Rac& operator*(Rac& RacObj);
	Rac& operator/(Rac& RacObj);
	friend ostream& operator<<(ostream& ostreamOut, Rac& RacObj);//friend indica que es una funci�n amiga de la clase
	//cuando no se coloca el prototipo indica un m�todo y cuando no indica una funci�n amiga
	//la diferencia es que las funciones amigas pueden recibir m�s de un argumento
	//en este caso usamos el flujo ostreamOut para imprimir un racional 
	//cout<<r<<endl; mandamos el racional al flujo cout
	
	//friend ostream& operator<<=(ostream& ostreamOut, Rac& RacObj);
	Rac(const Rac&);
	Rac(int intNum, int intDen);
	Rac();
	void simplificar();
	int n;
	int d;
	int mcd;
};//end struct Rac



#endif 
