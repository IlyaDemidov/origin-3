#include <iostream>
#include <Windows.h>
#include <exception>


template<typename T>
class table
{
private:
    int col;
    int row;
    T** arr;
public:
    table(const int col, const int row) : col(col), row(row)
    {
        arr = new T * [col];
        for (size_t i = 0; i < col; ++i)
            arr[i] = new T[row];
        for (size_t i = 0; i < col; ++i) {
            for (size_t j = 0; j < row; ++j) {
                arr[i][j] = 0;
            }
        }
    }


    ~table()
    {
        for (size_t i = 0; i < col; ++i) delete[] arr[i];
         
        delete[] arr;
    }
   
    table(const table& other) = delete;
    table& operator= (const table& other) = delete;

    bool index_out(int i)
    {
        if (i < col && i >= 0)  return true;
           
        return false;
    }

    const bool index_out(int i) const
    {
        if (i < col && i >= 0) return true;
            
        return false;
    }

    class my_class
    {
    public:
        class my_class (T* array, int row_pr) : array(array), row_pr(row_pr) {}
        ~my_class() = default;

        T& operator[] (int index)
        {
            if (!index_out_1(index)) throw std::out_of_range("Неверный второй индекс ");

            return array[index];
        }
        
        const T operator[] (int index) const 
        {
            if (!index_out_1(index)) throw std::out_of_range("Неверный второй индекс ");

            return array[index];
        }
        
    private:
        bool index_out_1(int i)
        {
            if (i < row_pr && i >= 0) return true;
                
            return false;
        }

        const bool index_out_1(int i) const
        {
            if (i < row_pr && i >= 0) return true;
                
            return false;
        }
        int row_pr;
        T* array;
    };

    my_class operator[](int i)
    { 
        if (!index_out(i)) throw std::out_of_range("Неверный первый индекс ");

        return my_class(arr[i], row);
    }

    const my_class operator[](int i) const
    {
        if (!index_out(i)) throw std::out_of_range("Неверный первый индекс ");

        return my_class(arr[i], row);
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try
    {
        table<int> arr(2, 3);

        arr[0][0] = 4;
        arr[1][2] = 12;

        std::cout << arr[0][0] << " , " << arr[1][2] << "\n";

    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

        system("pause");
        return 0;
}