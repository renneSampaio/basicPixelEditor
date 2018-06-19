#include "LineTool.hpp"
#include "Bitmap.hpp"
#include "Pixel.hpp"

#include <iostream>

#include <GL/freeglut.h>

void LineTool::getMouseInput(int button, int state, int x, int y)
{
    if (state != GLUT_DOWN) {
        return;
    }

    positions.push_back(x);
    positions.push_back(y);

    if (button == GLUT_LEFT_BUTTON) 
    {
        drawLine();

    } else if (button == GLUT_RIGHT_BUTTON)
    {
        drawLine();

        positions.clear();
        index = 0;
    }
}

void LineTool::getKeyboardInput(unsigned char key, int x, int y)
{

}

void LineTool::drawLine()
{
    if (positions.size() < 4) return;

    drawLineBresenham(positions[index], positions[index+1], positions[index+2], positions[index+3]);
    //drawLineDDA(positions[index], positions[index+1], positions[index+2], positions[index+3]);
    //drawLineMediumPoint(positions[index], positions[index+1], positions[index+2], positions[index+3]);
    index+=2;
}

void LineTool::drawLineBresenham(int x1, int y1, int x2, int y2)
{
    bool mirror = false;
    if (y2 > y1) {
        y2 = y2 -2*(y2 - y1);
        mirror = true;
    }
    
    int deltaX = x2 - x1;
    int deltaY = y1 - y2;

    // Base case: First Octant
    int a = deltaY;
    int b = -deltaX;

    if (deltaX >= 0 && std::abs(deltaX) >= std::abs(deltaY)) { // FIRST OCTANT
        int dM = 2*a + b;
        int y = y1;
        for (int x = x1; x <= x2; x++) {
            if (mirror)
                img.setPixelSafe(x, y + 2*(y1 - y), mainColor);
            else
                img.setPixelSafe(x, y, mainColor);
            if (dM > 0) {
                y--;
                dM += 2*a + 2*b;
            } else {
                dM += 2*a;
            }
        }
    } else 
    if (deltaX >= 0 && std::abs(deltaX) < std::abs(deltaY)) { // SECOND OCTANT
        int dM = a + 2*b;
        int x = x1;
        for (int y = y1; y >= y2; y--) {
            if (mirror)
                img.setPixelSafe(x, y + 2*(y1 - y), mainColor);
            else
                img.setPixelSafe(x, y, mainColor);
            if (dM < 0) {
                x++;
                dM += 2*a + 2*b;
            } else {
                dM += 2*b;
            }
        }
    } else 
    if (deltaX < 0 && std::abs(deltaY) >= std::abs(deltaX)) { // THIRD OCTANT
        int dM = -a + 2*b;
        int x = x1;
        for (int y = y1; y >= y2; y--) {
            if (mirror)
                img.setPixelSafe(x, y + 2*(y1 - y), mainColor);
            else
                img.setPixelSafe(x, y, mainColor);
            if (dM > 0) {
                x--;
                dM += -2*a + 2*b;
            } else {
                dM += 2*b;
            }
        }
    } else
    if ( deltaX < 0 && std::abs(deltaY) < std::abs(deltaX)) { // FOURTH OCTANT
        int dM = -2*a + b;
        int y = y1;
        for (int x = x1; x >= x2; x--) {
            if (mirror)
                img.setPixelSafe(x, y + 2*(y1 - y), mainColor);
            else
                img.setPixelSafe(x, y, mainColor);
            if (dM < 0) {
                y--;
                dM += -2*a + 2*b;
            } else {
                dM += -2*a;
            }
        }
    }
}

void LineTool::drawLineDDA(int x1, int y1, int x2, int y2)
{
    if (std::min(x1, x2) == x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }

    int delta = std::max(std::abs(x2 - x1), std::abs(y2 - y1));

    for (int i = 0; i <= delta; i++) {
        float t = (float)i/delta;
        float px = x1 + (x2 - x1) * t;
        float py = y1 + (y2 - y1) * t;
        img.setPixelSafe(px, py, mainColor);
    }
}

void LineTool::drawLineMediumPoint(int x1, int y1, int x2, int y2)
{
    if (std::abs(x1 - x2) <= 1 && std::abs(y1 - y2) <= 1) {
        img.setPixelSafe(x1, y1, mainColor);
        img.setPixelSafe(x2, y2, mainColor);
    } else {
        int xMedio = (x1 + x2)/2;
        int yMedio = (y1 + y2)/2;
        drawLineMediumPoint(x1, y1, xMedio, yMedio);
        drawLineMediumPoint(xMedio, yMedio, x2, y2);
    }
}

LineTool::~LineTool()
{
}

