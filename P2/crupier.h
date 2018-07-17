//crupier.h
#ifndef CRUPIER_H
#define CRUPIER_H
	#include <string>
	#include <iostream>
	#include "persona.h"
	using namespace std;
	//Clase Crupier
	class Crupier : public Persona{
		private:
			string codigo_;
		public:  
			//Observador
			string getCodigo()const{	return codigo_;}
			//Modificadores
			void setCodigo(string codigo){	codigo_=codigo;}
			//Constructor
			Crupier(string codigo, string DNI, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona(DNI, nombre, apellidos, direccion, localidad, provincia, pais){codigo_=codigo;};
	};
#endif
