#include <iostream>

class Product
{
protected:
	char* product_type;

private:
	char* product_name;
	double product_cost;

public:
	// Access methods
	const char* get_product_type()const { return this->product_type; }
	const char* get_product_name()const { return this->product_name; }
	double get_product_cost()const { return this->product_cost; }

	virtual void set_product_type(char* product_type = nullptr)
	{
		
		int type_size = 0;
		if (product_type)
		{
			type_size = strlen(product_type) + 1;
			this->product_type = new char[type_size] {};
			for (int i = 0; i < type_size; i++) this->product_type[i] = product_type[i];
			this->product_type[type_size - 1] = '\0';
		}
		else
		{
			char name[] = {'N','e','w',' ','t','y','p','e','\0'};
			type_size = 9;
			this->product_type = new char[type_size] {};
			for (int i = 0; i < type_size; i++) this->product_type[i] = name[i];
		}
		
	}
	
	void set_product_name(char* product_name = nullptr)
	{
		int name_size = 0;
		if (product_name)
		{
			name_size = strlen(product_name) + 1;
			this->product_name = new char[name_size] {};
			for (int i = 0; i < name_size; i++) this->product_name[i] = product_name[i];
			this->product_name[name_size - 1] = '\0';
		}
		else
		{
			char name[] = { 'T','e','s','t',' ','p','r','o','d','u','c','t','\0' };
			name_size = 13;
			this->product_name = new char[name_size] {};
			for (int i = 0; i < name_size; i++) this->product_name[i] = name[i];
		}
	}
	void set_product_cost(double product_cost) { this->product_cost = product_cost; }


	// Constructors
	Product(char* product_type)
	{
		this->set_product_type(product_type);
		this->set_product_name(product_name);
		this->product_cost = 0;
	}

	Product(char* product_type = nullptr, char* product_name = nullptr, double product_cost = 0)
	{
		this->set_product_type(product_type);
		this->set_product_name(product_name);
		this->product_cost = product_cost;
	}

	Product(const Product& other)
	{
		this->set_product_type(other.product_type);
		this->set_product_name(other.product_name);
		this->set_product_cost(other.product_cost);
	}

	Product(Product&& other)
	{
		this->set_product_type(other.product_type);
		this->set_product_name(other.product_name);
		this->set_product_cost(other.product_cost);

		other.product_type = nullptr;
		other.product_name = nullptr;
	}

	virtual ~Product()
	{
		delete[] this->product_type;
		delete[] this->product_name;
	}

	// Operators
	Product& operator=(const Product& other)
	{
		if (this == &other) return *this;

		delete[] this->product_type;
		delete[] this->product_name;
		this->product_type = other.product_type;
		this->product_name = other.product_name;
		this->set_product_cost(other.product_cost);
		return *this;
	}

	Product& operator=(Product&& other)
	{
		if (this == &other) return *this;

		delete[] this->product_type;
		delete[] this->product_name;
		this->product_type = other.product_type;
		this->product_name = other.product_name;
		this->set_product_cost(other.product_cost);

		other.product_type = nullptr;
		other.product_name = nullptr;

		return *this;
	}

	// Methods
	virtual void work() {};

	virtual void print()
	{
		std::cout << "Type of this product is : " << "\"" << this->get_product_type() << std::endl <<
			"The product is named: " << "\"" << this->get_product_name() <<
			"\"" << "; and costs: " << this->get_product_cost() << "$" << std::endl << std::endl;
	}
};

class Computer :public Product
{
private:

public:
	// Access methods
	void set_product_type(char* product_type = nullptr) override
	{
		char name[] = { 'C','o','m','p','u','t','e','r','\0' };
		int type_size = 9;
		this->product_type = new char[type_size] {};
		for (int i = 0; i < type_size; i++) this->product_type[i] = name[i];
		
	}

	// Constructors
	Computer(char* product_type = nullptr, char* product_name = nullptr, double product_cost = 0):Product(product_type = nullptr, product_name = nullptr, product_cost = 0)
	{
		this->set_product_type();

	}
	
	~Computer()	{}


	// Operators
	operator Product()
	{
		return *this;
	}

	// Methods
	void work() override { std::cout << "The computer can do calculations!" << std::endl; }

	void print() override
	{
		Product::print();
		this->work();
		std::cout << std::endl;
	}
};

class Machine :public Product
{
private:

public:
	// Access methods
	void set_product_type(char* product_type = nullptr) override
	{
		char name[] = { 'M','a','c','h','i','n','e','\0' };
		int type_size = 8;
		this->product_type = new char[type_size] {};
		for (int i = 0; i < type_size; i++) this->product_type[i] = name[i];

	}

	// Constructors
	Machine(char* product_type = nullptr, char* product_name = nullptr, double product_cost = 0) :Product(product_type = nullptr, product_name = nullptr, product_cost = 0)
	{
		this->set_product_type();
	}

	~Machine() {}

	// Operators
	operator Product()
	{
		return *this;
	}

	// Methods
	void work() override { std::cout << "The machine can produce products!" << std::endl; }

	void print() override
	{
		Product::print();
		this->work();
		std::cout << std::endl;
	}
};

class Creator
{

public:
	virtual ~Creator() {}

	virtual Product factoryMethod() = 0;

	Product createOperation()
	{
		Product product = this->factoryMethod();
		return product;
	}
	
};

class Computer_Сreator :public Creator
{
private:
	Computer computer;
public:
	// Constructors
	Computer_Сreator() {};

	// Operators
	operator Computer()
	{
		return *this;
	}

	// Methods
	Product factoryMethod()
	{
		this->computer.work();
		return this->computer;
	}
};

class Machine_Creator :public Creator
{
private:
	Machine machine;
public:
	// Constructors
	Machine_Creator() {}

	// Operators
	operator Machine()
	{
		return *this;
	}

	// Methods
	Product factoryMethod()
	{
		this->machine.work();
		return this->machine;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	Computer_Сreator* computer_creator = new Computer_Сreator;
	Machine_Creator* machine_creator = new Machine_Creator;

	computer_creator->createOperation().print();

	machine_creator->createOperation().print();

	delete computer_creator;
	delete machine_creator;
}