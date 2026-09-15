#include "Fraction.h"

void Fraction::Init()
{
    numerator = rand() % 10 + 1;
    denominator = rand() % 10 + 1;
}

void Fraction::Init(int _numerator, int _denominator)
{
    numerator = _numerator;
    if (_denominator != 0)
    {
        denominator = _denominator;
    }
    else
    {
        denominator = 1;
    }
}

void Fraction::Print()
{
    cout << numerator << "/" << denominator << endl;
}

void Fraction::SetNumerator(int _numerator)
{
    numerator = _numerator;
}

int Fraction::GetNumerator()
{
    return numerator;
}

void Fraction::SetDenominator(int _denominator)
{
    if (_denominator != 0)
    {
        denominator = _denominator;
    }
}

int Fraction::GetDenominator()
{
    return denominator;
}

Fraction Fraction::Add(Fraction b)
{
    Fraction rez;
    int num = numerator * b.denominator + b.numerator * denominator;
    int den = denominator * b.denominator;
    rez.Init(num, den);
    return rez;
}

Fraction Fraction::Sub(Fraction b)
{
    Fraction rez;
    int num = numerator * b.denominator - b.numerator * denominator;
    int den = denominator * b.denominator;
    rez.Init(num, den);
    return rez;
}

Fraction Fraction::Mul(Fraction b)
{
    Fraction rez;
    int num = numerator * b.numerator;
    int den = denominator * b.denominator;
    rez.Init(num, den);
    return rez;
}

Fraction Fraction::Div(Fraction b)
{
    Fraction rez;
    int num = numerator * b.denominator;
    int den = denominator * b.numerator;
    rez.Init(num, den);
    return rez;
}
