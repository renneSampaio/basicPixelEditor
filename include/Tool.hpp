#ifndef TOOL_HEADER__
#define TOOL_HEADER__

class Bitmap;
struct Pixel;

class Tool
{
    public:
	Tool(Bitmap& img, Pixel& mainColor, Pixel& secondaryColor)
	    :img(img), mainColor(mainColor), secondaryColor(secondaryColor)
	{}
	
	virtual void getMouseInput(int button, int state, int x, int y) = 0;
	virtual void getKeyboardInput(unsigned char key, int x, int y) = 0;
	virtual void getMouseMotionInput(int x, int y) {};

	virtual ~Tool() {};

    protected:
	Bitmap& img;
	Pixel& mainColor;
	Pixel& secondaryColor;
};


#endif
