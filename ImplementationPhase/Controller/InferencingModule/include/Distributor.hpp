#ifndef DISTRIBUTOR_H_
#define DISTRIBUTOR_H_

#include "Inferencer.hpp"
#include <string>

class Distributor : public Inferencer {

	public: 
		void setInput(std::vector<std::string> input);
		int getAmountImages();

	protected:
		std::vector<std::string> directories;
		std::map<std::string, cv::Mat> images;

};
#endif