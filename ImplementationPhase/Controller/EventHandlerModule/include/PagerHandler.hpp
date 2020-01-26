#ifndef PAGER_HANDLER_H_
#define PAGER_HANDLER_H_

#include "EventHandler.hpp"
#include "Pager.hpp"

class PagerHandler : public EventHandler {
    
    public:
        void onAction();

    protected:
        Pager* pager;

};
#endif