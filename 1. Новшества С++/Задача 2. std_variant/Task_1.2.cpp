#include <iostream>
#include <variant>
#include <vector>
#include <algorithm>

std::variant<int, std::string, std::vector<int>> get_variant() 
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

void foo(std::variant <int, std::string, std::vector<int>> x)
{
	if(std::holds_alternative<int>(x)) std::cout << std::get<int>(x)*2 << "\n";
	if (std::holds_alternative<std::string>(x)) std::cout << std::get<std::string>(x) << "\n";
	if (std::holds_alternative<std::vector<int>>(x)) std::ranges::for_each(std::get<std::vector<int>>(x), [](const int& i) {std::cout << i << " "; }) ;
}

int main()
{
	foo(get_variant());
    
	std::cout << "\n";
	system("pause");
	return 0;
}