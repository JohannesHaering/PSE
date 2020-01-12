#include "CameraHandler.hpp"

#include <opencv2/opencv.hpp>
#include <stdexcept>

CameraHandler(int deviceId, int timeout) : deviceId(deviceId), timeout(timeout)
{
    cameraInput = cv::VideoCapture().open(deviceId);
    if (!cameraInput.isOpened())
    {
        throw std::invalid_argument("Camera cant be opened");
    }

    camera.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
}
cv::Mat getNextFrame()
{
    cv::Mat frame;
    auto success = cameraInput.read(frame);
    if (!success)
    {
        throw std::invalid_argument("Frame couldnt be read");
    }
    return frame;
}

~CameraHandler()
{
    cameraInput.release();
}