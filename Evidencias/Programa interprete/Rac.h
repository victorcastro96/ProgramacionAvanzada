/** Rac.h - Una clase para representar n\'umeros racionales.*/
#include <iostream>	
#include <fstream>	
using namespace std;	

#ifndef Rac_h
#define Rac_h

    /** 
     *  Clase para representar n\'umeros racionales
     *  @author Lamberto Maza Casas
     *  @version 2018.02.12
     */
     
//Segeneran los m�todos calcular m�ximo com�n divisor para simplificar el resultado
//se hace una sobrecarga de operadores para el uso de n�meros racionales
struct Rac {
    int calc_mcd(); //Regresa el m�ximo com�n divisor
    void set_mcd(int MCD); 
    
    Rac& operator+(Rac& RacObj); 
    Rac& operator-(Rac& RacObj);
    Rac& operator*(Rac& RacObj);
    Rac& operator/(Rac& RacObj);
    Rac& operator+(int intVal);
    Rac& operator-(int intVal);
    Rac& operator*(int intVal);
    Rac& operator/(int intVal);
    
	friend Rac& operator+(int intVal,Rac& RacObj); //se emplea la funci�n amigo (otorga acceso a miembros privados)
 	friend Rac& operator-(int intVal,Rac& RacObj); //se emplea la funci�n amigo (otorga acceso a miembros privados) 
 	friend Rac& operator*(int intVal,Rac& RacObj); //se emplea la funci�n amigo (otorga acceso a miembros privados)
 	friend Rac& operator/(int intVal,Rac& RacObj); //se emplea la funci�n amigo (otorga acceso a miembros privados)
    friend ostream& operator<<(ostream& ostreamOut, Rac& RacObj); //Sobrecarga del operador de insercci�nd e flujo 
    															//se empleara para la escritura en c�digo latex
//    friend ostream& operator<<=(ostream& ostreamOut,Rac& RacObj);
	
//Sobrecarga de m�todos para la clase Rac
	Rac(const Rac&); 
    Rac(int intNum, int intDen);
    Rac();
    Rac(int){ }
    void simplificar();//Reducci�n de t�rminos
	std::string string_show();
    int n;		/* numerador */
    int d;		/* denominador*/
    int mcd;	/* m\'aximo com\'un divisor*/
};//end struct Rac

#endif // Rac_h
