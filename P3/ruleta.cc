//ruleta.cc
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

#include "ruleta.h"
#include "jugador.h"
#include "crupier.h"

using namespace std;
//Setter Modificadores
bool Ruleta::setBanca (int banca){
	if(banca>0){
		banca_=banca;
		return true;
	}
	return false;
}
bool Ruleta::setBola (int bola){
	if(bola>=0 && bola<=36){
		bola_=bola;
		return true;
	}
	return false;
}

//Metodos
void Ruleta::addJugador(Jugador jug){
	ifstream fichero;
	bool encontrado=false;
	string nomFich =jug.getDNI()+".txt";
	fichero.open(nomFich.c_str());
	if (!fichero.is_open()){
   	//El fichero no existe y se ha creado
   	ofstream fichNuevo;
   	fichNuevo.open(nomFich.c_str());
	}else fichero.close();
	//Exista o no exista el fichero del jugador hay que añadir a la lista.
	for (list<Jugador>::iterator it = jugadores_.begin(); it!=jugadores_.end(); ++it){
   	//Comprobar si el dni del jugador ya esta evitamos jugadores repetidos
   	if(((*it).getDNI())==(jug.getDNI())) encontrado=true;
   }
	if(!encontrado)	jugadores_.push_back(jug);
}

int Ruleta::deleteJugador(string DNI){
	if(jugadores_.empty()){
		return -1;
	}else{
		for (list<Jugador>::iterator it = jugadores_.begin(); it!=jugadores_.end(); ++it){
   		if(it->getDNI()==DNI){
   			jugadores_.erase(it);	
   			return 1;
   		}
   	}
   }
   return -2;
}
//Borra un jugador 
int Ruleta::deleteJugador(Jugador jug){
	string dni=jug.getDNI();
	return deleteJugador(dni);
}
//Guarda la lista jugadores_ , los jugadores que hay en el fichero de texto jugadores.txt
void Ruleta::escribeJugadores(){
	ofstream fichero;	
	fichero.open("jugadores.txt");
	for (list<Jugador>::iterator it = jugadores_.begin(); it!=jugadores_.end(); ++it){
		fichero << it->getDNI() << "," << it->getCodigo() << "," << it->getNombre() << "," << it->getApellidos() << "," << it->getDireccion() << "," << it->getLocalidad() << "," << it->getProvincia() << "," << it->getPais() << "," << it->getDinero() << "\n";
   }
   fichero.close();
}
//Lee del fichero jugadores.txt en la lista jugadores_ de la clase ruleta
void Ruleta::leeJugadores(){
	ifstream fichero;
	string dni, codigo, nombre, apellidos, direccion, localidad, provincia, pais, dinero;
	
	fichero.open("jugadores.txt");
	if (fichero.is_open()){
	//borrar la lista de jugadores;
	jugadores_.clear();
	//leer una linea del archivo
    while (getline (fichero,dni,',')){
    	getline(fichero,codigo,',');
    	getline(fichero,nombre,',');
    	getline(fichero,apellidos,',');
    	getline(fichero,direccion,',');
    	getline(fichero,localidad,',');
    	getline(fichero,provincia,',');
    	getline(fichero,pais,',');
    	getline(fichero,dinero,'\n');
    	//guardar cada jugador en la lista
    	Jugador j(dni, codigo,nombre, direccion, localidad, provincia, pais);
    	j.setDinero(atoi(dinero.c_str()));
    	jugadores_.push_back(j);
    }
    //cerrar fichero
    fichero.close();
	}
}
//Funcion que hace girar la ruleta y saca un numero del 0 al 36
void Ruleta::giraRuleta(){
	int semilla;
	srand(time(NULL));
	semilla = rand();
	setBola(semilla%37);
}
//Funcion que le recoge los premios de cada jugador
void Ruleta::getPremios(){
//Recorrer la lista de jugadores y cargar sus apuestas de los ficheros correspondientes
	for (list<Jugador>::iterator iJug = jugadores_.begin(); iJug!=jugadores_.end(); ++iJug){
		iJug->setApuestas();
		list <Apuesta> la=iJug->getApuestas();
		//Actualiza el dinero de cada jugador con lo que ha ganado o perdido
		//actualiza el dinero de la banca con lo que ha ganado o perdido ambos proceso se hacen a la vez
		for(list<Apuesta>::iterator iApu = la.begin(); iApu != la.end(); ++iApu){
			//compruebo el tipo de apuesta
			
			switch(iApu->tipo){
				//tipo1: compruebo si el valor de la bola es el mismo que el de la apuesta
				//			si son iguales el jugador gana la cantidad*35
				case 1: 
					if(atoi((iApu->valor).c_str())==bola_){
						ganaJugador(*iJug,(iApu->cantidad)*35);
						}else{
						pierdeJugador(*iJug,iApu->cantidad);
					}
					//cout<<"Dinero Apuesta Tipo 1: "<<iJug->getDinero()<<endl;
					break;
				//tipo 2: compruebo de que color es el valor de la bola y compruebo si valor del jugador es igual
				//			 si son iguales el jugador gana la cantidad*1
				case 2: 
					if(bola_==0){
						pierdeJugador(*iJug,iApu->cantidad);
					}else{
						string color=comprobarColor();
						if(color==(iApu->valor)){
							ganaJugador(*iJug,iApu->cantidad);
						}else {
							pierdeJugador(*iJug,iApu->cantidad);
						}
						
					}
					break;
				//tipo 3: compruebo si el valor de la bola es par o impar y compruebo si el valor del jugador es igual
				//			 si son iguales el jugador gana la cantidad*1
				case 3: 
					if(bola_==0){
						pierdeJugador(*iJug,iApu->cantidad);
					}else{
						string esPar=comprobarPar();
						if(esPar==(iApu->valor)){
							ganaJugador(*iJug,iApu->cantidad);
						}else {
							pierdeJugador(*iJug,iApu->cantidad);
						}
					}
					break;
				//tipo 4: compruebo si el valor de la bola es alto o bajo, y comparo con el que tiene el jugador 
				//			 si son iguales el jugador gana la cantidad*1
				case 4:
					if(bola_==0){
						pierdeJugador(*iJug,iApu->cantidad);
					}else{
						string esAlto=comprobarPasa();
						if(esAlto==(iApu->valor)){
							ganaJugador(*iJug,iApu->cantidad);
						}else {
							pierdeJugador(*iJug,iApu->cantidad);
						}
					}
		
					break;
					
				default: cout<<"Error en el tipo de apuesta\n";
			}
		}
	}
}
//Funcion que simula que el jugador ha ganado y pierde la banca
void Ruleta::ganaJugador(Jugador &j, int cant){
	j.setDinero(j.getDinero() + cant);
	setBanca(banca_-cant);	
}
//Funcion que simula que el jugador pierde y gana la banca
void Ruleta::pierdeJugador(Jugador &j,int cant){
	j.setDinero(j.getDinero()-cant);
	setBanca(getBanca()+cant);
	
}

//Comprobaciones del valor de la bola
//1.Comprobar si la bola es par o impar
string Ruleta::comprobarPar(){
	if(bola_==0)
		return "cero";
	if(bola_%2==0)
		return "par";
	else 
		return "impar";
}
//2.Comprobar si la bola es roja o negra
string Ruleta::comprobarColor(){
	switch(bola_){
		case 0: 
			return "cero";
			break;
		case 1:	case 3:	case 5:	case 7:	case 9:	case 12:	case 14:	case 16:	case 18:
		case 19: case 21: case 23: case 25: case 27: case 30: case 32: case 34: case 36:
			return "rojo";
			break;
		default: return "negro";
	}
}
//3.Comprobar si la bola es alta o baja
string Ruleta::comprobarPasa(){
	if(bola_==0) return "cero";
	if(bola_>=1 && bola_<=18) return "bajo";
	return "alto";
}
