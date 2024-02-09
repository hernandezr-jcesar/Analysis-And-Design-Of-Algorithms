#include <iostream>
using namespace std;	

int largo;	
char cadena[111];

bool verificarcadena(char *cadena, char *subcad, int sublargo){
	for(int i = 1;i <= sublargo; ++i ){  			//O(n)
		if(cadena[i] != subcad[i]){					//O(n)
			return 0 ;								//O(n)
		}
	}
	return 1;										//O(1)
		
}

int main(){
	cin >> largo >> cadena+1;						//O(1)
	for(int i=largo/2; i ; --i){					//O(n)	
		if(verificarcadena(cadena, cadena+i, i)){	//O(n)  //O(n^2)
			cout << largo-i+1; 						//O(n)
			return 0;								//O(n)
		}		
	}
	
	cout << largo;									//O(1)
	return 0;										//O(1)
}
/*
Complejidad total del algoritmo:  O(n)

CORREXION la complejidad del algoritmo es O(n^2)
porque manda llamar a una funcion que si es O(n) dentro
de un for por lo que se puede repetir hasta n veces adentro del for.
*/

/*
	Correxion del paradigma usado en el algoritmo
	es por divide y venceras 
	
	
*/

  
