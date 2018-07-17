#include "persona.h"
#include "jugador.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

void Jugador::setApuestas(){
	
	Apuesta ap;
	string dni,nomFich;
	string tipo, valor, cantidad;
	dni=getDNI();
	nomFich=dni+".txt";
	apuestas_.clear();
	//abrir el fichero
	ifstream fichero;
	fichero.open(nomFich.c_str());
	if (fichero.is_open()){
	//leer una linea del archivo
    while (getline (fichero,tipo,',')){
    	getline(fichero,valor,',');
    	getline(fichero,cantidad,'\n');
    	//guardar cada apuesta en la lista
    	ap.tipo=(atoi(tipo.c_str()));
    	ap.valor=valor;
    	ap.cantidad=(atoi(cantidad.c_str()));
    	apuestas_.push_back(ap);
    }
    //cerrar fichero
    fichero.close();
	}
	else cout << "Unable to open file";

}
