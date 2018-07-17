// dados_unittest.cc: Juan A. Romero
// A sample program demonstrating using Google C++ testing framework.
//


// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "dados.h"
#include "gtest/gtest.h"

// Tests the c'tor.
TEST(Dados, Constructor) {
  Dados d;
  
  EXPECT_EQ(1, d.getDado1());
  EXPECT_EQ(1, d.getDado2());
  EXPECT_EQ(2, d.getSuma());
}

// Tests operación lanzamiento
TEST(Dados, Lanzamiento) {
  Dados d;
  d.lanzamiento();
  EXPECT_GT(d.getDado1(), 0);
  EXPECT_LT(d.getDado1(), 7);
  EXPECT_GT(d.getDado2(), 0);
  EXPECT_LT(d.getDado2(), 7);

}

// Tests operación Suma
TEST(Dados, Suma) {
  Dados d;
  
  EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
  
  d.lanzamiento();
 EXPECT_EQ(d.getDado1()+d.getDado2(), d.getSuma());
  
}
// Tests operación Diferencia
TEST(Dados, Diferencia) {
	Dados d;
	if(d.getDado1()>d.getDado2())
	  EXPECT_EQ(d.getDado1()-d.getDado2(), d.getDiferencia());
	else EXPECT_EQ(d.getDado2()-d.getDado1(), d.getDiferencia());
	d.lanzamiento();
	if(d.getDado1()>d.getDado2())
	  EXPECT_EQ(d.getDado1()-d.getDado2(), d.getDiferencia());
	else EXPECT_EQ(d.getDado2()-d.getDado1(), d.getDiferencia());

}
// Tests modificadores
TEST(Dados, Modificadores) {
  Dados d;
  
  EXPECT_FALSE(d.setDado1(9));
  EXPECT_FALSE(d.setDado1(-9));
  EXPECT_FALSE(d.setDado2(9));
  EXPECT_FALSE(d.setDado2(-9));
  d.setDado1(3);
  EXPECT_EQ(3, d.getDado1());
  d.setDado2(2);
  EXPECT_EQ(2, d.getDado2());
  EXPECT_EQ(5, d.getSuma());
}

//Tests El número de lazamientos que ha realizado el dado1 y el dado2 apartado a)
TEST (Dados, ConstructorLanzamientos){
	Dados d;
	
	EXPECT_EQ(0, d.getLanzamientos1());
	EXPECT_EQ(0, d.getLanzamientos2());
}

TEST(Dados, NumeroLanzamientos) {
  Dados d;
  for(int i=0;i<100;i++){
  	d.lanzamiento();
  }
  EXPECT_EQ(100,d.getLanzamientos1());
  EXPECT_EQ(100,d.getLanzamientos2());
}

//Tests media de los valores que se van obteniendo en los dados apartado b)
TEST(Dados, Media){
	Dados d;
	int suma1=0;
	int suma2=0;
	float med1,med2;
	EXPECT_EQ(0,d.getMedia1());
	EXPECT_EQ(0,d.getMedia2());
	for(int i=0;i<100;i++){
  		d.lanzamiento();
		suma1 += d.getDado1();
		suma2 += d.getDado2();
  	}
  	d.setDado1(5);
	d.setDado2(3);
	suma1 +=5;
	suma2 +=3;
	med1=(float)suma1/d.getLanzamientos1();
	med2=(float)suma2/d.getLanzamientos2();
	
	EXPECT_EQ(med1,d.getMedia1());
	EXPECT_EQ(med2,d.getMedia2());

}

//Tests Ultimos de los valores que se van obteniendo en los dados apartado d)
TEST(Dados,Ultimos){
	Dados d;
	int vecUltimosDado1[100], vecUltimosDado2[100];
	int vUltDad1[100],vUltDad2[100];
	
	for(int i=0;i<100;i++){
  		d.lanzamiento();
  		d.getUltimos1(vecUltimosDado1);
  		d.getUltimos2(vecUltimosDado2);
		vUltDad1[d.getLanzamientos1()%5]=d.getDado1();
  		vUltDad2[d.getLanzamientos2()%5]=d.getDado2();		  
	}
 	for(int i=0;i<5;i++){
 		EXPECT_EQ(vUltDad1[i],vecUltimosDado1[i]);
  		EXPECT_EQ(vUltDad2[i],vecUltimosDado2[i]);
 	}
  		
  		
}
