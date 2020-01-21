#ifndef DEVICE_HANDLER_H_
#define DEVICE_HANDLER_H_

#include "inferencepageadapter.h"
#include "ResultManager.hpp"

class DeviceHandler 
{
    public: 
		DeviceHandler(InferencePageAdapter page);
		DeviceHandler();
		void onAction();

    private: 
		InferencePageAdapter page;

};
#endif