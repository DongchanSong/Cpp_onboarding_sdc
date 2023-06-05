#include <string>
#include "Matrix.h"

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
