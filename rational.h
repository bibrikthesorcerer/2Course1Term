#pragma once
#include <iostream>

class rational
{
private:
   int m_numer;
   int m_denum;


public:
   rational(int numer_ = 0, int denum_ = 1);

   rational(const rational& obj);

   rational& reduce();

   rational& operator=(const rational& obj);

   rational operator*(const rational& obj);
   rational operator*(int num);

   rational operator+(const rational& obj);
   rational operator+(int num);

   rational operator-(const rational& obj);
   rational operator-(int num);


   rational operator/(const rational& obj);
   rational operator/(int num);

   int& numerator();
   int& denumerator();

   rational& operator+();
   rational& operator-();

   rational& operator*=(const rational& obj);
   rational& operator*=(int num);

   rational& operator+=(const rational& obj);
   rational& operator+=(int num);

   rational& operator-=(const rational& obj);
   rational& operator-=(int num);

   rational& operator/=(const rational& obj);
   rational& operator/=(int num);

   bool operator==(rational& obj) const;
   bool operator!=(rational& obj) const;

   friend std::ostream& operator<<(std::ostream& os_, const rational& obj);

   ~rational() {};

};