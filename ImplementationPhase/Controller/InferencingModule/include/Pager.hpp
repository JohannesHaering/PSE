#ifndef PAGER_H_
#define PAGER_H_

#include "InferencePageAdapter.hpp"

class Pager {

	public: 
		void reset(int maxPage);
		void next();
		void prev();
		int getCurrentPage();
		bool nextEnable();
		bool prevEnable();
		ContentView* getGUIPage();

	protected: 
		int currentPage;
		int maxPage;
		InferencePageAdapter *page;
        virtual void disable() = 0;

};
#endif
