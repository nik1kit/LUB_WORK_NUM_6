#ifndef BIGRATIONAL_H
#define BIGRATIONAL_H

#include "BigInteger.h" // Подключаем класс BigInteger
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class BigRational
{
  private:
    BigInteger numerator;   // Числитель
    BigInteger denominator; // Знаменатель

    // Вспомогательные методы
    void simplify();                              // Метод для сокращения дроби
    BigInteger gcd(BigInteger &a, BigInteger &b); // Метод для нахождения НОД
  public:
    // Конструкторы
    BigRational();                                               // Конструктор по умолчанию
    BigRational(const BigInteger &num, const BigInteger &denom); // Конструктор с числителем и знаменателем
    BigRational(const int &num, const int &denom);
    BigRational(const BigInteger &num); // Конструктор с целым числом
    BigRational(const int &num);

    // Операторы присваивания
    BigRational &operator=(const BigRational &other); // Оператор присваивания
    BigRational &operator=(const BigInteger &other);  // Присваивание от целого числа
    BigRational &operator=(const int &other);         // Присваивание от целого числа

    // Операторы арифметических операций
    BigRational operator+(const BigRational &other) const; // Сложение
    BigRational operator+(const BigInteger &other) const;  // Сложение
    BigRational operator+(const int &other) const;         // Сложение
    friend BigRational operator+(const int& lhs, const BigRational& rhs);
    BigRational operator-(const BigRational &other) const; // Вычитание
    BigRational operator-(const BigInteger &other) const;  // Вычитание
    BigRational operator-(const int &other) const;         // Вычитание
    friend BigRational operator-(const int& lhs, const BigRational& rhs);
    BigRational operator*(const BigRational &other) const; // Умножение
    BigRational operator*(const BigInteger &other) const;  // Умножение
    BigRational operator*(const int &other) const;         // Умножение
    friend BigRational operator*(const int& lhs, const BigRational& rhs);
    BigRational operator/(const BigRational &other) const; // Деление
    BigRational operator/(const BigInteger &other) const;  // Деление
    BigRational operator/(const int &other) const;         // Деление
    friend BigRational operator/(const int& lhs, const BigRational& rhs);
    BigRational operator-() const;                         // Унарный минус

    // Операторы сравнения
    bool operator==(const BigRational &other) const; // Равенство
    bool operator==(const BigInteger &other) const;  // Равенство
    bool operator==(const int &other) const;         // Равенство
    bool operator!=(const BigRational &other) const; // Неравенство
    bool operator!=(const BigInteger &other) const;  // Неравенство
    bool operator!=(const int &other) const;         // Неравенство
    bool operator<(const BigRational &other) const;  // Меньше
    bool operator<(const BigInteger &other) const;   // Меньше
    bool operator<(const int &other) const;          // Меньше
    bool operator>(const BigRational &other) const;  // Больше
    bool operator>(const BigInteger &other) const;   // Больше
    bool operator>(const int &other) const;          // Больше
    bool operator<=(const BigRational &other) const; // Меньше или равно
    bool operator<=(const BigInteger &other) const;  // Меньше или равно
    bool operator<=(const int &other) const;         // Меньше или равно
    bool operator>=(const BigRational &other) const; // Больше или равно
    bool operator>=(const BigInteger &other) const;  // Больше или равно
    bool operator>=(const int &other) const;         // Больше или равно

    // Методы для представления числа
    std::string toString() const;                      // Преобразование в строку
    std::string asDecimal(size_t precision = 0) const; // Представление в виде десятичной дроби

    // Оператор приведения к double
    explicit operator double() const; // Приведение к типу double
};

#endif // BIGRATIONAL_H
