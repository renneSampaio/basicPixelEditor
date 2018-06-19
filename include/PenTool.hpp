#ifndef PENTOOL_HEADER__
#define PENTOOL_HEADER__

#include "Tool.hpp"

class PenTool : public Tool
{
    public:
	PenTool(Bitmap& img, Pixel& mainColor, Pixel& secondaryColor)
	    :Tool(img, mainColor, secondaryColor)
	{}

	void getMouseInput(int button, int state, int x, int y);
	void getKeyboardInput(unsigned char key, int x, int y);
	void getMouseMotionInput(int x, int y);

	~PenTool();
};

#endif
