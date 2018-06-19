#ifndef POLYTOOL_HEADER__
#define POLYTOOL_HEADER__

#include "LineTool.hpp"

#include <vector>

class PolyTool : public LineTool
{
    public:
	PolyTool(Bitmap& img, Pixel& mainColor, Pixel& secondaryColor)
	    :LineTool(img, mainColor, secondaryColor)
	{}

	void getMouseInput(int button, int state, int x, int y);
	void getKeyboardInput(unsigned char key, int x, int y);

	~PolyTool();

    private:
        void drawPoly();

};

#endif