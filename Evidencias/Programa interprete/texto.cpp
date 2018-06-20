#include <iostream>
#include <stdlib.h>  /*malloc()*/
//#include <fstream>  /*ofstream*/
//using std::cout;
//using std::endl;
//using std::string;
//using std::ofstream;

#include "Rac.h"

void respuesta(Rac& ans){
	ofstream archivo;
	archivo.open("ans.txt",ios::out); //Abriendo el archivo (lo crea o lo remplaza)
	if(archivo.fail()){
		cout<<"error";
		exit(1);
	}
	archivo<<"ans"<<endl<<ans.n<<"/"<<ans.d<<endl;
	
	//archivo.Close();
	}

