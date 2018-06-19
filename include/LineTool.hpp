#ifndef LINETOOL_HEADER__
#define LINETOOL_HEADER__

#include "Tool.hpp"

#include <vector>

class LineTool : public Tool
{
    public:
	LineTool(Bitmap& img, Pixel& mainColor, Pixel& secondaryColor)
	    :Tool(img, mainColor, secondaryColor)
	{}

	virtual void getMouseInput(int button, int state, int x, int y);
	virtual void getKeyboardInput(unsigned char key, int x, int y);

	~LineTool();

    protected:
        void drawLine();
        void drawLineBresenham(int x1, int y1, int x2, int y2);
        void drawLineDDA(int x1, int y1, int x2, int y2);
        void drawLineMediumPoint(int x1, int y1, int x2, int y2);


        std::vector<int> positions;
        int index = 0;

};

#endif
