#include "Sound.h"
#include "keyboard.h"

#include <fstream>
#include <iostream>
#include <unordered_map>

// Constructor definition
Keyboard::Keyboard() : keyboardWindow(sf::VideoMode(1920, 1200), "Keyboard Window") {
    keyboardWindow.setFramerateLimit(60);
    for (int pianoIter = 0; pianoIter < sizeOfPiano; pianoIter++)
    {
        std::string name = "../assets/sounds/pianoKeyIndex-mp3/note" + std::to_string(pianoIter) + ".mp3";
        if (!pianoBuffer[pianoIter].loadFromFile(name))
        {
            std::cerr << "Failed to load note";
        }
        pianoSound[pianoIter].setBuffer(pianoBuffer[pianoIter]);
    }

    //loads jpg image from computer
    backgroundTexture.loadFromFile("../assets/textures/beigeBackground.jpg");
    backgroundImage.setTexture(&backgroundTexture);
    backgroundImage.setSize(sf::Vector2f(2400,1600));

    //loads in gradient for white and black key textures (change filepath as needed)
    whiteKeyTexture.loadFromFile("C:/Users/bauti/KeyboardProjectFiles/beigeToWhite.jpg");
    whiteKeyTextureDark.loadFromFile("C:/Users/bauti/KeyboardProjectFiles/beigeToWhite_Dark.jpg");
    blackKeyTexture.loadFromFile("C:/Users/bauti/KeyboardProjectFiles/blackGradient.jpg");
    blackKeyTextureLight.loadFromFile("C:/Users/bauti/KeyboardProjectFiles/blackTextureLight.jpg");

    if(!pianoIndexFont.loadFromFile("C:/Users/bauti/KeyboardProjectFiles/LexendDeca-VariableFont_wght.ttf"))
    {
        std::cerr << "Unable to load font." << std::endl;
    }

    //FOR PURPOSES OF INITIALIZING THE SPACING BETWEEN THE BLACK KEYS PROPERLY (notes and characters)
    std::set<int> xPositionSkip = {38,41,43,46,48,51,53,56,58};

    //WHITE KEYS INITIALIZED BELOW

    // START OF PIANO INDEX SYMBOLS INITIALIZATION (lowercase letters, numbers)
    float xPositionSymbolsWhite = 20;
    float yPositionSymbolsWhite = 1000;

    std::ifstream pianoIndexSymbolsLower("C:/Users/bauti/KeyboardProjectFiles/pianoIndexLetters_WhiteKeys.txt");
    if(pianoIndexSymbolsLower.is_open())
    {
        int currentIter = 0;
        std::string indexSymbolsLower;
        while(std::getline(pianoIndexSymbolsLower,indexSymbolsLower))
        {
            keyboardCharacters[currentIter].setFont(pianoIndexFont);
            keyboardCharacters[currentIter].setCharacterSize(40);
            keyboardCharacters[currentIter].setFillColor(sf::Color::Black);
            keyboardCharacters[currentIter].setOutlineColor(sf::Color::White);
            keyboardCharacters[currentIter].setOutlineThickness(2);
            keyboardCharacters[currentIter].setString(indexSymbolsLower);
            keyboardCharacters[currentIter].setPosition(sf::Vector2f(xPositionSymbolsWhite,yPositionSymbolsWhite));

            currentIter++;
            xPositionSymbolsWhite += 66.6;
        }
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
    pianoIndexSymbolsLower.close();

    // START OF PIANO INDEX SYMBOLS INITIALIZATION (special characters, uppercase letters)
    float xPositionSymbolsBlack = 53;
    float yPositionSymbolsBlack = 800;
    std::ifstream pianoIndexSymbolsUpper("C:/Users/bauti/KeyboardProjectFiles/pianoIndexLetters_BlackKeys.txt");
    if(pianoIndexSymbolsUpper.is_open())
    {
        int currentIter = 36;
        std::string indexSymbolsUpper;
        while(std::getline(pianoIndexSymbolsUpper,indexSymbolsUpper))
        {
            if(xPositionSkip.find(currentIter) != xPositionSkip.end())
            {
                xPositionSymbolsBlack += 66.6;
            }
            keyboardCharacters[currentIter].setFont(pianoIndexFont);
            keyboardCharacters[currentIter].setCharacterSize(30);
            keyboardCharacters[currentIter].setFillColor(sf::Color::Black);
            keyboardCharacters[currentIter].setOutlineColor(sf::Color::White);
            keyboardCharacters[currentIter].setOutlineThickness(2);
            keyboardCharacters[currentIter].setString(indexSymbolsUpper);
            keyboardCharacters[currentIter].setPosition(sf::Vector2f(xPositionSymbolsBlack,yPositionSymbolsBlack));

            currentIter++;
            xPositionSymbolsBlack += 66.6;
        }

    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
    pianoIndexSymbolsUpper.close();

    //WHITE KEYS INITIALIZED BELOW
    float xPositionWhiteKeys = 0;
    float yPositionWhiteKeys = 700;
    for(int iter = 0; iter < 36; iter++)
    {
        keyboardNotes[iter].setPosition(xPositionWhiteKeys,yPositionWhiteKeys);
        keyboardNotes[iter].setSize(sf::Vector2f(66.6,400));
        keyboardNotes[iter].setOutlineThickness(2);
        keyboardNotes[iter].setOutlineColor(sf::Color::Black);
        keyboardNotes[iter].setTexture(&whiteKeyTexture);
        xPositionWhiteKeys += 66.6;
    }

    //BLACK KEYS INITIALIZED BELOW
    float xPositionBlackKeys = 45.3;
    float yPositionBlackKeys = 700;
    std::set<int> xPositionSkip = {38,41,43,46,48,51,53,56,58};
    for(int iterator = 36; iterator < 61; iterator++)
    {
        if(xPositionSkip.find(iterator) != xPositionSkip.end())
        {
            xPositionBlackKeys += 66.6;
        }
        keyboardNotes[iterator].setPosition(xPositionBlackKeys,yPositionBlackKeys);
        keyboardNotes[iterator].setSize(sf::Vector2f(40,200));
        keyboardNotes[iterator].setFillColor(sf::Color::Black);
        keyboardNotes[iterator].setOutlineThickness(2);
        keyboardNotes[iterator].setOutlineColor(sf::Color::Black);
        // keyboardNotes[iterator].setTexture(&blackKeyTexture);
        xPositionBlackKeys += 66.6;
    }
}

void Keyboard::keyboardEvent() { //test for events
    sf::Event events{};
    while (keyboardWindow.pollEvent(events)) {
        if (events.type == sf::Event::KeyPressed) {
            if(events.key.code == sf::Keyboard::Escape) {
                keyboardWindow.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && events.type == sf::Event::TextEntered) {
                std::cout<<charDetectASCII(events.text.unicode)<<std::endl;
                // piano.loopSwitch(charDetectASCII(events.text.unicode));
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)) {
                // piano.increaseVolume();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Dash)) {
                piano.decreaseVolume();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
                piano.increasePitch();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
                piano.decreasePitch();
            }
        }
        if(events.type == sf::Event::MouseButtonPressed){
            if (events.type == sf::Event::MouseButtonPressed) {
                std::cout<<"touch is enabled"<<events.mouseButton.button<<"at position("<<events.mouseButton.x<<","<<events.mouseButton.y;
                piano.playSound(events, keyboardNotes);
            }
        }

    }
}

int Keyboard::charDetectASCII(int unicodeDetect)
{
    std::unordered_map<int, int> unicodeIndexMap =
            {
                    //WHITE KEYS ASCII TO PIANO INDEX
                    //0-9 nums
                    {48,9},{49,0}, {50,1}, {51,2},{52,3},{53,4},{54,5},{55,6},{56,7},{57,8},
                    //lower q-p char
                    {113,10},{119,11},{101,12},{114,13},{116,14},{121,15},{117,16},{105,17},{111,18},{112,19},
                    //lower a-l char
                    {97,20},{115,21},{100,22},{102,23},{103,24},{104,25},{106,26},{107,27},{108,28},
                    //lower z-m char
                    {122,29},{120,30},{99,31},{118,32},{98,33},{110,34},{109,35},

                    //BLACK KEYS ASCII TO PIANO INDEX
                    // @# %^& ()
                    {64,36},{35,37},{37,38},{94,39},{38,40},{40,41},{41,42},
                    // QWE TY IOP
                    {81,43},{87,44},{69,45},{84,46},{89,47},{73,48},{79,49},{80,50},
                    // SD GHJ LZ
                    {83,51},{68,52},{71,53},{72,54},{74,55},{76,56},{90,57},
                    //CVB
                    {67,58},{86,59},{66,60}
            };

    //general template for detection
    if(unicodeIndexMap.find(unicodeDetect) != unicodeIndexMap.end())
    {
        return unicodeIndexMap[unicodeDetect];
    }
    else
        return -1;
}

void Keyboard::drawKeyboard() {
    keyboardWindow.draw(backgroundImage);
    for(int iterate = 0; iterate < 61; iterate++)
    {
        keyboardWindow.draw(keyboardNotes[iterate]);
    }
}

void Keyboard::renderWindow() {
    keyboardWindow.clear();
    drawKeyboard();
    keyboardWindow.display();
}

void Keyboard::runKeyboard() {
    while (keyboardWindow.isOpen()) {
        keyboardEvent();  // Handles events (keyboard, mouse)
        renderWindow();   // clear and draw
    }
}
// SFML has internal events, which are stored somewhere. The object named events we created stores the events that come from the pollEvent function,
// which continuously checks for events in order. Now, the object events of type sf::Event contains data that we can compare to our existing items,
// such as Close, Escape, or KeyboardPressed

//CODE DUMP
// if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && events.key.code) {

// if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) && events.key.code == sf::Keyboard::B) {
//     pianoSound[events.key.code].play();
// }


// std::ifstream pianoIndexSymbols("pianoIndexLetters.txt");
// for(int iter= 0; iter < 36; iter++) {
//     keyboardNotes[iter].setPosition(xPositionWhiteKeys,yPositionWhiteKeys) ;
//     keyboardNotes[iter].setSize(sf::Vector2f(66.6,400));
//     keyboardNotes[iter].setFillColor(sf::Color::White);
//     keyboardNotes[iter].setOutlineThickness(2);
//     keyboardNotes[iter].setOutlineColor(sf::Color::Black) ;
//     keyboardNotes[iter].setTexture(&whiteKeyTexture);
//
//     if (pianoIndexSymbols.is_open()){
//     std::string indexSymbol;
//     std::getline( pianoIndexSymbols, indexSymbol);
//     keyboardCharacters[iter].setFont (pianoIndexFont) ;
//     keyboardCharacters[iter].setCharacterSize(50);
//     keyboardCharacters[iter].setFillColor(sf::Color::Blue) ;
//     keyboardCharacters[iter].setString(indexSymbol) ;
//     keyboardCharacters[iter].xPositionWhiteKeys + 33.3,
//     keyboardCharacters[iter].setPosition(sf::Vector2f(xPositionWhiteKeys+33.3,yPositionWhiteKeys+50);
// }