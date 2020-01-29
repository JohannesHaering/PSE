#ifndef DEVICE_HANDLER_H_
#define DEVICE_HANDLER_H_

#include "InferencePageAdapter.hpp"
#include "ResultManager.hpp"
#include "DispatchManager.hpp"

class DeviceHandler 
{
    public: 
		DeviceHandler(InferencePageAdapter* page);
		void onAction();

    private: 
		InferencePageAdapter* page;

};
#endif
