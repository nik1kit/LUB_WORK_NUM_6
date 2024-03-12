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
    friend BigRational operator+(const int &lhs, const BigRational &rhs);
    BigRational operator-(const BigRational &other) const; // ���������
    BigRational operator-(const BigInteger &other) const;  // ���������
    BigRational operator-(const int &other) const;         // ���������
    friend BigRational operator-(const int &lhs, const BigRational &rhs);
    BigRational operator*(const BigRational &other) const; // ���������
    BigRational operator*(const BigInteger &other) const;  // ���������
    BigRational operator*(const int &other) const;         // ���������
    friend BigRational operator*(const int &lhs, const BigRational &rhs);
    BigRational operator/(const BigRational &other) const; // �������
    BigRational operator/(const BigInteger &other) const;  // �������
    BigRational operator/(const int &other) const;         // �������
    friend BigRational operator/(const int &lhs, const BigRational &rhs);
    BigRational operator-() const; // ������� �����

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
    std::string toString();                            // �������������� � ������
    std::string asDecimal(size_t precision = 0) const; // ������������� � ���� ���������� �����
    void set_numer(int a)
    {
        this->numerator = a;
    }
    void set_denom(int b)
    {
        this->denominator = b;
    }
    BigInteger gcd(BigInteger x, BigInteger y)
    {
        BigInteger zero(0);
        if (x < zero)
            x = -x;
        if (y < zero)
            y = -y;
        while (x != y)
        {
            if (x > y)
            {
                x = x - y;
            }
            else
            {
                y = y - x;
            }
        }
        return x;
    }

    void simplify()
    {
        BigInteger common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }

    // �������� ���������� � double
    double to_double(); // ���������� � ���� double
};

#endif // BIGRATIONAL_H
