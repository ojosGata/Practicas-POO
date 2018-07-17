//juego.cc
//Prueba de la case dados
#include <iostream>
using namespace std;

#include "dados.h"


int main(void){
	Dados d;
	cout<<"programa de prueba\n";
	
	cout<<"el valor inicial del dado 1 = "<<d.getDado1()<<"\n";
	cout<<"el valor inicial del dado 2 = "<<d.getDado2()<<"\n";
	d.lanzamiento();
	cout<<"el valor del dado 1 = "<<d.getDado1()<<"\n";
	cout<<"el valor del dado 2 = "<<d.getDado2()<<"\n";
	cout<<"la suma de los dados es: "<< d.suma()<<"\n"	;
	d.setDado1(7);
	cout<<"el valor del dado 1 = "<<d.getDado1()<<"\n";
	//d._d1=5;//No se puede usar indica que es privado
	//Comprobar el numero de lanzamientos:
	for(int i=0;i<100;i++){
		d.lanzamiento();	
	}
	cout<<"El numero de lanzamientos del dado1 es ="<<d.getLanzamientos1()<<endl;
	cout<<"El numero de lanzamientos del dado2 es ="<<d.getLanzamientos2()<<endl;	
	
}
