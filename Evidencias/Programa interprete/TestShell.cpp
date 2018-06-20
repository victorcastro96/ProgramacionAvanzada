#include <iostream>
#include <vector>
using namespace std;
#include <stdio.h>
#include <windows.h>	/*STARTUPINFO, PROCESS_INFORMATION*/
#include "Pol_Directory.h"
#include "String_Tokenizer.h"
#include "Polinomio.h"

#define MAXSIZE	1000
int last_backslash(TCHAR*);
void get_substr(TCHAR* cmdL,int intCantidad,char charBuf[MAXSIZE]);
//#define TEST_SHELL
#ifdef TEST_SHELL
int main(){
  TCHAR*              cmdline;
  STARTUPINFO         startup_info;
  PROCESS_INFORMATION process_info;
  char charBuffer[MAXSIZE];
  char exepath[MAXSIZE];
  char str[MAXSIZE];

  cmdline = GetCommandLine();	/*obtiene la orden o comando equivalente de CLI*/
  								/*CLI: Command Line Interface*/
  cout<<cmdline<<endl;
  int intCantidad=last_backslash(cmdline);
  printf("intCantidad=%i\n",intCantidad);
  get_substr(cmdline,intCantidad,charBuffer);
  printf("%s\n",charBuffer);
  char workspace[]="workspace.txt";
  sprintf(exepath,"%s%s",charBuffer,"comando0.exe");
  char dummy[]="dummy";
  sprintf(str,"%s ./%s %s %s %s %s","comando0.exe",
  		  workspace,"var1","+","var2",dummy);
  printf("IMPRIMIR COMANDO A EJECUTAR PASANDO ARGUMENTOS:\n");	
  printf("%s\n",str);
  fill_n( (char*)&process_info, sizeof( PROCESS_INFORMATION ), 0 );
  fill_n( (char*)&startup_info, sizeof( STARTUPINFO ),         0 );
  startup_info.cb = sizeof( STARTUPINFO );
  if (!CreateProcess(
         exepath,
         str,
         NULL,
         NULL,
         TRUE,
         NORMAL_PRIORITY_CLASS,
         NULL,
         NULL,
         &startup_info,
         &process_info
         )){
   	return 2;
  }
  CloseHandle( process_info.hThread );
  // wait for the child program to terminate
  WaitForSingleObject( process_info.hProcess, INFINITE );
  
  //Leer el resultado
  string source_name=string(workspace);
  Pol_Directory the_directory;
  the_directory.load_data(source_name);
  string coeffs0=the_directory.lookup_entry("ans");
  String_Tokenizer tokenizer0(coeffs0,":");
  vector<string> arr0;
  while(tokenizer0.has_more_tokens()){
    arr0.push_back(tokenizer0.next_token());
  }//end while()
  int num,den;	/*numerador,denominador*/
  Rac *RacPt0=new Rac[arr0.size()];
  string stringIntNum,stringIntDen;
  String_Tokenizer tokenizerForRac;
  for(int i=0;i<arr0.size();i++){
	tokenizerForRac=String_Tokenizer(arr0[i],"/");
		
	stringIntNum=tokenizerForRac.next_token();
	num=atoi(stringIntNum.c_str());
		
	stringIntDen=tokenizerForRac.next_token();
	den=atoi(stringIntDen.c_str());
		
	*(RacPt0+i)=Rac(num,den);
  }
  Polinomio PolResult0(arr0.size()-1,RacPt0);
  cout<<PolResult0<<endl;
  cout<<PolResult0.string_show()<<endl;
  
  return 0;
}//end main()
#endif

/**
 * Devuelve la cantidad de car\'acteres que hay que usar de cmdL 
 * para incluir hasta el \'ultimo backslash (es decir, desde el 
 * car\'acter 0 hasta el car\'acter que devuelve esta funci\'on)
 */
int last_backslash(TCHAR* cmdL){
	int r=0,i=0,intI=0;
	while('\0'!=cmdL[i]){
		if('\\'==cmdL[i]){
			r++;
		}
		i++;
	}/*Now r is the amount of backslashes*/
	i=0;
	while((intI<r)&&('\0'!=cmdL[i])){
		if('\\'==cmdL[i]){
			intI++;
		}
		i++;
	}
	return i;
}

void get_substr(TCHAR* cmdL,int intCantidad,char charBuf[MAXSIZE]){
	int i=0;
	while(i<intCantidad){
		charBuf[i]=cmdL[i];
		i++;
	}
	charBuf[i]='\0';
}





