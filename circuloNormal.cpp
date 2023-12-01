#include <SFML/Graphics.hpp>
using namespace sf;

int main() {

    RenderWindow window(VideoMode(300, 300), "SFML works!");
    EllipseShape shape(Vector2f(200.f, 100.f));  // Cambia los par�metros para ajustar el tama�o del �valo
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
