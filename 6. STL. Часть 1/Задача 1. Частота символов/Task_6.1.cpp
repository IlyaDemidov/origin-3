#include <map>
#include <algorithm>
#include <string>
#include <iostream>

void sort(std::map< char, int>& m)
{
    std::multimap<int, char> multi_m;

    for (auto& i : m) { multi_m.insert({ i.second, i.first });}
        
    for (auto it = multi_m.rbegin(); it != multi_m.rend(); ++it)
        std::cout << it->second << ": " << it->first << '\n';
}

int main()
{
    std::string str = "Hello world!!";

    std::map<char, int> freq;
    std::for_each(std::begin(str),std::end(str),[&freq](const char& c) {freq[c]++;});

    std::cout << "[IN]: " << str << std::endl;
    std::cout << "[OUT]:" << std::endl;

    sort(freq);
    
    std::cout << "\n";
    system("pause");
    return 0;
}