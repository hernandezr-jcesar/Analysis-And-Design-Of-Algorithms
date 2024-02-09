#include <math.h>
#include <complex>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
//Programa que implementa la transformada de fourier usando la formula. Tambien conocido
// Como DFT (Discret Fourier Transform )

vector<complex<double> > dft(vector<complex<double> > X){
	//Determine number of samples
	int N = X.size();
	int K = N;
	
	//Allocate memory for internals.
	complex<double> intSum;
	
	//Allocate memory for output
	vector<complex<double> > output;
	output.reserve(K);
	
	//Loop through each k
	for(int k=0; k<K; k++){
		//Loop through each n
		intSum = complex<double>(0, 0);
		for(int n=0; n<N; n++){
			double realPart = cos(((2*M_PI)/N) * k * n);
			double imagPart = sin(((2*M_PI)/N) * k * n);
			complex<double> w (realPart, - imagPart);
			intSum += X[n] * w;
		}
		output.push_back(intSum);
	}
	return output;
}

int main(){
	// Create a test signal
	int N = 1000;
	vector<complex<double> > signal;
	signal.reserve(N);
	
	double sigK = 3.0;
	//doouble sigPhase = M_PI / 4.0;
	double sigPhase = 0.0;
	
	for(int x=0; x<N; ++x)
	{
		auto currentSample = complex<double>
			(cos((2*M_PI/static_cast<double>(N)) *
				sigK * static_cast<double>(x) + sigPhase), 0.0);
		signal.push_back(currentSample);
	}
	//Compute the DFT
	vector<complex<double> > Fx = dft(signal);
	
	//Display yhe fist six valeus (real and imaginary components).
	cout << "****" <<endl;
	cout << "First 6 samples of the output..."<< endl;
	cout << "\n" << "k\t" << setw(12)
		<< "Real\t" << setw(12) << "Imag" << endl;
	for(int i=0; i<6; ++i){
		cout << i << "\t"
		<< setw(12) << Fx[i].real() / static_cast<double>(N) << "\t"	
		<< setw(12) << Fx[i].imag() / static_cast<double>(N) << "\t"
		<< endl;
	}
	
	return 0;
	
	 
}
