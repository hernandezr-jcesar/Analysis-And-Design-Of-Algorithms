#include<stdio.h>

#include <iostream>
using namespace std;
#include<stdio.h>

int main(){
int n,l=0,i;

	cout << "\n Ingrese el largo de la secuencia:\t";
	cin >> n;
char arr[n],arrf[n];
	
		cin >> arr;	
	

for( i=0;i<n;i++){
	if(arr[i]=='U' &&arr[i+1]=='R'){
		arrf[i]='D';
		i++;
		l++;
	}
	if(arr[i]=='R'&&arr[i+1]=='U'){
		arrf[i]='D';
		i++;l++;
	}else{
		arrf[i]=arr[i];
		l++;
	}
}

cout <<"FINAL " <<arrf << " " <<l;

return 0;
}
