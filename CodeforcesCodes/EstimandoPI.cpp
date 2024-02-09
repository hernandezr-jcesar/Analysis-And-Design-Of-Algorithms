#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

int main(){
	float num_point_circle = 0;
	float num_point_total = 0;
	int range;
	float x, y, distancia;
	cin >> range;
	srand (time(NULL));
	for(int i=0; i <= range;i++){
		x = (rand()%10) /10.0f;
		y = (rand()%10) / 10.0f;
		distancia = x*x + y*y;
	//	cout << distancia<< endl;
		//cout << x << endl << y << endl;
		if (distancia <= 1){num_point_circle++;}
		num_point_total++;
	}
	float resultado=(4*(num_point_circle/num_point_total));
	cout << resultado;
}
