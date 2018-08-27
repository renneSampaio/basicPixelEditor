#ifndef FILLTOOL_HEADER__
#define FILLTOOL_HEADER__

#include "Tool.hpp"

class FillTool : public Tool
{
    public:
    FillTool(Bitmap& img, Pixel& mainColor, Pixel& secondaryColor)
        :Tool(img, mainColor, secondaryColor)
    {}

    void getMouseInput(int button, int state, int x, int y);
    void getKeyboardInput(unsigned char key, int x, int y);

    ~FillTool() {}

    private:
    void fill(int x, int y, Pixel oldColor, Pixel newColor);
};

#endif
