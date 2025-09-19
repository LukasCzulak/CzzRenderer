#include "Renderer.hpp"
#include "Utils.hpp"

using namespace std;

bool continueRunning(sf::RenderWindow& window);

int main() {
    Renderer renderer{};
    unsigned int desktopWidth, desktopheight;
    DesktopUtils::getDesktopSize(desktopWidth, desktopheight);
    sf::RenderWindow window(sf::VideoMode(desktopWidth, desktopheight), "CzzRenderer", sf::Style::None);

    sf::Texture framebufferTexture;
    framebufferTexture.create(desktopWidth, desktopheight);

    sf::Sprite framebufferSprite(framebufferTexture);

    while (window.isOpen()) {
        if (!continueRunning(window)) {
            window.close();
        }

        renderer.clear();
        for (int i = 200; i < 500; i++) {
            renderer.paintPixel(400, i, Color::Red);
        }

        framebufferTexture.update(reinterpret_cast<const sf::Uint8*>(renderer.getCanvas()));
        window.clear();
        window.draw(framebufferSprite);
        window.display();
    }

    return 0;
}

bool continueRunning(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if ((event.type == sf::Event::Closed) || 
            (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) 
        {
            return false;
        }
    }
    return true;
}