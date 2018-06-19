#include "RectTool.hpp"
#include "Bitmap.hpp"
#include "Pixel.hpp"

#include <GL/freeglut.h>

void RectTool::getMouseInput(int button, int state, int x, int y)
{
    if (state != GLUT_DOWN) return;

    positions.push_back(x);
    positions.push_back(y);

    if (positions.size() >= 4)
    {
        drawRect(positions[index], positions[index+1], positions[index+2], positions[index+3]);
        positions.clear();
        index = 0;
    }
}

void RectTool::getKeyboardInput(unsigned char key, int x, int y)
{

}

void RectTool::drawRect(int x1, int y1, int x2, int y2)
{
    if (x2 < x1) std::swap(x1, x2);
    if (y2 < y1) std::swap(y1, y2);


    for(int py = y1; py <= y2; py++) {
        img.drawHorizontalLine(x1, py, x2 - x1, mainColor);
    }
}

RectTool::~RectTool()
{
}

