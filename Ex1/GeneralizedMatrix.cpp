#include <iostream>
#include <vector>
#include <string>
#include "Matrix.h"

int DimensionFault(const std::vector<std::vector<int>>);
void DimensionFaultCheck(const std::vector<std::vector<int>>, const std::vector<std::vector<int>>);

int main()
{
    std::vector<std::vector<int>> m1{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> m2{{2, 0, 0}, {0, 2, 0}, {0, 0, 2}};
    // std::vector<std::vector<int>> m1{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    // std::vector<std::vector<int>> m2{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    // std::vector<std::vector<int>> m1{{1, 0, 0, 0}, {0, 1, 0, 0}};
    // std::vector<std::vector<int>> m2{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
    // std::vector<std::vector<int>> m1{{0}, {0, 0, 1}};
    // std::vector<std::vector<int>> m2{{1}};

    Matrix matrix1(m1.size(), m1[0].size(), m1);
    Matrix matrix2(m2.size(), m2[0].size(), m2);

    std::cout << "1. M1:" << std::endl;
    matrix1.Display();
    std::cout << "2. M2:" << std::endl;
    matrix2.Display();

    try
    {
        Matrix a = matrix1.AddMatrices(matrix2);
        std::cout << "3. M1 + M2:" << std::endl;
        a.Display();
        Matrix b = matrix1.MultiplyMatrices(matrix2);
        std::cout << "4. M1 * M2:" << std::endl;
        b.Display();
    }
    catch (const std::string &e)
    {
        std::cout << e << std::endl;
    }

    return 0;
}

int DimensionFault(const std::vector<std::vector<int>> vect)
{
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i].size() != vect[0].size())
        {
            return 1;
        }
    }
    return 0;
}
void DimensionFaultCheck(const std::vector<std::vector<int>> vect1, const std::vector<std::vector<int>> vect2)
{
    if (DimensionFault(vect1) || DimensionFault(vect2))
    {
        throw std::string("Invalid matrix dimension");
    }
}
Matrix::Matrix(const int num_row, const int num_col, const std::vector<std::vector<int>> vect)
{
    numberOfRows_ = num_row;
    numberOfColumns_ = num_col;
    matrix_ = vect;
}
int Matrix::GetNumberOfRow() const { return matrix_.size(); }
int Matrix::GetNumberOfColumn() const { return matrix_[0].size(); }
void Matrix::SetElement(const int i, const int j, const int value) { matrix_[i][j] = value; }
void Matrix::Display() const
{
    if (numberOfRows_ == 0)
    {
        std::cout << "  Impossible!" << std::endl
                  << std::endl;
    }
    else
    {
        for (int i = 0; i < numberOfRows_; i++)
        {
            for (int j = 0; j < numberOfColumns_; j++)
            {
                std::cout << matrix_[i][j] << "\t";
            }
            std::cout << std::endl
                      << std::endl;
        }
    }
}

Matrix Matrix::AddMatrices(const Matrix B) const
{

    DimensionFaultCheck(matrix_, B.matrix_);

    if (numberOfRows_ == B.numberOfRows_ && numberOfColumns_ == B.numberOfColumns_)
    {
        std::vector<std::vector<int>> addedMatrix(numberOfRows_, std::vector<int>(numberOfColumns_, 0));
        for (int i = 0; i < numberOfRows_; i++)
        {
            for (int j = 0; j < numberOfColumns_; j++)
            {
                addedMatrix[i][j] = matrix_[i][j] + B.matrix_[i][j];
            }
        }
        return Matrix(numberOfRows_, numberOfColumns_, addedMatrix);
    }
    else
    {
        return Matrix(0, 0, std::vector<std::vector<int>>{{NULL}});
    }
}
Matrix Matrix::MultiplyMatrices(const Matrix B) const
{
    DimensionFaultCheck(matrix_, B.matrix_);
    if (numberOfColumns_ == B.numberOfRows_)
    {
        std::vector<std::vector<int>> multipliedMatrix(numberOfRows_, std::vector<int>(B.numberOfColumns_, 0));
        for (int i = 0; i < numberOfRows_; i++)
        {
            for (int j = 0; j < B.numberOfColumns_; j++)
            {
                for (int k = 0; k < numberOfColumns_; k++)
                {
                    multipliedMatrix[i][j] += matrix_[i][k] * B.matrix_[k][j];
                }
            }
        }
        return Matrix(numberOfRows_, B.numberOfColumns_, multipliedMatrix);
    }
    else
    {
        return Matrix(0, 0, std::vector<std::vector<int>>{{NULL}});
    }
}
