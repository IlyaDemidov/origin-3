#include <iostream>
#include<Windows.h>
#include<stdexcept>


class smart_array
{
public:
	smart_array(int size) : c_size(size), free_element(size) { c_array = new int[c_size]; };
	~smart_array() { delete[] c_array; };

	void add_element(int x)
	{
		if (free_element == 0) throw std::out_of_range(" Нехватает размерности массива ");

		c_array[c_size - free_element] = x;
		free_element--;
	}

	const int& get_element(int index) const
	{
		if (index < 0 || index > c_size - 1) throw std::out_of_range(" Индекс вне диапазона ");

		return c_array[index];
	}

	smart_array& operator=(smart_array& array)
	{
		if (this == &array) return *this;

		if (c_array) delete[] c_array;

		c_size = array.c_size;
		c_array = new int[c_size];

		for (int i = 0; i < c_size; ++i)
			c_array[i] = array.c_array[i];

		return *this;
	}

private:
	int* c_array = nullptr;
	int c_size{};
	int free_element{};
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try
	{
		smart_array arr(5);

		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);

		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}


	std::cout << "\n";
	system("pause");

	return 0;
}
