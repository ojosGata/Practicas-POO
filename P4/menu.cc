#include "crupier.h"
#include "ruleta.h"

#include <iostream>
#include <string>
using namespace std;
void imprimirPremiosxJugador(list <Jugador> lisJug);
void importeBanca(int valor);
int main(){
	int opcion=0;
	int numJugadores, sumaMesa, lanzas, valorBanca;
	Jugador j("0000","0000");
	string dni="", codigo="", nombre="", apellidos="";
	string direccion="", localidad="", provincia="", pais="";
	Crupier c("1111","111x");
	
	Ruleta r(c);
	do{
		//Menu
		cout<<"\nBienvenido al menu de la Ruleta\n";
		cout<<"Elija una opción\n";
		cout<<"-----------------------------------------------------------------\n";
		cout<<"|                              	RULETA                          |\n";
		cout<<"-----------------------------------------------------------------\n";
		cout<<"|\t1) Cargar los jugadores del fichero \"jugadores.txt\"\t|\n";
		cout<<"|\t2) Guardar los jugadores en \"jugadores.txt\"        \t|\n";
		cout<<"|\t3) Ver el estado de la ruleta                        \t|\n";
		cout<<"|\t4) Girar ruleta y mostrar premios\"                  \t|\n";
		cout<<"|\t5) Eliminar un jugador de la mesa                    \t|\n";
		cout<<"|\t6) Añadir un jugador a la mesa                       \t|\n";
		cout<<"|\t7) Salir del programa                                \t|\n";
		cout<<"-----------------------------------------------------------------\n";
		cin>>opcion;
		switch(opcion){
			case 1:
				//Cargar jugadores
				r.leeJugadores();
				break;
			case 2:
				//Guardar jugadores
				r.escribeJugadores();
				break;
			case 3:
				//Ver Estado ruleta
				
				r.getEstadoRuleta(numJugadores, sumaMesa,lanzas,valorBanca);
				cout<<"Actualmente hay " << numJugadores << " en la mesa" << endl;
				cout<<"En juego hay " << sumaMesa << "€ en la mesa" << endl;
				importeBanca(valorBanca);
				break;
			case 4:
				//girar la ruleta y muestra resultados
				r.giraRuleta();
				cout<<"La bola es " << r.getBola()<<endl;
				r.getPremios();
				r.getEstadoRuleta(numJugadores, sumaMesa,lanzas,valorBanca);
				imprimirPremiosxJugador(r.getJugadores());
				importeBanca(valorBanca);
				break;
			case 5:
				//eliminar un jugador
				getchar();
				int estadoBorrado;
				cout<<"Introduzca el dni del jugador se va a eliminar:"<<endl;
				getline(cin, dni, '\n');
				estadoBorrado=r.deleteJugador(dni);
				if(estadoBorrado == 1)
					//Borrado correctamente
					cout<< "El jugador con dni: "<< dni << " ha sido elimando correctamente de la mesa"<<endl;
				else if(estadoBorrado == -2)
					//El jugador no se ha encontrado
					cout<< "El jugador con dni: "<< dni << " no esta en la lista de jugadores"<<endl;
				else //la lista esta vacia
					cout<<"La lista esta vacia, debe introducir algun jugador antes de borrar"<<endl;
				break;
			case 6:
				//añadir jugador
				getchar();
				cout<<"Introduzca los datos del jugador"<<endl;
				cout<<"Dni: ";
				getline(cin, dni, '\n');
				cout<<"Codigo: ";
				getline(cin, codigo, '\n');
				cout<<"Nombre: ";
				getline(cin, nombre, '\n');
				cout<<"Apellidos: ";
				getline(cin, apellidos, '\n');
				cout<<"Direccion: ";
				getline(cin, direccion, '\n');
				cout<<"Localidad: ";
				getline(cin, localidad, '\n');
				cout<<"Provicia: ";
				getline(cin, provincia, '\n');
				cout<<"pais: ";
				getline(cin, pais, '\n');
				j.setDNI(dni);
				j.setCodigo(codigo);
				j.setNombre(nombre);
				j.setApellidos(apellidos);
				j.setDireccion(direccion);
				j.setLocalidad(localidad);
				j.setProvincia(provincia);
				j.setPais(pais);
				r.addJugador(j);
				break;
			case 7:
				cout<<"\n\n\n Saliendo del menu Ruleta"<<endl;
				cout<<"\n\n\n ADIOS"<<endl;
				//Salir
				break;
			//default:
				//volver a intentar		
		
		}
	}while(opcion!=7);
	return 0;
}
//Muestra por pantalla los premios por jugador
void imprimirPremiosxJugador(list <Jugador> lisJug){
	for (list<Jugador>::iterator it = lisJug.begin(); it!=lisJug.end(); ++it){
		cout<<"Jugador: " << it->getDNI()<<"-"<<it->getApellidosyNombre()<<"  Importe: " << it->getDinero() << endl;
		
	}

}
//Muestra por pantalla el importe actual de la banca
void importeBanca(int valor){
	if(valor <0)
		cout<<"La banca ha perdido " << valor << "€"<< endl;
	else
		cout<<"La banca ha ganado " << valor << "€"<< endl;
}
