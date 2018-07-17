//ruleta.h
#ifndef RULETA_H
#define RULETA_H
	#include "persona.h"
	#include "jugador.h"
	#include "crupier.h"
	#include <list>
	#include <string>
	#include <ctime>
	using namespace std;
	class Ruleta{
		private:
			int banca_;
			int bola_;
			Crupier crupier_;
			list <Jugador> jugadores_;
			
			//metodos privados
			void ganaJugador(Jugador &j, int cant);
			void pierdeJugador(Jugador &j, int cant);
			string comprobarPar();
			string comprobarColor();
			string comprobarPasa();
			
		public:
			//Constructor
			Ruleta(Crupier c):crupier_(c.getDNI(),c.getCodigo()){bola_=-1; banca_=1000000;}

			//getter u observador
			int getBanca()	const{	return banca_;}
			int getBola() const{	return bola_;}	
			Crupier getCrupier()const{	return crupier_;}
			list <Jugador> getJugadores()const{	return jugadores_;}
			
			
			//setter o modificador
			bool setBanca (int banca);
			bool setBola (int bola);
			void setCrupier(Crupier cru){	crupier_=cru;}
			
			//Metodos 
			void addJugador(Jugador jug);
			int deleteJugador(string DNI);
			int deleteJugador(Jugador jug);
			void escribeJugadores();
			void leeJugadores();
			void giraRuleta();
			void getPremios();
			
			
	};


#endif
