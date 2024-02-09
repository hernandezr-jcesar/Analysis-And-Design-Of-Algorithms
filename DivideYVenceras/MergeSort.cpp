#include<iostream>
using namespace std;
//funcion para mezclar los sub-arreglos izquierdos y derechos del arreglo original
void mezclarDOSarreglos(int izqSA[], int derSA[], int arr[], int n, int m){
	// i es para arreglo izquierdo
	// j es para el arreglo derecho
	// k es para el arreglo original
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	while(i < n && j < m){
		if(izqSA[i] <= derSA[j]){
			arr[k] = izqSA[i];
			i++;
		}else{
			arr[k] = derSA[j];
			j++;
		}
		k++;
	}
	
	//copiar los elementos restantes del arreglo izquierdo[]
	while(i < n){
		arr[k] = izqSA[i];
		i++;
		k++;
	}
	//copiar los elementos restantes del arreglo derecjo[]
	while(j < m){
		arr[k] = derSA[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int tam){
	//caso especial en el que no se necesita ordenar un arrelo
	if(tam == 0){
	return;
	} 
	//si solo existe un elemento en el arreglo no se necesita dividir el arreglo
	if(tam == 1){
	return;
	}
	
	//crear el isqSA[] y el derSA[] y agregar los elementos del arreglo original
	int n = tam / 2; // tamanio arreglo izquierdo
	int m = tam - n; // tamanio arreglo derecho
	
	int izqSA[n];
	int derSA[m];
	
	int k = 0;
	
	for(int i=0; i < n; i++){
		izqSA[i] = arr[k];
		k++;
	}
	for(int j = 0; j < m; j++){
		derSA[j] = arr[k];
		k++;
	}
	
	//llamando a mergeSort para el sub-arreglo izquierdo
	mergeSort(izqSA, n);
	//llamando a mergeSort para el sub-arreglo derecho
	mergeSort(derSA, m);
	
	//mezclar los dos sub-arreglos de regreso a el arreglo original
	mezclarDOSarreglos(izqSA, derSA, arr, n, m);
	return ;
}

int main(){
	int arr[] = {10, 100, 5, 99, 36, 12, 55};
	int tamanio = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, tamanio);
	
	cout << "Arreglo ordenado:"<< endl;
	for(int i=0; i < tamanio; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
