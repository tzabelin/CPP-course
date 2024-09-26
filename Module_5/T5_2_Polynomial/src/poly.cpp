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

std::istream& operator>>(std::istream& is, Poly& p)
{
    std::string input;
    is >> input;
    std::stringstream ss(input);
    p = Poly();
    int sign = 1;
    bool first_term = true;
    while (ss)
    {
        ss >> std::ws; 
        char c = ss.peek();
        if (c == '+')
        {
            ss.get();
            sign = 1;
        }
        else if (c == '-')
        {
            ss.get();
            sign = -1;
        }
        else if (first_term)
        {
            sign = 1;
        }
        else if (ss.eof())
        {
            break;
        }

        first_term = false;

        int mul;
        if (!(ss >> mul))
        {
            is.setstate(std::ios::failbit);
            return is;
        }

        char x;
        if (!(ss >> x) || x != 'x')
        {
            is.setstate(std::ios::failbit);
            return is;
        }

        int exp;
        if (!(ss >> exp))
        {
            is.setstate(std::ios::failbit);
            return is;
        }

        mul *= sign;
        p[exp] = mul;
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Poly& p)
{
    bool first_term = true;
    for (auto it = p.begin(); it != p.end(); ++it)
    {
        int exp = it->first;
        int mul = it->second;
        if (mul == 0)
            continue;

        if (first_term)
        {
            if (mul < 0)
                os << "-";
            os << std::abs(mul) << "x" << exp;
            first_term = false;
        }
        else
        {
            if (mul > 0)
                os << "+";
            else
                os << "-";
            os << std::abs(mul) << "x" << exp;
        }
    }
    return os;
}