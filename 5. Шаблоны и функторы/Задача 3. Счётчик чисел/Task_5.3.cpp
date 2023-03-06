#include <iostream>
#include <vector>
#include <algorithm>

class Number_Counter
{
public:
    Number_Counter() :sum{ 0 }, count{0} {}
	
    const int& get_sum() const { return sum; }
    const int& get_count() const { return count; }

    void operator () (const std::vector<int>& vec)
    {
        std::for_each(vec.begin(), vec.end(), [this](const int& x) {if (x % 3 == 0) { set_count(); set_sum(x); } });
    }

private:
    int sum;
    int count;

    void set_count() { count++; }
    void set_sum(const int& x) { sum += x; }

};


int main()
{
    Number_Counter c;

    std::vector<int> vec{ 4, 1, 3, 6, 25, 54 };

    c(vec);

    std::cout << "[IN]: ";
    for (const int& i : vec) std::cout << i << " ";

    std::cout << "\n[OUT]: get_sum() = " << c.get_sum() << '\n';
    std::cout << "[OUT]: get_count() = " << c.get_count() << '\n';



    std::cout << "\n";
    system("pause");
    return 0;
}