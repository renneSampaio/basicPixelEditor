#include <iostream>

#include "Bitmap.hpp"

int main() 
{
    Bitmap img(100,100);
    img.clear(Pixel{0x01010502});

    img.setPixelSafe(10, 10, 0x14FFFFFF);

    std::cout << +img.getPixelSafe(10,10).r << '\n';
    std::cout << +img.getPixelSafe(40,30).g << '\n';
    std::cout << +img.getPixelSafe(50,10).b << '\n';
    std::cout << +img.getPixelSafe(20,30).a << '\n';

}
