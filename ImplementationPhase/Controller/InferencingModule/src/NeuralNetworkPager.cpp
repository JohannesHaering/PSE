#include "Pager.hpp"
#include "NeuralNetworkPager.hpp"

/*
* Creates a Pager that keeps track of neural networks.
* Parameters:
* -int maxPage: the maximum amount of pages that can be displayed
* -InferencePageAdapter page: the page that displays the results
*/
NeuralNetworkPager::NeuralNetworkPager(int maxPage, InferencePageAdapter *page) {
    this->maxPage = maxPage;
    this->page = page;
    this->currentPage = 0;
}

/*
* Checks if a button should be disabled and calls the view.
*/
void NeuralNetworkPager::disable() {
    page->nextNNEnable(nextEnable());
    page->prevNNEnable(prevEnable());
}    

