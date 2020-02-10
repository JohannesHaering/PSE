#include "VideoCutter.hpp"

#include <opencv2/opencv.hpp>
#include <list>
#include <stdexcept>

std::list<cv::Mat> VideoCutter::cutIntoFrames(cv::VideoCapture video, int frameInterval)
{
    if (!video.isOpened())
    {
        throw std::invalid_argument("Video file cant be opened");
    }

    std::list<cv::Mat> frames;
    int counter = 0;

    while (true)
    {
        cv::Mat frame;
        // Capture frame-by-frame
        video >> frame;

        if (frame.empty())
        {
            break;
        }

        if (counter % frameInterval == 0)
        {
            frames.push_back(frame);
        }
        counter += 1;
    }
    return frames;
}
