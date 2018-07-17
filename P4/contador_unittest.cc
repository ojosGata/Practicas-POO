// contador_unittest.cc: Ana Isabel
// A sample program demonstrating using Google C++ testing framework.
//
// This sample shows how to write a more complex unit test for a class
// that has multiple member functions.
//
// Usually, it's a good idea to have one test for each method in your
// class.  You don't have to do that exactly, but it helps to keep
// your tests organized.  You may also throw in additional tests as
// needed.

#include "contador.h"
#include "gtest/gtest.h"

TEST(Contador, Constructor) {
  Contador c(7);
  
  EXPECT_EQ(7, c.get());
}
 
TEST(Contador,OperadorMasMas) {
	Contador c(7);
	c++;
	EXPECT_EQ(8, c.get());
	++c;
	EXPECT_EQ(9, c.get());
}

TEST(Contador, OperadorMenosMenos) {
	Contador c(7);
	c--;
	EXPECT_EQ(6, c.get());
	--c;
	EXPECT_EQ(5, c.get());
}
TEST(Contador, OperadorSoloMas) {
	Contador c(7);
	Contador d(5);
	d=c+5;
	EXPECT_EQ(12, d.get());
	d=10+c;
	EXPECT_EQ(17, d.get());
}
TEST(Contador, OperadorSoloMenos) {
	Contador c(7);
	Contador d(5);
	d=c-5;
	EXPECT_EQ(2, d.get());
	d=8-c;
	EXPECT_EQ(1, d.get());
}
TEST(Contador, MetodoUndoMasMas) {
	Contador c(0);
	EXPECT_EQ(false,c.undo());
	c++;
	EXPECT_EQ(true,c.undo());
	c++;
	c++;
	EXPECT_EQ(false,c.undo(4));
	EXPECT_EQ(2, c.get());
	EXPECT_EQ(true,c.undo(2));
	EXPECT_EQ(0, c.get());
}
TEST(Contador, MetodoUndoMenosMenos) {
	Contador c(10);
	EXPECT_EQ(false,c.undo());
	c--;
	EXPECT_EQ(true,c.undo());
	c--;
	c--;
	EXPECT_EQ(false,c.undo(4));
	EXPECT_EQ(8, c.get());
	EXPECT_EQ(true,c.undo(2));
	EXPECT_EQ(10, c.get());
}

