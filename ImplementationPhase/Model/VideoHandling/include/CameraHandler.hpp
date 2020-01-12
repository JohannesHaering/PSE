#ifndef CAMERA_HANDLER_H_
#define CAMERA_HANDLER_H_

#include <opencv2/opencv.hpp>

class CameraHandler
{
public:
    CameraHandler(int deviceId, int timeout);
    ~CameraHandler();
    cv::Mat getNextFrame();

private:
    int deviceId;
    int timeout;
    cv::VideoCapture cameraInput;
}