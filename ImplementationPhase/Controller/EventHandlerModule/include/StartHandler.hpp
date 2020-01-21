#ifndef START_HANDLER_H_
#define START_HANDLER_H_

#include "EventHandler.hpp"
#include "Inferencer.hpp"

class StartHandler : public EventHandler {

    public: 
        StartHandler(Inferencer inferencer);
		StartHandler();
        void onAction();

    private:
        Inferencer inferencer;    

};
#endif