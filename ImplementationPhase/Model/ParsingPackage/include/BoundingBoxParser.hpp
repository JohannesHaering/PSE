#ifndef BOUNDING_BOX_PARSER_H_
#define BOUNDING_BOX_PARSER_H_

#include "Parser.hpp"
#include "BoundingBox.hpp"

#include <string>

class BoundingBoxParser : public Parser<BoundingBox>
{
public:
    BoundingBox parse(std::string toParse);
    std::string parseBack(BoundingBox boundingBox);

private:
    std::string basePartsDelimeter = "$";
    std::string probabilitiesDelimeter = "/";
};
#endif