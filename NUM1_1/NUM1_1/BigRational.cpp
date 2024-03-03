#include "BigRational.h"
#include "BigInteger.h"

// КОНСТРУКТОРЫ
// Конструктор по умолчанию
BigRational::BigRational()
{
    numerator = BigInteger(0);
    denominator = BigInteger(1);
}

// Конструктор с числителем и знаменателем типа BigInteger
BigRational::BigRational(const BigInteger &num, const BigInteger &denom)
{
    // Проверка на нулевой знаменатель
    if (denom == BigInteger(0))
    {
        // Если знаменатель равен нулю, выбрасываем исключение или выполняем коррекцию
        throw std::invalid_argument("Denominator cannot be zero.");
    }

    // Выполнение коррекции, если необходимо
    if (denom < BigInteger(0))
    {
        numerator = -num;     // Числитель меняет знак
        denominator = -denom; // Знаменатель меняет знак
    }
    else
    {
        numerator = num;
        denominator = denom;
    }
}

// Конструктор с int числителем и знаменателем
BigRational::BigRational(const int &num, const int &denom)
{
    // Проверка на нулевой знаменатель
    if (denom == 0)
    {
        // Если знаменатель равен нулю, выбрасываем исключение или выполняем коррекцию
        throw std::invalid_argument("Denominator cannot be zero.");
    }

    // Выполнение коррекции, если необходимо
    if (denom < 0)
    {
        numerator = -num;     // Числитель меняет знак
        denominator = -denom; // Знаменатель меняет знак
    }
    else
    {
        numerator = num;
        denominator = denom;
    }
}

// Конструктор с целым числом
BigRational::BigRational(const BigInteger &num) : numerator(num), denominator(BigInteger(1))
{
}

// Конструктор с int числом
BigRational::BigRational(const int &num) : numerator(BigInteger(num)), denominator(BigInteger(1))
{
}

// ОПЕРАТОРЫ АРИФМЕТИЧЕСКИХ ОПЕРАЦИЙ
// Сложение BigRational с другим BigRational
BigRational BigRational::operator+(const BigRational &other) const
{
    BigInteger newNum = numerator * other.denominator + other.numerator * denominator;
    BigInteger newDenom = denominator * other.denominator;
    return BigRational(newNum, newDenom);
}

// Сложение BigRational с BigInteger
BigRational BigRational::operator+(const BigInteger &other) const
{
    BigInteger newNum = numerator + other * denominator;
    return BigRational(newNum, denominator);
}

// Сложение BigRational с int
BigRational BigRational::operator+(const int &other) const
{
    BigInteger newNum = numerator + other * denominator;
    return BigRational(newNum, denominator);
}

BigRational operator+(const int &lhs, const BigRational &rhs)
{
    return BigRational(lhs) + rhs;
}

// Вычитание BigRational из другого BigRational
BigRational BigRational::operator-(const BigRational &other) const
{
    BigInteger newNum = numerator * other.denominator - other.numerator * denominator;
    BigInteger newDenom = denominator * other.denominator;
    return BigRational(newNum, newDenom);
}

// Вычитание BigInteger из BigRational
BigRational BigRational::operator-(const BigInteger &other) const
{
    BigInteger newNum = numerator - other * denominator;
    return BigRational(newNum, denominator);
}

// Вычитание int из BigRational
BigRational BigRational::operator-(const int &other) const
{
    BigInteger newNum = numerator - other * denominator;
    return BigRational(newNum, denominator);
}

BigRational operator-(const int &lhs, const BigRational &rhs)
{
    return BigRational(lhs) - rhs;
}
// Умножение BigRational на другой BigRational
BigRational BigRational::operator*(const BigRational &other) const
{
    BigInteger newNum = numerator * other.numerator;
    BigInteger newDenom = denominator * other.denominator;
    return BigRational(newNum, newDenom);
}

// Умножение BigRational на BigInteger
BigRational BigRational::operator*(const BigInteger &other) const
{
    BigInteger newNum = numerator * other;
    return BigRational(newNum, denominator);
}

// Умножение BigRational на int
BigRational BigRational::operator*(const int &other) const
{
    BigInteger newNum = numerator * other;
    return BigRational(newNum, denominator);
}

BigRational operator*(const int &lhs, const BigRational &rhs)
{
    return BigRational(lhs) * rhs;
}

// Деление BigRational на другой BigRational
BigRational BigRational::operator/(const BigRational &other) const
{
    BigInteger newNum = numerator * other.denominator;
    BigInteger newDenom = denominator * other.numerator;
    return BigRational(newNum, newDenom);
}

// Деление BigRational на BigInteger
BigRational BigRational::operator/(const BigInteger &other) const
{
    BigInteger newDenom = denominator * other;
    return BigRational(numerator, newDenom);
}

// Деление BigRational на int
BigRational BigRational::operator/(const int &other) const
{
    BigInteger newDenom = denominator * other;
    return BigRational(numerator, newDenom);
}

BigRational operator/(const int &lhs, const BigRational &rhs)
{
    return BigRational(lhs) / rhs;
}

// Унарный минус
BigRational BigRational::operator-() const
{
    return BigRational(-numerator, denominator);
}

// ОПЕРАТОРЫ ПРИСВАИВАНИЯ
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
    denominator = 1; // Целое число, знаменатель равен 1
    return *this;
}

BigRational &BigRational::operator=(const int &other)
{
    numerator = other;
    denominator = 1; // Целое число, знаменатель равен 1
    return *this;
}

// ОПЕРАТОРЫ СРАВНЕНИЯ
bool BigRational::operator==(const BigRational &other) const
{
    // Проверяем равенство числителей и знаменателей
    return numerator == other.numerator && denominator == other.denominator;
}

bool BigRational::operator==(const BigInteger &other) const
{
    // Проверяем, что знаменатель равен 1, т.е. число целое, и числитель равен другому BigInteger
    return denominator == 1 && numerator == other;
}

bool BigRational::operator==(const int &other) const
{
    // Проверяем, что знаменатель равен 1, т.е. число целое, и числитель равен другому целому числу
    return denominator == 1 && numerator == other;
}
bool BigRational::operator!=(const BigRational &other) const
{
    // Используем оператор == для проверки равенства, затем инвертируем результат
    return !(*this == other);
}

bool BigRational::operator!=(const BigInteger &other) const
{
    // Используем оператор == для проверки равенства, затем инвертируем результат
    return !(*this == other);
}

bool BigRational::operator!=(const int &other) const
{
    // Используем оператор == для проверки равенства, затем инвертируем результат
    return !(*this == other);
}
bool BigRational::operator<(const BigRational &other) const
{
    // Преобразуем оба числа к общему знаменателю и сравниваем числители
    BigInteger this_num = numerator * other.denominator;
    BigInteger other_num = other.numerator * denominator;
    return this_num < other_num;
}

bool BigRational::operator<(const BigInteger &other) const
{
    // Преобразуем числитель к BigInteger и сравниваем его с другим числом
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num < other_num;
}

bool BigRational::operator<(const int &other) const
{
    // Преобразуем числитель к BigInteger и сравниваем его с другим числом
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num < other_num;
}

bool BigRational::operator>(const BigRational &other) const
{
    // Преобразуем оба операнда к BigInteger и сравниваем их
    BigInteger this_num = numerator * other.denominator;
    BigInteger other_num = other.numerator * denominator;
    return this_num > other_num;
}

bool BigRational::operator>(const BigInteger &other) const
{
    // Преобразуем текущий объект BigRational к BigInteger и сравниваем с other
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num > other_num;
}

bool BigRational::operator>(const int &other) const
{
    // Преобразуем текущий объект BigRational к BigInteger и сравниваем с other
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num > other_num;
}

bool BigRational::operator<=(const BigRational &other) const
{
    // Преобразуем оба числа к общему знаменателю и сравниваем числители
    BigInteger this_num = numerator * other.denominator;
    BigInteger other_num = other.numerator * denominator;
    return this_num <= other_num;
}

bool BigRational::operator<=(const BigInteger &other) const
{
    // Преобразуем числитель к BigInteger и сравниваем его с другим числом
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num <= other_num;
}

bool BigRational::operator<=(const int &other) const
{
    // Преобразуем числитель к BigInteger и сравниваем его с другим числом
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num <= other_num;
}

bool BigRational::operator>=(const BigRational &other) const
{
    // Преобразуем оба операнда к BigInteger и сравниваем их
    BigInteger this_num = numerator * other.denominator;
    BigInteger other_num = other.numerator * denominator;
    return this_num >= other_num;
}

bool BigRational::operator>=(const BigInteger &other) const
{
    // Преобразуем текущий объект BigRational к BigInteger и сравниваем с other
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num >= other_num;
}

bool BigRational::operator>=(const int &other) const
{
    // Преобразуем текущий объект BigRational к BigInteger и сравниваем с other
    BigInteger this_num = numerator;
    BigInteger other_num = other * denominator;
    return this_num >= other_num;
}

// GCD SIMPLIFY
// Реализация метода для сокращения дроби
void BigRational::simplify()
{
    BigInteger common_divisor = gcd(numerator, denominator);
    numerator /= common_divisor;
    denominator /= common_divisor;
}

// Реализация метода для нахождения НОД
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
        return numerator.toString(); // Если знаменатель равен 1, возвращаем только числитель
    }
    else
    {
        return numerator.toString() + "/" + denominator.toString();
        // Иначе возвращаем строку вида "числитель/знаменатель"
    }
}

// ASDECIMAL
std::string BigRational::asDecimal(size_t precision) const
{
    // Проверка наличия целого значения
    if (denominator == 1)
    {
        return numerator.toString(); // Если знаменатель равен 1, вернуть только числитель
    }
    else
    {
        // Вычисление десятичной дроби
        BigInteger integralPart = numerator / denominator;   // Целая часть
        BigInteger fractionalPart = numerator % denominator; // Дробная часть
        std::string decimal = integralPart.toString() + "."; // Строка для хранения десятичной дроби

        // Вычисление дробной части с заданной точностью
        for (size_t i = 0; i < precision; ++i)
        {
            fractionalPart *= 10; // Умножение дробной части на 10 для получения следующей цифры
            BigInteger digit = fractionalPart / denominator; // Вычисление очередной цифры
            decimal += digit.toString();                     // Добавление цифры к строке
            fractionalPart %= denominator;                   // Оставляем только остаток для следующей итерации
        }

        return decimal;
    }
}

// ПРИВЕДЕНИЕ К DOUBLE
BigRational::operator double() const
{
    double result = static_cast<double>(numerator); // Преобразование числителя в тип double
    result /= static_cast<double>(denominator);     // Деление на знаменатель
    return result;
}
