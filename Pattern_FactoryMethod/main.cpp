#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Product
{
private:
	char* product_name;
	double product_cost;

public:
	// Access methods
	char* get_product_name() { return this->product_name; }
	double get_product_cost() { return this->product_cost; }

	void set_product_name(char* product_name) { this->product_name = product_name; }
	void set_product_cost(double product_cost) { this->product_cost = product_cost; }

	// Constructors
	Product(char* product_name = "Test product", double product_cost = 0)


	Product create_product()=0;
};

void main()
{
	setlocale(LC_ALL, "");


}