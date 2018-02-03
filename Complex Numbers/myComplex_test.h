#ifndef COMPLEX_TEST_H
#define COMPLEX_TEST_H

#include "myComplex.h"

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cxxtest/TestSuite.h>

using namespace std;

const double delta = 0.0001;
// Multiple test classes are used so groups of functions can be tested
// independently.
class myComplexGetters : public CxxTest::TestSuite {
public:
  void testGetReal1(){
    TS_ASSERT_DELTA(myComplex(5,5).getReal(), 5, delta);
  }

  void testGetReal2(){
    TS_ASSERT_DELTA(myComplex(6).getReal(), 6, delta);
  }

  void testGetIm1(){
    TS_ASSERT_DELTA(myComplex(5,6).getImaginary(), 6, delta);
  }

  void testGetIm2(){
    TS_ASSERT_DELTA(myComplex(6).getImaginary(), 0, delta);
  }

};

class myComplexSetters : public CxxTest::TestSuite {
public:

  void testSetReal1(){
    myComplex a;

    a.setReal(7);
    TS_ASSERT_DELTA(a.getReal(), 7, delta);
  }

  void testSetReal2(){
    myComplex a;
    a.setReal(-7);
    TS_ASSERT_DELTA(a.getReal(), -7, delta);
  }

  void testSetReal3(){
    myComplex a;
    a.setReal(0);
    TS_ASSERT_DELTA(a.getReal(), 0, delta);
  }

  void testSetImg1(){
    myComplex a;
    a.setImaginary(7);
    TS_ASSERT_DELTA(a.getImaginary(), 7, delta);
  }

  void testSetImg2(){
    myComplex a;
    a.setImaginary(-7);
    TS_ASSERT_DELTA(a.getImaginary(), -7, delta);
  }

  void testSetImg3(){
    myComplex a;
    a.setImaginary(0);
    TS_ASSERT_DELTA(a.getImaginary(), 0, delta);
  }

  void testSetBoth1(){
    myComplex a;
    a.setComplex(7,0);
    TS_ASSERT_DELTA(a.getReal(), 7, delta);
    TS_ASSERT_DELTA(a.getImaginary(), 0, delta);
  }

  void testSetBoth2(){
    myComplex a;
    a.setComplex(0, -7);
    TS_ASSERT_DELTA(a.getReal(), 0, delta);
    TS_ASSERT_DELTA(a.getImaginary(), -7, delta);
  }

  void testSetBoth3(){
    myComplex a;
    a.setComplex(0,0);
    TS_ASSERT_DELTA(a.getReal(), 0, delta);
    TS_ASSERT_DELTA(a.getImaginary(), 0, delta);
  }


};

class myComplexAdd : public CxxTest::TestSuite {
public:
  void testAdd1(){
    myComplex a(0,0);
    myComplex b(1,1);
    myComplex c(0,1);
    myComplex d(1,0);
    myComplex e(1,0);
    myComplex f(0,1);
    TS_ASSERT_EQUALS(a.addition(b), myComplex(1,1));
    TS_ASSERT_EQUALS(b.addition(b), myComplex(2,2));
    TS_ASSERT_EQUALS(c.addition(c), myComplex(0,2));
    TS_ASSERT_EQUALS(d.addition(d), myComplex(2,0));
    TS_ASSERT_EQUALS(e.addition(f), myComplex(1,1));
    
  }
};

class myComplexSub : public CxxTest::TestSuite {
public:
  void testSub1(){
    myComplex a(0,0);
    myComplex b(1,1);
    myComplex c(0,1);
    myComplex d(1,0);
    myComplex e(1,0);
    myComplex f(0,1);
    myComplex g(1,2);
    TS_ASSERT_EQUALS(a.subtraction(a), myComplex(0,0));
    TS_ASSERT_EQUALS(b.subtraction(c), myComplex(1,0));
    TS_ASSERT_EQUALS(c.subtraction(c), myComplex(0,0));
    TS_ASSERT_EQUALS(d.subtraction(e), myComplex(0,0));
    TS_ASSERT_EQUALS(f.subtraction(g), myComplex(-1,-1));
    
  }
};

class myComplexMult : public CxxTest::TestSuite {
public:
  void testMult1(){
    myComplex a(0,0);
    myComplex b(1,1);
    myComplex c(1,1);
    myComplex d(1,2);
    myComplex e(1,0.5);
    TS_ASSERT_EQUALS(a.multiplication(b), myComplex(0,0));
    TS_ASSERT_EQUALS(b.multiplication(c), myComplex(0,2));
    TS_ASSERT_EQUALS(c.multiplication(c), myComplex(0,2));
    TS_ASSERT_EQUALS(d.multiplication(e), myComplex(0,2.5));
    
  }
};

class myComplexDiv : public CxxTest::TestSuite {
public:
  void testDiv1(){
    myComplex a(0,0);
    myComplex b(10,10);
    myComplex c(1,5);
    myComplex d(1,2);
    myComplex e(1,0.5);
    TS_ASSERT_EQUALS(a.division(b), myComplex(0,0));
    TS_ASSERT_EQUALS(b.division(c), myComplex(2.30769,-1.53846));
    TS_ASSERT_EQUALS(d.division(e), myComplex(1.6,1.2));
  }
};

class myComplexAddOperator : public CxxTest::TestSuite {
public:
  void testAdd1(){
    TS_ASSERT_EQUALS(myComplex(0,0) + myComplex(1,1), myComplex(1,1));
  }

  void testAdd2(){
    TS_ASSERT_EQUALS(myComplex(1,1) + myComplex(1,1), myComplex(2,2));
  }

  void testAdd3(){
    TS_ASSERT_EQUALS(myComplex(1,2) + myComplex(1,0.5), myComplex(2,2.5));
  }

  void testAdd4(){
    TS_ASSERT_EQUALS(myComplex(1,2) + myComplex(1,0), myComplex(2,2));
  }

};

class myComplexSubOperator : public CxxTest::TestSuite {
public:
  void testSub1(){
    TS_ASSERT_EQUALS(myComplex(0,0) - myComplex(1,1), myComplex(-1,-1));
  }

  void testSub2(){
    TS_ASSERT_EQUALS(myComplex(1,1) - myComplex(1,1), myComplex(0,0));
  }

  void testSub3(){
    TS_ASSERT_EQUALS(myComplex(1,2) - myComplex(1,0.5), myComplex(0,1.5));
  }

};

class myComplexMultOperator : public CxxTest::TestSuite {
public:
  void testMult1(){
    TS_ASSERT_EQUALS(myComplex(0,0) * myComplex(1,1), myComplex(0,0));
  }

  void testMult2(){
    TS_ASSERT_EQUALS(myComplex(1,1) * myComplex(1,1), myComplex(0,2));
  }

  void testMult3(){
    TS_ASSERT_EQUALS(myComplex(1,2) * myComplex(1,0.5), myComplex(0,2.5));
  }

};

class myComplexDivisionOperator : public CxxTest::TestSuite {
public:
  void testDiv1(){
    TS_ASSERT_EQUALS(myComplex(0,0) / myComplex(1,1), myComplex(0,0));
  }

  void testDiv2(){
    TS_ASSERT_EQUALS(myComplex(10,10) / myComplex(1,5), myComplex(2.30769,-1.53846));
  }

  void testDiv3(){
    TS_ASSERT_EQUALS(myComplex(1,2) / myComplex(1,0.5), myComplex(1.6,1.2));
  }

};

class myComplexPolarMagitude : public CxxTest::TestSuite {
public:
  void testpolar1(){
    TS_ASSERT_DELTA(myComplex(0,0).getMagnitude(), 0, delta);
  }

  void testpolar2(){
    TS_ASSERT_DELTA(myComplex(5,0).getMagnitude(), 5, delta);
  }

  void testpolar3(){
    TS_ASSERT_DELTA(myComplex(0,5).getMagnitude(), 5, delta);
  }

  void testpolar4(){
    TS_ASSERT_DELTA(myComplex(5,5).getMagnitude(), 7.0710, delta);
  }

  void testpolar5(){
    TS_ASSERT_DELTA(myComplex(10,1).getMagnitude(), 10.0498, delta);
  }

  void testpolar6(){
    TS_ASSERT_DELTA(myComplex(-10,0).getMagnitude(), 10.0, delta);
  }

  void testpolar7(){
    TS_ASSERT_DELTA(myComplex(0,-10).getMagnitude(), 10.0, delta);
  }

  void testpolar8(){
    TS_ASSERT_DELTA(myComplex(-10,-1).getMagnitude(), 10.0498, delta);
  }

  void testpolar9(){
    TS_ASSERT_DELTA(myComplex(-10,10).getMagnitude(), 14.1421, delta);
  }

};

class myComplexPolarAngle : public CxxTest::TestSuite {
public:
  void testpolar1(){
    TS_ASSERT_DELTA(fmod(myComplex(0,0).getAngle() + 720,180), 0, delta);
  }

  void testpolar2(){
    TS_ASSERT_DELTA(fmod(myComplex(5,0).getAngle()+ 720,180), 0, delta);
  }

  void testpolar3(){
    TS_ASSERT_DELTA(fmod(myComplex(0,5).getAngle()+ 720,180), 90, delta);
  }

  void testpolar4(){
    TS_ASSERT_DELTA(fmod(myComplex(5,5).getAngle()+ 720,180), 45, delta);
  }

  void testpolar5(){
    TS_ASSERT_DELTA(fmod(myComplex(10,1).getAngle()+ 720,180), 5.7105 , delta);
  }

  /*void ttestpolar6(){
    TS_ASSERT_DELTA(fmod(myComplex(-10,0).getAngle()+ 720,180), 0.0, 0.1);
  } */

  void testpolar7(){
    TS_ASSERT_DELTA(fmod(myComplex(0,-10).getAngle()+ 720,180), 90, delta); // -90
  }

  void testpolar8(){
    TS_ASSERT_DELTA(fmod(myComplex(-10,-1).getAngle()+ 720,180), 5.7105 , delta);
  }

  void testpolar9(){
    TS_ASSERT_DELTA(fmod(myComplex(-10,10).getAngle()+ 720,180), 135, delta);// -45
  }

};


class myComplexEquality : public CxxTest::TestSuite {
public:
  void testeq1(){
    TS_ASSERT(myComplex(5,5) == myComplex(5,5));
  }
  
  void testeq10(){
    TS_ASSERT(myComplex(5,5) == myComplex(5,5.000001));
  }
  
  void testeq11(){
    TS_ASSERT(myComplex(5,10) == myComplex(5.000001,10));
  }

  void testeq2(){
    TS_ASSERT(!(myComplex(5,5) == myComplex(5,6)));
  }

  void testeq3(){
    TS_ASSERT(!(myComplex(5,5) == myComplex(6,5)));
  }

  void testeq4(){
    TS_ASSERT(!(myComplex(5,6) == myComplex(5,5)));
  }

  void testeq5(){
    TS_ASSERT(!(myComplex(6,5) == myComplex(5,5)));
  }

  void testneq1(){
    TS_ASSERT(myComplex(5,5) != myComplex(5,6));
  }

  void testneq2(){
    TS_ASSERT(myComplex(5,5) != myComplex(6,5));
  }

  void testneq3(){
    TS_ASSERT(myComplex(5,6) != myComplex(5,5));
  }

  void testneq4(){
    TS_ASSERT(myComplex(6,5) != myComplex(5,5));
  }

  void testneq5(){
    TS_ASSERT(!(myComplex(5,5) != myComplex(5,5)));
  }

};

class myComplexConjugate : public CxxTest::TestSuite {
public:
  void testcon1(){
    TS_ASSERT_EQUALS(myComplex(5,5).conjugate(), myComplex(5,-5));
  }

  void testcon2(){
    TS_ASSERT_EQUALS(myComplex(5,5).conjugate().conjugate(), myComplex(5,5));
  }

  void testcon3(){
    TS_ASSERT_EQUALS(myComplex(0,0.5).conjugate(), myComplex(0,-0.5));
  }

};

class myComplexStream : public CxxTest::TestSuite {
public:
  void teststream1(){
    myComplex a = myComplex(5,5);
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "(5+5i)");
  }

  void teststream2(){
    myComplex a = myComplex(5.5,5.5);
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "(5.5+5.5i)");
  }

  void teststream3(){
    myComplex a = myComplex(5,0);
    stringstream stream;
    stream << a;
    string out = stream.str();
    out.erase(remove_if(out.begin(), out.end(), ::isspace), out.end());
    TS_ASSERT_EQUALS(out, "(5+0i)");
  }

};

//#include <cxxtest/ValueTraits.h>

namespace CxxTest
{
CXXTEST_TEMPLATE_INSTANTIATION
class ValueTraits<myComplex>{
    string thing;
public:
    ValueTraits(const myComplex& m) { thing = m.display(); }
    const char* asString() const { return thing.c_str(); }
};
};

#endif
