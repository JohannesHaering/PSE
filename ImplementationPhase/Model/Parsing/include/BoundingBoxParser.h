#ifndef BOUNDING_BOX_PARSER
#define BOUNDING_BOX_PARSER

#include "Parser.h"
#include "../../ResultModel/include/BoundingBox.h"

#include <string>
#include <list>

using namespace std;

class BoundingBoxParser : public Parser<BoundingBox> {
    public:
        BoundingBox parse(string toParse);
    private:
        string basePartsDelimeter = "$";
        string probabilitiesDelimeter = "/";
};
#endif