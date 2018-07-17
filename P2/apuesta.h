//apuesta.h
#ifndef APUESTA_H
#define APUESTA_H
	#include <string>
	#include <iostream>
	#include <sstream>
	using namespace std;
	//Clase Apuesta, a partir de la practica3 se declaro como una estructura (struct)
	class Apuesta{
		private: // atributos privados de la clase
			int tipo_;
			string valor_;
			int cantidad_;
		public:
			//Observadores o getters declarados inline
			int getTipo()const{return tipo_;}
			string getValor()const{return valor_;}
			int getCantidad()const{return cantidad_;}
			//Modificadores o setters declarados inline
			void setTipo(int tipo){tipo_=tipo;}
			void setValor(string valor){valor_=valor;}
			void setCantidad(int cantidad){cantidad_=cantidad;}
			//Funcions que muestra una apuesta tb declara inline
			string mostrarApuesta(){
				ostringstream cad;
				cad<<"Apuesta: " <<(tipo_) <<", "<<valor_ <<", " <<(cantidad_) <<"\n";
				return cad.str();
			}

			
	};
#endif
