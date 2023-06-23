#include "different_api/m300/gps/gps.cc"
#include "different_api/m300/navigation/navigation.cc"
#include "different_api/m300/sensor_data/sensor_data.cc"
#include "different_api/m300/status/status.cc"
#include "different_api/m600/gps/gps.cc"
#include "different_api/m600/navigation/navigation.cc"
#include "different_api/m600/sensor_data/sensor_data.cc"
#include "different_api/m600/status/status.cc"

#include <iostream>

class VehicleData
{
public:
    virtual ~VehicleData(){};

    virtual void SetGPSNum() = 0;
    virtual void SetGPSHealth() = 0;
    virtual void SetPosNED() = 0;
    virtual void SetPosLLH() = 0;
    virtual void SetVelHdg() = 0;
    virtual void SetEuler() = 0;

    virtual void SetFlightStatus() = 0;
    virtual void SetGimbalStatus() = 0;
    virtual void SetCameraStatus() = 0;
    virtual void SetDistanceStatus() = 0;

    virtual void SetCameraData() = 0;
    virtual void SetGimbalData() = 0;
    virtual void SetDistanceData() = 0;

protected:
    float gpsNum_;
    int gpsHealth_;
    nlab::lib::Vector3f posNED_;
    nlab::lib::Vector3 posLLH_;
    nlab::lib::Vector3f velHdg_;
    nlab::lib::Vector3f euler_;

    int flightStatus_;
    int gimbalStatus_;
    int cameraStatus_;
    int distanceStatus_;

    std::vector<std::vector<int>> cameraData_;
    nlab::lib::Vector3f gimbalData_;
    float distanceData_;
};
class VehicleData_M300 : public VehicleData
{
public:
    M300Gps *m300Gps;
    M300Navigation *m300Navigation;
    M300SensorData *m300SensorData;
    M300Status *m300Status;

    void SetGPSNum() { gpsNum_ = m300Gps->GetGpsNum(); }
    void SetGPSHealth() { gpsHealth_ = int(m300Gps->GetGpsHealth()); }
    void SetPosNED() { posNED_ = m300Navigation->GetPosNed(); }
    void SetPosLLH() { posLLH_ = m300Navigation->GetPosLlh(); }
    void SetVelHdg() { velHdg_ = m300Navigation->GetVelHdg(); }
    void SetEuler() { euler_ = m300Navigation->GetEuler(); }

    void SetFlightStatus() { flightStatus_ = int(m300Status->GetFlightStatus()); }
    void SetGimbalStatus() { gimbalStatus_ = int(m300Status->GetPayloadStatus(M300Status::PAYLOAD_TYPE::GIMBAL)); }
    void SetCameraStatus() { cameraStatus_ = int(m300Status->GetPayloadStatus(M300Status::PAYLOAD_TYPE::CAMERA)); }
    void SetDistanceStatus() { distanceStatus_ = int(m300Status->GetPayloadStatus(M300Status::PAYLOAD_TYPE::SONAR)); }

    void SetCameraData() { cameraData_ = m300SensorData->GetCameraData(); }
    void SetGimbalData() { gimbalData_ = m300SensorData->GetGimbalData(); }
    void SetDistanceData() { distanceData_ = m300SensorData->GetSonarData(); }
};
class VehicleData_M600 : public VehicleData
{
    M600Gps *m600Gps;
    M600Navigation *m600Navigation;
    M600SensorData *m600SensorData;
    M600Status *m600Status;

    void SetGPSNum() { gpsNum_ = m600Gps->GetGpsNum(); }
    void SetGPSHealth() { gpsHealth_ = int(m600Gps->GetGpsHealth()); }
    void SetPosNED() { posNED_ = m600Navigation->GetPosNed(); }
    void SetPosLLH() { posLLH_ = m600Navigation->GetPosLlh(); }
    void SetVelHdg() { velHdg_ = m600Navigation->GetVelBody(); } //// body to heading transform 필요
    void SetEuler() { euler_ = m600Navigation->GetEuler(); }

    void SetFlightStatus() { flightStatus_ = int(m600Status->GetFlightStatus()); }
    void SetGimbalStatus() { gimbalStatus_ = int(m600Status->GetPayloadStatus(M600Status::PAYLOAD_TYPE::GIMBAL)); }
    void SetCameraStatus() { cameraStatus_ = int(m600Status->GetPayloadStatus(M600Status::PAYLOAD_TYPE::CAMERA)); }
    // void SetDistanceStatus() { m600Status->GetPayloadStatus(M600Status::PAYLOAD_TYPE(-1)); }
    void SetDistanceStatus() { std::cout << "M600: Distance status unavailable" << std::endl; }

    void SetCameraData() { cameraData_ = m600SensorData->GetCameraData(); }
    void SetGimbalData() { gimbalData_ = m600SensorData->GetGimbalData(); }
    void SetDistanceData() { std::cout << "M600: Distance data unavailable" << std::endl; }
};

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
        vehicleData->SetVelHdg();
        vehicleData->SetEuler();

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
    VehicleData *CreateVehicle() const override
    {
        return new VehicleData_M300();
    }
};

class FcInputImpl_M600 : public FcInputImpl
{
public:
    VehicleData *CreateVehicle() const override
    {
        return new VehicleData_M600();
    }
};

int main()
{
    FcInputImpl *fcM300 = new FcInputImpl_M300();
    VehicleData *dataM300 = fcM300->FromApiToMc();

    FcInputImpl *fcM600 = new FcInputImpl_M600();
    VehicleData *dataM600 = fcM600->FromApiToMc();

    delete fcM300;
    delete fcM600;
    return 0;
}