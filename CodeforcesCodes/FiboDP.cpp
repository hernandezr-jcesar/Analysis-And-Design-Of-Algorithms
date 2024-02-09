#include <stdio.h>
#include <iostream>
using namespace std;
/*
Tecnica DP:
		memoization(recordar)
				guardar valores que se usaran despues
*/
//Almacena valores que voy a usar despues
int dp[101];	//Cuantos valores necesito? n = 101
int estaCalculado[101];

int f(int n){
	if(n == 1){
		return 1;
	}
	if(n == 0){
		return 1;
	}
	if (estaCalculado[n] == 1){
		return dp[n];
	}
	
	dp[n]= f(n-1) + f(n-2);
	estaCalculado[n] = 1;
	return dp[n];
}
int main(void){
	int n = 0;
	cin >> n;
	cout << "F(" << n <<") = " << f(n);
}
