#pragma once
#include <iostream>
#include <string>
using namespace std;

class Watch
{
private:
	string name;
	int price;
	string country;
public:
	Watch(string name, int price, string country);
	~Watch();
	string get_name();
	int get_price();
	string get_country();
	friend Watch get_most_expensive_watch(Watch** Watches, int length);
};