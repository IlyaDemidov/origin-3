#include <iostream>
#include <set>
#include <vector>
#include <list>


template <typename T>
void print_container(const T& t)
{
    for (const auto& i : t) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main()
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    print_container(test_set);

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    print_container(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    print_container(test_vector);
    
    
    
    std::cout << "\n";
    system("pause");
    return 0;
}