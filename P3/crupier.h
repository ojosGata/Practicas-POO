//crupier.h
#ifndef CRUPIER_H
#define CRUPIER_H
	#include <string>
	#include <iostream>
	#include "persona.h"
	using namespace std;
	class Crupier:public Persona{
		private:
			string codigo_;
		public:  
			//Observador: getter
			string getCodigo()const{	return codigo_;}
			//Modificador: setter
			void setCodigo(string codigo){	codigo_=codigo;}
			//Constructor
			Crupier(string DNI,string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona( DNI, nombre, apellidos, direccion, localidad, provincia, pais),codigo_(codigo){};
			
	};
#endif
