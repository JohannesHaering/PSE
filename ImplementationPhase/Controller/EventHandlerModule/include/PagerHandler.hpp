#ifndef PAGER_HANDLER_H_
#define PAGER_HANDLER_H_

#include "EventHandler.hpp"
#include "Pager.hpp"
#include "InferencingDistributorClassification.hpp"

class PagerHandler : public EventHandler {
    
    public:
        virtual void onAction() = 0;

    protected:
        Pager* pager;
};
#endif
