#include <iostream>
using namespace std;

void intercambio(int* a, int* b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
//esta funcion toma el ultimo elemento como pivote
//coloca los valotes menores a la izquierda
//y los valores mayores a la derecha
int particion(int arr[], int primero, int ultimo){
	int pivote = arr[ultimo]; // pivote
	int i = (primero - 1);//indice del elemento mas pequenio
	
	for(int j = primero; j <= ultimo - 1; j++){
		//si el elemento actual es mas pequenio que el pivote
		if(arr[j] < pivote){
			i++; //se incrementa el indice del elemento mas pequenio
			intercambio(&arr[i], &arr[j]);
		}
	}
	intercambio(&arr[i + 1], &arr[ultimo]);
	return (i + 1);
}

void quickSort(int arr[], int primero, int ultimo){
	if(primero < ultimo){
		int ip = particion (arr, primero, ultimo);//indice de la particion
		//ordenar por separado antes y despues de la particion
		quickSort(arr,primero, ip - 1);
		quickSort(arr, ip + 1, ultimo);
		
	}
}
int main(){
	int n;//Numero de quehaceres
	int k;//Numero de queaceres que se pueden hacer en x tiempo
	int x;//El tiempo
	
	cin >> n >> k >>x;
	
	int ti[n];//Tiempo en hacer cada i-esimo quehacer
	
	int tiempominimo = 0;
	
	for(int i=0; i < n; i++){
		cin >> ti[i];
		
	}
	quickSort(ti,0,n-1);
		
	for(int i=n; i > (n-k-1); i--){
		ti[i] = x;
	}
		
	for(int i=0; i < n; i++){
		tiempominimo = tiempominimo + ti[i];
	}
	
	cout << tiempominimo;
	
	
}
