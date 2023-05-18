#include <iostream>
#include <vector>

class Matrix
{
public:
    Matrix(int num_row, int num_col, std::vector<std::vector<int>> vect);
    int GetNumberOfRow();
    int GetNumberOfColumn();
    void SetElement(int i, int j, int value);
    void Display();
    Matrix AddMatrices(Matrix B);
    Matrix MultiplyMatrices(Matrix B);

private:
    int numberOfRows_;
    int numberOfColumns_;
    std::vector<std::vector<int>> matrix_;
};

int main()
{
    std::vector<std::vector<int>> m1{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> m2{{2, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, 1}};

    Matrix matrix1(m1.size(), m1[0].size(), m1);
    Matrix matrix2(m2.size(), m2[0].size(), m2);

    std::cout << "1. M1:" << std::endl;
    matrix1.Display();

    std::cout << "2. M2:" << std::endl;
    matrix2.Display();

    if (matrix1.GetNumberOfRow() == matrix2.GetNumberOfRow() && matrix1.GetNumberOfColumn() == matrix2.GetNumberOfColumn())
    {
        Matrix a = matrix1.AddMatrices(matrix2);
        std::cout << "3. M1 + M2:" << std::endl;
        a.Display();
    }
    else
    {
        std::cout << "3. Matrix addition is impossible" << std::endl
                  << std::endl;
    }

    if (matrix1.GetNumberOfColumn() == matrix2.GetNumberOfRow())
    {
        Matrix b = matrix1.MultiplyMatrices(matrix2);
        std::cout << "4. M1 * M2:" << std::endl;
        b.Display();
    }
    else
    {
        std::cout << "4. Matrix multiplication is impossible" << std::endl
                  << std::endl;
    }

    return 0;
}

Matrix::Matrix(int num_row, int num_col, std::vector<std::vector<int>> vect)
{
    numberOfRows_ = num_row;
    numberOfColumns_ = num_col;
    matrix_ = vect;
}
int Matrix::GetNumberOfRow() { return matrix_.size(); }
int Matrix::GetNumberOfColumn() { return matrix_[0].size(); }
void Matrix::SetElement(int i, int j, int value) { matrix_[i][j] = value; }
void Matrix::Display()
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
Matrix Matrix::AddMatrices(Matrix B)
{
    std::vector<std::vector<int>> AddedMatrix(numberOfRows_, std::vector<int>(numberOfColumns_, 0));
    for (int i = 0; i < numberOfRows_; i++)
    {
        for (int j = 0; j < numberOfColumns_; j++)
        {
            AddedMatrix[i][j] = matrix_[i][j] + B.matrix_[i][j];
        }
    }
    return Matrix(numberOfRows_, numberOfColumns_, AddedMatrix);
}
Matrix Matrix::MultiplyMatrices(Matrix B)
{
    std::vector<std::vector<int>> MultipliedMatrix(numberOfRows_, std::vector<int>(B.numberOfColumns_, 0));
    for (int i = 0; i < numberOfRows_; i++)
    {
        for (int j = 0; j < B.numberOfColumns_; j++)
        {
            for (int k = 0; k < numberOfColumns_; k++)
            {
                MultipliedMatrix[i][j] += matrix_[i][k] * B.matrix_[k][j];
            }
        }
    }
    return Matrix(numberOfRows_, B.numberOfColumns_, MultipliedMatrix);
}
