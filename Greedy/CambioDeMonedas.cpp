#include <iostream>
using namespace std;
/*
El problema del cambio
es dar cambio de x cantidad de dinera
Con la menor cantidad de monedas posibles
entre las cuales las denominciones son:
$ 1  
$ 2  
$ 5 
$ 10
Pesos
El programa se debe de realizar para cualquier denominacion
EJEMPLO DE INPUT DE LA CLASE
1 2 5 10
123 
*/
int main(){
	//Tomando en cuenta m1 < m2 < m3 < m4
	int canti;
	int m1=0,m2=0,m3=0,m4=0;
	int cantm1=0, cantm2=0, cantm3=0, cantm4=0;
	int total=0;
	int sobrante;
	cin >> m1 >> m2 >> m3 >> m4; 
	cin >> canti;
	
	cantm4 = canti / m4;
	sobrante = canti % m4;
	
	cantm3 = sobrante / m3;
	sobrante = sobrante % m3;
	
	cantm2 = sobrante / m2;
	sobrante = sobrante % m2;
	
	cantm1 = sobrante;
	
	total = cantm1 + cantm2 + cantm3 + cantm4;
	
	cout << endl;
	cout << cantm4 << " x $"<< m4 << endl;
	cout << cantm3 << " x $"<< m3 << endl;
	cout << cantm2 << " x $"<< m2 << endl;
	cout << cantm1 << " x $"<< m1 << endl;
	cout << "Total de monedas:" << total << endl;
	
}
