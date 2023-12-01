#include <SFML/Graphics.hpp>
#include "Puntos.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Ojo de Mosca");

    int numPuntos = 30;
    float radio = 200.0f;
    sf::Color inicio = sf::Color(0, 255, 255);
    sf::Color finale = sf::Color(255, 255, 0);

    Puntos puntos(numPuntos, radio, inicio, finale);

    while (window.isOpen()) {
        sf::Event evento;
        while (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        puntos.dibujar(window);
        window.display();
    }

    return 0;
}
