#include <iostream>
#include <vector>

template <typename T>
void my_sgr(T x)
{
    std::cout << "[IN]: " << x << "\n";
    std::cout << "[OUT]: " << x*x << "\n";
}

template<>
void my_sgr(std::vector<int> x)
{
    std::cout << "[IN]: ";
    for (int i = 0; i < x.size(); i++)
    {
        if (i == x.size() - 1) {std::cout << x[i] << std::endl; break;}
        std::cout << x[i] << ", ";
    }

    std::cout << "[OUT]: ";
    for (int i = 0; i < x.size(); i++)
    {
        if (i == x.size() - 1) { std::cout << x[i] * x[i] << std::endl; break; }
        std::cout << x[i] * x[i] << ", ";
    }
}

int main()
{
    my_sgr(4);
    my_sgr(std::vector<int>{ -1, 4, 8 });
        
      
    std::cout << "\n";
    system("pause");
    return 0;
}