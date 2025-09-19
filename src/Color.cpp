#include "Color.hpp"

Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha)
    : r(r), g(g), b(b), alpha(alpha) {

    }

Color::Color()
    : r(0), g(0), b(0), alpha(0) {

    }

const Color Color::Black(0, 0, 0, 255);
const Color Color::White(255, 255, 255, 255);
const Color Color::Red(255, 0, 0, 255);
const Color Color::Green(0, 255, 0, 255);
const Color Color::Blue(0, 0, 255, 255);
