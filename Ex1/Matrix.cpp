#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix(int num_row, int num_col, vector<vector<int>> vect);
    int GetNumberOfRow();
    int GetNumberOfColumn();
    void SetElement(int i, int j, int value);
    void Display();
    Matrix AddMatrices(Matrix B);
    Matrix MultiplyMatrices(Matrix B);

private:
    int n_row;
    int n_col;
    vector<vector<int>> matrix;
};

int main()
{
    vector<vector<int>> m1{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    vector<vector<int>> m2{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Matrix matrix1(3, 3, m1);
    Matrix matrix2(3, 3, m2);
    matrix1.Display();
    matrix2.Display();
    Matrix a = matrix1.AddMatrices(matrix2);
    a.Display();
    Matrix b = matrix1.MultiplyMatrices(matrix2);
    b.Display();
    return 0;
}

Matrix::Matrix(int num_row, int num_col, vector<vector<int>> vect)
{
    n_row = num_row;
    n_col = num_col;
    matrix = vect;
}
int Matrix::GetNumberOfRow() { return matrix.size(); }
int Matrix::GetNumberOfColumn() { return matrix[0].size(); }
void Matrix::SetElement(int i, int j, int value) { matrix[i][j] = value; }
void Matrix::Display()
{
    cout << "-------------------------------" << endl;
    for (int i = 0; i < n_row; i++)
    {
        for (int j = 0; j < n_col; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "-------------------------------" << endl;
}
Matrix Matrix::AddMatrices(Matrix B)
{
    vector<vector<int>> Added_M(n_row,vector<int>(n_col,0));
    for (int i = 0; i < n_row; i++)
    {
        for (int j = 0; j < n_col; j++)
        {
            Added_M[i][j] = matrix[i][j] + B.matrix[i][j];
        } 
    }
    return Matrix(n_row, n_col, Added_M);
}
Matrix Matrix::MultiplyMatrices(Matrix B)
{
    vector<vector<int>> Multiplied_M(n_row, vector<int>(B.n_col, 0));
    for (int i = 0; i < n_row; i++)
    {
        for (int j = 0; j < B.n_col; j++)
        {
            for (int k = 0; k < n_col; k++)
            {
                Multiplied_M[i][j] += matrix[i][k] * B.matrix[k][j];
            }
        }
    }
    return Matrix(n_row, B.n_col, Multiplied_M);
}
