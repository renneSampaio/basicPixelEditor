#ifndef PENTOOL_HEADER__
#define PENTOOL_HEADER__

#include "Tool.hpp"
#include "Pixel.hpp"

class PenTool : public Tool
{
    public:
	PenTool(Bitmap& img, Pixel& mainColor, Pixel& secondaryColor)
	    :Tool(img, mainColor, secondaryColor), currentColor(mainColor)
	{}

	void getMouseInput(int button, int state, int x, int y);
	void getKeyboardInput(unsigned char key, int x, int y);
	void getMouseMotionInput(int x, int y);

	~PenTool();

    private:
	Pixel currentColor;
};

#endif
