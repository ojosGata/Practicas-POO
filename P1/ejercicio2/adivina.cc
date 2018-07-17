//adivina.cc
//Programa que elige un numero aleatorio de 1 al 10 y el usuario lo adivinara.
#include <iostream>
using namespace std;
#include <cstdlib>
#include <ctime>

int main(){
	int numAleatorio, semilla, numero=0;
	srand(time(NULL));
	semilla = rand();
	numAleatorio=(semilla%10)+1;
	
	while(numero!=numAleatorio){
		cout<<"Elige un numero del 1 al 10\n";
		cin>>numero;
		if(numAleatorio>numero){
			cout<<"Mayor.Elige otro numero. \n";
		}else if (numAleatorio<numero){
			cout<<"Menor.Elige otro numero.\n";
		}
	}
	if(numero==numAleatorio){
		cout<<"Correcto el numero es: "<< numero<<"\n";
	
	}


	return 0;
}
