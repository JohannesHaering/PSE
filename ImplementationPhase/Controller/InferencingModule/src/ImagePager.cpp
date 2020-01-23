#include "Pager.hpp"
#include "ImagePager.hpp"
#include "InferencePageAdapter.hpp"

/*
* Creates a Pager that keeps track of the displayed Images
* Parameters:
* -int maxPage: the maximum numbers of images that can be displayed
*/
ImagePager::ImagePager(int maxPage, InferencePageAdapter page) {
    this->maxPage = maxPage;
    this->page = page;
}

/*
* Checks if a button on the gui should be disabled and calls the gui in that case
*/ 
void ImagePager::disable() {
    page.nextImageEnable(nextEnable());
    page.prevImageEnable(prevEnable());
}    
