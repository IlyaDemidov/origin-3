#include <iostream>
#include <vector>

template <typename T>
void print_vector(std::vector<T> x)
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

template<typename T>
std::vector<T> my_sgr(std::vector<T> x)
{
    std::vector<T>y;
    for (const int& i : x) { y.push_back(i * i); }
    return y;
}

int main()
{
    double var{ 4 };
    std::cout << "[IN]: " << var << "\n";
    std::cout << "[OUT]: " << my_sgr(var) << "\n";
    
    std::vector<double>vec{ -1, 4, 8 };
    std::cout << "[IN]: ";
    print_vector(vec);
    
    std::cout << "[OUT]: ";
    print_vector(my_sgr(vec));
      


    std::cout << "\n";
    system("pause");
    return 0;
}