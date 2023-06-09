#include "DietUser.h"
#include "DB.cpp"

DietUser::DietUser(std::string name, int days)
    : name(name)
{
    DB db;
    int day;
    int month;
    string strmonth;
    std::tm* timeinfo;
    const int secondsPerDay = 24 * 60 * 60;
    
    //ввод дня начала
    time_t first = time(0); 
    timeinfo = std::localtime(&first);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    strmonth = db.getMonth(month);
    std::ostringstream oss1;
    oss1 << day  << " " << strmonth;
    dayFirst = oss1.str();
    
    //ввод сегодняшнего дня
    time_t now = first;
    timeinfo = std::localtime(&now);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    strmonth = db.getMonth(month);
    std::ostringstream oss2;
    oss2 << day  << " " << strmonth;
    dayNow = oss2.str();
    
    //ввод дня окончания
    time_t last = first + days * secondsPerDay;
    timeinfo = std::localtime(&last);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    strmonth = db.getMonth(month);
    std::ostringstream oss3;
    oss3 << day  << " " << strmonth;
    dayLast = oss3.str();
    
    //ввод питания и тренировки
    size_t spacePos1 = dayFirst.find(' ');
    size_t spacePos2 = dayNow.find(' ');
    int day1 = stoi(dayFirst.substr(0, spacePos1));
    string month1 = dayFirst.substr(spacePos1 + 1);
    int day2 = stoi(dayNow.substr(0, spacePos2));
    string month2 = dayNow.substr(spacePos2 + 1);
    if (month1 == month2){
        nutrition = db.getNutrition((day2 - day1) % 7, name);
        workout = db.getWorkout((day2 - day1) % 7, name);
    }
    else{
        nutrition = db.getNutrition((day2 + (db.getDaysInMonth(month1) - day1)) % 7, name);
        workout = db.getWorkout((day2 + (db.getDaysInMonth(month1) - day1)) % 7, name);
    }

}

DietUser::DietUser(std::string name, std::string dayFirst, std::string dayLast)
    : name(name), dayFirst(dayFirst), dayLast(dayLast)
{
    DB db;
    int day;
    int month;
    string strmonth;
    std::tm* timeinfo;
    
    //ввод сегодняшнего дня
    time_t now = time(0);
    timeinfo = std::localtime(&now);
    day = timeinfo->tm_mday;
    month = timeinfo->tm_mon + 1;
    strmonth = db.getMonth(month);
    std::ostringstream oss2;
    oss2 << day  << " " << strmonth;
    dayNow = oss2.str();
    
    //ввод питания и тренировки
    size_t spacePos1 = dayFirst.find(' ');
    size_t spacePos2 = dayNow.find(' ');
    int day1 = stoi(dayFirst.substr(0, spacePos1));
    string month1 = dayFirst.substr(spacePos1 + 1);
    int day2 = stoi(dayNow.substr(0, spacePos2));
    string month2 = dayNow.substr(spacePos2 + 1);
    if (month1 == month2){
        nutrition = db.getNutrition((day2 - day1) % 7, name);
        workout = db.getWorkout((day2 - day1) % 7, name);
    }
    else{
        nutrition = db.getNutrition((day2 + (db.getDaysInMonth(month1) - day1)) % 7, name);
        workout = db.getWorkout((day2 + (db.getDaysInMonth(month1) - day1)) % 7, name);
    }
}

DietUser::~DietUser() {}

std::string DietUser::getDayFirst(){ //вывод дня начала диеты
    return dayFirst;
}

std::string DietUser::getDayLast(){ //вывод дня конца диеты
    return dayLast;
}

std::string DietUser::getDayNow(){ //вывод сегодняшнего дня диеты
    return dayNow;
}

std::string DietUser::getName(){ //вывод названия диеты
    return name;
}

std::string DietUser::getNutrition(){ //вывод питания
    return nutrition;
}

std::string DietUser::getWorkout(){ //вывод тренировки
    return workout;
}

bool DietUser::isOver(){
    DB db;
    
    //Ввод в отдельные переменные дня и месяца начала/сегодняшнего/конца худения
    size_t spacePos1 = dayLast.find(' ');
    size_t spacePos2 = dayNow.find(' ');
    size_t spacePos3 = dayFirst.find(' ');
    int day1 = stoi(dayLast.substr(0, spacePos1));
    string month1 = dayLast.substr(spacePos1 + 1);
    int day2 = stoi(dayNow.substr(0, spacePos2));
    string month2 = dayNow.substr(spacePos2 + 1);
    int day3 = stoi(dayFirst.substr(0, spacePos3));
    string month3 = dayFirst.substr(spacePos3 + 1);
    int monthLast = db.getMonth(month1);
    int monthNow = db.getMonth(month2);
    int monthFirst = db.getMonth(month3);
    
    //Логика окончания диеты
    if((monthNow >= monthFirst) || (monthNow == 0 && monthFirst == 11)){
        if(monthNow == monthLast){
            if(day1 > day2){
                return false;
            }
            else{
                return true;
            }
        }
        else if((monthLast - monthNow == 1) || (monthNow == 11 && monthLast == 0)){
            return false;
        }
        else
        {
            return true;
        }
    }
    else{
        return true;
    }
}