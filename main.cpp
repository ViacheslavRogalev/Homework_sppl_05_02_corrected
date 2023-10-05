#include<iostream>


template<class T>
class Matrix
{
    T** matrix;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c)
    {
        matrix = new T * [rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new T[cols];
        }
    }

    Matrix(const Matrix& other)
    {
        rows = other.rows;
        cols = other.cols;
        matrix = new T * [other.rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new T[other.cols];
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; i < cols; i++)
            {
                matrix[i][j] = other.matrix[i][j];
            }
    }

    T* operator[](T rows)
    {
        return matrix[rows];
    }

    Matrix operator = (const Matrix& other)
    {
        if (this != &other)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
        }
        rows = other.rows;
        cols = other.cols;
        matrix = new T * [other.rows];
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new T[other.cols];
        }
        for (int i = 0; i < rows; i++)
            for (int j = 0; i < cols; i++)
            {
                matrix[i][j] = other.matrix[i][j];
            }

        return *this;
    }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] matrix[i];
        }

        delete[] matrix;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    Matrix<int> table(2, 3);

    auto& test = table;

    test[0][0] = 4;

    std::cout << "\n test[0][0] = " << test[0][0] << std::endl;

    return 0;
}