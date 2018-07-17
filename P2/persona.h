//persona.h
#ifndef PERSONA_H
#define PERSONA_H
	#include <string>
	#include <iostream>
	using namespace std;
	class Persona{
		private:
			string DNI_;
			string nombre_;
			string apellidos_;
			string direccion_;
			string localidad_;
			string provincia_;
			string pais_;
		public:
			//getter y setter
			//Observadores
			string getDNI()const { return DNI_;  }
			string getNombre()const {	return nombre_;}
			string getApellidos()const{	return apellidos_;}
			string getDireccion()const{	return direccion_;}
			string getLocalidad()const {	return localidad_;}
			string getProvincia()const {	return provincia_;}
			string getPais()const {	return pais_;}
			//Modificadores
			void setDNI(string DNI){ DNI_=DNI;  }
			void setNombre(string nombre){	nombre_=nombre;}
			void setApellidos(string apellidos){	apellidos_=apellidos;}
			void setDireccion(string direccion){	direccion_=direccion;}
			void setLocalidad(string localidad){	localidad_=localidad;}
			void setProvincia(string provincia){	provincia_=provincia;}
			void setPais(string pais){	pais_=pais;}
			
			//constructor
			
			Persona(string DNI, string nombre="",string apellidos="",string direccion="",string localidad="",string provincia="",string pais="");
			
			//Metodos
			string getApellidosyNombre();
	
	};
	
	


#endif
