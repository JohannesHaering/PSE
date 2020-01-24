#ifndef PAGER_H_
#define PAGER_H_

#include "inferencepageadapter.h"

class Pager {

	public: 
		void reset(int maxPage);
		void next();
		void prev();
		int getCurrentPage();
		bool nextEnable();
		bool prevEnable();
		ContentView getGUIPage();

	protected: 
		int currentPage;
		int maxPage;
		InferencePageAdapter page;
		virtual void disable();

};
#endif