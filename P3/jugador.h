//jugador.h
#ifndef JUGADOR_H
#define JUGADOR_H
	#include <string>
	#include <list>
	#include "persona.h"
	
	struct Apuesta{
		int tipo;
		string valor;
		int cantidad;
	
	};
	
	using namespace std;
	//Clase jugador que hereda de persona
	class Jugador:public Persona{
		private:
			int dinero_;
			string codigo_;
			list <Apuesta> apuestas_;
		public:
			//Constructor
			Jugador(string DNI,string codigo,string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais),codigo_(codigo){dinero_=1000;};
			//getters-Observador
			int getDinero()const{return dinero_;}
			string getCodigo()const{return codigo_;}
			
			//setters-Modificador
			void setDinero(int dinero){dinero_=dinero;}
			void setCodigo(string codigo){codigo_=codigo;}
			
			//Funciones especificas
			 list <Apuesta>getApuestas()const{return apuestas_;}
			void setApuestas();
	
	};
	

#endif
