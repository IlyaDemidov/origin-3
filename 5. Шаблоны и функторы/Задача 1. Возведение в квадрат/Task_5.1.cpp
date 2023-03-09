#include <iostream>
#include <vector>

void print_vector(std::vector<int> x)
{
  for (int i = 0; i < x.size(); i++)
  {
    if (i == x.size() - 1) {std::cout << x[i] << std::endl; break;}
    std::cout << x[i] << ", ";
  }
}

template <typename T>
T my_sgr(T x)
{
    return x * x;
}

template<>
std::vector<int> my_sgr(std::vector<int> x)
{
    std::vector<int>y;
    for (const int& i : x) { y.push_back(i * i); }
    return y;
}

int main()
{
    int var{ 4 };
    std::cout << "[IN]: " << var << "\n";
    std::cout << "[OUT]: " << my_sgr(var) << "\n";
    
    std::vector<int>vec{ -1, 4, 8 };
    std::cout << "[IN]: ";
    print_vector(vec);
    
    std::cout << "[OUT]: ";
    print_vector(my_sgr(vec));
      


    std::cout << "\n";
    system("pause");
    return 0;
}