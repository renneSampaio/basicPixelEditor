#include "PolyTool.hpp"
#include "Bitmap.hpp"
#include "Pixel.hpp"

#include <GL/freeglut.h>

void PolyTool::getMouseInput(int button, int state, int x, int y)
{
    if (state != GLUT_DOWN) return;

    positions.push_back(x);
    positions.push_back(y);

    if (positions.size() >= 4) 
    {
        drawLineBresenham(positions[index], positions[index+1], positions[index+2], positions[index+3]);
        index+=2;
    }

    if (button == GLUT_RIGHT_BUTTON)
    {
        drawPoly();
        positions.clear();
        index = 0;
    }
}

void PolyTool::getKeyboardInput(unsigned char key, int x, int y)
{

}

void PolyTool::drawPoly()
{
    drawLineBresenham(positions[index], positions[index+1], positions[0], positions[1]);
}

PolyTool::~PolyTool()
{
}

