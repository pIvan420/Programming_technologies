#include <iostream>
using namespace std;


int main1()
{
    setlocale(LC_ALL, "");

    int firstNum, secondNum;
    char operation;
    int flag = 0;
    while (true) {
        if (flag == 0) { //условие для ввода числа, а не продолжения операции
            cout << "Введите первое число: ";
            cin >> firstNum; //ввод первого числа
            flag = 1;
        }
        cout << "Введите арифметическую операцию (+, -, *, /): ";
        cin >> operation; //ввод арифметической операции
        if (operation == 'C') { //обнуление результата 
            flag = 0;
            continue;
        }
        if (operation == 'Q') { //выход из программы
            break;
        }
        cout << "Введите второе число: ";
        cin >> secondNum; //ввод второго числа
        switch (operation) //разветвлитель арифметических операций
        {
        case '+': firstNum += secondNum; cout << firstNum << "\n"; break;
        case '-': firstNum -= secondNum; cout << firstNum << "\n"; break;
        case '*': firstNum *= secondNum; cout << firstNum << "\n"; break;
        case '/': firstNum /= secondNum; cout << firstNum << "\n"; break;
        default: cout << "Вы ввели неверную операцию, повторите ввод";
        }
    }
    return 0;
}
