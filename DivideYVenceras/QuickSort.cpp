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
int main (){
	int arr[] ={10, 100, 5, 99, 36, 12, 55};
	int tamanio = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0 , tamanio-1);
	cout << "Arreglo ordenado:" << endl;
	for(int i= 0; i < tamanio; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}
