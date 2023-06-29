#ifndef FCINPUTINMPL_H
#define FCINPUTINMPL_H

#include "VehicleData.h"

class FcInputImpl
{
public:
    virtual ~FcInputImpl(){};
    virtual VehicleData *CreateVehicle() const = 0;

    VehicleData *FromApiToMc()
    {
        VehicleData *vehicleData = CreateVehicle();

        vehicleData->SetGPSNum();
        vehicleData->SetGPSHealth();
        vehicleData->SetPosNED();
        vehicleData->SetPosLLH();
        vehicleData->SetEuler(); // M600에서 body to Hdg 변환 필요한데, euler angle이 먼저 정의되어야 하기 때문에 SetVelHdg보다 먼저 호출
        vehicleData->SetVelHdg();

        vehicleData->SetFlightStatus();
        vehicleData->SetGimbalStatus();
        vehicleData->SetCameraStatus();
        vehicleData->SetDistanceStatus();

        vehicleData->SetCameraData();
        vehicleData->SetGimbalData();
        vehicleData->SetDistanceData();

        return vehicleData;
    };
};

class FcInputImpl_M300 : public FcInputImpl
{
public:
    VehicleData *CreateVehicle() const override { return new VehicleData_M300(); }
};

class FcInputImpl_M600 : public FcInputImpl
{
public:
    VehicleData *CreateVehicle() const override { return new VehicleData_M600(); }
};

class FcInputImpl_Mavic : public FcInputImpl
{
public:
    VehicleData *CreateVehicle() const override { return new VehicleData_Mavic(); }
};

class FcInputImpl_Skydio : public FcInputImpl
{
public:
    VehicleData *CreateVehicle() const override { return new VehicleData_Skydio(); }
};

#endif // !FCINPUTINMPL_H
