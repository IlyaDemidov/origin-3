#include <iostream>

struct Point
{
	double m_x;
	double m_y;
	Point(double x, double y)
	{
		m_x = x;
		m_y = y;
	}
};

void print_point(const Point& point_object)
{
	std::cout << "x:" << point_object.m_x << ", y: "
		<< point_object.m_y << std::endl;
}

int main()
{
	for (int i = 0; i < 5; i++) 
	{
		Point my_point(i, 2 * i);
		print_point(my_point);
	}

	std::cout << "\n";
	system("pause");
	return 0;
}