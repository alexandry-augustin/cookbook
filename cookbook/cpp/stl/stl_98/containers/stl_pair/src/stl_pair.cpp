#include <iostream>
#include <utility>
#include <string>

int main()
{
	std::pair<std::string, double> product1("product1", 3.25);

	std::pair<std::string, double> product2;
	product2.first = "product2";
	product2.second = 0.99;

	std::pair<std::string, double> product3;
	product3=std::make_pair("product3", 20.0);

	//cout << "The price of " << product1.first << " is $" << product1.second << endl;
	//cout << "The price of " << product2.first << " is $" << product2.second << endl;
	//cout << "The price of " << product3.first << " is $" << product3.second << endl;

	return 0;
}
