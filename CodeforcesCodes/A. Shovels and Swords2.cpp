#include <iostream>
using namespace std;
/*
	para cada pala se necesitan
	palos		2
	diamantes	1
	para cada espada se necesitan
	palos 		1
	diamantes	2
*/
int main(){
	int testcases;
	int palos,diamantes;
	int esmeraldas[testcases];
	int maxesme;
	cin >> testcases;
	
	
	for(int i=0; i<testcases; i++)	{
		cin >> palos >> diamantes;
		maxesme =  (palos + diamantes)/3;
		
		if (maxesme > palos){
			esmeraldas[i] =  palos;	
		}
		if (maxesme > diamantes){
			esmeraldas[i] = diamantes;
		}
		else{
			esmeraldas[i] = maxesme;
		}	
	}
	cout << endl;
	for(int j=0; j < testcases;j++){
		cout << esmeraldas[j]<< endl;
	}
	
	//return 0;
}
