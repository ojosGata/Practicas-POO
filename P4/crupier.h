//crupier.h
#ifndef CRUPIER_H
#define CRUPIER_H
	#include <string>
	#include <iostream>
	#include "persona.h"
	using namespace std;
	/*
		Crupier: Persona que esta pendiente de la ruleta
	
	*/
	class Crupier:public Persona{
		private:
			string codigo_;
		public:  
			
			string getCodigo()const{	return codigo_;}
			void setCodigo(string codigo){	codigo_=codigo;}
			
			Crupier(string DNI,string codigo, string nombre="", string apellidos="", string direccion="", string localidad="", string provincia="", string pais=""):Persona( DNI, nombre, apellidos, direccion, localidad, provincia, pais),codigo_(codigo){};
	};
#endif
