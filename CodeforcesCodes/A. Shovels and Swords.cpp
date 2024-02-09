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

	int maxesme;
	
	cin >> testcases;
	int esmeraldas[testcases];
	
	for(int i=0; i<testcases; i++)	{		//O(n)
		cin >> palos >> diamantes;			//O(n)
		maxesme =  (palos + diamantes)/3;	//O(n)
				
		if (maxesme > palos){				//O(n)
			esmeraldas[i] =  palos;			//O(n)
		}
		else if (maxesme > diamantes){		//O(n)
			esmeraldas[i] = diamantes;		//O(n)
		}
		else{
			esmeraldas[i] = maxesme;		//O(n)
		}	
	}
	
	cout << endl;							//O(1)
	for(int j=0; j < testcases;j++){		//O(n)
		cout << esmeraldas[j]<< endl;		//O(n)
	}
	
	return 0;
}
/*
Complejidad total del algoritmo:  O(n)
*/


