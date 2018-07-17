// persona_unittest.cc:

#include "crupier.h"
#include "gtest/gtest.h"

TEST(Crupier, ConstructorParametrosDefecto) {
  Crupier c("33XX","5555");
  
  EXPECT_EQ("33XX", c.getCodigo());
  EXPECT_EQ("5555", c.getDNI());
  EXPECT_EQ("", c.getNombre());
  EXPECT_EQ("", c.getApellidos());
  EXPECT_EQ("", c.getDireccion());
  EXPECT_EQ("", c.getLocalidad());
  EXPECT_EQ("", c.getProvincia());
  EXPECT_EQ("", c.getPais());
  EXPECT_EQ(", ", c.getApellidosyNombre());
}
TEST(Crupier, ConstructorParametros) {
  Crupier c("44XX","4444", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla","Spain");
  
  EXPECT_EQ("44XX", c.getCodigo());
  EXPECT_EQ("4444", c.getDNI());
  EXPECT_EQ("Carlos", c.getNombre());
  EXPECT_EQ("Gutierrez", c.getApellidos());
  EXPECT_EQ("C/ Mesa 1", c.getDireccion());
  EXPECT_EQ("Aguilar", c.getLocalidad());
  EXPECT_EQ("Sevilla", c.getProvincia());
  EXPECT_EQ("Spain", c.getPais());
  EXPECT_EQ("Gutierrez, Carlos", c.getApellidosyNombre());
}

TEST(Crupier, ConstructorCopiaDefecto) {
  Crupier c("44XX","4444", "Carlos", "Gutierrez", "C/ Mesa 1", "Aguilar", "Sevilla", "Spain");
  Crupier q(c);
  Crupier r=q;
  EXPECT_EQ("44XX",q.getCodigo());
  EXPECT_EQ("4444", q.getDNI());
  EXPECT_EQ("Carlos", q.getNombre());
  EXPECT_EQ("Gutierrez", q.getApellidos());
  EXPECT_EQ("C/ Mesa 1", q.getDireccion());
  EXPECT_EQ("Aguilar", q.getLocalidad());
  EXPECT_EQ("Sevilla", q.getProvincia());
  EXPECT_EQ("Spain", q.getPais());
  EXPECT_EQ("Gutierrez, Carlos", q.getApellidosyNombre());
  
  EXPECT_EQ("44XX",r.getCodigo());
  EXPECT_EQ("4444", r.getDNI());
  EXPECT_EQ("Carlos", r.getNombre());
  EXPECT_EQ("Gutierrez", r.getApellidos());
  EXPECT_EQ("C/ Mesa 1", r.getDireccion());
  EXPECT_EQ("Aguilar", r.getLocalidad());
  EXPECT_EQ("Sevilla", r.getProvincia());
  EXPECT_EQ("Spain", r.getPais());
  EXPECT_EQ("Gutierrez, Carlos", r.getApellidosyNombre());
}
TEST(Crupier, ProbarSet){
	Crupier c("3333C","11111");
	c.setCodigo("222TT");
	EXPECT_EQ("222TT",c.getCodigo());
}
