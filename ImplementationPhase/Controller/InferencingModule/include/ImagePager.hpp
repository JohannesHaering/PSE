#ifndef IMAGE_PAGER_H_
#define IMAGE_PAGER_H_

#include "Pager.hpp"

class ImagePager : public Pager {

    public:
        ImagePager(int maxPage, InferencePage page);
        int getCurrentPage();
        void reset(int max);

    private: 
        void disable();  
        
};
#endif