#include <string>
using namespace std;

template <class T>
class Watch7A
{
private:
	string name;
	T price;
	string manufacturer;
public:
	Watch7A(string name, T price, string manufacturer) {
		this->name = name;
		this->price = price;
		this->manufacturer = manufacturer;
	}
	~Watch7A() {}
	string get_name() {
		return name;
	}
	T get_price() {
		return price;
	}
	string get_manufacturer() {
		return manufacturer;
	}
};