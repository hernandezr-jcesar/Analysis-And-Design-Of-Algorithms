#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	int a,b,c;
	int cont;
	int contaglobal=0;
	
	cin >> n;
	for(int l=0;l<n;l++){
	a=0;
	b=0;
	c=0;
	
	cont=0;
	
	cin >> a >> b >> c;
		if (a == 1){cont++;	}
		if (b == 1){cont++;	}
		if (c == 1){cont++;	}
		if (cont >= 2){contaglobal++; }

	}
	cout << contaglobal++;
	
	
}

//INPUT 
	//Primera linea cantidad de problemas del concurso desde (entero)(1 <= n <= 100)
	//Despues las otras lineas son solo 3 numeros ya sean 1 o 0
	// 1 cuando la persona este segura de la solucion
	// 0 cuando la persona no esta segura de la solucion
//OUTPUT
	//Cantidad de problemas que el equipo de 3 personas puede resolver
	// esto se calcula si en cada problema al menos 2 personas estan seguras de la solucion
	//Entonces si en la linea existe 1 1 el contador de problemas resueltos sube
	/*	
	EXAMPLES
	input
	3
	1 1 0
	1 1 1
	1 0 0
	output
	2
	
	input
	2
	1 0 0
	0 1 1
	output
	1
	*/
	
	//entrada 
	/*
	se tienen n elementos en l
	numero entero desde 0 hasta 1000
	conteo de votaciones
	si minimo 2 votantes en ese elemento votan que si
	la salida es 
	la cantidad de elementos aprobados 
	
	*/
	
	
	
	
