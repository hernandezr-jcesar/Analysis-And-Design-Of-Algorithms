//Calcular el n esimo Coeficiente del j-esimo renglon 
//termino de un binomio cuadrado perfecto el cual 
// Se puede calcular de forma visual con Triangulo de Pascal

//Por fuerza bruta
#include<iostream>
#include<stdio.h>
using namespace std;

int Coeficiente[100][100];
	//FUERZA BRUTA
int Triangulo(int n){
	//Triangulo[j][k]=1;
	Coeficiente [0][0]= 1;
	Coeficiente [1][0]= 1;
	Coeficiente [1][1]= 1;
	
	for(int j=2; j <= n; j++){
		for(int k=0; k <= j; k++){
			Coeficiente[j][0] = 1;
			if(k==n){
				Coeficiente[j][k] = 1;
			}
			else{
				Coeficiente[j][k] = (Coeficiente[j-1][k-1] + Coeficiente[j-1][k]);
			}	
			//cout << Coeficiente[j][k]<< " ";
		}
		//cout << endl;
	}
	
}
void imprimir(int n){
	cout << endl;
	for (int j=0; j	<= n; j++){
		for (int k=0; k <= j	; k++){
			cout << Coeficiente[j][k]<< " ";
		}	
		cout << endl;
	}
	
	
}
void buscar(int n, int i){
	if(i <= 0){
		cout << "no existe ese termino";
	}
	i=i-1;
	if(i > n ){
		cout << "no existe ese termino";
	}
	
	else{
		cout << Coeficiente[n][i];	
	}
	
	
}
int main(){
	//i => i-esimo estado
	//n => n-esimo renglon del triangulo
	int n;
	int i;
	cout << "Cual es el termino que busca:"<< endl;
	cout << "Valor de la exponencial del binomio:";
	cin >> n ;
	cout << "Numero del termino: ";
	cin >> i;
	Triangulo(n);
	//imprimir(n);
	buscar(n,i);
	return 0;
}
