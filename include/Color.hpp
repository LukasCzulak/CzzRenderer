#pragma once

class Color {
public: 
    Color(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha);
    Color();

    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char alpha;

    static const Color Black;
    static const Color White;
    static const Color Red;
    static const Color Green;
    static const Color Blue;
};