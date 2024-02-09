//Mejor conocido como 
//Strassen's algorithm for matrix multiplication
//La multiplicacion de matrices se realiza de renglon por columna
/*
	[A11] [A12]    	[B11] [B12]		[C11][C12]
	[A21] [A22]  *  [B21] [B22]	 =	[C21][C22]		O(n^3)
		A				 B				C
	C11= A11*B11 + A12*B21
	C12= A11*B12 + A12*B22
	C21= A21*B11 + A22*B21
	C22= A21*B12 + A22*B22
----------------------------------------------------------------------
STRASSEN'S ALGORITHM

P1= A11*B12 - A11*B22
P2= A11*B22 + A12*B22
P3= A21*B11 + A22*B11
P4= A22*B21 - A22*B11
P5= A11*B11 + A11*B22 + A22*B11 + A22*B22
P6= A12*B21 + A12*B22 - A22*B21 - A22*B22
P7= A11*B11 + A11*B12 - A21*B11 - A21*B12


C11= P5 + P4 - P2 + P6
C12= P1 + P2
C21= P3 + P4
C22= P5 + P1 - P3 - P7

Input de ejemplo segun el cormen 4.2-1 pg.82
2

1 3  
7 5  

6 8
4 2

18 14
62 66 


*/

//Este programa solo funcionara para matrices de 2 por 2
#include<iostream>
#include<math.h>
using namespace std;

void strassen(int A[][2], int B[][2], int C[][2],int n){
	if (n == 2){
		int P1,P2,P3,P4,P5,P6,P7;
		//P1= A 1  1  * B 1  2   -  A 1  1  * B 2  2
		P1 = (A[0][0] * B[0][1]) - (A[0][0] * B[1][1]);
		//P2= A 1  1  * B 2  2   +  A 1  2  * B 2  2
		P2 = (A[0][0] * B[1][1]) + (A[0][1] * B[1][1]);
		//P3= A 2  1  * B 1  1   +  A 2  2  * B 1  1
		P3 = (A[1][0] * B[0][0]) + (A[1][1] * B[0][0]);
		//P4= A 2 2   * B 2  1   -  A 2  2  * B 1  1
		P4 = (A[1][1] * B[1][0]) - (A[1][1] * B[0][0]);
		//P5= A 1  1  * B 1  1   +  A 1  1  * B 2  2   +  A 2  2  * B 1  1   +  A 2  2  * B 2  2
		P5 = (A[0][0] * B[0][0]) + (A[0][0] * B[1][1]) + (A[1][1] * B[0][0]) + (A[1][1] * B[1][1]);
		//P6= A 1  2  * B 2  1   +  A 1  2  * B 2  2   -  A 2  2  * B 2  1   -  A 2  2  * B 2  2
		P6 = (A[0][1] * B[1][0]) + (A[0][1] * B[1][1]) - (A[1][1] * B[1][0]) - (A[1][1] * B[1][1]);
		//P7= A 1  1  * B 1  1   +  A 1  1  * B 1  2   -  A 2  1  * B 1  1   -  A 2  1  * B 1  2
		P7 = (A[0][0] * B[0][0]) + (A[0][0] * B[0][1]) - (A[1][0] * B[0][0]) - (A[1][0] * B[0][1]);
				
		//C11= P5 + P4 - P2 + P6
		C[n-2][n-2] = P5 + P4 - P2 + P6;
		//C12= P1 + P2
		C[n-2][n-1] = P1 + P2;
		//C21= P3 + P4
		C[n-1][n-2] = P3 + P4;
		//C22= P5 + P1 - P3 - P7
		C[n-1][n-1] = P5 + P1 - P3 - P7;
	}
	
}

void ImprimirMatriz(int X[][2],int n){
	cout << endl;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout << X[i][j]<<" ";
		}
		cout << "\n";
	}
}
void LlenarMatriz(int X[][2],int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> X[i][j];
		}
	}
}
bool esPotenciaDe2(int n){
	//Regrasa 1 si es potencia de 2 
	float num;
	num = n;
	while(num>=2){
		num= num / 2;
	}
	if (num != 1){
		return 0;
	}
	else if (num == 1){
		return 1;
	}
}


int main(){
	// n = Numero de filas. Como debe de ser una matriz cuadrada, 
	//el numero de columnas debe de ser el mismo
	int n;  
	bool verifica;
	do{
		cin >> n;
		verifica = esPotenciaDe2(n);
		if(verifica != 1  || n>4){
		cout << "El valor debe de ser una potencia de 2\n";
		cout << "Con un valor valido entre:\n 1-4\n";
		n = 0;
		}
		
	}while(n>4 || verifica != 1);
	int i, j;
	int A[2][2];
	int B[2][2];
	int C[2][2];
	
	LlenarMatriz(A,n);
	LlenarMatriz(B,n);
	
	for(i=0; i<n ; i++){
		for(j=0; j<n; j++){
			C[i][j]=0;
		}
	}
	if (n == 1){
		C[0][0] = A[0][0] * B[0][0];
	}else{
		strassen(A,B,C,n);
	}
	//ImprimirMatriz(A,n);
	
	//ImprimirMatriz(B,n);
		
	ImprimirMatriz(C,n);
	
}


