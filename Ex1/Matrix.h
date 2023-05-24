#include <iostream>
#include <vector>

class Matrix
{
public:
    Matrix(const int, const int, const std::vector<std::vector<int>>);
    int GetNumberOfRow() const;
    int GetNumberOfColumn() const;
    void SetElement(const int, const int, const int);
    void Display() const;
    Matrix AddMatrices(const Matrix) const;
    Matrix MultiplyMatrices(const Matrix) const;

private:
    int numberOfRows_;
    int numberOfColumns_;
    std::vector<std::vector<int>> matrix_;
};
