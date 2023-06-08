#include <gtest/gtest.h>
#include "Matrix.h"

std::vector<std::vector<int>> m1{{1}};
std::vector<std::vector<int>> m2{{1}, {0}};
std::vector<std::vector<int>> m3{{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}};
std::vector<std::vector<int>> m4{{2}};
std::vector<std::vector<int>> m5{{3}};
std::vector<std::vector<int>> m6{{1, 2}, {3, 4}};
std::vector<std::vector<int>> m7{{2, 0}, {0, 2}};
std::vector<std::vector<int>> m8{{2, 4}, {6, 8}};

Matrix matrix1(m1.size(), m1[0].size(), m1);
Matrix matrix2(m2.size(), m2[0].size(), m2);
Matrix matrix3(m3.size(), m3[0].size(), m3);
Matrix matrix4(m4.size(), m4[0].size(), m4);
Matrix matrix5(m5.size(), m5[0].size(), m5);
Matrix matrix6(m6.size(), m6[0].size(), m6);
Matrix matrix7(m7.size(), m7[0].size(), m7);
Matrix matrix8(m8.size(), m8[0].size(), m8);

TEST(GetNumberOfRowTest, GetNumberOfRow)
{

    // EXPECT_EQ(matrix2.GetNumberOfRow(), 3);
    // ASSERT_EQ(matrix2.GetNumberOfRow(), 3);
    GTEST_ASSERT_EQ(matrix1.GetNumberOfRow(), 1);
    GTEST_ASSERT_EQ(matrix2.GetNumberOfRow(), 2);
    GTEST_ASSERT_EQ(matrix3.GetNumberOfRow(), 3);
}

TEST(AddMatricesTest, AddMatrices)
{
    for (int i = 0; i < matrix1.GetNumberOfRow(); i++)
    {
        for (int j = 0; j < matrix1.GetNumberOfColumn(); j++)
        {
            GTEST_ASSERT_EQ((matrix1.AddMatrices(matrix4)).GetTwoDimensionVector()[i][j], matrix5.GetTwoDimensionVector()[i][j]);
        }
    }

    GTEST_ASSERT_EQ(matrix5.GetTwoDimensionVector(), matrix1.AddMatrices(matrix4).GetTwoDimensionVector());
}

TEST(MultiplyMatricesTest, MultiplyMatrices)
{
    for (int i = 0; i < matrix6.GetNumberOfRow(); i++)
    {
        for (int j = 0; j < matrix6.GetNumberOfColumn(); j++)
        {
            GTEST_ASSERT_EQ((matrix6.MultiplyMatrices(matrix7)).GetTwoDimensionVector()[i][j], matrix8.GetTwoDimensionVector()[i][j]);
        }
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}