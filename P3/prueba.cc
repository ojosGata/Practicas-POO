#include "persona.h"
#include "jugador.h"
#include "apuesta.h"
#include "crupier.h"
#include "ruleta.h"
#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
	list <Jugador> jugadores;
	list <Apuesta> listaDeApuestas;
	Jugador jug1("dni11","cod11");
	jugadores.push_back(jug1);
	Jugador jug2("dni22","cod22");
	jugadores.push_back(jug2);
	Jugador jug3("dni33","cod33");
	jugadores.push_back(jug3);
	Jugador jug4("dni44","cod44");
	jugadores.push_back(jug4);
	Jugador jug5("dni55","cod55");
	jugadores.push_back(jug5);
	Jugador jug6("dni66","cod66");
	jugadores.push_back(jug6);
	Crupier c("dni77","cod77");
	string nomfich=jug1.getDNI()+".txt";
	ofstream salida(nomfich.c_str());
	salida << 1 << "," << "10" << "," << 15<< "\n";
	salida << 2 << "," << "rojo" << "," << 25<< "\n";
	salida << 3 << "," << "par" << "," << 35<< "\n";
	salida << 4 << "," << "bajo" << "," << 45<< "\n";
	salida.close();
	list<Apuesta> l;
	jug1.setApuestas();
	listaDeApuestas=jug1.getApuestas();
	for (list<Apuesta>::iterator iApu = listaDeApuestas.begin(); iApu!=listaDeApuestas.end(); ++iApu){
		cout<<(*iApu).getTipo()<<","<<(*iApu).getValor()<<","<<(*iApu).getCantidad()<<endl;
	}
	jug2.setApuestas();
	for (list<Jugador>::iterator iJug = jugadores.begin(); iJug!=jugadores.end(); ++iJug){
		cout<<(*iJug).getCodigo()<<endl;
	}
	cout<<c.getDNI()<<endl;
	Ruleta r(c);
	r.addJugador(jug1);
	r.addJugador(jug2);
	r.escribeJugadores();
}


