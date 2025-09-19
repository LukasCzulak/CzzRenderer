#pragma once

#include "Color.hpp"
#include <SFML/Graphics.hpp>

class Renderer {
public:
    Renderer(unsigned int width, unsigned int height);
    Renderer();
    ~Renderer();

    void clear(Color color = Color::Black);
    void paintPixel(unsigned int x, unsigned int y, Color color);
    void update();
    const Color* getCanvas();
    unsigned int canvasSize() const;

private:
    unsigned int width;
    unsigned int height;
    Color* canvas;
};
