#ifndef IMAGE_PAGER_H_
#define IMAGE_PAGER_H_

#include "Pager.hpp"
#include "InferencePageAdapter.hpp"

class ImagePager : public Pager {

    public:
        ImagePager(int maxPage, InferencePageAdapter *page);
        int getCurrentPage();
        void reset(int max);

    private: 
        void disable();  
        
};
#endif