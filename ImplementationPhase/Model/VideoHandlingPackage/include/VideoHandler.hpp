#ifndef VIDEO_HANDLER_H_
#define VIDEO_HANDLER_H_

#include <opencv2/opencv.hpp>
#include <list>

class VideoHandler {
    public:
        VideoHandler(int frameInterval);
        std::list<cv::Mat> handleVideo(cv::VideoCapture video);
    private:
    int frameInterval = 1;
};
#endif