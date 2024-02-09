#include <iostream>
using namespace std;

int main(){
	// MIK puede ir arriba o abajo
	//Entrada: la secuencia de movimientos de MIK
	// Que en si es muy larga
	//Tengo que cambiar los cada dos movimientos UR o RU con 
	//un movimiento diagonal D
	
	//Salida: Imprimir el largo de la secuencia de movimientos despues de los 
	//cambios
	
	int n; // largo de la secuencia;
	cin >> n;
	
	char cadena[n];
	
	cin >> cadena;
	
	for(int i=0; i < n;i++){
		if (cadena[i] == 'R' && cadena[i+1] == 'U'){
			cadena[i] = ' ';
			cadena[i+1] = 'D';
			i++;
		} 
		if (cadena[i] == 'U' && cadena[i+1] == 'R'){
			cadena[i] = ' ';
			cadena[i+1] = 'D';
			i++;
		}
	
	}
	int conta=0;
	for(int i=0; i < n; i++){
		if(cadena[i] != ' '){
			conta++;
		}
	}
	cout << endl;
	//cout << cadenaD << endl;
	//cout << cadena << endl;
	cout << conta;
	return 0;
}
