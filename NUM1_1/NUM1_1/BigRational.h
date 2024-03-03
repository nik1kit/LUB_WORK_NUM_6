#ifndef BIGRATIONAL_H
#define BIGRATIONAL_H

#include "BigInteger.h" // ���������� ����� BigInteger
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class BigRational
{
  private:
    BigInteger numerator;   // ���������
    BigInteger denominator; // �����������

    // ��������������� ������
    void simplify();                              // ����� ��� ���������� �����
    BigInteger gcd(BigInteger &a, BigInteger &b); // ����� ��� ���������� ���
  public:
    // ������������
    BigRational();                                               // ����������� �� ���������
    BigRational(const BigInteger &num, const BigInteger &denom); // ����������� � ���������� � ������������
    BigRational(const int &num, const int &denom);
    BigRational(const BigInteger &num); // ����������� � ����� ������
    BigRational(const int &num);

    // ��������� ������������
    BigRational &operator=(const BigRational &other); // �������� ������������
    BigRational &operator=(const BigInteger &other);  // ������������ �� ������ �����
    BigRational &operator=(const int &other);         // ������������ �� ������ �����

    // ��������� �������������� ��������
    BigRational operator+(const BigRational &other) const; // ��������
    BigRational operator+(const BigInteger &other) const;  // ��������
    BigRational operator+(const int &other) const;         // ��������
    friend BigRational operator+(const int& lhs, const BigRational& rhs);
    BigRational operator-(const BigRational &other) const; // ���������
    BigRational operator-(const BigInteger &other) const;  // ���������
    BigRational operator-(const int &other) const;         // ���������
    friend BigRational operator-(const int& lhs, const BigRational& rhs);
    BigRational operator*(const BigRational &other) const; // ���������
    BigRational operator*(const BigInteger &other) const;  // ���������
    BigRational operator*(const int &other) const;         // ���������
    friend BigRational operator*(const int& lhs, const BigRational& rhs);
    BigRational operator/(const BigRational &other) const; // �������
    BigRational operator/(const BigInteger &other) const;  // �������
    BigRational operator/(const int &other) const;         // �������
    friend BigRational operator/(const int& lhs, const BigRational& rhs);
    BigRational operator-() const;                         // ������� �����

    // ��������� ���������
    bool operator==(const BigRational &other) const; // ���������
    bool operator==(const BigInteger &other) const;  // ���������
    bool operator==(const int &other) const;         // ���������
    bool operator!=(const BigRational &other) const; // �����������
    bool operator!=(const BigInteger &other) const;  // �����������
    bool operator!=(const int &other) const;         // �����������
    bool operator<(const BigRational &other) const;  // ������
    bool operator<(const BigInteger &other) const;   // ������
    bool operator<(const int &other) const;          // ������
    bool operator>(const BigRational &other) const;  // ������
    bool operator>(const BigInteger &other) const;   // ������
    bool operator>(const int &other) const;          // ������
    bool operator<=(const BigRational &other) const; // ������ ��� �����
    bool operator<=(const BigInteger &other) const;  // ������ ��� �����
    bool operator<=(const int &other) const;         // ������ ��� �����
    bool operator>=(const BigRational &other) const; // ������ ��� �����
    bool operator>=(const BigInteger &other) const;  // ������ ��� �����
    bool operator>=(const int &other) const;         // ������ ��� �����

    // ������ ��� ������������� �����
    std::string toString() const;                      // �������������� � ������
    std::string asDecimal(size_t precision = 0) const; // ������������� � ���� ���������� �����

    // �������� ���������� � double
    explicit operator double() const; // ���������� � ���� double
};

#endif // BIGRATIONAL_H
