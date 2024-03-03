#include "BigInteger.h"

BigInteger operator%(const BigInteger &left, const int &right)
{
    BigInteger tmp = right;
    return left % tmp;
}

BigInteger operator*(const int &left, const BigInteger &right)
{
    BigInteger tmp = left;
    return tmp * right;
}

BigInteger operator*(const BigInteger &left, const int &right)
{
    BigInteger tmp = right;
    return tmp * left;
}

BigInteger operator+(const int &left, const BigInteger &right)
{
    BigInteger tmp = left;
    return tmp - right;
}

BigInteger operator-(const BigInteger &left, const int &right)
{
    BigInteger tmp = right;
    return left - tmp;
}

BigInteger operator-(const int &left, const BigInteger &right)
{
    BigInteger tmp = left;
    return tmp - right;
}

BigInteger operator+(const BigInteger &left, const int &right)
{
    BigInteger tmp = right;
    return left + tmp;
}

bool BigInteger::operator==(const BigInteger &other) const
{
    bool less = (*this < other);
    bool greater = (other < *this);
    return !less && !greater;
}

bool BigInteger::operator==(const int other) const
{
    BigInteger bigOther(other);
    bool equal = (*this == bigOther);
    return equal;
}

bool BigInteger::operator!=(const BigInteger &other) const
{
    bool equal = (*this == other);
    return !equal;
}

bool BigInteger::operator!=(const int &other) const
{
    // Преобразуем int в BigInteger
    BigInteger otherBigInt(other);
    // Используем оператор сравнения !=
    return *this != otherBigInt;
}

bool BigInteger::operator<=(const BigInteger &other) const
{
    bool equal = (*this == other);
    bool less = (*this < other);
    return equal || less;
}

bool BigInteger::operator>(const BigInteger &other) const
{
    bool equal = (*this == other);
    bool less = (*this < other);
    return !less && !equal;
}

bool BigInteger::operator>=(const BigInteger &other) const
{
    bool less = (*this < other);
    return !less;
}

bool BigInteger::operator<(const BigInteger &other) const
{
    // Проверяем, что не -0
    if (sign && (bigInt.empty() || (bigInt.size() == 1 && bigInt.back() == 0)))
    {
        if ((other.bigInt.empty()) || (other.bigInt.size() == 1 && other.bigInt.back() == 0))
        {
            return false;
        }
        if (other.sign)
        {
            return false;
        }
        if (!other.sign)
        {
            return true;
        }
    }

    // случай разных знаков
    if (sign && !other.sign)
    {
        return true;
    }
    else if (!sign && other.sign)
    {
        return false;
    }

    if (bigInt.size() < other.bigInt.size())
    {
        return !sign;
    }
    else if (bigInt.size() > other.bigInt.size())
    {
        return sign;
    }

    for (int i = bigInt.size() - 1; i >= 0; i--)
    {
        if (bigInt[i] < other.bigInt[i])
        {
            return !sign;
        }
        else if (bigInt[i] > other.bigInt[i])
        {
            return sign;
        }
    }

    return sign;
}

BigInteger::BigInteger() : sign(false)
{
}

BigInteger::BigInteger(const std::string &value)
{
    sign = (value[0] == '-');

    for (size_t i = value.size() - 1; i >= sign; i--)
    {
        bigInt.push_back(value[i] - '0');
    }
}

BigInteger::BigInteger(const BigInteger &other)
{
    bigInt = other.bigInt;
    sign = other.sign;
}

BigInteger::BigInteger(const int value)
{
    int tmp = value;

    if (tmp >= 0)
    {
        sign = false;
    }
    else
    {
        sign = true;
        tmp = -tmp;
    }

    while (tmp > 0)
    {
        bigInt.push_back(tmp % base);
        tmp /= base;
    }
}

BigInteger &BigInteger::operator=(const BigInteger &value)
{
    this->bigInt = value.bigInt;
    this->sign = value.sign;
    return *this;
}

std::string BigInteger::toString() const
{
    std::ostringstream stream;
    stream << *this;
    std::string str = stream.str();
    return str;
}

std::ostream &operator<<(std::ostream &stream, const BigInteger &value)
{
    // случай -0
    if (value.sign)
    {
        if (!(value.bigInt.empty() || (value.bigInt.size() == 1 && value.bigInt.back() == 0)))
        {
            stream << "-";
        }
    }

    stream << (value.bigInt.empty() ? 0 : value.bigInt.back());

    for (int i = static_cast<int>(value.bigInt.size()) - 2; i >= 0; --i)
    {
        stream << value.bigInt[i];
    }

    return stream;
}

BigInteger &BigInteger::operator%=(const BigInteger &other)
{
    *this = *this % other;
    return *this;
}

BigInteger &BigInteger::operator/=(const BigInteger &other)
{
    *this = *this / other;
    return *this;
}

BigInteger &BigInteger::operator*=(const BigInteger &other)
{
    *this = *this * other;
    return *this;
}

BigInteger &BigInteger::operator-=(const BigInteger &other)
{
    *this = *this - other;
    return *this;
}

BigInteger &BigInteger::operator+=(const BigInteger &other)
{
    *this = *this + other;
    return *this;
}

std::istream &operator>>(std::istream &stream, BigInteger &value)
{
    std::string str;
    stream >> str;
    value = BigInteger(str);
    return stream;
}

BigInteger BigInteger::operator-() const
{
    BigInteger res(*this);
    res.sign = !res.sign;
    return res;
}

BigInteger &BigInteger::operator++()
{
    *this += 1;
    return *this;
}

BigInteger &BigInteger::operator--()
{
    *this -= 1;
    return *this;
}

BigInteger BigInteger::operator++(int)
{
    BigInteger tmp(*this);
    *this += 1;
    return tmp;
}

BigInteger BigInteger::operator--(int)
{
    BigInteger tmp(*this);
    *this -= 1;
    return tmp;
}

BigInteger operator%(const BigInteger &left, const BigInteger &right)
{
    BigInteger div = left / right;
    return left - (div * right);
}

BigInteger operator+(const BigInteger &left, const BigInteger &right)
{
    bool signFlag = false;
    BigInteger tmpL(left), tmpR(right), zero(0);

    if (tmpL < zero && tmpR < zero)
    {
        tmpL = -tmpL;
        tmpR = -tmpR;
        signFlag = true;
    }
    else if (tmpL < zero)
    {
        return tmpR - (-tmpL);
    }
    else if (tmpR < zero)
    {
        return tmpL - (-tmpR);
    }

    // для двух неотрицательных чисел
    int carry = 0; // флаг переноса
    size_t max_size = std::max(tmpL.bigInt.size(), tmpR.bigInt.size());
    for (size_t i = 0; i < max_size || carry; i++)
    {
        if (i == tmpL.bigInt.size())
        {
            tmpL.bigInt.push_back(0);
        }
        tmpL.bigInt[i] += carry;
        if (i < tmpR.bigInt.size())
        {
            tmpL.bigInt[i] += tmpR.bigInt[i];
        }
        carry = tmpL.bigInt[i] >= base; // система счисления
        if (carry)
        {
            tmpL.bigInt[i] -= base;
        }
    }

    tmpL.sign = signFlag;
    return tmpL;
}

BigInteger operator-(const BigInteger &left, const BigInteger &right)
{
    bool signFlag = false;
    BigInteger tmpL(left), tmpR(right), zero(0);

    if (tmpL < zero && tmpR < zero)
    {
        tmpL = -tmpL;
        tmpR = -tmpR;
        signFlag = true;
    }
    else if (tmpR < zero)
    {
        return tmpL + (-tmpR);
    }
    else if (tmpL < zero)
    {
        return -(-tmpL + tmpR);
    }

    // два неотрицательных числа
    if (tmpR > tmpL)
    {
        std::swap(tmpR, tmpL);
        signFlag = true;
    }

    // left >= right // left - right
    int carry = 0; // флаг переноса
    for (size_t i = 0; i < tmpR.bigInt.size() || carry; i++)
    {
        int tmpDigit = tmpL.bigInt[i];
        tmpDigit -= carry;

        if (i < tmpR.bigInt.size())
        {
            tmpDigit -= tmpR.bigInt[i];
        }

        carry = tmpDigit < 0;

        if (carry)
        {
            tmpDigit += base;
        }

        tmpL.bigInt[i] = static_cast<int>(tmpDigit);
    }

    eraseZeros(tmpL.bigInt);
    tmpL.sign = signFlag;
    return tmpL;
}

BigInteger operator*(const BigInteger &left, const BigInteger &right)
{
    size_t rightSize = right.bigInt.size();
    size_t leftSize = left.bigInt.size();

    BigInteger res;
    res.bigInt.resize(leftSize + rightSize);

    for (size_t i = 0; i < left.bigInt.size(); i++)
    {
        int carry = 0;
        for (size_t j = 0; j < rightSize || carry; j++)
        {
            int tmp = res.bigInt[i + j] + carry;
            if (j < rightSize)
            {
                tmp += left.bigInt[i] * right.bigInt[j];
            }
            res.bigInt[i + j] = tmp % base;
            carry = tmp / base;
        }
    }

    eraseZeros(res.bigInt);
    res.sign = (left.sign ^ right.sign);
    return res;
}

BigInteger operator/(const BigInteger &left, const int &right)
{
    if (right == 0)
    {
        std::cerr << "Деление на ";
        return 0;
    }
    BigInteger tmpL(left);
    int carry = 0;
    int size = tmpL.bigInt.size();

    for (int i = size - 1; i >= 0; i--)
    {
        int cur = tmpL.bigInt[i] + carry * base;
        tmpL.bigInt[i] = cur / right;
        carry = cur % right;
    }

    while (size > 1 && tmpL.bigInt.back() == 0)
    {
        tmpL.bigInt.pop_back();
        size--;
    }

    return right < 0 ? -tmpL : tmpL;
}

BigInteger operator/(const BigInteger &left, const BigInteger &right)
{
    if (right == 0)
    {
        std::cerr << "Деление на ";
        return 0;
    }
    if (right == 2)
    {
        return left / 2;
    }

    bool resultSign = (left.sign) ^ (right.sign);

    BigInteger tmpL(left), tmpR(right), zero(0);
    tmpL.sign = false;
    tmpR.sign = false;

    if (tmpL < tmpR)
    {
        return zero;
    }

    if (tmpL == tmpR)
    {
        BigInteger unit = 1;
        unit.sign = resultSign;
        return unit;
    }

    BigInteger top = tmpL / 2;
    BigInteger bottom = zero;

    while (top > bottom)
    {
        BigInteger middle = (top + bottom) / 2;
        BigInteger multiply = middle * tmpR;

        if (multiply < tmpL)
        {
            if ((middle + 1) * tmpR > tmpL)
            {
                eraseZeros(middle.bigInt);
                middle.sign = resultSign;
                return middle;
            }
            bottom = middle;
        }
        else if (multiply > tmpL)
        {
            top = middle;
        }
        else
        {
            eraseZeros(middle.bigInt);
            middle.sign = resultSign;
            return middle;
        }
    }

    // убираем лишние нули
    eraseZeros(bottom.bigInt);
    bottom.sign = resultSign;
    return bottom;
}
