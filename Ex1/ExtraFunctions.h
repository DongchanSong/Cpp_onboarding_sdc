#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H

#include <iostream>
#include <vector>

int DimensionFault(const std::vector<std::vector<int>>);
void DimensionFaultCheck(const std::vector<std::vector<int>>, const std::vector<std::vector<int>>);

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

#endif // !
