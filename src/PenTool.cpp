#include "PenTool.hpp"
#include "Bitmap.hpp"
#include "Pixel.hpp"

#include <GL/freeglut.h>

void PenTool::getMouseInput(int button, int state, int x, int y)
{
    Pixel color = mainColor;
    if (button == GLUT_RIGHT_BUTTON)
    {
	color = secondaryColor;
    }

    if (state == GLUT_DOWN)
    {
        img.setPixelSafe(x, y, color);
    }
}

void PenTool::getKeyboardInput(unsigned char key, int x, int y)
{

}

void PenTool::getMouseMotionInput(int x, int y)
{
    img.setPixelSafe(x, y, mainColor);
}

PenTool::~PenTool()
{
}

