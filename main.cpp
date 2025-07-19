#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML window");

    const sf::Font font("font.ttf");
    sf::Text text(font, "Hello world", 50);
    text.setPosition({ 50, 50 });

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            const auto keyEvent = event->getIf<sf::Event::KeyPressed>();
            if (keyEvent) {
                // Ctrl-Q will close also
                if (keyEvent->code == sf::Keyboard::Key::Q && keyEvent->control) {
                    window.close();
                }
                if (keyEvent->code == sf::Keyboard::Key::S && keyEvent->alt) {
                    text.setString("Alt-S pressed");
                }
                if (keyEvent->code == sf::Keyboard::Key::S
                    && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RAlt)) {
                    text.setString("AltGr-S pressed");
                }
            }
        }

        // Clear screen
        window.clear();
        window.draw(text);
        window.display();
    }
}