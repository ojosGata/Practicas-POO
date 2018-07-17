#include "contador.h"
#include <iostream>
using namespace std;
//Sobrecarga del operador ==
Contador& Contador::operator=(const int &i){
	entero_=i;
	return *this;
}

//Sobrecarga del Operador ++ 
Contador Contador::operator++(void){//++c tipo 1
	tOperacion t;
	t.tipo=1;
	t.valor=1;
	++entero_; 
	listaO.push_back(t);
	return *this;
}
Contador	Contador::operator++(int){ //c++ tipo 1
	tOperacion t;
	t.tipo=1;
	t.valor=1; 
	listaO.push_back(t);
	entero_++;
	return *this;
}
//Sobrecarga Operador --
Contador Contador::operator--(void){//--c tipo 2
	tOperacion t;
	t.tipo=2;
	t.valor=1; 
	listaO.push_back(t);
	--entero_;
	return *this;
}
Contador Contador::operator--(int){//c-- tipo 2
	tOperacion t;
	t.tipo=2;
	t.valor=1; 
	listaO.push_back(t);
	entero_--;
	return *this;
}
//Sobrecarga Operador +
int operator+(Contador c, int i){ //c+10 tipo 3
	tOperacion t;
	t.tipo=3;
	t.valor=i;
	c.listaO.push_back(t);
	return c.get() + i;
}
int operator+(int i, Contador c){ //10+c tipo 4
	tOperacion t;
	t.tipo=4;
	t.valor=i; 
	c.listaO.push_back(t);
	return i+c.get();
}
//Sobrecarga Operador -
int operator-(Contador c, int i){ //c-10	tipo 5
	tOperacion t;
	t.tipo=5;
	t.valor=i;
	c.listaO.push_back(t);
	return c.get() - i;
}
int operator-(int i, Contador c){ //10-c tipo 6
	tOperacion t;
	t.tipo=6;
	t.valor=i;
	c.listaO.push_back(t);

	return i-c.get();
}
//Metodos Deshace los n últimos operaciones realizadas sobre el operador
bool Contador::undo(int n){
	list <tOperacion> lis=getLista();
	if(listaO.empty()) return false;
	else if(n>(int)listaO.size()) return false;
	else{
		//Recorrer la lista hasta llegar a n desde el final para ir desapilando 
		list<tOperacion>::iterator it=listaO.begin();
		for(int i =0; i<n; i++){
			switch(it->tipo){
				case 1: //operaciones tipo c++ o ++c
					set(get()-it->valor);
					break;
				case 2: //operaciones tipo c-- o --c
					set(get()+it->valor);
					break;
				case 3: //operaciones tipo c+10
					set(get()-it->valor); 
					cout<<"valor: "<<it->valor<<endl;
					break;
				case 4: //operaciones tipo 10+c
					set(it->valor-get());
					break;
				case 5: //operaciones tipo c-10
					set(get()+it->valor);
					break;
				case 6: //operaciones tipo 10-c
					set(it->valor+get());
					break;
			}
			it++;
			listaO.pop_back();
		}
		return true;
		
	}
}
bool Contador::undo(){
	return undo(1);
}
