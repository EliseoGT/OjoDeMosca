#ifndef PUNTOS_H
#define PUNTOS_H

#include <SFML/Graphics.hpp>
#include <vector>

class Puntos {
public:
    Puntos(int numPuntos, float radio, sf::Color coloInicio, sf::Color colorFinal);
    void dibujar(sf::RenderWindow& window);

private:
    std::vector<sf::Vector2f> puntos;
    int numPuntos;
    float radio;
    sf::Color colorInicio;
    sf::Color colorFinal;

};

#endif
