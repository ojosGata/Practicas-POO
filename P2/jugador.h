//jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H
	#include <string>
	#include <iostream>
	#include <list>
	#include "persona.h"
	#include "apuesta.h"
	using namespace std;
	class Jugador:public Persona{
		private:
			int dinero_;
			string codigo_;
			list <Apuesta> apuestas_;
		public:
			//Constructor
			Jugador(string codigo, string DNI, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais="",int dinero=1000):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais){codigo_=codigo; dinero_=dinero;}

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
