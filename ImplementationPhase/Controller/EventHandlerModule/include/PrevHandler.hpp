#ifndef PREV_HANDLER_H_
#define PREV_HANDLER_H_

#include "Pager.hpp"
#include "PagerHandler.hpp"

class PrevHandler : public PagerHandler {

    public:
        PrevHandler(Pager* pager, Pager* otherPager, InferencingDistributorClassification* inferencer);   
        void onAction() override;

};
#endif
