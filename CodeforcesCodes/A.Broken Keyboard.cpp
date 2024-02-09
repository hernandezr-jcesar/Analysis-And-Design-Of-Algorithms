#include<iostream>
#include<string>
using namespace std;
string res[26];


void cadenaENorden(string cadena){
	int largo = cadena.length();
	string alfabeto="abcdefghijklmnopqrstuvwxyz";
	string temp = " ";
	for(int i=0; i < largo; i++){
		temp[i] = ' ';
	}
	
	int conta=0;
	for(int j=0; j < largo;j++){
		if(cadena[j] != ' '){
			temp[conta] = cadena[j];
			conta++;			
		}
		//cout << cadena<< endl;
	}
	for(int k=0; k<largo;k++){
		//if (temp[k] = )
		
		cout<<temp[k];
	}
	cout<<endl;	
	
}

void res(string cadena){
	
	int largo = cadena.length();
	
	if(largo == 1){
			cout << cadena<< endl;
	}
	else{		
			for(int i = 0; i <largo; i++){			//6
				if(cadena[i] == cadena[i+1]){	// 6 y 5 son iguales	
					cadena[i] = ' ';			//6 se convierte en ' '
					cadena[i+1] = ' ';			//5 se convierte en ' '
					i++;						//i = 5					
				}				
			}
			
			cadenaENorden(cadena);
		}
}
	
	


int main(){
	int t; //test cases
	
	cin >> t;
	
	string cadena[t];
	
	for(int i=0; i<t; i++){
		cin >> cadena[i];		
		
	}
	cout << endl;
	for(int i=0; i<t; i++){
		res(cadena[i]);
	}
	
	return 0;
	
	
}

/*
	A.Broken Keyboard
	
	el teclado tiene 26 teclas 
	cada una para una letra del alfabeto latin
	
	Pueden pasar dos cosas al precionar una tecla
	
	1.-Si la tecla funciona bien:
	el caracter precionado aparece al final de la cadena
	
	2.-Si la tecla no funciona
	2 caracteres aparecenal final de la cadena
	
	INPUT:
	1.- numero de casos
	2.- una cadena por cada caso no mas grande que 500 caracteres
	
	
	OUTPUT:
	para cada caso inprimir la cadena res con los caracteres que 
	si funcionan en orden alfabetico sin separaciones ni repeticiones.
	
	
*/
