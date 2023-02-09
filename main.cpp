#include <iostream>
/*#include "DoubleArray.h"
#include "StringClass.h"
#include "SException.h"
#include "DAException.h"
#include "GeoHeritage.h"
#include "table.h"*/
#include "rational.h"


int main()
{
   rational r1(2, 4);
   rational r2(1, 2);
   std::cout << r1 + r2;


   r1.reduce();
   return 0;
}