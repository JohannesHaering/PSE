#ifndef DEVICE_HANDLER_H_
#define DEVICE_HANDLER_H_

#include "InferencePage.hpp"
#include "ResultManager.hpp"

class DeviceHandler 
{
    public: 
		DeviceHandler(InferencePage page);
		DeviceHandler();
		void onAction();

    private: 
		InferencePage page;

};
#endif