#include <iostream>


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
   
    bool at_col(int i) 
    {
        if (i < col && i >= 0)  return true;
           
        return false;
    }

    const bool at_col(int i) const
    {
        if (i < col && i >= 0) return true;
            
        return false;
    }

    class my_class
    {
    public:
        class my_class (T* array, int row_pr) : array(array), row_pr(row_pr) {}
        ~my_class() = default;

        T& operator[] (int index) { return array[index];}
        
        const T operator[] (int index) const { return array[index];}
        
    private:
        bool at(int i)
        {
            if (i < row_pr && i >= 0) return true;
                
            return false;
        }

        const bool at(int i) const
        {
            if (i < row_pr && i >= 0) return true;
                
            return false;
        }
        int row_pr;
        T* array;
    };

    my_class operator[](int i){ return my_class(arr[i], row);}

    const my_class operator[](int i) const { return my_class(arr[i], row);}
};

int main()
{
        auto test = table<int>(2, 3);
        test[0][0] = 4;
        test[1][2] = 12;

        std::cout << test[0][0] << " , " << test[1][2] << "\n";

        system("pause");
        return 0;
}