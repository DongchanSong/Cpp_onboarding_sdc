#include <gtest/gtest.h>
#include "FcInputImpl.h"

VehicleData *dataM300 = new VehicleData_M300();
VehicleData *dataM600 = new VehicleData_M600();
VehicleData *dataMavic = new VehicleData_Mavic();
VehicleData *dataSkydio = new VehicleData_Skydio();

TEST(M300_GPS, m300_GPS)
{
    ASSERT_LT(dataM300->GetGPSNum(), 20 + 1);
    // ASSERT_GE(dataM300->GetGPSNum(), 1);

    // ASSERT_LT(dataM300->GetGPSHealth(), 2 + 1);
    // ASSERT_GE(dataM300->GetGPSHealth(), 1);
}

// TEST(M600_GPS, m600_GPS)
// {
//     ASSERT_LT(dataM600->GetGPSNum(), 20 + 1);
//     ASSERT_GE(dataM600->GetGPSNum(), 1);

//     ASSERT_LT(dataM600->GetGPSHealth(), 2 + 1);
//     ASSERT_GE(dataM600->GetGPSHealth(), 1);
// }

// TEST(Mavic_GPS, mavic_GPS)
// {
//     ASSERT_LT(dataMavic->GetGPSNum(), 20 + 1);
//     ASSERT_GE(dataMavic->GetGPSNum(), 1);

//     ASSERT_LT(dataMavic->GetGPSHealth(), 2 + 1);
//     ASSERT_GE(dataMavic->GetGPSHealth(), 1);
// }

// TEST(Skydio_GPS, skydio_GPS)
// {
//     ASSERT_LT(dataSkydio->GetGPSNum(), 20 + 1);
//     ASSERT_GE(dataSkydio->GetGPSNum(), 1);

//     ASSERT_LT(dataSkydio->GetGPSHealth(), 2 + 1);
//     ASSERT_GE(dataSkydio->GetGPSHealth(), 1);
// }

int main(int argc, char *argv[])
{
    std::cout << dataM300->GetGPSNum() << std::endl;
    std::cout << dataM300->GetGPSHealth() << std::endl;
    std::cout << dataM300->GetFlightStatus() << std::endl;
    std::cout << dataM300->GetGimbalStatus() << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}