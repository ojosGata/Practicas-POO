//ruleta.h
#ifndef RULETA_H
#define RULETA_H
	#include "persona.h"
	#include "jugador.h"
	#include "crupier.h"

	#include <ctime>
	#include <cstdlib>
	#include <string>	
	#include <list>
	
	
	
	using namespace std;
	
	
	/*struct EstadoRuleta{
		int numJugadores;
		int dineroEnMesa;
		int numeroLanzamientos;
		int dineroBanca;
	};*/
	class Ruleta{
		private:
			int banca_;
			int bola_;
			Crupier crupier_;
			list <Jugador> jugadores_;
			
			int lanzamientos;
			//EstadoRuleta estadoActual;
			//Metodos Privados
			void ganaJugador(Jugador &j, int cant);
			void pierdeJugador(Jugador &j, int cant);
			string comprobarPar();
			string comprobarColor();
			string comprobarPasa();
			
		public:
			//Constructor
			Ruleta(Crupier c):crupier_(c.getDNI(),c.getCodigo()){ bola_=-1; banca_=1000000;srand(time(NULL));lanzamientos=0;}

			//getter u observador
			int getBanca()	const{	return banca_;}
			int getBola() const{	return bola_;}	
			Crupier getCrupier()const{	return crupier_;}
			list <Jugador> getJugadores()const{	return jugadores_;}
			int getLanzamientos()const{return lanzamientos;}
			
			//setter o modificador
			bool setBanca (int banca);
			bool setBola (int bola);
			void setCrupier(const Crupier &cru){	crupier_=cru;}
			void setLanzamientos(int l){lanzamientos=l;}
			
			//Metodos 
			void addJugador(const Jugador &jug);
			int deleteJugador(string DNI);
			int deleteJugador(const Jugador &jug);
			void escribeJugadores();
			void leeJugadores();
			void giraRuleta();
			void getPremios();
			void getEstadoRuleta(int &jug, int &dinero, int &lanz, int &ganaBanca);
			
			
	};


#endif
