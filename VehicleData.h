#ifndef VEHICLEDATA_H
#define VEHICLEDATA_H

#include "different_api/m300/gps/gps.cc"
#include "different_api/m300/navigation/navigation.cc"
#include "different_api/m300/sensor_data/sensor_data.cc"
#include "different_api/m300/status/status.cc"

#include "different_api/m600/gps/gps.cc"
#include "different_api/m600/navigation/navigation.cc"
#include "different_api/m600/sensor_data/sensor_data.cc"
#include "different_api/m600/status/status.cc"

#include "different_api/mavic/gps/gps.cc"
#include "different_api/mavic/sensor/camera_data/camera_data.cc"
#include "different_api/mavic/sensor/gimbal_data/gimbal_data.cc"
#include "different_api/mavic/sensor/integrated_navigation/integrated_navigation.cc"
#include "different_api/mavic/sensor/lidar_data/lidar_data.cc"
#include "different_api/mavic/sensor/visual_data/visual_data.cc"
#include "different_api/mavic/status/status.cc"

#include "different_api/skydio/camera/camera.cc"
#include "different_api/skydio/flight_controller/flight_controller.cc"
#include "different_api/skydio/gimbal/gimbal.cc"
#include "different_api/skydio/gps/gps.cc"
#include "different_api/skydio/lidar/lidar.cc"

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

    void SetGPSNum() override { gpsNum_ = m300Gps->GetGpsNum(); }
    void SetGPSHealth() override { gpsHealth_ = int(m300Gps->GetGpsHealth()); }
    void SetPosNED() override { posNED_ = m300Navigation->GetPosNed(); }
    void SetPosLLH() override { posLLH_ = m300Navigation->GetPosLlh(); }
    void SetVelHdg() override { velHdg_ = m300Navigation->GetVelHdg(); }
    void SetEuler() override { euler_ = m300Navigation->GetEuler(); }

    void SetFlightStatus() override { flightStatus_ = int(m300Status->GetFlightStatus()); }
    void SetGimbalStatus() override { gimbalStatus_ = int(m300Status->GetPayloadStatus(M300Status::PAYLOAD_TYPE::GIMBAL)); }
    void SetCameraStatus() override { cameraStatus_ = int(m300Status->GetPayloadStatus(M300Status::PAYLOAD_TYPE::CAMERA)); }
    void SetDistanceStatus() override { distanceStatus_ = int(m300Status->GetPayloadStatus(M300Status::PAYLOAD_TYPE::SONAR)); }

    void SetCameraData() override { cameraData_ = m300SensorData->GetCameraData(); }
    void SetGimbalData() override { gimbalData_ = m300SensorData->GetGimbalData(); }
    void SetDistanceData() override { distanceData_ = m300SensorData->GetSonarData(); }
};
class VehicleData_M600 : public VehicleData
{
public:
    M600Gps *m600Gps;
    M600Navigation *m600Navigation;
    M600SensorData *m600SensorData;
    M600Status *m600Status;

    void SetGPSNum() override { gpsNum_ = m600Gps->GetGpsNum(); }
    void SetGPSHealth() override { gpsHealth_ = int(m600Gps->GetGpsHealth()); }
    void SetPosNED() override { posNED_ = m600Navigation->GetPosNed(); }
    void SetPosLLH() override { posLLH_ = m600Navigation->GetPosLlh(); }
    void SetVelHdg() override
    {
        dcmH2B_ = nlab::lib::Dcmf(nlab::lib::Eulerf(euler_(0), euler_(1), 0.0f));
        velHdg_ = dcmH2B_.transpose() * (m600Navigation->GetVelBody());
    }
    void SetEuler() override { euler_ = m600Navigation->GetEuler(); }

    void SetFlightStatus() override { flightStatus_ = int(m600Status->GetFlightStatus()); }
    void SetGimbalStatus() override { gimbalStatus_ = int(m600Status->GetPayloadStatus(M600Status::PAYLOAD_TYPE::GIMBAL)); }
    void SetCameraStatus() override { cameraStatus_ = int(m600Status->GetPayloadStatus(M600Status::PAYLOAD_TYPE::CAMERA)); }
    // void SetDistanceStatus() override { m600Status->GetPayloadStatus(M600Status::PAYLOAD_TYPE(-1)); }
    void SetDistanceStatus() override { std::cout << "M600: Distance status unavailable" << std::endl; }

    void SetCameraData() override { cameraData_ = m600SensorData->GetCameraData(); }
    void SetGimbalData() override { gimbalData_ = m600SensorData->GetGimbalData(); }
    // void SetDistanceData() override { throw std::runtime_error("Distance data unavailable"); }
    void SetDistanceData() override { std::cout << "M600: Distance data unavailable" << std::endl; }

private:
    nlab::lib::Dcmf dcmH2B_ = {};
};

class VehicleData_Mavic : public VehicleData
{
public:
    MavicGps *mavicGps;
    MavicCameraData *mavicCameraData;
    MavicGimbalData *mavicGimbalData;
    MavicIntegratedNavigation *mavicIntegratedNavigation;
    MavicLidarData *mavicLidarData;
    MavicVisualData *mavicVisualData;
    MavicStatus *mavicStatus;

    void SetGPSNum() override { gpsNum_ = mavicGps->GetGpsNum(); }
    void SetGPSHealth() override { gpsHealth_ = int(mavicGps->GetGpsHealth()); }
    void SetPosNED() override { posNED_ = mavicIntegratedNavigation->GetPosNed(); }
    void SetPosLLH() override { posLLH_ = mavicIntegratedNavigation->GetPosLlh(); }
    void SetVelHdg() override { velHdg_ = mavicIntegratedNavigation->GetVelHdg(); }
    void SetEuler() override { euler_ = mavicIntegratedNavigation->GetEuler(); }

    void SetFlightStatus() override { flightStatus_ = int(mavicStatus->GetFlightStatus()); }
    void SetGimbalStatus() override { gimbalStatus_ = int(mavicStatus->GetPayloadStatus(MavicStatus::PAYLOAD_TYPE::GIMBAL)); }
    void SetCameraStatus() override { cameraStatus_ = int(mavicStatus->GetPayloadStatus(MavicStatus::PAYLOAD_TYPE::CAMERA)); }
    void SetDistanceStatus() override { distanceStatus_ = int(mavicStatus->GetPayloadStatus(MavicStatus::PAYLOAD_TYPE::LIDAR)); }

    void SetCameraData() override { cameraData_ = mavicCameraData->GetCameraData(); }
    void SetGimbalData() override { gimbalData_ = mavicGimbalData->GetGimbalData(); }
    void SetDistanceData() override { distanceData_ = mavicLidarData->GetTopLidarDistance(); }
};

class VehicleData_Skydio : public VehicleData
{
public:
    SkydioCamera *skydioCamera;
    SkydioFlightController *skydioFlightController;
    SkydioGimbal *skydioGimbal;
    SkydioGps *skydioGps;
    SkydioLidar *skydioLidar;

    void SetGPSNum() override { gpsNum_ = skydioGps->GetGpsNum(); }
    void SetGPSHealth() override { gpsHealth_ = int(skydioGps->GetGpsHealth()); }
    void SetPosNED() override { posNED_ = skydioFlightController->GetPosNed(); }
    void SetPosLLH() override { posLLH_ = skydioFlightController->GetPosLlh(); }
    void SetVelHdg() override { velHdg_ = skydioFlightController->GetVelHdg(); }
    void SetEuler() override { euler_ = nlab::lib::Eulerf(skydioFlightController->GetQuaternion()); }

    void SetFlightStatus() override { flightStatus_ = int(skydioFlightController->GetFlightStatus()); }
    void SetGimbalStatus() override { gimbalStatus_ = int(skydioGimbal->GetGimbalStatus()); }
    void SetCameraStatus() override { cameraStatus_ = int(skydioCamera->GetCameraStatus()); }
    void SetDistanceStatus() override { distanceStatus_ = int(skydioLidar->GetLidarStatus()); }

    void SetCameraData() override { cameraData_ = skydioCamera->GetCameraData(); }
    void SetGimbalData() override { gimbalData_ = skydioGimbal->GetGimbalData(); }
    void SetDistanceData() override { distanceData_ = skydioLidar->GetForwardLidarDistance(); }
};

#endif // ! VEHICLEDATA_H
