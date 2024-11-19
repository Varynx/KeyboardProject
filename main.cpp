
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Keyboard
{
private:
    sf::RenderWindow keyboardWindow;

public:
    Keyboard() : keyboardWindow(sf::VideoMode(800,600),"Keyboard Window") {
        keyboardWindow.setFramerateLimit(60);
    }

    void keyboardEvent()
    {
        sf::Event event;// event object holds information about an event(key

        while(keyboardWindow.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                keyboardWindow.close();
            }
            if (event.key.code == sf::Keyboard::Escape) {
                keyboardWindow.close();
            }
        }
    }

    void keyboardLogic()
    {
        sf::Event keyboardEvent;// event object holds information about an event(key

        while(keyboardWindow.pollEvent(keyboardEvent))
        {
            if(keyboardEvent.type == sf::Event::KeyPressed) {//checks if key is pressed(so it only checks once a button has been pressed)
                if (keyboardEvent.key.code == sf::Keyboard::A) {

                }
            }
        }
    }
    void renderWindow()
    {
        keyboardWindow.clear();

        //draw stuff here

        keyboardWindow.display();
    }

    //main method to initiate, includes logic update and window update
    void runKeyboard()
    {
        while(keyboardWindow.isOpen())
        {
            keyboardEvent(); //handles events (keys, mouse)
            keyboardLogic();
            renderWindow(); //clear window and display everything

        }
    }
};


int main()
{
    Keyboard keyboardObj, *keyboardPtr = &keyboardObj;

    keyboardPtr->runKeyboard();
}




// SFML has internal events, which are stored somewhere. The object we created stores the events that come from the pollEvent function,
// which continuously checks for events in order. Now, the object of type sf::Event contains data that we can compare to our existing items,
// such as Close, Escape, or KeyboardPressed
