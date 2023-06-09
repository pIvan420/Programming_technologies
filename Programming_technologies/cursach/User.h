#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include "DietUser.h"


class User {
private:
    std::string name; // Имя пользователя
    double height; // Рост
    int weight; // Вес
    double BMI; // ИМТ
    DietUser dietType; //Диета

public:
    User(std::string name, double height, int weight, std::string dietName, int days);
    User(std::string name, double height, int weight, std::string dietName, std::string dayFirst, std::string dayLast);
    ~User();
    std::string getName();
    double getHeight();
    int getWeight();
    void setWeight(int weight1);
    double getBMI();
    DietUser getDietType();
    void save(); //Сохранение файла
    int final(); //Удаление файла при окончании диеты (дополнительно выводит результат худения)
};