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
		if(index < 0 || index > c_size - 1) throw std::out_of_range(" Индекс вне диапазона ");

		return c_array[index];
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
		arr.add_element(14);
		arr.add_element(15);
	
		std::cout << arr.get_element(2) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}


    std::cout << "\n";
    system("pause");

    return 0;
}
