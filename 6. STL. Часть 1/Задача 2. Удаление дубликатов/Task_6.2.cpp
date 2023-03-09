#include <iostream>
#include <set>
#include <conio.h>

int main()
{
	std::set<int> list;
	int Size{ 0 };
	
	std::cout << "[IN]:" << "\n";
	std::cin >> Size;

	for (size_t i = 0; i < Size; i++)
	{
		int x{ 0 }; std::cin >> x;
		list.insert(x);
	}

	std::cout << "[OUT]:" << "\n";
	for (auto it = list.rbegin(); it != list.rend(); ++it)
		std::cout << *it << '\n';

	
	std::cout << "\n";
	system("pause");
	return 0;
}