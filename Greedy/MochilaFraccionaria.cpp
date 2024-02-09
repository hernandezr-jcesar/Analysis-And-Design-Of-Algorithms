#include<iostream>
using namespace std;
//Problema de la mochila fraccionaria
/*
Problema:
se desea cargar una mochila de capacidad 5 kg y 700 cm^3
Se desea llevar un valor máximo
Se va a llenar con objetos de diferente valor
Nota: existe una cantidad ilimitada de objetos.
EJ:
				valor			peso
objeto 1:  $ 10 por cm^3   100g por cm^3
objeto 2:  $ 15 por cm^3   200g por cm^3
objeto 3:  $ 5 por cm^3    20g por cm^3
objeto 4:  $ 3 por cm^3    21g por cm^3
INPUT DEL EJEMPLO PARA EL PROGRAMA:


5

4

10 100
15 200
5 20
3 21

*/
void intercambia(float a[], float b[],int conta){
	float temp;
	temp = a[conta];
	a[conta] = b[conta+1];
	b[conta+1] = temp;
}

int main(){
	float pesoTotal=0, valorTotal=0;
	int cantidadObjetoEscojido; 
	float pesomochila;
	float pesomochilafijo;
	//meter valor de peso de la mochila en kg
	cin >> pesomochila;
	pesomochila= pesomochila * 1000;
	
	pesomochilafijo = pesomochila;
	//cantidada de objetos
	int cant;
	cin >> cant;
	float pesoObjetos[cant];
	float valorObjetos[cant];
	float valor_peso_objeto[cant];
	
	for(int i=0; i<cant;i++){
		cin >> pesoObjetos[i];
		cin >> valorObjetos[i];
		//calcular el valor sobre el peso de cada objeto
		valor_peso_objeto[i] = valorObjetos[i] / pesoObjetos[i];
		//cout << valor_peso_objeto[i]<<endl ;
	}
	//Usando burbuja para ordenar los valores/peso de cada objeto 
	for(int i = cant-1; i>0; i--){
		for(int j = 0; j < i; j++){
			if(valor_peso_objeto[j] > valor_peso_objeto[j+1]){
				intercambia(valor_peso_objeto,valor_peso_objeto,j);
				intercambia(pesoObjetos,pesoObjetos,j);
				intercambia(valorObjetos,valorObjetos,j);
			}
		}
		cout <<"valor/peso: "<< valor_peso_objeto[i]<<endl;
		cout <<"valor: "<<valorObjetos[i]<<endl;
		cout <<"peso: "<<pesoObjetos[i]<<endl;
		cout << endl;
	}
	
	//for(int i = cant -1 ; i > 0; i--){
		//acciones para la mochila fraccionaria:
		int i = cant-1;
		float pesoFaltante=0, porcientoObjeto=0;
		float partequecabe=0, pesotomado=0;
		float valortomado=0;
		do{
			
		if(pesoObjetos[i] <= pesomochila){
			pesoTotal = pesoTotal + pesoObjetos[i];
			valorTotal = valorTotal + valorObjetos[i];
			pesomochila = pesomochila - pesoObjetos[i];
		}
		
		if(pesoObjetos[i] > pesomochila){
			pesoFaltante = pesomochila;
			porcientoObjeto = (pesoObjetos[i] * 100)/ pesoFaltante;
			partequecabe = porcientoObjeto/100;
			
			pesotomado = pesoObjetos[i] / partequecabe;
			valortomado = valorObjetos[i] / partequecabe;
			
			pesoTotal = pesoTotal + pesotomado;
			valorTotal = valorTotal + valortomado;
			pesomochila = pesomochila - pesotomado;
			
		}
		cout << "Peso: " << pesoTotal << endl ;
		cout << "Valor: " << valorTotal << endl ;
		cout << endl;
		}while(pesomochila!=0);
		cout << "Valor maximo posible: $"<< valorTotal <<" pesos"<<endl;
		
	//}
}

