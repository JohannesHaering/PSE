#ifndef IMAGE_PAGER_H_
#define IMAGE_PAGER_H_

#include "Pager.hpp"
#include "InferencePageAdapter.hpp"

class ImagePager : public Pager {

    public:
        ImagePager(int maxPage, InferencePageAdapter *page);

    private: 
        void disable();  
        
};
#endif
