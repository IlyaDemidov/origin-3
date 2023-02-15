#include <iostream>
#include <Windows.h>
#include <vector>
#include <algorithm>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector<int> arr{ 4, 7, 9, 14, 12 };

    auto my_print = [](const int& i) {std::cout << i << " "; };

    std::cout << "Входные данные: ";
    std::ranges::for_each(arr, my_print);

    
    std::ranges::for_each(arr, [](int& n) {if(n % 2 != 0) n*=3;});

    std::cout << "\nВыходные данные: ";
    std::ranges::for_each(arr, my_print);

    std::cout << "\n";
    system("pause");

    return 0;
}
