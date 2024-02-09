/*
Problema: 
	Longest Common Subsequence(subsecuencia más larga)
	(LCS)
	
	Problema Clasico de DP
	
	Problema:
	Entrada: dos cadenas de símbolos
	Salida: la longitud de la subsecuencia común más larga
	
	DATOS IMPORTATES A TOMAR EN CUENTA:
	Solo se pueden tomar valores en orden si no tomaste un valor no se
	puede cambiar de opinion
	ejemplo no puede ser 
	hola
	{olah} Incorrecto
	
	Ejemplo de entrada:
	
	aksdhflkeruyasd
	asjdhlkasdhfhss
	
	Salida 9
	
	EJEMPLO VIDEO MIT:
	
	MICHAELANGELO
	HIEROGLYPHOLOGY
	
	salida = 5
		
*/

/*
	Preguntas a responder:
	1. ¿Cuántas subsecuencias tiene A?
	Con los ejemplos anteriores supongo que tiene n^2 subsecuencias  siendo n 
	la longitud de la cadena A
	
	2. Propón un algoritmo por fuerza bruta. (¿Qué complejidad tiene?)
	3. ¿Tiene la propiedad de subestructura óptima? ¿Por qué?
	4. ¿Tiene problemas traslapados? SI ¿Por qué?
	porque las subsecuencias se pueden repetir en la primera cadena y en la segunda tambien
	por lo que tendriamos que guardar las que ya tenemos en una memo y verificar cada vez si ya se tiene guardada
	 
	5. Propón un modelo recursivo de solucion.
	6. Calcular complejidad. ¿Cuántos estados tiene? ¿Cuánto cuesta calcular cada estado?
	7. Implementar (Recursiva + memoization)
*/

#include <string> 
#include <iostream>
using namespace std;
struct subsecuencia{
	int indice;
	string subsecuencia;
	int perteneceAcadena;
};

struct memoization{
	int indice;
	int L1;//largo
	int L2;
	int longitudmaxima;
	
};
int maximo(int, int);
int lcs(string,string, int , int ,memoization memo[100][100]);


int main(){
	string cadena1;
	string cadena2;
	
	cin >> cadena1 >> cadena2;
	
	int largo1 = cadena1.length();
	int largo2 = cadena2.length();

	struct memoization memo[100][100];
	cout<< lcs(cadena1, cadena2,largo1, largo2,memo) << endl;
	return 0;
}

int maximo(int valor1, int valor2){ 
	
	if(valor1 >= valor2){
		return valor1;
	}
	else if(valor1 < valor2){
		return valor2;
	}			
}
int lcs(string cad1,string cad2, int i, int j,memoization memo[100][100]){
	
	if(i == memo[i][j].L1 && j == memo[i][j].L2){
		return memo[i][j].longitudmaxima;
	}
	else{
		
		int longitudmaxima;
		int caja1, caja2;
		
		if (i == 0 || j == 0){
			longitudmaxima = 0;
			
		}else if(cad1[i-1] == cad2[j-1]){
			longitudmaxima = 1 + lcs(cad1, cad2, i-1, j-1, memo);
		}else if(cad1[i-1] != cad2[j-1]){
			caja1 = lcs(cad1,cad2,i-1,j,memo);
			caja2 = lcs(cad1,cad2,i,j-1,memo);
			longitudmaxima = maximo(caja1, caja2);
		}
		memo[i][j].L1 = i;
		memo[i][j].L2 = j;
		memo[i][j].longitudmaxima = longitudmaxima;
		return longitudmaxima;
	}
}


