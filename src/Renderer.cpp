#include "Renderer.hpp"
#include <Utils.hpp>

Renderer::Renderer(unsigned int width, unsigned int height)
    : width(width), height(height) {
    canvas = new Color[width * height];
}

Renderer::Renderer() {
    DesktopUtils::getDesktopSize(width, height);
    canvas = new Color[width * height];
}

Renderer::~Renderer() {
    delete[] canvas;
}

unsigned int Renderer::canvasSize() const {
    return width * height;
}

void Renderer::clear(Color color) {
    for (unsigned int i = 0; i < canvasSize(); i++) {
        canvas[i] = color;
    }
}

void Renderer::paintPixel(unsigned int x, unsigned int y, Color color) {
    if (x >= width || y >= height) {
        return;
    }
    unsigned int index = y * width + x;
    canvas[index] = color;
}

void Renderer::update() {
    return;
}

const Color* Renderer::getCanvas() {
    return canvas;
}