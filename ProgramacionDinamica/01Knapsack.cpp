
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
/*
Ejemplo de entrada al algoritmo:
 5  kg 
 
 3 objetos
 
 8 kg	  $ 199
 2 kg     $ 520 
 1 kg 	  $ 300
 4 kg	  $ 50
 5 kg 	  $ 250
 
 
 input en el programa:
10
5

8 199
2 520
1 300	
4 50
5 250
==> Respuesta correcta:  1070
0 1 1 0 1
7
4
1 1
3 4
4 5
5 7
==> Resp : 9
0 1 1 0
10
3

6 70
7 1
3 3
==> Resp: 73
1 0 1

NOTA ARREGLAR LA SALIDA DE LOS OBJETOS QUE SE TOMAN Y LOS QUE NO
*/
#include <iostream>
using namespace std;
struct objet{
	int indice;
	int valor;
	int peso;
	bool decision;
};
struct memoization{
	int indice;
	int peso;
	int valormaximo;
};
int maximo(int valor1, int valor2){ 
	
	if(valor1 >= valor2){
		return valor1;
	}
	else if(valor1 < valor2){
		return valor2;
	}			
}
int Knapsack(int n,int W,objet O[],memoization memo[]){
	// W = peso maximo de la mochila
	// n  = indice de objetos
	// O[] el objeto
	if (memo[n].indice == n && memo[n].peso == W){
		return memo[n].valormaximo;
		
	}else{
		int valormaximo;   
		int caja1, caja2;
		
		if (n == 0 || W == 0){
			valormaximo = 0;
			
			//O[n].decision = 0;
		}
		else if(O[n].peso > W ){
		
			valormaximo = Knapsack(n-1, W,O,memo);
			
			//O[n].decision = 0;
		}else if(O[n].peso <= W ){
		
			caja1 = Knapsack(n-1, W,O,memo);
		
			caja2 = (O[n].valor + Knapsack(n-1, W - O[n].peso,O,memo));
			
			valormaximo = maximo(caja1,caja2);	
			/*
			if (valormaximo == caja2){
				O[n].decision = 1;
			}*/
		}
		memo[n].valormaximo = valormaximo;
	
		return valormaximo;
	}
}
int main(){
	int cantidad, valor, peso;
	int pesomochila;
	//Entrada del peso de la mochila en kg
	cin >> pesomochila;
	//Entrada de la cantidad de objetos
	cin >> cantidad;
	//Creacion de un struct llamado objeto
	struct objet objeto[cantidad];
	//Llenado de datos de cada objeto
	for(int i=cantidad;i>0;i--){
		//indice del objeto
		objeto[i].indice = i;
		//peso del objeto
		cin >> objeto[i].peso;
		//valor del objeto
		cin >> objeto[i].valor;
		
		objeto[i].decision = 0;
	}
	cout << endl; 
	//un arreglo para guardar los estados unicos
	struct memoization memo[cantidad];
	cout << Knapsack(cantidad, pesomochila, objeto, memo)<<endl;
	/*
	for(int i=1 ; i<cantidad+1; i++){
		cout << i << " ";
	}	
	cout << endl;
	for(int i=cantidad ; i>0; i--){
		cout<< objeto[i].decision << " " ;
	}
	cout << endl;
	*/
	return 0;	
}

