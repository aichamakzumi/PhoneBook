#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Fraction
{
private:
    int numerator;   // чисельник
    int denominator; // знаменник

public:
    // Методи ініціалізації (Init)
    void Init();
    void Init(int _numerator, int _denominator);

    // Метод виводу (Print)
    void Print();

    // Сеттери та геттери
    void SetNumerator(int _numerator);
    int GetNumerator();

    void SetDenominator(int _denominator);
    int GetDenominator();

    // Арифметичні операції
    Fraction Add(Fraction b);
    Fraction Sub(Fraction b);
    Fraction Mul(Fraction b);
    Fraction Div(Fraction b);
};

#endif
