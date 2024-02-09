#include <iostream>
using namespace std;
//knapsack problem
//mochila entera
// n objetos 
// p precio del objeto
// w peso del objeto 
// V valor maximo
// W peso maximo de la mochila

// solo se tienen 2 opciones 
// lo tomas o no lo tomas
// salida: maximo valor que se puede obtener
struct objet{
	int numero;
	int precio;
	int peso;
};

int valormaximo(int n, int W,objet objeto[]){ 
	//int W; //  peso maximo de la mochila
	int V[n][W]; // valor maximo posible
	for(int i=0;i==n;i++){
		
		if( W < objeto[i].peso){
		//V[n-1][w];
		//V[n-1][w-wi];
			return 0;
			
		}
		else{
			
		}	
	
	}
	
	
}
int main(){
	int numero, precio, peso;
	int PesoMax;
	cin >> PesoMax;
	
	cin >> numero;
	struct objet objeto[numero];
	
	for(int i=0;i==numero;i++){
	objeto[i].numero = i;
	cin >> objeto[i].peso;
	cin >> objeto[i].precio;
	}

	valormaximo(numero,PesoMax, objeto);

	return 0;	
}

