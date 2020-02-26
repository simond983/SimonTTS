#include <SFML/Graphics.hpp>

#include "SimonTTS.h"

int main()
{
    SimonTTS tts;
    tts.loadAToZFiles("Audio/Letters/a.wav", 'a');


    sf::RenderWindow window(sf::VideoMode(1280, 720), "SimonTTS");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                window.close();
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}