#include "FillTool.hpp"
#include "Bitmap.hpp"
#include "Pixel.hpp"

#include <vector>
#include <GL/freeglut.h>

void FillTool::getMouseInput(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
        fill(x, y, img.getPixelSafe(x, y), mainColor);
}

void FillTool::getKeyboardInput(unsigned char key, int x, int y)
{
}

void FillTool::fill(int x, int y, Pixel oldColor, Pixel newColor)
{
    std::vector<int> pontos;
    pontos.push_back(x);
    pontos.push_back(y);

    while(!pontos.empty())
    {
        int _y = pontos.back(); pontos.pop_back();
        int _x = pontos.back(); pontos.pop_back();

        img.setPixelSafe(_x, _y, newColor);

        if (_x > 0 && ( img.getPixelSafe(_x-1, _y) == oldColor) ) {
            pontos.push_back(_x-1);
            pontos.push_back(_y);
        }

        if (_y < img.getHeight() && ( img.getPixelSafe(_x, _y+1) == oldColor) ) {
            pontos.push_back(_x);
            pontos.push_back(_y + 1);
        }
        
        if (_x < img.getWidth() && ( img.getPixelSafe(_x+1, _y) == oldColor) ) {
            pontos.push_back(_x+1);
            pontos.push_back(_y);
        }

        if (_y > 0 && ( img.getPixelSafe(_x, _y-1) == oldColor) ){
            pontos.push_back(_x);
            pontos.push_back(_y-1);
        }

    }

}
