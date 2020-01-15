#ifndef VIDEO_CUTTER_H_
#define VIDEO_CUTTER_H_

#include <opencv2/opencv.hpp>
#include <list>

class VideoCutter {
    public:
        std::list<cv::Mat> cutIntoFrames(cv::VideoCapture video, int frameInterval);
};
#endif
