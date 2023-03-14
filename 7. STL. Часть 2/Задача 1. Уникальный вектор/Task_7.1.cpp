#include <iostream>
#include <vector>
#include <algorithm>

void killer_doubles(std::vector<int>& vec)
{
    std::sort(vec.begin(),vec.end());
    auto v = std::unique(vec.begin(), vec.end());
    vec.erase(v, vec.end());
}

void print_vec(const std::vector<int>& vec)
{
    for (const auto& i : vec) std::cout << i << " ";

    std::cout << '\n';
}

int main()
{
    std::vector<int> vec{ 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN]: "; 
    print_vec(vec);

    killer_doubles(vec);

    std::cout << "[OUT]: ";
    print_vec(vec);



    std::cout << "\n";
    system("pause");
    return 0;
}
