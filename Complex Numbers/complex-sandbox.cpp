#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;

#include "myComplex.h"

int main(){
  myComplex A(10,10), B(10, 10), C(1, 0), D(0, 1), Result;

  cout << A << " minus " << B << " = " << A-B << endl;
  Result = A - B;
  cout << Result.display() << endl;
  Result = A + 5;

  cout << Result << endl;

  cout << Result << endl;

  cin >> D;

  cout << C << " plus " << D << " = " << C+D << endl;
  Result = C + D;
  cout << Result.display() << endl;

  C.setComplex(2.0,1.5);
  D.setComplex(0,1.0);
  cout << C << " multiplied by " << D << " = " << C*D << endl;
  Result = C * D;
  cout << Result.display() << endl;

  C.setComplex(2.0,1.0);
  D.setComplex(2.0,1.0);
  cout << C << " multiplied by " << D << " = " << C*D << endl;
  Result = C * D;
  cout << Result.display() << endl;

  C.setComplex(0.0,1.5);
  D.setComplex(0.0,1.5);
  cout << C << " multiplied by " << D << " = " << C*D << endl;
  Result = C * D;
  cout << Result.display() << endl;

  C.setComplex(1.0,2.5);
  D.setComplex(-1.0,2.5);
  cout << C << " multiplied by " << D << " = " << C*D << endl;
  Result = C * D;
  cout << Result.display() << endl;

  cout << B << " divided by " << C << " = " << B/C << endl;
  Result = B / C;
  cout << Result.display() << endl;
}

