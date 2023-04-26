#pragma once
#include <iostream>
#include <string>
using namespace std;

class Watch2
{
private:
	string name;
	int price;
	string country;
	bool operator<(Watch2 ww2); //это для 6 задания
	static int count;
public:
	Watch2(string name, int price, string country);
	~Watch2();
	string get_name();
	int get_price();
	string get_country();
	static int get_count();
	friend Watch2 get_most_expensive_watch(Watch2** Watches, int length);
	friend Watch2 get_most_expensive_watch(Watch2** Watches1, Watch2** Watches2, int length);
};