#ifndef RECTTOOL_HEADER__
#define RECTTOOL_HEADER__

#include "Tool.hpp"

#include <vector>

class RectTool : public Tool
{
    public:
	RectTool(Bitmap& img, Pixel& mainColor, Pixel& secondaryColor)
	    :Tool(img, mainColor, secondaryColor)
	{}

	void getMouseInput(int button, int state, int x, int y);
	void getKeyboardInput(unsigned char key, int x, int y);

	~RectTool();

    private:
        void drawRect(int x1, int y1, int x2, int y2);

        std::vector<int> positions;
        int index = 0;

};

#endif