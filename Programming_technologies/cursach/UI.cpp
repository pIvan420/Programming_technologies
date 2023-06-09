#include <iostream>
#include <string>
#include <fstream>
#include "User.h"
#include "DB.cpp"
using namespace std;

User* Registration();
User* SignIn();
void Information(User* user);
void Final(User* user);


int main()
{
	DB db;
	string answer;
	User* user;
	cout << "Приветствуем в программе диеты!" << endl;
	ifstream userFile;
	userFile.open(db.getUserPath()); // старт потока
	if (!userFile) { // срабатывает если файла пользователя не найдено (новый пользователь)
		user = Registration();
	}
	else { // срабатывает, если файл пользователя есть
	    string check;
	    getline(userFile, check);
	    userFile.close();
	    if(check == "1"){
	        user = Registration();
	    }
	    else{
	        user = SignIn();
	    }
	}
	if (user->getDietType().isOver()){ //проверка на закончилась ли диета
	    Final(user);
	}
	else{
	    Information(user);
	}
}

User* Registration() {
	DB db;
	string answer; // строка ответа на вопросы
	string login;
	string height;
	string weight;
	string diet;
	string days;
	cout << "Вы новенький? Давайте зарегистрируемся!" << endl;
	while (true) {
		cout << "Введите логин (от 2-х символов): ";
		cin >> login;
		if (login.length() < 4) {
			cout << "Ошибка, логин меньше 2-х символов.\nЗаполните форму еще раз.";
			continue;
		}
		break;
	}
	while (true) { // рост
		cout << "Введите рост в см: ";
		try {
			cin >> height;
			if (stod(height) < 100 || stod(height) > 210) {
				cout << "Ошибка, некорректный рост. Дозволенный рост от 100 до 210 см. Заполните форму еще раз.\n";
				continue;
			}
			break;
		}
		catch (exception& e) {
			cout << "Ошибка, некорректный рост. Заполните форму еще раз.\n";
			continue;
		}

	}
	while (true) {
		cout << "Введите вес в кг: ";
		try {
			cin >> weight;
			if (stoi(weight) < 15 || stoi(weight) > 300) {
				cout << "Ошибка, некорректный вес. Дозволенный вес от 15 до 300 кг. Заполните форму еще раз.\n";
				continue;
			}
			break;
		}
		catch (exception& e) {
			cout << "Ошибка, некорректный вес. Заполните форму еще раз.\n";
		}
	}
	bool flag = true;
	while (flag){ // выбор диеты + краткая информация
	    int dietNum;
    	while (true) {
    		cout << "Выберете номер диеты и прочитайте краткую информацию." << endl;
    		for (int i = 0; i < db.getCountDiets(); i++) {
    			cout << i + 1 << ")" << db.getDiet(i) << ";" << endl;
    		}
    		cout << "Введите номер диеты: ";
    		try {
    			cin >> dietNum;
    			if (dietNum < 1 || dietNum > db.getCountDiets()) {
    				cout << "Ошибка, такого номера не найдено. Заполните форму еще раз.\n";
    				continue;
    			}
    			break;
    		}
    		catch (exception& e) {
    			cout << "Ошибка, некорректный номер. Заполните форму еще раз.\n";
    		}
    	}
    	cout << db.getDescription(dietNum - 1); // вывод краткой информации о выбранной диете
    	while (true){
    	    cout << "Хотите выбрать " << db.getDiet(dietNum - 1) << "? (да, нет)\nОтвет: ";
    	    cin >> answer;
    	    if (answer == "да"){
    	        diet = db.getDiet(dietNum - 1);
    	        flag = false;
    	        break;
    	    }
    	    else if (answer == "нет"){
    	        break;
    	    }
    	    else{
    	        cout << "Извините, я не понял ваш ответ. Повторите ввод.\n";
    	    }
    	}
	}
	while (true) { // длительность диеты
		cout << "Введите продолжительность диеты (от 7 до 30 дней): ";
		try {
			cin >> days;
			if (stoi(days) < 7 || stoi(days) > 30) {
				cout << "Ошибка, некорректное число. Дозволенная продолжительность диеты от 7 до 30 дней. Заполните форму еще раз.\n";
				continue;
			}
			break;
		}
		catch (exception& e) {
			cout << "Ошибка, некорректное число. Заполните форму еще раз.\n";
		}
	}
	User* user = new User(login, stod(height), stoi(weight), diet, stoi(days));
	cout << "Пользователь успешно зарегистрирован!" << endl;
    return user;
}

User* SignIn() {
    DB db;
    ifstream userFile;
    userFile.open(db.getUserPath());
    string name;
	string height;
	string weight;
	string dietName;
	string dayFirst;
	string dayLast;
	getline(userFile, name);
	getline(userFile, height);
	getline(userFile, weight);
	getline(userFile, dietName);
	getline(userFile, dayFirst);
	getline(userFile, dayLast);
	userFile.close();
	User* user = new User(name, stod(height), stoi(weight), dietName, dayFirst, dayLast);
	cout << "Привет, " << user->getName() << endl;
	return user;
}

void Information(User* user) {
    string answer;
    while (true){
        cout << "\nЧто желаете сделать? Введите номер операции:" << endl;
        cout << "1)Узнать свой рост;\n2)Узнать свой вес;\n3)Ввести новый вес;\n4)Узнать свой ИМТ;\n5)Узнать название вашей диеты;\n" <<
        "6)Узнать дату начала диеты;\n7)Узнать дату окончания диеты;\n8)Узнать питание на сегодня;\n9)Узнать тренировку на сегодня;\n" <<
        "10)Выйти из программы.\n" << endl;
        cout << "Введите операцию: ";
        cin >> answer;
        if(answer == "1"){
           cout << "Ваш рост: " << user->getHeight() << " см.\n";
        }
        else if(answer == "2"){
            cout << "Ваш вес: " << user->getWeight() << " кг.\n";
        }
        else if(answer == "3"){
            string newWeight;
            while (true){
                try {
                    cout << "Введите новый вес: ";
                    cin >> newWeight;
                    if (stoi(newWeight) < 15 || stoi(newWeight) > 300) {
        				cout << "Ошибка, некорректный вес. Дозволенный вес от 15 до 300 кг. Заполните форму еще раз.\n";
        				continue;
    		    	}   
    		        break;
                }
                catch (exception& e) {
                    cout << "Ошибка, некорректный вес. Заполните форму еще раз.\n";
                }
            }
            user->setWeight(stoi(newWeight));
            cout << "Ваш новый вес введен!\n";
        }
        else if(answer == "4"){
            cout << "Ваш ИМТ: " << user->getBMI() << "\n";
            if (user->getBMI() < 18.5){
                cout << "У вас недовес.\n";
            }
            else if (user->getBMI() > 24.9){
                cout << "У вас перевес.\n";
            }
            else{
                cout << "Ваш вес оптимален.\n";
            }
        }
        else if(answer == "5"){
            cout << "Ваша диета: " << user->getDietType().getName() << endl;
        }
        else if(answer == "6"){
            cout << "Дата начала диеты: " << user->getDietType().getDayFirst() << endl;
        }
        else if(answer == "7"){
            cout << "Дата окончания диеты: " << user->getDietType().getDayLast() << endl;
        }
        else if(answer == "8"){
            cout << "Ваше питание на сегодня:\n" << user->getDietType().getNutrition() << endl;
        }
        else if(answer == "9"){
            cout << "Ваша тренировка на сегодня:\n" << user->getDietType().getWorkout() << endl;
        }
        else if(answer == "10"){
            user->save();
            cout << "Удачи!\n";
            break;
        }
        else{
            cout << "Извините, я не понял, что вы ввели. Повторите отправку сообщения.\n";
        }
    }
}

void Final(User* user){
    int weight;
    weight = user->final();
    cout << "Поздравляем с завершением диеты! Вы похудели на " << weight << " кг.\n";
    cout << "Удачи!";
}