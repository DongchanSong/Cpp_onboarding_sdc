#ifndef MATRIX_H
#define MATRIX_H

#include "ExtraFunctions.h"

class Matrix
{
public:
    Matrix(const int, const int, std::vector<std::vector<int>>);
    int GetNumberOfRow() const;
    int GetNumberOfColumn() const;
    void SetElement(const int, const int, const int);
    void Display() const;
    Matrix AddMatrices(Matrix &) const;
    Matrix MultiplyMatrices(Matrix &) const;

private:
    int numberOfRows_;
    int numberOfColumns_;
    std::vector<std::vector<int>> matrix_;
};

Matrix::Matrix(const int num_row, const int num_col, std::vector<std::vector<int>> vect)
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

Matrix Matrix::AddMatrices(Matrix &B) const
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
Matrix Matrix::MultiplyMatrices(Matrix &B) const
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

#endif // !Matrix_H
