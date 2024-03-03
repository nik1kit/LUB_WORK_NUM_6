#include "BigInteger.h"
#include "BigRational.h"
#include <iostream>

int main()
{
    setlocale(LC_ALL, "ru");
    // Создание объектов BigInteger
    BigInteger num1 = 10;
    BigInteger num2 = -30;
    BigInteger num3 = 1;
    BigInteger num4 = -1;

    // Тестирование операций сложения, вычитания, умножения, деления и остатка
    BigInteger sum = num1 + num2;
    BigInteger diff = num1 - num2;
    BigInteger prod = num1 * num2;
    BigInteger div = num2 / num1;
    BigInteger mod = num2 % num1;

    // Тестирование унарного минуса
    BigInteger neg = -num1;

    // Тестирование инкремента и декремента
    num3--;
    num4++;
    BigInteger inc = num3;
    BigInteger dec = num4;

    // Тестирование операторов сравнения
    bool isEqual = (num1 == num2);
    bool isNotEqual = (num1 != num2);
    bool isLessThan = (num1 < num2);
    bool isGreaterThan = (num1 > num2);
    bool isLessThanOrEqual = (num1 <= num2);
    bool isGreaterThanOrEqual = (num1 >= num2);

    // Вывод результатов
    std::cout << "Сумма: " << sum.toString() << std::endl;
    std::cout << "Разность: " << diff.toString() << std::endl;
    std::cout << "Произведение: " << prod.toString() << std::endl;
    std::cout << "Частное: " << div.toString() << std::endl;
    std::cout << "Остаток: " << mod.toString() << std::endl;
    std::cout << "Отрицание: " << neg.toString() << std::endl;
    std::cout << "Инкремент: " << inc.toString() << std::endl;
    std::cout << "Декремент: " << dec.toString() << std::endl;
    std::cout << "Равно: " << isEqual << std::endl;
    std::cout << "Не равно: " << isNotEqual << std::endl;
    std::cout << "Меньше: " << isLessThan << std::endl;
    std::cout << "Больше: " << isGreaterThan << std::endl;
    std::cout << "Меньше или равно: " << isLessThanOrEqual << std::endl;
    std::cout << "Больше или равно: " << isGreaterThanOrEqual << std::endl;
    std::cout << num1 - 10 << std::endl;
    std::cout << num1 / 0 << std::endl;

    std::cout << "------------------------------------------------" << std::endl;

    BigRational num01 = 4;
    BigRational num02(3, 7);
    BigRational num03(-2, 5);

    // Простые тесты операторов
    BigRational sum01 = num01 + num02;
    BigRational sum02 = num01 + 2;
    BigRational sum03 = 5 + num01;

    BigRational diff01 = num01 - num02;
    BigRational diff02 = num01 - 2;
    BigRational diff03 = 5 - num01;

    BigRational mul01 = num01 * num02;
    BigRational mul02 = num01 * 2;
    BigRational mul03 = 5 * num01;

    BigRational div01 = num01 / num02;
    BigRational div02 = num01 / 2;
    BigRational div03 = 5 / num01;

    bool comp01 = (num01 == num02);
    bool comp02 = (num01 != num02);
    bool comp03 = (num01 < num02);
    bool comp04 = (num01 > num02);
    bool comp05 = (num01 <= num02);
    bool comp06 = (num01 >= num02);

    // Вывод результата
    std::cout << "num01: " << num01.toString() << std::endl;
    std::cout << "num02: " << num02.toString() << std::endl;
    std::cout << "num03: " << num03.toString() << std::endl;
    std::cout << "sum01: " << sum01.toString() << std::endl;
    std::cout << "sum02: " << sum02.toString() << std::endl;
    std::cout << "sum03: " << sum03.toString() << std::endl;
    std::cout << "diff01: " << diff01.toString() << std::endl;
    std::cout << "diff02: " << diff02.toString() << std::endl;
    std::cout << "diff03: " << diff03.toString() << std::endl;
    std::cout << "mul01: " << mul01.toString() << std::endl;
    std::cout << "mul02: " << mul02.toString() << std::endl;
    std::cout << "mul03: " << mul03.toString() << std::endl;
    std::cout << "div01: " << div01.toString() << std::endl;
    std::cout << "div02: " << div02.toString() << std::endl;
    std::cout << "div03: " << div03.toString() << std::endl;
    std::cout << "comp01: " << (comp01 ? "true" : "false") << std::endl;
    std::cout << "comp02: " << (comp02 ? "true" : "false") << std::endl;
    std::cout << "comp03: " << (comp03 ? "true" : "false") << std::endl;
    std::cout << "comp04: " << (comp04 ? "true" : "false") << std::endl;
    std::cout << "comp05: " << (comp05 ? "true" : "false") << std::endl;
    std::cout << "comp06: " << (comp06 ? "true" : "false") << std::endl;
    std::cout << "decimal: " << num02.asDecimal(5) << std::endl;
    return 0;
}
