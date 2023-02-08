#include <iostream>
#include <numeric>
#include "rational.h"

rational::rational(int numer_, int denum_)
{
   m_denum = denum_;
   m_numer = numer_;
}

rational::rational(const rational& obj)
{
   m_denum = obj.m_denum;
   m_numer = obj.m_numer;
}

rational& rational::reduce()
{
   int temp = std::gcd(m_numer, m_denum);

   m_numer /= temp;
   m_denum /= temp;

   return *this;

}

rational& rational::operator=(const rational& obj)
{
   m_denum = obj.m_denum;
   m_numer = obj.m_numer;

   return *this;
}

rational rational::operator*(const rational& obj)
{
   rational res = *this;
   res.m_numer *= obj.m_numer;
   res.m_denum *= obj.m_denum;
   res.reduce();
   return res;
}

rational rational::operator*(int num)
{
   rational res = *this;
   res.m_numer *= num;
   res.m_denum *= num;
   return res;
}

rational rational::operator+(const rational& obj)
{
   rational res = *this;
   if (res.m_denum == obj.m_denum)
   {
      res.m_numer += obj.m_numer;
   }
   else
   {
      int temp = res.m_denum;
      res = res * obj.m_denum;
      res.m_numer += temp * obj.m_numer;
      res.reduce();
   }
   return res;
}

rational rational::operator+(const int num)
{
   rational res = *this;
   res.m_numer += num * m_denum;
   res.reduce();
   return res;
}

rational rational::operator-(const rational& obj)
{
   rational res = *this;
   if (res.m_denum == obj.m_denum)
   {
      res.m_numer -= obj.m_numer;
   }
   else
   {
      int temp = res.m_denum;
      res = res * obj.m_denum;
      res.m_numer -= temp * obj.m_numer;
      res.reduce();
   }
   return res;
}

rational rational::operator-(int num)
{
   rational res = *this;
   res.m_numer -= num * m_denum;
   res.reduce();
   return res;
}

rational rational::operator/(const rational& obj)
{
   rational res = *this;
   res.m_numer *= obj.m_denum;
   res.m_denum *= obj.m_numer;
   res.reduce();
   return res;
}

rational rational::operator/(int num)
{
   rational res = *this;
   res.m_denum *= num;
   return res;
}

int& rational::numerator()
{
   reduce();
   return m_numer;
}

int& rational::denumerator()
{
   reduce();
   return m_denum;
}

rational& rational::operator+()
{
   return *this;
}

rational& rational::operator-()
{
   m_numer *= -1;
   return *this;
}

rational& rational::operator*=(const rational& obj)
{
   return *this = *this * obj;
}

rational& rational::operator*=(int num)
{
   return *this = *this * num;
}

rational& rational::operator+=(const rational& obj)
{
   return *this = *this + obj;
}

rational& rational::operator+=(int num)
{
   return *this = *this + num;
}

rational& rational::operator-=(const rational& obj)
{
   return *this = *this - obj;
}

rational& rational::operator-=(int num)
{
   return *this = *this - num;
}

rational& rational::operator/=(const rational& obj)
{
   return *this = *this / obj;
}

rational& rational::operator/=(int num)
{
   return *this = *this / num;
}

bool rational::operator==(rational& obj) const
{
   rational o1 = *this;
   rational o2 = obj;
   o1.reduce();
   o2.reduce();
   return (o1.m_numer == o2.m_numer && o1.m_denum == o2.m_denum);
}

bool rational::operator!=(rational& obj) const
{
   return !(*this == obj);
}

std::ostream& operator<<(std::ostream& os_, const rational& obj)
{
   os_ << obj.m_numer << "/" << obj.m_denum;

   os_ << std::endl;

   return os_;
}
