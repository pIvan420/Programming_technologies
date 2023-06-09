#include "User.h"
#include "DB.cpp"
#include <cstdio>
#include <filesystem>

User::User(std::string name, double height, int weight, std::string dietName, int days)
    : name(name), height(height), weight(weight), dietType(dietName, days)
{
    DB db;
    BMI = weight / pow(height / 100, 2);
    std::ofstream outputFile(db.getUserPath());
    if (outputFile) {
        // Записываем данные пользователя
        outputFile << name << endl;
        outputFile << height << endl;
        outputFile << weight << endl;
        outputFile << dietType.getName() << endl;
        outputFile << dietType.getDayFirst() << endl;
        outputFile << dietType.getDayLast() << endl;
        outputFile << BMI << endl;
        outputFile << weight << endl;
        outputFile.close();
    } else {
        std::cout << "Ошибка при создании файла\n";
    }
}

User::User(std::string name, double height, int weight, std::string dietName, std::string dayFirst, std::string dayLast)
    : name(name), height(height), weight(weight), dietType(dietName, dayFirst, dayLast)
{
    BMI = weight / pow(height / 100, 2);
}

User::~User() {}

std::string User::getName(){ //вывод имени
    return name;
}

double User::getHeight(){ //вывод роста
    return height;
}

void User::setWeight(int weight1){ //ввод веса
    weight = weight1;
    BMI = weight / pow(height / 100, 2);
}

int User::getWeight(){ //вывод веса
    return weight;
}

double User::getBMI(){ //вывод ИМТ
    return BMI;
}

DietUser User::getDietType(){ //вывод класса диеты
    return dietType;
}

void User::save(){
    DB db;
    std::ifstream inputFile(db.getUserPath());
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
    lines[2] = std::to_string(weight);
    lines[6] = std::to_string(BMI);
    std::ofstream outputFile(db.getUserPath());
    for (const std::string& updatedLine : lines) {
        outputFile << updatedLine << std::endl;
    }
    outputFile.close();
}

int User::final(){
    DB db;
    int weightStart;
    int weightFinal;
    std::ifstream inputFile(db.getUserPath());
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();
    weightStart = std::stoi(lines[7]);
    weightFinal = std::stoi(lines[2]);
    const char* filename = db.getUserPath().c_str();
    std::ofstream file(filename, std::ios::out | std::ios::trunc); //удаление всего из файла
    file.close();
    std::ofstream file1(filename);
    file1 << "1" << endl;
    file1.close();
    
    return weightStart - weightFinal;
}
