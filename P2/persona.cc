#include "persona.h"
//Constructor de la clase Persona
Persona::Persona(string DNI, string nombre,string apellidos,string direccion,string localidad,string provincia,string pais){
	DNI_=DNI;
	nombre_=nombre;
	apellidos_=apellidos;
	direccion_=direccion;
	localidad_=localidad;
	provincia_=provincia;
	pais_=pais;
	
}
// Concatenación de apellidos y nombre de una persona
string Persona::getApellidosyNombre(){	
	return (getApellidos()+", "+getNombre());
}

