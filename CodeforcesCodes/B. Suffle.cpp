#include <iostream>
using namespace std;

int main(){
	
	int t; // test cases
	
	cin >> t;
	
	int n[t], x[t], m[t]; //
	int li[n[t]], ri[n[t]];
	
	int i,j;
	int conta=0;
	for(i=0; i < t;i++){
		cin >> n[i] >> x[i] >> m[i];
		
		for(j=0; j < m[i];j++){
			cin  >> li[conta] >> ri[conta];
			conta++;
			//cout << li[i][j] <<" "<< ri[i][j] <<endl;
		}
		
	}
	cout << endl;
	cout << endl;
	conta =0;
	for(i=0; i < t;i++){
		cout << n[i] << " " << x[i] << " " << m[i] << endl;		
		
		for(j=0; j < m[i];j++){
			cout << li[conta] <<" "<< ri[conta] <<endl;
			conta++;
		}
		
	}

}
