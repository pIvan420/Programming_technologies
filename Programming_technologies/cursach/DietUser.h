#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <sstream>


class DietUser
{
private:
    std::string name;
    std::string dayFirst;
    std::string dayLast;
    std::string dayNow;
    std::string nutrition;
    std::string workout;

public:
    DietUser(std::string name, int days);
    DietUser(std::string name, std::string dayFirst, std::string dayLast);
    ~DietUser();
    std::string getName();
    std::string getDayFirst();
    std::string getDayLast();
    std::string getDayNow();
    std::string getNutrition();
    std::string getWorkout();
    bool isOver();
};