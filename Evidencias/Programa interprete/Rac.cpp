#include <cmath>
#include "Rac.h"
#include <stdio.h>
    /** 
     *  Clase para representar n\'umeros racionales
     *  @author Lamberto Maza Casas
     *  @version 2018.02.12
     */

int Rac::calc_mcd()
{
	int M,N,tmp,MCD;
	/*si numerador!=0 y denominador!=0, usar Algoritmo de Euclides*/
	if((n!=0)&&(d!=0)){
		if(n>d){
			M=abs(n);N=abs(d);
		}else{
			M=abs(d);N=abs(n);
		}/* ALGORITMO DE EUCLIDES (300 a.C.) */
		while((tmp=M%N)!=0){ /* M = QN + tmp */
			M=N;
			N=tmp;
		}/*cuando este while termina, en N se tiene el mcd*/
		MCD=N;
	}else{/*si no, hacer mcd=1*/
		MCD=1;/*Para evitar problemas cuando n=0 o d=0*/
	}
    return MCD;
}

void Rac::set_mcd(int MCD)
{
    mcd=MCD;
}

Rac& Rac::operator+(Rac& RacObj)
{
	Rac RacR;
	Rac& RacResult=RacR;
	RacResult.n=n*RacObj.d+d*RacObj.n;
	RacResult.d=d*RacObj.d;
	RacResult.set_mcd(RacResult.calc_mcd());
	RacResult.simplificar();
//	cout<<RacResult.n<<"/"<<RacResult.d<<endl;
	return RacResult;
}

Rac& Rac::operator-(Rac& RacObj)
{
	Rac RacR;
	Rac& RacResult=RacR;
	RacResult.n=n*RacObj.d-d*RacObj.n;
	RacResult.d=d*RacObj.d;
	RacResult.set_mcd(calc_mcd());
	RacResult.simplificar();
	return RacResult;
}

Rac& Rac::operator*(Rac& RacObj)
{
	Rac RacR;
	Rac& RacResult=RacR;
	RacResult.n=n*RacObj.n;
	RacResult.d=d*RacObj.d;
	RacResult.set_mcd(calc_mcd());
	RacResult.simplificar();
	return RacResult;
}

Rac& Rac::operator/(Rac& RacObj)
{
	Rac RacR;
	Rac& RacResult=RacR;
	RacResult.n=n*RacObj.d;
	RacResult.d=d*RacObj.n;
	RacResult.set_mcd(calc_mcd());
	RacResult.simplificar();
	return RacResult;
}

ostream& operator<<(ostream& ostreamOut, Rac& RacObj)
{
	ostreamOut<<"\\frac{"<<RacObj.n<<"}{"\
//	ostreamOut<<RacObj.d<<"}"<<endl;
		      <<RacObj.d<<"}"<<endl;
	return ostreamOut;
}

Rac::Rac(int intNum, int intDen):n(intNum),d(intDen)
{
	set_mcd(calc_mcd());
}

Rac::Rac():mcd(1) /*para evitar divisi\'on entre cero si se llama a simplificar*/
{
}

void Rac::simplificar()
{
	n=n/mcd;
	d=d/mcd;    
}

//ostream& operator<<=(ostream& ostreamOut,Rac& RacObj){
//	Rac R1=RacObj;
//	ostreamOut<<R1;
//	return ostreamOut;
//}
Rac::Rac(const Rac& R):n(R.n),d(R.d)
{
//	n=R.n;
//	d=R.d;
	mcd=calc_mcd();
}

Rac& Rac::operator+(int intVal)
{
	Rac op(intVal,1),R;
	R=*this+op;
	Rac& r=R;
	return r;
}

Rac& Rac::operator-(int intVal)
{
	Rac op(intVal,1),R;
	R=*this-op;
	Rac& r=R;
	return r;
}

Rac& Rac::operator*(int intVal)
{
	Rac op(intVal,1),R;
	R=*this*op;
	Rac& r=R;
	return r;
}

Rac& Rac::operator/(int intVal)
{
	Rac op(intVal,1),R;
	R=*this/op;
	Rac& r=R;
	return r;
}

Rac& operator+(int intVal,Rac& RacObj)
{
	Rac op(intVal,1),R;
	R=op+RacObj;
	Rac& r=R;
	return r;
}

Rac& operator-(int intVal,Rac& RacObj)
{
	Rac op(intVal,1),R;
	R=op-RacObj;
	Rac& r=R;
	return r;
}

Rac& operator*(int intVal,Rac& RacObj)
{
	Rac op(intVal,1),R;
	R=op*RacObj;
	Rac& r=R;
	return r;
}

Rac& operator/(int intVal,Rac& RacObj)
{
	Rac op(intVal,1),R;
	R=op/RacObj;
	Rac& r=R;
	return r;
}

std::string Rac::string_show(){
//	string& result;
	char str[128];
	sprintf(str,"%d/%d",n,d);
	string Result=string(str);
//	string& result=Result;
	return Result; 
}



