#include "CircleTool.hpp"
#include "Bitmap.hpp"
#include "Pixel.hpp"

#include <GL/freeglut.h>
#include <cmath>

void CircleTool::getMouseInput(int button, int state, int x, int y)
{
    if (state != GLUT_DOWN) return;

    positions.push_back(x);
    positions.push_back(y);

    if (positions.size() >= 4)
    {
        int a = std::pow( std::abs(positions[index] - x), 2);
        int b = std::pow( std::abs(positions[index+1] - y), 2);
        int r = std::sqrt( a + b );

        drawCircle(positions[index], positions[index+1], r);
        positions.clear();
        index = 0;
    }
}

void CircleTool::getKeyboardInput(unsigned char key, int x, int y)
{

}

void CircleTool::drawCircle(int cx, int cy, int r)
{
    float d = 10/4.0 - 2*r;

    for (int x = r, y = 0; x >= y; y++) {
        img.setPixelSafe(cx + x, cy + y, mainColor);
        img.setPixelSafe(cx - x, cy + y, mainColor);
        img.setPixelSafe(cx + x, cy - y, mainColor);
        img.setPixelSafe(cx - x, cy - y, mainColor);
        img.setPixelSafe(cx + y, cy + x, mainColor);
        img.setPixelSafe(cx - y, cy + x, mainColor);
        img.setPixelSafe(cx + y, cy - x, mainColor);
        img.setPixelSafe(cx - y, cy - x, mainColor);

        if (d < 0) {
            d += 4*y + 6;
        } else {
            x--;
            d += 4*(y - x) + 10;
        }
    }
}

CircleTool::~CircleTool()
{
}

