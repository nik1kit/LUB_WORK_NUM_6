#ifndef BIGINTEGER_H
#define BIGINTEGER_H
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const int base = 10;

inline void eraseZeros(std::vector<int> &source)
{
    while (source.size() > 1 && source.back() == 0)
    {
        source.pop_back();
    }
}

class BigInteger
{
  public:
    BigInteger();
    ~BigInteger() = default;
    BigInteger(const BigInteger &value);

    explicit BigInteger(std::string &value); // BigInteger bigIntNumberExplicit(���-�� ���)
    BigInteger(const int value);

    BigInteger &operator=(const BigInteger &value);
    BigInteger &operator=(BigInteger &&value) = default;

    std::string toString() const;

    // ������ � �������.
    bool operator==(const BigInteger &other) const;
    bool operator==(const int other) const;
    bool operator!=(const BigInteger &other) const;
    bool operator!=(const int &other) const;
    bool operator<(const BigInteger &other) const;
    bool operator<=(const BigInteger &other) const;
    bool operator>(const BigInteger &other) const;
    bool operator>=(const BigInteger &other) const;

    //    ������� ��������
    BigInteger operator-() const;

    //    pre/post increment/decrement
    BigInteger &operator++();
    BigInteger &operator--();

    BigInteger operator++(int);
    BigInteger operator--(int);

    //    �������� ���������
    friend BigInteger operator+(const BigInteger &left, const BigInteger &right);
    friend BigInteger operator+(const BigInteger &left, const int &right);
    friend BigInteger operator+(const int &left, const BigInteger &right);
    friend BigInteger operator*(const BigInteger &left, const BigInteger &right);
    friend BigInteger operator*(const int &left, const BigInteger &right);
    friend BigInteger operator*(const BigInteger &left, const int &right);
    friend BigInteger operator-(const BigInteger &left, const BigInteger &right);
    friend BigInteger operator-(const int &left, const BigInteger &right);
    friend BigInteger operator-(const BigInteger &left, const int &right);
    friend BigInteger operator/(const BigInteger &left, const int &right);
    friend BigInteger operator/(const BigInteger &left, const BigInteger &right);
    friend BigInteger operator%(const BigInteger &left, const BigInteger &right);
    friend BigInteger operator%(const BigInteger &left, const int &right);

    //    ��������� ���������
    BigInteger &operator+=(const BigInteger &other);
    BigInteger &operator-=(const BigInteger &other);
    BigInteger &operator*=(const BigInteger &other);
    BigInteger &operator/=(const BigInteger &other);
    BigInteger &operator%=(const BigInteger &other);

    //    �������������� �����
    operator bool() const
    {
        return !bigInt.empty() && bigInt.back() != 0;
    }

    //    ����/�����
    friend std::ostream &operator<<(std::ostream &stream, const BigInteger &value);
    friend std::istream &operator>>(std::istream &stream, BigInteger &value);


  private:
    bool sign; // if not positive
    std::vector<int> bigInt;

};

#endif // BIGINTEGER_H
