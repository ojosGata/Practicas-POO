//dados.cc
//Métodos de la clase Dados
#include "dados.h"
#include <cstdlib>
#include <ctime>
//Constructor que inicializa los atributos de la clase y lanza la semilla
Dados::Dados(){
	d1_=1;
	d2_=1;
	lanzamientos1_=0;
	lanzamientos2_=0;
	media1_=0;
	media2_=0;
	srand(time(NULL));
}
//Observadores o getters Esta funciones pueden ser declaradas inline o bien implementarlas en dado.h
int Dados::getDado1(){
	return d1_; //Devuelve el valor de dado 1
}
int Dados::getDado2(){
	return d2_; //Devuelve el valor de dado 2
}
int Dados::getLanzamientos1(){
	return lanzamientos1_; //Devuelve el número de lanzamientos del dado 1
}
int Dados::getLanzamientos2(){
	return lanzamientos2_; //Devuelve el número de lanzamientos del dado 2
}
//Modificadores o setters Estas funciones si son cortas pueden ser declaradas inline o bien implementarlas en dado.h
void Dados::setLanzamientos1(int valor){
	lanzamientos1_=valor; //Pone un valor en el número de lanzamientos del dado 1
}
void Dados::setLanzamientos2(int valor){
	lanzamientos2_=valor; //Pone un valor en el número de lanzamientos del dado 2
}
/*
	Modificador que antes de poner un valor al dado 1 comprueba que esta entre 1 y 6 si no es asi devuelve false
	Además aumenta el número de lazamientos y añade el valor para calcular la media y lo pone en el vector
*/
bool Dados::setDado1(int valor){ 
	if(valor>=1 && valor<=6){
		d1_=valor;
		setLanzamientos1(getLanzamientos1()+1);
		media1_+=(float)valor;
		ponerEnVector1();
		
		return true;
	}else{
		return false;
	}
}
/*
	Modificador que antes de poner un valor al dado 2 comprueba que esta entre 1 y 6 si no es asi devuelve false
	Además aumenta el número de lazamientos y añade el valor para calcular la media y lo pone en el vector
*/
bool Dados::setDado2(int valor){
	if(valor>=1 && valor<=6){
		d2_=valor;
		setLanzamientos2(getLanzamientos2()+1);
		media2_+=(float)valor;
		ponerEnVector2();
		return true;
	}else{
		return false;
	}
	
}

//Métodos o comportamiento de la clase
void Dados::lanzamiento(){ //Metodo que hace el lanzamiento de los dos dados
	//srand(time(NULL));
	setDado1((rand()%6) + 1);
	setDado2((rand()%6) + 1);
	//media1_+=(float)getDado1();
	//media2_+=(float)getDado2();
	
}
int Dados::getSuma(){ //Método que devuelve la suma de los valores de los dos dados
	return (d1_ + d2_);
}
int Dados::getDiferencia(){ //Método que devuelve la resta de ambos valores, el valor siempre debe ser positivo
	if(d1_>d2_) return (d1_ - d2_);
	else return (d2_ - d1_);

}
float Dados::getMedia1(){ //Método que devuelve la media de todos los lanzamientos que se han realizado con el dado 1
	if(media1_==0)
		return 0;
	else
		return (media1_/(float)getLanzamientos1());

}
float Dados::getMedia2(){ //Método que devuelve la media de todos los lanzamientos que se han realizado con el dado 2
	if(media2_==0)
		return 0;
	else
		return (media2_/(float)getLanzamientos2());
}
/*Estos métodos se podrían considerar como privados ya que solo lo utiliza la clase */
void Dados::ponerEnVector1(){ //En un vector de 5 elementos se va poniendo los ultimos valores del dado1
	int  l=getLanzamientos1();
	ultimos1_[l%5]=getDado1();
	
}
void Dados::ponerEnVector2(){ //En un vector de 5 elementos se va poniendo los ultimos valores del dado2
	int l=getLanzamientos2();
	ultimos2_[l%5]=getDado2();

}
/*
 Estos métodos si son publicos ya que se utilizaran fueran de la clase para saber los ultimos lanzamientos de los
 dados
*/
void Dados::getUltimos1(int *vector1){ //Guarda en vector1 los valores de los ultimos 5 lanzamientos
	for(int i=0;i<5;i++){
		vector1[i]=ultimos1_[i];
	}
	
}
void Dados::getUltimos2(int *vector2){ //Guarda en vector2 los valores de los ultimos 5 lanzamientos
	for(int i=0;i<5;i++){
		vector2[i]=ultimos2_[i];
	}
}
