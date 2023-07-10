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
void RangeCheck(double, double, double);
void RangeCheck(nlab::lib::Vector3f, nlab::lib::Vector3f, nlab::lib::Vector3f);
void RangeCheck(nlab::lib::Vector3, nlab::lib::Vector3, nlab::lib::Vector3);
void RangeCheckGPSandPos(VehicleData &);

float gpsNumRange[2] = {1.0f, 21.0f};
int gpsHealthRange[2] = {1, 3};
nlab::lib::Vector3f posNEDRange[2] = {nlab::lib::Vector3f(-50.0f, -50.0f, 1.0f), nlab::lib::Vector3f(50.0f, 50.0f, 101.0f)};
nlab::lib::Vector3 posLLHRange[2] = {nlab::lib::Vector3(37.0, 126.0, 1.0), nlab::lib::Vector3(38.0, 127.0, 101.0)};
nlab::lib::Vector3f velHdgRange[2] = {nlab::lib::Vector3f(-3.0f, -3.0f, -3.0f), nlab::lib::Vector3f(3.0f, 3.0f, 3.0f)};
nlab::lib::Vector3f velBodyRange[2] = {nlab::lib::Vector3f(-3.0f, -3.0f, -3.0f), nlab::lib::Vector3f(3.0f, 3.0f, 3.0f)};
nlab::lib::Vector3f eulerRange[2] = {nlab::lib::Vector3f(-30, -30, -180), nlab::lib::Vector3f(30, 30, 180)};
nlab::lib::Quaternionf quaternionRange[2] = {};

TEST(M300_Range, m300_Range)
{
    RangeCheckGPSandPos(*dataM300);
    RangeCheck(dataM300->GetVelHdg(), velHdgRange[0], velHdgRange[1]);
    RangeCheck(dataM300->GetEuler(), eulerRange[0], eulerRange[1]);
}

TEST(M600_Range, m600_Range)
{
    RangeCheckGPSandPos(*dataM600);
    // RangeCheck(dataM600->GetVelBody(), velBodyRange[0], velBodyRange[1]);
    RangeCheck(dataM600->GetEuler(), eulerRange[0], eulerRange[1]);
}

TEST(Mavic_Range, mavic_Range)
{
    RangeCheckGPSandPos(*dataMavic);
    RangeCheck(dataMavic->GetVelHdg(), velHdgRange[0], velHdgRange[1]);
    RangeCheck(dataMavic->GetEuler(), eulerRange[0], eulerRange[1]);
}

TEST(Skydio_Range, skydio_Range)
{
    RangeCheckGPSandPos(*dataSkydio);
    RangeCheck(dataSkydio->GetVelHdg(), velHdgRange[0], velHdgRange[1]);
    // RangeCheck(dataSkydio->GetQuaternion(), eulerRange[0], eulerRange[1]);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

void RangeCheck(int object, int lowerBound, int upperBound)
{
    ASSERT_GE(object, lowerBound);
    ASSERT_LT(object, upperBound);
}

void RangeCheck(float object, float lowerBound, float upperBound)
{
    ASSERT_GE(object, lowerBound);
    ASSERT_LE(object, upperBound);
}

void RangeCheck(double object, double lowerBound, double upperBound)
{
    ASSERT_GE(object, lowerBound);
    ASSERT_LE(object, upperBound);
}

void RangeCheck(nlab::lib::Vector3f object, nlab::lib::Vector3f lowerBound, nlab::lib::Vector3f upperBound)
{
    RangeCheck(object(0), lowerBound(0), upperBound(0));
    RangeCheck(object(1), lowerBound(1), upperBound(1));
    RangeCheck(object(2), lowerBound(2), upperBound(2));
}

void RangeCheck(nlab::lib::Vector3 object, nlab::lib::Vector3 lowerBound, nlab::lib::Vector3 upperBound)
{
    RangeCheck(object(0), lowerBound(0), upperBound(0));
    RangeCheck(object(1), lowerBound(1), upperBound(1));
    RangeCheck(object(2), lowerBound(2), upperBound(2));
}

void RangeCheckGPSandPos(VehicleData &data)
{
    RangeCheck(data.GetGPSNum(), gpsNumRange[0], gpsNumRange[1]);
    RangeCheck(data.GetGPSHealth(), gpsHealthRange[0], gpsHealthRange[1]);

    RangeCheck(data.GetPosNED(), posNEDRange[0], posNEDRange[1]);
    RangeCheck(data.GetPosLLH(), posLLHRange[0], posLLHRange[1]);
}