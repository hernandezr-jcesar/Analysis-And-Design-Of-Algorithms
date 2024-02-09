#include <iostream>

using namespace std;

int main(){
	const int P_MAX = 220;
	const int N_MAX = 11;
	int P; //	Niños que viven en el orfanato
	int N; //	Cantidad de bolsas de dulces recibidas
	int cant; // Cantidad de dulces que hay en las bolsas
	int cont=0;
	int totdul=0;
	int dulrepart;
	int sobrantes;
		cin >> P >> N ;
	do{	
		cant=0;
		cin >> cant;
		
		totdul = totdul + cant;
		cont++;
	}while(cont!= N);
		
	dulrepart = totdul/P;	
	sobrantes = totdul%P;	
	
	cout << dulrepart << " " << sobrantes;
		
		
		return 0;
}
