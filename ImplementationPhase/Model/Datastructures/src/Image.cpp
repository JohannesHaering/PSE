#include "../include/Image.h"

#include <list>
#include <string>
#include <utility>

using namespace std;

Image::Image(string imageId, int height, int width, int channelNumb, list<int> pixels) : imageId(imageId), height(height), width(width), channelNumb(channelNumb), pixels(pixels) {}
pair<int, int> Image::getPixelPosition(float x, float y)
{
    return make_pair((int)(width * x), (int)(height * y));
};
string Image::getImageId()
{
    return imageId;
}
int Image::getChannelNumb()
{
    return channelNumb;
}
int Image::getWidth()
{
    return width;
}
int Image::getHeight()
{
    return height;
}
list<int> Image::getPixels()
{
    return pixels;
}