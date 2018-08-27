#ifndef CIRCLETOOL_HEADER__
#define CIRCLETOOL_HEADER__

#include "Tool.hpp"

#include <vector>

class CircleTool : public Tool
{
    public:
	CircleTool(Bitmap& img, Pixel& mainColor, Pixel& secondaryColor)
	    :Tool(img, mainColor, secondaryColor)
	{}

	void getMouseInput(int button, int state, int x, int y);
	void getKeyboardInput(unsigned char key, int x, int y);

	~CircleTool();

    private:
        void drawCircle(int x, int y, int r);

        std::vector<int> positions;
        int index = 0;

};

#endif