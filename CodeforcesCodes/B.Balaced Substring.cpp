#include <iostream>
#include <string>
using namespace std;
int contarceros(string c){
	int conta=0;
	int largo = c.length();
	for(int i=0; i < largo ; i++){
		if (c[i] == '0'){
			conta++;
		}
	}
	return conta;
}
int contarunos(string c){
	int conta=0;
	int largo = c.length();
	for(int i=0; i < largo; i++){
		if (c[i] == '1'){
			conta++;
		}
	}
	return conta;
}
int BalancedSubstring(string cadena, int n){
	
	string subcadena[n][n];
	int largoscad[n][n];
	int lbs = 0;
	for(int i=0; i<n;i++){
		for(int j=1; j <n; j++){
			subcadena[i][j] = cadena.substr(i,j);
			largoscad[i][j] = subcadena[i][j].length();
			if( (contarceros(subcadena[i][j]) ) == (contarunos(subcadena[i][j])) ){
				if(largoscad[i][j] >= lbs){
					lbs = largoscad[i][j];
						
				}
			
			}
				
		}
			
	}
	return lbs;
}
int main(){
	int n;//El largo de la cadena e 0s y 1s
	
	cin >> n;
	string cadena;
	cin >> cadena;

	cout << BalancedSubstring(cadena,n) << endl;
	
}
