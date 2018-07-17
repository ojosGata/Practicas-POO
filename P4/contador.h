//contador.h
#ifndef CONTADOR_H
#define CONTADOR_H
	#include <iostream>
	#include <list>
	//Definicion de las operaciones
/*	c++ o ++c tipo 1 valor 1;
	c-- o --c tipo 2 valor 1;
	c+entero o entero+c tipo 3 valor entero
	c-entero o entero-c tipo 4 valor entero
*/	
	struct tOperacion{ // Estructura para poder controlar el tipo de operacion y cuanto hemos sumado o restado al contador
			int tipo;
			int valor;
	};
	using namespace std;
	class Contador{
		private:
			int entero_;
			
			
		public:
			list <tOperacion> listaO; //Esta lista tendra el tipo de operación y el orden que se han ido realizando
			//constructor
			Contador(int e){entero_= e;}
			//observador
			int get(){return entero_;}
			list <tOperacion> getLista(){return listaO;}
			//modificador
			void set(int entero){ entero_=entero;}
						
			//sobrecarga de operadores
			Contador& operator=(const int &i);
			//Operador ++
			Contador operator++(void);//++c
			Contador operator++(int); //c++
			//Operador --
			Contador operator--(void);//--c
			Contador operator--(int); //c--
			//Operador +
			friend int operator+(Contador c, int i); //c+10 
			friend int operator+(int i, Contador c); //10+c
			//Operador -
			friend int operator-(Contador c, int i); //c-10
			friend int operator-(int i, Contador c); //10-c
			
			//metodo
			bool undo(int i);
			bool undo();
			
	};
#endif
