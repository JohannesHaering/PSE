#ifndef NEXT_HANDLER_H_
#define NEXT_HANDLER_H_

#include "Pager.hpp"
#include "PagerHandler.hpp"

class NextHandler : public PagerHandler {
    
    public:
        NextHandler(Pager pager);
        void onAction();
 
    private:
        Pager pager;    

};
#endif