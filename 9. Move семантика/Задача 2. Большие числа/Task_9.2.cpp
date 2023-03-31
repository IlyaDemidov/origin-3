
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

class big_integer
{
public:
	big_integer(const std::string& str) :long_number(str) {};

	big_integer(big_integer&& str) noexcept
	{
		std::swap(long_number, str.long_number);
	}

	big_integer& operator=(big_integer&& str) noexcept
	{
		if (&str == this) return *this;

		if (!long_number.empty()) long_number.clear();

		std::swap(long_number, str.long_number);


		return *this;
	}

	friend std::ostream& operator<< (std::ostream& out, const big_integer& b_i)
	{
		out << b_i.long_number;
		return out;
	}

	friend big_integer operator+(big_integer& a, big_integer& b)
	{
		auto x = a.transfor_string_deque(a.long_number);
		auto y = b.transfor_string_deque(b.long_number);

		std::deque<int>* z;

		x.size() < y.size() ? z = &x : z = &y;

		size_t i = x.size() - y.size();

		if (i < 0) i *= -1;

		while (i != 0)
		{
			z->push_front(0);
			i--;
		}

		std::transform(x.begin(), x.end(), y.begin(), x.begin(), std::plus<int>());

		for (size_t j = x.size() - 1; j >= 1; j--)
		{
			if(x[j] > 9)
			{
				x[j]-= 10;
				x[j - 1] ++;
			}
		}

		std::string str_out;
		for (const auto& c : x)
		{
			str_out += std::to_string(c);
		}
		

		return big_integer(str_out);
	}

	friend big_integer operator*(big_integer& a, int b)
	{
		auto x = a.transfor_string_deque(a.long_number);

		std::for_each(x.begin(), x.end(), [b](int& i) {i *= b; });

		for (size_t j = x.size() - 1; j >= 1; j--)
		{
			if (x[j] > 9)
			{
				int n{ 0 };
				while (x[j] > 9)
				{
					n++;
					x[j] -= 10;
				}

				x[j - 1]+= n;
			}
		}

		std::string str_out;
		for (const auto& c : x)
		{
			str_out += std::to_string(c);
		}


		return big_integer(str_out);
	}

private:
	std::string long_number;

	std::deque<int> transfor_string_deque(const std::string& str)
	{
		std::deque<int> arr;

		for(auto i:str)
		{
			arr.push_back(int(i) - 48);
		}

		return arr;
	}

};


int main()
{
	auto number1 = big_integer("114575");
	auto number2 = big_integer("78524");

	auto result = number1 + number2;

	std::cout << result << "\n";
	std::cout << result * 3 << "\n";
	

	system("pause");
	return 0;
}