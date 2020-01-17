#include "VideoHandler.hpp"
#include "VideoCutter.hpp"

#include <opencv2/opencv.hpp>
#include <list>

VideoHandler::VideoHandler(int frameInterval) : frameInterval(frameInterval) {}

std::list<cv::Mat> VideoHandler::handleVideo(cv::VideoCapture video)
{
    std::list<cv::Mat> frames = VideoCutter().cutIntoFrames(video, frameInterval);
<<<<<<< HEAD
    return frames;
}
=======
}
>>>>>>> staging
