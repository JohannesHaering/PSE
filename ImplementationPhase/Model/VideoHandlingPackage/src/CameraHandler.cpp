#include "CameraHandler.hpp"

#include <opencv2/opencv.hpp>
#include <stdexcept>

CameraHandler::CameraHandler(int deviceId, int timeout) : deviceId(deviceId), timeout(timeout)
{
    cameraInput = cv::VideoCapture().open(deviceId);
    if (!cameraInput.isOpened())
    {
        throw std::invalid_argument("Camera cant be opened");
    }

    cameraInput.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cameraInput.set(cv::CAP_PROP_FRAME_HEIGHT, 480); //changed both from camera.set to cameraInput.set
}
cv::Mat CameraHandler::getNextFrame()
{
    cv::Mat frame;
    auto success = cameraInput.read(frame);
    if (!success)
    {
        throw std::invalid_argument("Frame couldnt be read");
    }
    return frame;
}

CameraHandler::~CameraHandler()
{
    cameraInput.release();
}
