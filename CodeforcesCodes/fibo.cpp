#include <stdio.h>
#include <iostream>
using namespace std;

int f (int n){
	if(n == 1){
		return 1;
	}
	if (n == 0){
		return 1;
	}
	return f(n-1) + f(n-2);
}
int main(void){
	int n = 0;
	cin >> n;
	cout << "F(" << n <<") = " << f(n);

}
