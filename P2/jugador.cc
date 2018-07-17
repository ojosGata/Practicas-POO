#include "persona.h"
#include "jugador.h"
#include "apuesta.h"
#include <iostream>
#include <list>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;
//Método de para Leer un fichero las apuestas de un jugador y la guarda en su lista de apuestas
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
    	ap.setTipo(atoi(tipo.c_str()));
    	ap.setValor(valor);
    	ap.setCantidad(atoi(cantidad.c_str()));
    	apuestas_.push_back(ap);
    }
    //cerrar fichero
    fichero.close();
	}
	else cout << "Unable to open file";
	
	
	
	
	


}
