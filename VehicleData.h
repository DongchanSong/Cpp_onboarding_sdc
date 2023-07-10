#ifndef VEHICLEDATA_H
#define VEHICLEDATA_H

#include "different_api/m300/gps/gps.h"
#include "different_api/m300/navigation/navigation.h"
#include "different_api/m300/sensor_data/sensor_data.h"
#include "different_api/m300/status/status.h"

#include "different_api/m600/gps/gps.h"
#include "different_api/m600/navigation/navigation.h"
#include "different_api/m600/sensor_data/sensor_data.h"
#include "different_api/m600/status/status.h"

#include "different_api/mavic/gps/gps.h"
#include "different_api/mavic/sensor/camera_data/camera_data.h"
#include "different_api/mavic/sensor/gimbal_data/gimbal_data.h"
#include "different_api/mavic/sensor/integrated_navigation/integrated_navigation.h"
#include "different_api/mavic/sensor/lidar_data/lidar_data.h"
#include "different_api/mavic/sensor/visual_data/visual_data.h"
#include "different_api/mavic/status/status.h"

#include "different_api/skydio/camera/camera.h"
#include "different_api/skydio/flight_controller/flight_controller.h"
#include "different_api/skydio/gimbal/gimbal.h"
#include "different_api/skydio/gps/gps.h"
#include "different_api/skydio/lidar/lidar.h"

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

    virtual float GetGPSNum() = 0;
    virtual int GetGPSHealth() = 0;
    virtual nlab::lib::Vector3f GetPosNED() = 0;
    virtual nlab::lib::Vector3 GetPosLLH() = 0;
    // virtual nlab::lib::Vector3f GetVelBody() = 0;
    virtual nlab::lib::Vector3f GetVelHdg() = 0;
    virtual nlab::lib::Vector3f GetEuler() = 0;

    virtual int GetFlightStatus() = 0;
    virtual int GetGimbalStatus() = 0;
    virtual int GetCameraStatus() = 0;
    virtual int GetDistanceStatus() = 0;

    virtual std::vector<std::vector<int>> GetCameraData() = 0;
    virtual nlab::lib::Vector3f GetGimbalData() = 0;
    virtual float GetDistanceData() = 0;

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

    float GetGPSNum() override { return gpsNum_; }
    int GetGPSHealth() override { return gpsHealth_; }
    nlab::lib::Vector3f GetPosNED() override { return posNED_; }
    nlab::lib::Vector3 GetPosLLH() override { return posLLH_; }
    nlab::lib::Vector3f GetVelHdg() override { return velHdg_; }
    nlab::lib::Vector3f GetEuler() override { return euler_; }

    int GetFlightStatus() override { return flightStatus_; }
    int GetGimbalStatus() override { return gimbalStatus_; }
    int GetCameraStatus() override { return cameraStatus_; }
    int GetDistanceStatus() override { return distanceStatus_; }

    std::vector<std::vector<int>> GetCameraData() override { return cameraData_; }
    nlab::lib::Vector3f GetGimbalData() override { return gimbalData_; }
    float GetDistanceData() override { return distanceData_; }
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
    void SetVelBody() { velBody_ = m600Navigation->GetVelBody(); }
    void SetVelHdg() override
    {
        dcmH2B_ = nlab::lib::Dcmf(nlab::lib::Eulerf(euler_(0), euler_(1), 0.0f));
        velHdg_ = dcmH2B_.transpose() * (m600Navigation->GetVelBody());
    }
    void SetEuler() override { euler_ = m600Navigation->GetEuler(); }

    void SetFlightStatus() override { flightStatus_ = int(m600Status->GetFlightStatus()); }
    void SetGimbalStatus() override { gimbalStatus_ = int(m600Status->GetPayloadStatus(M600Status::PAYLOAD_TYPE::GIMBAL)); }
    void SetCameraStatus() override { cameraStatus_ = int(m600Status->GetPayloadStatus(M600Status::PAYLOAD_TYPE::CAMERA)); }
    void SetDistanceStatus() override { std::cout << "M600: Distance status unavailable" << std::endl; }

    void SetCameraData() override { cameraData_ = m600SensorData->GetCameraData(); }
    void SetGimbalData() override { gimbalData_ = m600SensorData->GetGimbalData(); }
    void SetDistanceData() override { std::cout << "M600: Distance data unavailable" << std::endl; }

    float GetGPSNum() override { return gpsNum_; }
    int GetGPSHealth() override { return gpsHealth_; }
    nlab::lib::Vector3f GetPosNED() override { return posNED_; }
    nlab::lib::Vector3 GetPosLLH() override { return posLLH_; }
    nlab::lib::Vector3f GetVelBody() { return velBody_; }
    nlab::lib::Vector3f GetVelHdg() override { return velHdg_; }
    nlab::lib::Vector3f GetEuler() override { return euler_; }

    int GetFlightStatus() override { return flightStatus_; }
    int GetGimbalStatus() override { return gimbalStatus_; }
    int GetCameraStatus() override { return cameraStatus_; }
    int GetDistanceStatus() override { return -1; }

    std::vector<std::vector<int>> GetCameraData() override { return cameraData_; }
    nlab::lib::Vector3f GetGimbalData() override { return gimbalData_; }
    float GetDistanceData() override { return -1; }

private:
    nlab::lib::Dcmf dcmH2B_ = {};
    nlab::lib::Vector3f velBody_;
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

    float GetGPSNum() override { return gpsNum_; }
    int GetGPSHealth() override { return gpsHealth_; }
    nlab::lib::Vector3f GetPosNED() override { return posNED_; }
    nlab::lib::Vector3 GetPosLLH() override { return posLLH_; }
    nlab::lib::Vector3f GetVelHdg() override { return velHdg_; }
    nlab::lib::Vector3f GetEuler() override { return euler_; }

    int GetFlightStatus() override { return flightStatus_; }
    int GetGimbalStatus() override { return gimbalStatus_; }
    int GetCameraStatus() override { return cameraStatus_; }
    int GetDistanceStatus() override { return distanceStatus_; }

    std::vector<std::vector<int>> GetCameraData() override { return cameraData_; }
    nlab::lib::Vector3f GetGimbalData() override { return gimbalData_; }
    float GetDistanceData() override { return distanceData_; }
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
    void SetQuaternion() { quaternion_ = skydioFlightController->GetQuaternion(); }
    void SetEuler() override { euler_ = nlab::lib::Eulerf(skydioFlightController->GetQuaternion()); }

    void SetFlightStatus() override { flightStatus_ = int(skydioFlightController->GetFlightStatus()); }
    void SetGimbalStatus() override { gimbalStatus_ = int(skydioGimbal->GetGimbalStatus()); }
    void SetCameraStatus() override { cameraStatus_ = int(skydioCamera->GetCameraStatus()); }
    void SetDistanceStatus() override { distanceStatus_ = int(skydioLidar->GetLidarStatus()); }

    void SetCameraData() override { cameraData_ = skydioCamera->GetCameraData(); }
    void SetGimbalData() override { gimbalData_ = skydioGimbal->GetGimbalData(); }
    void SetDistanceData() override { distanceData_ = skydioLidar->GetForwardLidarDistance(); }

    float GetGPSNum() override { return gpsNum_; }
    int GetGPSHealth() override { return gpsHealth_; }
    nlab::lib::Vector3f GetPosNED() override { return posNED_; }
    nlab::lib::Vector3 GetPosLLH() override { return posLLH_; }
    nlab::lib::Vector3f GetVelHdg() override { return velHdg_; }
    nlab::lib::Quaternionf GetQuaternion() { return quaternion_; }
    nlab::lib::Vector3f GetEuler() override { return euler_; }

    int
    GetFlightStatus() override
    {
        return flightStatus_;
    }
    int GetGimbalStatus() override { return gimbalStatus_; }
    int GetCameraStatus() override { return cameraStatus_; }
    int GetDistanceStatus() override { return distanceStatus_; }

    std::vector<std::vector<int>> GetCameraData() override { return cameraData_; }
    nlab::lib::Vector3f GetGimbalData() override { return gimbalData_; }
    float GetDistanceData() override { return distanceData_; }

private:
    nlab::lib::Quaternionf quaternion_;
};

#endif // ! VEHICLEDATA_H
