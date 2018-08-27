#include "PenTool.hpp"
#include "Bitmap.hpp"
#include "Pixel.hpp"

#include <GL/freeglut.h>

void PenTool::getMouseInput(int button, int state, int x, int y)
{
    currentColor = mainColor;
    if (button == GLUT_RIGHT_BUTTON)
    {
	currentColor = secondaryColor;
    }

    if (state == GLUT_DOWN)
    {
        img.setPixelSafe(x, y, currentColor);
    }
}

void PenTool::getKeyboardInput(unsigned char key, int x, int y)
{

}

void PenTool::getMouseMotionInput(int x, int y)
{
    img.setPixelSafe(x, y, currentColor);
}

PenTool::~PenTool()
{
}

