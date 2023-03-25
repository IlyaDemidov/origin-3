#include <iostream>
#include <utility>
#include <vector>

template <typename T>
void move_vectors(std::vector<T>& one, std::vector<T>& two)
{
    one = std::move(two);
}

int main()
{
    std::vector <std::string> one = { "test_string1", "test_string2" };
    std::vector <std::string> two;

    move_vectors(two, one);

    std::vector <int> three{ 1,2,1,4 };
    std::vector <int> four;

    move_vectors(four, three);


    std::cout << "\n";
    system("pause");

    return 0;
}