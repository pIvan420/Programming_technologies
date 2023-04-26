#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace WatchNameSpace {
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
		friend Watch2 get_most_expensive_watch(Watch2** watches, int length) {
			Watch2* curWatch = watches[0];
			for (int i = 1; i < length; i++) {
				if (curWatch < watches[i]) {
					curWatch = watches[i];
				}
			}
			return *curWatch;
		}
		friend Watch2 get_most_expensive_watch(Watch2** watches1, Watch2** watches2, int length) {
			Watch2* curWatch = watches1[0];
			for (int i = 1; i < length; i++) {
				if (curWatch < watches1[i]) {
					curWatch = watches1[i];
				}
			}
			for (int i = 0; i < length; i++) {
				if (curWatch < watches2[i]) {
					curWatch = watches2[i];
				}
			}
			return *curWatch;
		}
	};
}