#include <gtest/gtest.h>
#include "FcInputImpl.h"

FcInputImpl *fcM300 = new FcInputImpl_M300();
VehicleData *dataM300 = fcM300->FromApiToMc();

FcInputImpl *fcM600 = new FcInputImpl_M600();
VehicleData *dataM600 = fcM600->FromApiToMc();

FcInputImpl *fcMavic = new FcInputImpl_Mavic();
VehicleData *dataMavic = fcMavic->FromApiToMc();

FcInputImpl *fcSkydio = new FcInputImpl_Skydio();
VehicleData *dataSkydio = fcSkydio->FromApiToMc();

void RangeCheck(int, int, int);
void RangeCheck(float, float, float);
// void RangeCheck(nlab::lib::Vector3f, nlab::lib::Vector3f, nlab::lib::Vector3f);
// void RangeCheck(nlab::lib::Vector3, nlab::lib::Vector3, nlab::lib::Vector3);

TEST(M300_Range, m300_Range)
{
    RangeCheck(dataM300->GetGPSNum(), 20.0f + 1.0f, 1.0f);
    RangeCheck(dataM300->GetGPSHealth(), 3, 1);
}

TEST(M600_Range, m600_Range)
{
    RangeCheck(dataM600->GetGPSNum(), 20.0f + 1.0f, 1.0f);
    RangeCheck(dataM600->GetGPSHealth(), 3, 1);
}

TEST(Mavic_Range, mavic_Range)
{
    RangeCheck(dataMavic->GetGPSNum(), 20.0f + 1.0f, 1.0f);
    RangeCheck(dataMavic->GetGPSHealth(), 3, 1);
}

TEST(Skydio_Range, skydio_Range)
{
    RangeCheck(dataSkydio->GetGPSNum(), 20.0f + 1.0f, 1.0f);
    RangeCheck(dataSkydio->GetGPSHealth(), 3, 1);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void RangeCheck(int object, int upperBound, int lowerBound)
{
    ASSERT_LT(object, upperBound);
    ASSERT_GE(object, lowerBound);
}

void RangeCheck(float object, float upperBound, float lowerBound)
{
    ASSERT_LT(object, upperBound);
    ASSERT_GE(object, lowerBound);
}

void RangeCheck(nlab::lib::Vector3f object, nlab::lib::Vector3f upperBound, nlab::lib::Vector3f lowerBound)
{
    ASSERT_LT(object(0), upperBound(0));
    ASSERT_LT(object(1), upperBound(1));
    ASSERT_LT(object(2), upperBound(2));
    ASSERT_GE(object(0), lowerBound(0));
    ASSERT_GE(object(1), lowerBound(1));
    ASSERT_GE(object(2), lowerBound(2));
}

void RangeCheck(nlab::lib::Vector3 object, nlab::lib::Vector3 upperBound, nlab::lib::Vector3 lowerBound)
{
    ASSERT_LT(object(0), upperBound(0));
    ASSERT_LT(object(1), upperBound(1));
    ASSERT_LT(object(2), upperBound(2));
    ASSERT_GE(object(0), lowerBound(0));
    ASSERT_GE(object(1), lowerBound(1));
    ASSERT_GE(object(2), lowerBound(2));
}