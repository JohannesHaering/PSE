#ifndef PAGER_H_
#define PAGER_H_

#include "InferencePage.hpp"

class Pager {

	public: 
		void reset(int maxPage);
		void next();
		void prev();
		int getCurrentPage();

	protected: 
		int currentPage;
		int maxPage;
		InferencePage page;
		virtual void disable();

};
#endif