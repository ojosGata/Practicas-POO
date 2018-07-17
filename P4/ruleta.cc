//ruleta.cc
#include "ruleta.h"
#include "jugador.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>	
#include <list>

using namespace std;

//setter o modificador
bool Ruleta::setBanca(int banca){
	if(banca<0)
		return false;
	banca_ = banca;
	return true;
}

bool Ruleta::setBola(int bola){
	if(bola<0 || bola>36) 
		return false;
	bola_ = bola;
	return true;
}

//Metodos
/*
	addJugador(jugador)Añade el jugador pasado por parametro a la lista de jugadores de la ruleta
*/
void Ruleta::addJugador(const Jugador &jug){
	ifstream fichero;
	bool encontrado=false;
	string nomFich =jug.getDNI()+".txt";
	fichero.open(nomFich.c_str());
	if (!fichero.is_open()){
   	//El fichero no existe y se ha creado
   	ofstream fichNuevo;
   	fichNuevo.open(nomFich.c_str());
   	fichNuevo.close();
	}else fichero.close();
	//Exista o no exista el fichero del jugador hay que añadir a la lista.
	for (list<Jugador>::iterator it = jugadores_.begin(); it!=jugadores_.end() && !encontrado; ++it){
   	//Comprobar si el dni del jugador ya esta evitamos jugadores repetidos
   	if(it->getDNI()==jug.getDNI()){
   	 encontrado=true;
   	}
   }
	if(!encontrado){
		jugadores_.push_back(jug);
	}
}
/*
	deleteJugador(dni) borra un jugador por el dni
	devuelve:
		-1 si la lista esta vacia
		1 si el jugador ha sido borrado
		-2 si el jugador no ha sido encontrado
*/
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
/*
	deleteJugador(jugador): Funcion que borra un jugador, el parametro pasado es un jugador, y devuelve el valor de la funcion anterior:
		-1 si la lista esta vacia
		1 si el jugador ha sido borrado
		-2 si el jugador no esta en la lista
*/
int Ruleta::deleteJugador(const Jugador &jug){
	string dni=jug.getDNI();
	return deleteJugador(dni);
}
/*
	escribeJugadores: función que escribe en el fichero de texto jugadores.txt los jugadores que hay en la lista de jugadores_. Cada linea del fichero representa a un jugador
*/
void Ruleta::escribeJugadores(){
	ofstream fichero;	
	fichero.open("jugadores.txt");
	for (list<Jugador>::iterator it = jugadores_.begin(); it!=jugadores_.end(); ++it){
		fichero << it->getDNI() << "," << it->getCodigo() << "," << it->getNombre() << "," << it->getApellidos() << "," << it->getDireccion() << "," << it->getLocalidad() << "," << it->getProvincia() << "," << it->getPais() << "," << it->getDinero() << "\n";
   }
   fichero.close();
}
/*
	leeJugadores: funcion que introduce en la lista jugadores, los jugadores que  hay en el fichero jugadores.txt, la lista la crea nueva cada vez que se utiliza esta función	

*/
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
/*
	giraRuleta: Funcion que pone un valor en bola_ que esta comprendido entre 0 y 36
*/
void Ruleta::giraRuleta(){
	int semilla;
	semilla = rand();
	setBola(semilla%37);
	lanzamientos++;
}
/*
	getPremios: Funcion que actualiza los premios obtenidos por cada jugador
	Va recorriendo la lista de jugadores y por cada jugador recorrera sus apuestas y comprobara si el jugador ha ganado o perdido y se actualiza el dinero de dicho jugador y de la banca
*/
void Ruleta::getPremios(){
//Recorrer la lista de jugadores y cargar sus apuestas de los ficheros correspondientes
	for (list<Jugador>::iterator iJug = jugadores_.begin(); iJug!=jugadores_.end(); ++iJug){
		(*iJug).setApuestas();
		list<Apuesta> listaApuestaJ = iJug->getApuestas();
		//Actualiza el dinero de cada jugador con lo que ha ganado o perdido
		//actualiza el dinero de la banca con lo que ha ganado o perdido ambos proceso se hacen a la vez
		for(list<Apuesta>::iterator iApu = listaApuestaJ.begin(); iApu != listaApuestaJ.end(); ++iApu){
			//compruebo el tipo de apuesta
			switch(iApu->tipo){
				//tipo1: compruebo si el valor de la bola es el mismo que el de la apuesta
				//			si son iguales el jugador gana la cantidad*35
				case 1: 
					if(atoi(iApu->valor.c_str())==bola_){
						ganaJugador((*iJug),iApu->cantidad*35);
					}else{
						pierdeJugador((*iJug),iApu->cantidad);
					}
					break;
				//tipo 2: compruebo de que color es el valor de la bola y compruebo si valor del jugador es igual
				//			 si son iguales el jugador gana la cantidad*1
				case 2: 
					if(bola_==0){
						pierdeJugador((*iJug),iApu->cantidad);
					}else{
						string color=comprobarColor();
						if(color==iApu->valor){
							ganaJugador((*iJug),iApu->cantidad);
						}else {
							pierdeJugador((*iJug),iApu->cantidad);
						}
					}
					break;
				//tipo 3: compruebo si el valor de la bola es par o impar y compruebo si el valor del jugador es igual
				//			 si son iguales el jugador gana la cantidad*1
				case 3: 
					if(bola_==0){
						pierdeJugador((*iJug),iApu->cantidad);
					}else{
						string esPar=comprobarPar();
						if(esPar==iApu->valor){
							ganaJugador((*iJug),iApu->cantidad);
						}else {
							pierdeJugador((*iJug),iApu->cantidad);
						}
					}
					break;
				//tipo 4: compruebo si el valor de la bola es alto o bajo, y comparo con el que tiene el jugador 
				//			 si son iguales el jugador gana la cantidad*1
				case 4:
					if(bola_==0){
						pierdeJugador((*iJug),iApu->cantidad);
					}else{
						string esAlto=comprobarPasa();
						if(esAlto==iApu->valor){
							ganaJugador((*iJug),iApu->cantidad);
						}else {
							pierdeJugador((*iJug),iApu->cantidad);
						}
					}
					break;
				default: cout<<"Error en el tipo de apuesta\n";
			}
		}
	}
}
/*
	getEstadoRuleta: Funcion que recibe por parametros por referencia jug, dinero, lanz y ganaBanca
			Dentro de la funcion se calculara los valores de dicho parametros y como estan pasados por
			refencia se cambiará su valor
			jug= calcula los jugadores que hay es ese momento en la ruleta	
			dinero= dinero que tiene actualmente la banca y los jugadores
			lanz= numero de lanzamientos realizado
			ganaBanca= el dinero que lleva la banca ganado hasta el momento
	
*/
void Ruleta::getEstadoRuleta(int &jug, int &dinero, int &lanz, int &ganaBanca){
	//Contar a los jugadores
	jug=jugadores_.size();
	//suma de dinero encima de la mesa(dinero de los jugadores + dinero de la banca
	dinero=0;
	for (list<Jugador>::iterator iJug = jugadores_.begin(); iJug!=jugadores_.end(); ++iJug){
		dinero += iJug->getDinero();
	}
	dinero += getBanca();
	//Numero de lanzamientos
	lanz=getLanzamientos();
	//Calcular el dinero que lleva ganado la banca
	ganaBanca=getBanca()-1000000;
	
}

//Metodos Privados: Son usados solo por la clase

/*
	ganaJugador(jugador y cantidad): Funcion que incrementa la cantidad ganada al jugador y decrementa la cantidad perdida a la banca

*/
void Ruleta::ganaJugador(Jugador &j, int cant){
	j.setDinero(j.getDinero()+ cant);
	setBanca(getBanca()-cant);	
}
/*
	pierdeJugador(jugador y cantidad): Funcion que decrementa la cantidad perdida al jugador e incrementa la cantidad ganada a la banca

*/
void Ruleta::pierdeJugador(Jugador &j,int cant){
	setBanca(getBanca()+cant);
	j.setDinero(j.getDinero()-cant);
}

//Comprobaciones del valor de la bola
//1.Comprobar si la bola es par o impar
/*
	comprobarPar() Funcion que devuelve:
		el string "cero" si la bola_ es el cero
		el string "par" si la bola_ es par
		el string "impar" si la bola_ es impar
		
*/
string Ruleta::comprobarPar(){
	if(bola_==0) return "cero";
	if(bola_%2==0)
		return "par";
	else 
		return "impar";
}
//2.Comprobar si la bola es roja o negra
/*
	comprobarColor() Funcion que devuelve:
		el string "cero" si la bola_ es el cero
		el string "rojo" si la bola_ tiene alguno de estos valores 1, 2, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36
		el string "negro" en cualquier otro caso no indicado en los valores anteriores 
		
*/
string Ruleta::comprobarColor(){
	int vRojos[] ={1,2,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
	bool encontrado=false;
	if(bola_==0) return "cero";
	for(int i=0;i<18 && !encontrado;i++){
		if(bola_==vRojos[i]) encontrado = true;
	}
	if(encontrado) return "rojo";
	return "negro";
}
//3.Comprobar si la bola es alta o baja
/*
	comprobarPasa() Funcion que devuelve:
		el string "cero" si la bola_ es el cero
		el string "bajo" si la bola_ es menor de 18 inclusive
		el string "alto" en cualquier otro caso no especificado en los anteriores
		

*/
string Ruleta::comprobarPasa(){
	if(bola_==0) return "cero";
	if(bola_<=18) return "bajo";
	return "alto";
}



