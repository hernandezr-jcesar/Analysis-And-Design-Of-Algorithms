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
	
	EJEMPLO VIDEO MIT:
	
	HIEROGLYPHOLOGY
	
	MICHAELANGELO
		
	MICHAELANGELO
	HIEROGLYPHOLOGY
	salida = HELLO
	
	Ejemplo de 4 letras:
	
	SAVI
	{}  Subsecuencia epsilon
	{SAVI} Subsecuencia impropia tomar todo
	{S}  {A}  {V}  {I} Subsecuencias de un elemento
	{SA} {SV} {SI} 
	{AV} {AI}
	{VI} 
	{SAV} {SAI} {SVI} {AVI} 
	
	Total de subsecuencias: 16 
	
	
	Ejemplo de 3 letras
	
	SOL
	
	{}
	{SOL}
	{S} {O} {L}
	{SO} {SL} {OL}
	Total de subsecuencias: 8

	
	EJEMPLO DE 2 LETRAS
	
	NO
	{}
	{NO}
	{N} {O}
	Total de subsecuencias: 4
	
	
	
	
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
	int longitudmaxima;
	int L1;
	int L2;
};
/*
void Dp(string cad1, string cad2, memoization memo[], int limite){
	int largo1 = cad1.length();
	int largo2 = cad2.length();
	
	if (largo1 > largo2){
		for(int i=0; i < largo2; i++ ){
			for(int j=0; j < largo1; j++){
				if (cad2[i] == cad1[j] ){
					//if (verificarmemo(memo, cad1, largo1, i) == 0){
							memo[i].caracter = cad1[j];
							i++;
							//j = 0;
						//}
					//}
				}
				//cout << "hola";
			}
		}
	}
	else if(largo2 > largo1){
		
		for(int i=0; i < largo1; i++ ){
			for(int j=0; j < largo2; j++){
				if (cad1[i] == cad2[j] ){
					//if (verificarmemo(memo, cad1, largo1, i) == 0){
							memo[i].caracter = cad2[j];
							i++;
							//j = 0;
						//}
					//}
				}
				//cout << "hola";
			}
		}
	}

	//memo[0].cadena = "prueba";
	
}
int subsecuencias(int conta, subsecuencia sub[], string cadena, int Pertenece){
		int n = cadena.length();
		int limite = n;
		limite = limite * limite;
		
		
		if (conta == 1){
			//subsecuencia vacia(epsilon)
			sub[conta].indice = conta;
			sub[conta].subsecuencia = "";	
			sub[conta].perteneceAcadena = Pertenece;
		}else if (conta == 0){
			//subsecuencia impropia al tomar todo
			sub[conta].indice = conta;
			sub[conta].subsecuencia = cadena;	
			sub[conta].perteneceAcadena = Pertenece;
			return 0;
		}
		else if (conta > 1) {
			//se agregan cada uno de los digitos de la cadena
				sub[conta].indice = conta;
				sub[conta].subsecuencia = cadena[conta];	
				sub[conta].perteneceAcadena = Pertenece;
		}
		conta = subsecuencias(conta-1, sub, cadena, Pertenece);
			/*
				sub[i].indice = i;
				sub[i].subsecuencia = cadena[i] + cadena[i+1];	
				sub[i].perteneceAcadena = Pertenece;
			
		
		return conta;
	
}
*/
void obtener_subsecuecias(subsecuencia sub[], string cadena, int P){
	int n = cadena.length(); // cantidad de signos en la cadena
	int limite = cadena.length();
	limite = limite * limite;
	//n = n * n;
	//se agregan cada uno de los digitos de la cadena
	for(int i = 0 ; i < limite; i++){
		if (i == 0){
			//subsecuencia vacia(epsilon)
			sub[i].indice = i;
			sub[i].subsecuencia = "";	
			sub[i].perteneceAcadena = P;
		}else if(i == 1){
			//subsecuencia impropia al tomar todo
			sub[i].indice = i;
			sub[i].subsecuencia = cadena;	
			sub[i].perteneceAcadena = P;
		}else if(i > 1 ){
			sub[i].indice = i;
			sub[i].subsecuencia = cadena[i-2];	
			sub[i].perteneceAcadena = P;
		}else if( i > n + 1){
			sub[i].indice = i;
			sub[i].subsecuencia = cadena[i] + cadena[i+1];
			sub[i].perteneceAcadena = P;
		}
		/*else{
			
		}*/
	}
}
int maximo(int valor1, int valor2){ 
	
	if(valor1 >= valor2){
		return valor1;
	}
	else if(valor1 < valor2){
		return valor2;
	}			
}
//LONGEST COMMON SUBSECUENCE
int LCS(string cad1,string cad2, int L1, int L2,string lcs[],int lim, memoization memo[]){
	if(L1 == memo[lim].L1 && L2 == memo[lim].L2 ){
		return memo[lim].longitudmaxima;
	}
	else{
		
		int longitudmaxima;
		int caja1, caja2;
		
		if (L1 == 0 || L2 == 0){
			longitudmaxima = 0;
			//memo[lim].longitudmaxima = longitudmaxima;
			
		}else if(cad1[L1-1] == cad2[L2-1]){
			//lcs[0] =  lcs[0] + cad2[L1-1];
			longitudmaxima = 1 + LCS(cad1, cad2, L1-1, L2-1,lcs, lim-1, memo);
		}else if(cad1[L1-1] != cad2[L2-1]){
			caja1 = LCS(cad1,cad2,L1-1,L2,lcs,lim-1, memo);
			caja2 = LCS(cad1,cad2,L1,L2-1,lcs,lim-1, memo);
			longitudmaxima = maximo(caja1, caja2);
		}
		memo[lim].L1 = L1;
		memo[lim].L2 = L2;
		memo[lim].longitudmaxima = longitudmaxima;
		return longitudmaxima;
	}
}
int main(){
	string cadena1;
	string cadena2;
	
	string lcs[1]; //longest commun subsecuence
	cin >> cadena1 >> cadena2;
	
	int largo1 = cadena1.length();
	int largo2 = cadena2.length();
	int limite = 0;
	/*
	if (largo1 <= largo2){
	limite == largo1;
	}else if(largo2 < largo1){
	limite == largo2;
	}
	*/
	
	struct memoization memo[limite];
	/*
	for(int i=0; i < limite ; i++){
		
		memo[i].indice = i;
		memo[i].longitudmaxima = 0;
		memo[i].L1 = 0;
		memo[i].L2 = 0; 
	}
	*/
	lcs[0] = "";
	cout << LCS(cadena1, cadena2,largo1, largo2,lcs,limite-1, memo) << endl;
	cout << lcs[0];
	/*
	//struct subsecuencia sub1[limite];
	//struct subsecuencia sub2[cadena2.length()];
	
	//cout << cadena1 << "  " << cadena1.length() << endl;
	//cout << cadena2 << "  " << cadena2.length() << endl;
	obtener_subsecuecias(sub1,cadena1,1);
	//subsecuencias(limite, sub1, cadena1, 1);
	*/
	/*
	for(int i = limite-1; i == 0  ; i++){
		cout << memo[i].caracter<<".";
	}
	*/
	
	
	return 0;
} 

