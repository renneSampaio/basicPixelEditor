#ifndef PIXEL_HEADER__
#define PIXEL_HEADER__

#include <cstdint>

struct Pixel {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 0;
    
    Pixel() {};

    Pixel(uint32_t color) 
    {
	*this = color;
    };

    Pixel(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a)
	:r(_r), g(_g), b(_b), a(_a)
    {}
    
    Pixel& operator=(uint32_t color) {
	r = (color & 0xFF000000) >> 24;
	g = (color & 0x00FF0000) >> 16;
	b = (color & 0x0000FF00) >> 8;
	a = (color & 0x000000FF) >> 0;

	return *this;
    }
};

#endif

