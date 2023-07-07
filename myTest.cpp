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

TEST(M300_GPS, m300_GPS)
{
    ASSERT_LT(dataM300->GetGPSNum(), 20 + 1);
    ASSERT_GE(dataM300->GetGPSNum(), 1);

    ASSERT_LT(dataM300->GetGPSHealth(), 2 + 1);
    ASSERT_GE(dataM300->GetGPSHealth(), 1);
}

TEST(M600_GPS, m600_GPS)
{
    ASSERT_LT(dataM600->GetGPSNum(), 20 + 1);
    ASSERT_GE(dataM600->GetGPSNum(), 1);

    ASSERT_LT(dataM600->GetGPSHealth(), 2 + 1);
    ASSERT_GE(dataM600->GetGPSHealth(), 1);
}

TEST(Mavic_GPS, mavic_GPS)
{
    ASSERT_LT(dataMavic->GetGPSNum(), 20 + 1);
    ASSERT_GE(dataMavic->GetGPSNum(), 1);

    ASSERT_LT(dataMavic->GetGPSHealth(), 2 + 1);
    ASSERT_GE(dataMavic->GetGPSHealth(), 1);
}

TEST(Skydio_GPS, skydio_GPS)
{
    ASSERT_LT(dataSkydio->GetGPSNum(), 20 + 1);
    ASSERT_GE(dataSkydio->GetGPSNum(), 1);

    ASSERT_LT(dataSkydio->GetGPSHealth(), 2 + 1);
    ASSERT_GE(dataSkydio->GetGPSHealth(), 1);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}