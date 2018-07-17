#include "persona.h"
#include "jugador.h"
#include "crupier.h"
#include "apuesta.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main(){
	string nombre, apellidos, direccion, localidad, provincia, pais;
	Persona p("11223");
	Jugador j("2222","222xx");
	list <Apuesta> apuestaJugador;
	Apuesta a;
	cout <<"Introduce tu nombre:"<<endl;
	getline(cin, nombre, '\n');
	cout <<"Introduce tus apellidos:"<<endl;
	getline(cin, apellidos, '\n');
	cout <<"Introduce tu Direccion:"<<endl;
	getline(cin, direccion, '\n');
	cout <<"Introduce tu Localidad:"<<endl;
	getline(cin, localidad, '\n');
	cout <<"Introduce tu provincia:"<<endl;
	getline(cin, provincia, '\n');
	cout <<"Introduce tu pais:"<<endl;
	getline(cin, pais, '\n');
	
	j.setNombre(nombre);
	j.setApellidos(apellidos);
	j.setDireccion(direccion);
	j.setLocalidad(localidad);
	j.setProvincia(provincia);
	j.setPais(pais);
	cout<< "Nombre: "				<<j.getNombre()<<endl;
	cout<< "Apellido:  "			<<j.getApellidos()<<endl;
	cout<< "Direccion: "			<< j.getDireccion()<<endl;
	cout<< "Provincia: "			<<j.getProvincia()<<endl;
	cout<< "Localidad: "			<<j.getLocalidad()<<endl;
	cout<< "Pais: "				<<j.getPais()<<endl;
	cout<< "Saldo: "				<<j.getDinero()<<endl;
	cout<< "Codigo Jugador: "	<<j.getCodigo()<<endl;
	cout<< "Dni Jugador: "		<<j.getDNI()<<endl;
	cout<< "Nombre Completo: "	<<j.getApellidosyNombre()<<endl;
	cout<< "\ndni Persona: "	<<p.getDNI()<<endl;
	j.setApuestas();
	apuestaJugador=j.getApuestas();
	for (list<Apuesta>::iterator it = apuestaJugador.begin(); it!=apuestaJugador.end(); ++it){
   	cout << (*it).mostrarApuesta() << "\n";
   }

}


