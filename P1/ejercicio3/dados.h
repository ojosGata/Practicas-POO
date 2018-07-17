//dados.h
//Declaracion e la clase Dados
#ifndef DADOS_H
#define DADOS_H
	class Dados{
		private:
			int d1_; 
			int d2_;
			int lanzamientos1_;
			int lanzamientos2_;
			float media1_;
			float media2_;
			int ultimos1_[5];
			int ultimos2_[5];	
		public:
			//constructores
			Dados();
			//Observadores(getters)  y modificadores(setters)
		
			int getDado1();//las funciones que devuelvan el valor de los datos son los getter
			int getDado2();
			int getLanzamientos1();
			int getLanzamientos2();
			
			bool setDado1(int valor);//las funciones que modifiquen el valor de los datos son los setter
			bool setDado2(int valor);
			void setLanzamientos1(int valor);
			void setLanzamientos2(int valor);
			
			//funciones de la clase
			void lanzamiento();
			int getSuma();
			int getDiferencia();
			float getMedia1();
			float getMedia2();
			void ponerEnVector1();
			void ponerEnVector2();
			void getUltimos1(int *vector1);
			void getUltimos2(int *vector2);
			
	};

#endif
