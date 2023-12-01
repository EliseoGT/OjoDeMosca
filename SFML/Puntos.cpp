#include "Puntos.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Puntos::Puntos(int numPuntos, float radio, sf::Color colorInicio, sf::Color colorFinal) : numPuntos(numPuntos), radio(radio), colorInicio(colorInicio), colorFinal(colorFinal) {
    puntos.reserve(numPuntos);
    const float pi = std::acos(-1);
    for (int i = 0; i < numPuntos; ++i) {
        float angulo = 2 * pi * i / numPuntos;
        float x = radio * std::cos(angulo) + 400;
        float y = radio * std::sin(angulo) + 400;
        puntos.push_back(sf::Vector2f(x, y));
    }
}

void Puntos::dibujar(sf::RenderWindow& window) {
    const float pi = std::acos(-1);
    for (int i = 0; i < numPuntos; ++i) {
        for (int j = i + 1; j < numPuntos; ++j) {
            float anguloI = 2 * pi * i / numPuntos;
            float anguloJ = 2 * pi * j / numPuntos;
            float anguloDiferencia = std::abs(anguloJ - anguloI);

            if (!(anguloDiferencia >= pi * 0.99999 && anguloDiferencia <= pi * 1.00001)) {
                sf::Vertex linea[] = { sf::Vertex(puntos[i], colorInicio), sf::Vertex(puntos[j], colorFinal) };
                window.draw(linea, 2, sf::Lines);
            }
        }
    }
}
