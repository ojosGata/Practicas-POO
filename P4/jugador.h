//jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H
	#include <string>
	#include <iostream>
	#include <list>
	#include <iostream>
	#include <list>
	#include <cstdlib>
	#include <fstream>
	#include <string>

	#include "persona.h"
	
	using namespace std;
	
	struct Apuesta{
		int tipo;
		string valor;
		int cantidad;
	};
	/*
		Jugador: Persona que juega en la ruleta

	*/
	class Jugador:public Persona{
		private:
			int dinero_;
			string codigo_;
			list <Apuesta> apuestas_;
		public:
			//Constructor
			Jugador(string DNI,string codigo,string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais),codigo_(codigo){dinero_=1000;};

			//getters
			int getDinero()const{return dinero_;}
			string getCodigo()const{return codigo_;}
			
			//setters
			void setDinero(int dinero){dinero_=dinero;}
			void setCodigo(string codigo){codigo_=codigo;}
			
			//Funciones especificas
			list <Apuesta>getApuestas()const{return apuestas_;}
			
			void setApuestas();
	
	};
	

#endif
