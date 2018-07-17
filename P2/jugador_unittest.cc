//jugador.unittest.cc
#include "jugador.h"

#include "apuesta.h"

#include "gtest/gtest.h"


TEST(Jugador, ConstructorParametrosDefecto) {
  Jugador j("33XX","3333");
  
  EXPECT_EQ("33XX", j.getCodigo());
  EXPECT_EQ("3333", j.getDNI());
  EXPECT_EQ("", j.getNombre());
  EXPECT_EQ("", j.getApellidos());
  EXPECT_EQ("", j.getDireccion());
  EXPECT_EQ("", j.getLocalidad());
  EXPECT_EQ("", j.getProvincia());
  EXPECT_EQ("", j.getPais());
  EXPECT_EQ(", ", j.getApellidosyNombre());
  EXPECT_EQ(1000,j.getDinero());
}
 
TEST(Jugador, ConstructorParametros) {
  Jugador j("44XX","4444", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla","Spain");
   
  EXPECT_EQ("44XX", j.getCodigo());
  EXPECT_EQ("4444", j.getDNI());
  EXPECT_EQ("Carlos", j.getNombre());
  EXPECT_EQ("Gutierrez", j.getApellidos());
  EXPECT_EQ("C/ Mesa 1", j.getDireccion());
  EXPECT_EQ("Aguilar", j.getLocalidad());
  EXPECT_EQ("Sevilla", j.getProvincia());
  EXPECT_EQ("Spain", j.getPais());
  EXPECT_EQ("Gutierrez, Carlos", j.getApellidosyNombre());
  EXPECT_EQ(1000,j.getDinero());
}

TEST(Jugador, ConstructorCopiaDefecto) {
  Jugador j("44XX","4444", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "Spain");
  Jugador q(j);
  Jugador r=q;
  EXPECT_EQ("44XX",q.getCodigo());
  EXPECT_EQ("4444",  q.getDNI());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("Spain", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());
  EXPECT_EQ(1000,q.getDinero());
  
  EXPECT_EQ("44XX", r.getCodigo());
  EXPECT_EQ("4444", r.getDNI());
  EXPECT_EQ("Carlos", r.getNombre());
  EXPECT_EQ("Gutierrez", r.getApellidos());
  EXPECT_EQ("C/ Mesa 1", r.getDireccion());
  EXPECT_EQ("Aguilar", r.getLocalidad());
  EXPECT_EQ("Sevilla", r.getProvincia());
  EXPECT_EQ("Spain", r.getPais());
  EXPECT_EQ("Gutierrez, Carlos", r.getApellidosyNombre());
  EXPECT_EQ(1000,r.getDinero());
}

TEST(Jugador, OperadorIgualDefecto) {
  Jugador p("44XX", "4444","Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "Spain");
  Jugador q("66FF", "6666");
  q=p;
  EXPECT_EQ("44XX", q.getCodigo());
  EXPECT_EQ("4444", q.getDNI());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("Spain", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());
  EXPECT_EQ(1000,q.getDinero());
}
/*TEST(Jugador, FuncionsetApuesta){
	Jugador j("222XX","222XX", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla","Spain");
	
	list <Apuesta> lApuestas;
	
 	j.setApuestas();
	lApuestas=j.getApuestas();

  EXPECT_EQ(lApuestas, j.getApuestas());



}*/
