#include "poly.hpp"

#include <sstream>

int Poly::operator[](int exp) const 
{
    auto it = values_.find(exp);
    return it == values_.end() ? 0 : it->second;
}

Poly operator-(const Poly& p)
{
    Poly p2;
    int i = 0;
    for (auto it = p.begin(); it != p.end(); it++, i++) 
    {
        p2[i] = -it->second;
    }
    return p2;
}

Poly& Poly::operator+=(const Poly& b)
{
    int i=0;
    for (auto it = b.begin(); it != b.end(); it++, i++) 
    {
        (*this)[i] += it->second;
    }
    return *this;
}

Poly operator+(const Poly& a, const Poly& b)
{
    Poly p2 = a;
    p2 += b;
    return p2;
}

Poly& Poly::operator-=(const Poly& b)
{
    int i = 0;
    for (auto it = b.begin(); it != b.end(); it++, i++) 
    {
        (*this)[i] -= it->second;
    }
    return *this;
}

Poly operator-(const Poly& a, const Poly& b)
{
    Poly p2 = a;
    p2 -= b;
    return p2;
}

bool operator<(const Poly& a, const Poly& b)
{
    if (a.end()->first < b.end()->first) 
    return true;
    else
     return false;
}

bool operator>(const Poly& a, const Poly& b)
{
    if (a.end()->first > b.end()->first) 
    return true;
    else
     return false;
}

bool operator==(const Poly& a, const Poly& b)
{
    if (a.end()->first == b.end()->first) 
    return true;
    else
     return false;
}

bool operator!=(const Poly& a, const Poly& b)
{
    if (a.end()->first != b.end()->first) 
    return true;
    else
     return false;
}