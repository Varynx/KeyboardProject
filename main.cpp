#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle Example");

    // Create a circle shape
    sf::CircleShape circle(100.f); // Radius of 100
    circle.setFillColor(sf::Color::Green); // Set the color to green
    circle.setPosition(350, 250); // Set the position of the circle in the window

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close(); // Close the window when the close event is triggered
            }
            // Handle mouse move event
            if (event.type == sf::Event::MouseMoved) {
                // Get the mouse position
                int mouseX = event.mouseMove.x;
                int mouseY = event.mouseMove.y;

                // Output the mouse position to the console
                std::cout << "Mouse moved to: (" << mouseX << ", " << mouseY << ")\n";
            }
        }

        // Clear the window
        window.clear(sf::Color::Black);

        // Draw the circle
        window.draw(circle);

        // Display the contents of the window
        window.display();

    }
    return 0;
}