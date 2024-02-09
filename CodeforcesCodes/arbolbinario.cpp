#include <iostream>
#include <stdio.h>
#include <conio.h>

using namespace std;
struct estructuraNodo{
	int valor;
	struct estructuraNodo *izq;
	struct estructuraNodo *der;	
};

typedef struct estructuraNodo *nodo;

void insertar(int valorInsertar, nodo &raiz){
	if(raiz == NULL){
		nodo nuevo = new (struct estructuraNodo);
		nuevo->valor = valorInsertar;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		raiz = nuevo;
	}else{
		if(valorInsertar < raiz->valor){
			insertar(valorInsertar,raiz->izq);
		}else if(valorInsertar > raiz->valor){
			insertar(valorInsertar,raiz->der);
		}else{
			//numero repetido
		}
	}
}

void preorden(nodo raiz){
	if(raiz != NULL){
		cout<< raiz->valor<<", ";
		preorden(raiz->izq);
		preorden(raiz->der);
	}
}

void inorden(nodo raiz){
	if(raiz != NULL){
		inorden(raiz->izq);
		cout<< raiz->valor<<", ";
		inorden(raiz->der);
	}
}

void postorden(nodo raiz){
	if(raiz != NULL){
		postorden(raiz->izq);
		postorden(raiz->der);
		cout<< raiz->valor<<", ";
	}
}

bool buscar(int valorBuscar, nodo raiz){
	if(raiz != NULL){
		if(valorBuscar == raiz->valor){
			return true;
		}else if(valorBuscar > raiz->valor){
			return buscar(valorBuscar, raiz->der);
		}else if(valorBuscar < raiz->valor){
			return buscar(valorBuscar, raiz->izq);
		}
	}
}
int main(){
	nodo arbol = NULL;
	
	int numeros[] = {35,15,80,10,220,18,17,50,100,70,40};
	int sizeArray = (sizeof(numeros)/sizeof(*numeros));
	for(int i=0;i<sizeArray; i++){
		insertar(numeros[i],arbol);
	}
	
	preorden(arbol);
	cout<<endl;
	inorden(arbol);
	cout<<endl;
	postorden(arbol);
	cout<<endl;
	cout<<endl;
	cout << (buscar(100,arbol) ? "valor encontrado" : "valor no encontrado") <<endl;
	
	getch();
	return 0;	
}
