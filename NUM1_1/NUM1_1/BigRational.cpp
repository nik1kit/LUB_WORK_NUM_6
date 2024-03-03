#include "BigRational.h"
#include "BigInteger.h"

// ������������
// ����������� �� ���������
BigRational::BigRational()
{
    numerator = BigInteger(0);
    denominator = BigInteger(1);
}

// ����������� � ���������� � ������������ ���� BigInteger
BigRational::BigRational(const BigInteger &num, const BigInteger &denom)
{
    // �������� �� ������� �����������
    if (denom == BigInteger(0))
    {
        // ���� ����������� ����� ����, ����������� ���������� ��� ��������� ���������
        throw std::invalid_argument("Denominator cannot be zero.");
    }

    // ���������� ���������, ���� ����������
    if (denom < BigInteger(0))
    {
        numerator = -num;     // ��������� ������ ����
        denominator = -denom; // ����������� ������ ����
    }
    else
    {
        numerator = num;
        denominator = denom;
    }
}

// ����������� � int ���������� � ������������
BigRational::BigRational(const int &num, const int &denom)
{
    // �������� �� ������� �����������
    if (denom == 0)
    {
        // ���� ����������� ����� ����, ����������� ���������� ��� ��������� ���������
        throw std::invalid_argument("Denominator cannot be zero.");
    }

    // ���������� ���������, ���� ����������
    if (denom < 0)
    {
        numerator = -num;     // ��������� ������ ����
        denominator = -denom; // ����������� ������ ����
    }
    else
    {
        numerator = num;
        denominator = denom;
    }
}

// ����������� � ����� ������
BigRational::BigRational(const BigInteger &num) : numerator(num), denominator(BigInteger(1))
{
}

// ����������� � int ������
BigRational::BigRational(const int &num) : numerator(BigInteger(num)), denominator(BigInteger(1))
{
}

// ��������� �������������� ��������
// �������� BigRational � ������ BigRational
BigRational BigRational::operator+(const BigRational &other) const
{
    BigInteger newNum = numerator * other.denominator + other.numerator * denominator;
    BigInteger newDenom = denominator * other.denominator;
    return BigRational(newNum, newDenom);
}

// �������� BigRational � BigInteger
BigRational BigRational::operator+(const BigInteger &other) const
{
    BigInteger newNum = numerator + other * denominator;
    return BigRational(newNum, denominator);
}

// �������� BigRational � int
BigRational BigRational::operator+(const int &other) const
{
    BigInteger newNum = numerator + other * denominator;
    return BigRational(newNum, denominator);
}

BigRational operator+(const int &lhs, const BigRational &rhs)
{
    return BigRational(lhs) + rhs;
}

// ��������� BigRational �� ������� BigRational
BigRational BigRational::operator-(const BigRational &other) const
{
    BigInteger newNum = numerator * other.denominator - other.numerator * denominator;
    BigInteger newDenom = denominator * other.denominator;
    return BigRational(newNum, newDenom);
}

// ��������� BigInteger �� BigRational
BigRational BigRational::operator-(const BigInteger &other) const
{
    BigInteger newNum = numerator - other * denominator;
    return BigRational(newNum, denominator);
}

// ��������� int �� BigRational
BigRational BigRational::operator-(const int &other) const
{
    BigInteger newNum = numerator - other * denominator;
    return BigRational(newNum, denominator);
}

BigRational operator-(const int &lhs, const BigRational &rhs)
{
    return BigRational(lhs) - rhs;
}
// ��������� BigRational �� ������ BigRational
BigRational BigRational::operator*(const BigRational &other) const
{
    BigInteger newNum = numerator * other.numerator;
    BigInteger newDenom = denominator * other.denominator;
    return BigRational(newNum, newDenom);
}

// ��������� BigRational �� BigInteger
BigRational BigRational::operator*(const BigInteger &other) const
{
    BigInteger newNum = numerator * other;
    return BigRational(newNum, denominator);
}

// ��������� BigRational �� int
BigRational BigRational::operator*(const int &other) const
{
    BigInteger newNum = numerator * other;
    return BigRational(newNum, denominator);
}

BigRational operator*(const int &lhs, const BigRational &rhs)
{
    return BigRational(lhs) * rhs;
}

// ������� BigRational �� ������ BigRational
BigRational BigRational::operator/(const BigRational &other) const
{
    BigInteger newNum = numerator * other.denominator;
    BigInteger newDenom = denominator * other.numerator;
    return BigRational(newNum, newDenom);
}

// ������� BigRational �� BigInteger
BigRational BigRational::operator/(const BigInteger &other) const
{
    BigInteger newDenom = denominator * other;
    return BigRational(numerator, newDenom);
}

// ������� BigRational �� int
BigRational BigRational::operator/(const int &other) const
{
    BigInteger newDenom = denominator * other;
    return BigRational(numerator, newDenom);
}

BigRational operator/(const int &lhs, const BigRational &rhs)
{
    return BigRational(lhs) / rhs;
}

// ������� �����
BigRational BigRational::operator-() const
{
    return BigRational(-numerator, denominator);
}

// ��������� ������������
BigRational &BigRational::operator=(const BigRational &other)
{
    if (this != &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
    }
    return *this;
}

BigRational &BigRational::operator=(const BigInteger &other)
{
    numerator = other;
    denominator = 1; // ����� �����, ����������� ����� 1
    return *this;
}

BigRational &BigRational::operator=(const int &other)
{
    numerator = other;
    denominator = 1; // ����� �����, ����������� ����� 1
    return *this;
}

// ��������� ���������
bool BigRational::operator==(const BigRational &other) const
{
    // ��������� ��������� ���������� � ������������
    return numerator == other.numerator && denominator == other.denominator;
}

bool BigRational::operator==(const BigInteger &other) const
{
    // ���������, ��� ����������� ����� 1, �.�. ����� �����, � ��������� ����� ������� BigInteger
    return denominator == 1 && numerator == other;
}

bool BigRational::operator==(const int &other) const
{
    // ���������, ��� ����������� ����� 1, �.�. ����� �����, � ��������� ����� ������� ������ �����
    return denominator == 1 && numerator == other;
}
bool BigRational::operator!=(const BigRational &other) const
{
    // ���������� �������� == ��� �������� ���������, ����� ����������� ���������
    return !(*this == other);
}

bool BigRational::operator!=(const BigInteger &other) const
{
    // ���������� �������� == ��� �������� ���������, ����� ����������� ���������
    return !(*this == other);
}

bool BigRational::operator!=(const int &other) const
{
    // ���������� �������� == ��� �������� ���������, ����� ����������� ���������
    return !(*this == other);
}
bool BigRational::operator<(const BigRational &other) const
{
    // ����������� ��� ����� � ������ ����������� � ���������� ���������
    BigInteger this_num = numerator * other.denominator;
    BigInteger other_num = other.numerator * denominator;
    return this_num < other_num;
}

bool BigRational::operator<(const BigInteger &other) const
{
    // ����������� ��������� � BigInteger � ���������� ��� � ������ ������
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num < other_num;
}

bool BigRational::operator<(const int &other) const
{
    // ����������� ��������� � BigInteger � ���������� ��� � ������ ������
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num < other_num;
}

bool BigRational::operator>(const BigRational &other) const
{
    // ����������� ��� �������� � BigInteger � ���������� ��
    BigInteger this_num = numerator * other.denominator;
    BigInteger other_num = other.numerator * denominator;
    return this_num > other_num;
}

bool BigRational::operator>(const BigInteger &other) const
{
    // ����������� ������� ������ BigRational � BigInteger � ���������� � other
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num > other_num;
}

bool BigRational::operator>(const int &other) const
{
    // ����������� ������� ������ BigRational � BigInteger � ���������� � other
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num > other_num;
}

bool BigRational::operator<=(const BigRational &other) const
{
    // ����������� ��� ����� � ������ ����������� � ���������� ���������
    BigInteger this_num = numerator * other.denominator;
    BigInteger other_num = other.numerator * denominator;
    return this_num <= other_num;
}

bool BigRational::operator<=(const BigInteger &other) const
{
    // ����������� ��������� � BigInteger � ���������� ��� � ������ ������
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num <= other_num;
}

bool BigRational::operator<=(const int &other) const
{
    // ����������� ��������� � BigInteger � ���������� ��� � ������ ������
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num <= other_num;
}

bool BigRational::operator>=(const BigRational &other) const
{
    // ����������� ��� �������� � BigInteger � ���������� ��
    BigInteger this_num = numerator * other.denominator;
    BigInteger other_num = other.numerator * denominator;
    return this_num >= other_num;
}

bool BigRational::operator>=(const BigInteger &other) const
{
    // ����������� ������� ������ BigRational � BigInteger � ���������� � other
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num >= other_num;
}

bool BigRational::operator>=(const int &other) const
{
    // ����������� ������� ������ BigRational � BigInteger � ���������� � other
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num >= other_num;
}

// GCD SIMPLIFY
// ���������� ������ ��� ���������� �����
void BigRational::simplify()
{
    BigInteger common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;
}

// ���������� ������ ��� ���������� ���
BigInteger BigRational::gcd(BigInteger &a, BigInteger &b)
{
    BigInteger remainder;
    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

// TO-STRING
std::string BigRational::toString() const
{
    if (denominator == 1)
    {
        return numerator.toString(); // ���� ����������� ����� 1, ���������� ������ ���������
    }
    else
    {
        return numerator.toString() + "/" + denominator.toString();
        // ����� ���������� ������ ���� "���������/�����������"
    }
}

// ASDECIMAL
std::string BigRational::asDecimal(size_t precision) const
{
    // �������� ������� ������ ��������
    if (denominator == 1)
    {
        return numerator.toString(); // ���� ����������� ����� 1, ������� ������ ���������
    }
    else
    {
        // ���������� ���������� �����
        BigInteger integralPart = numerator / denominator;   // ����� �����
        BigInteger fractionalPart = numerator % denominator; // ������� �����
        std::string decimal = integralPart.toString() + "."; // ������ ��� �������� ���������� �����

        // ���������� ������� ����� � �������� ���������
        for (size_t i = 0; i < precision; ++i)
        {
            fractionalPart *= 10; // ��������� ������� ����� �� 10 ��� ��������� ��������� �����
            BigInteger digit = fractionalPart / denominator; // ���������� ��������� �����
            decimal += digit.toString();                     // ���������� ����� � ������
            fractionalPart %= denominator;                   // ��������� ������ ������� ��� ��������� ��������
        }

        return decimal;
    }
}

// ���������� � DOUBLE
BigRational::operator double() const
{
    double result = static_cast<double>(numerator); // �������������� ��������� � ��� double
    result /= static_cast<double>(denominator);     // ������� �� �����������
    return result;
}
