#include "Sound.h"
#include "keyboard.h"

#include <fstream>
#include <iostream>
#include <unordered_map>

/**
 * Basic constructor
 */
Keyboard::Keyboard() : keyboardWindow(sf::VideoMode(1920, 1080), "Keyboard Window") {
    keyboardWindow.setFramerateLimit(60);

    //loads jpg image from computer
    backgroundTexture.loadFromFile("../assets/textures/beigeBackground.jpg");
    backgroundImage.setTexture(&backgroundTexture);
    backgroundImage.setSize(sf::Vector2f(1920,1080));

    //loads in gradient for white and black key textures (change filepath as needed)
    whiteKeyTexture.loadFromFile("../assets/textures/beigeToWhite.jpg");
    whiteKeyTextureDark.loadFromFile("../assets/textures/beigeToWhite_Dark.jpg");

    blackKeyTexture.loadFromFile("../assets/textures/blackGradient.jpg");
    blackKeyTextureLight.loadFromFile("../assets/textures/blackTextureLight.jpg");

    if(!pianoIndexFont.loadFromFile("../assets/fonts/LexendDeca-VariableFont_wght.ttf"))
    {
        std::cerr << "Unable to load font." << std::endl;
    }

    //FOR PURPOSES OF INITIALIZING THE SPACING BETWEEN THE BLACK KEYS PROPERLY (notes and characters)
    std::set<int> xPositionSkip = {38,41,43,46,48,51,53,56,58};

    //WHITE KEYS INITIALIZED BELOW

    // START OF PIANO INDEX SYMBOLS INITIALIZATION (lowercase letters, numbers)
    float xPositionSymbolsWhite = 15;
    float yPositionSymbolsWhite = 950;

    std::ifstream pianoIndexSymbolsLower("../assets/textFiles/pianoIndexLetters_WhiteKeys.txt");
    if(pianoIndexSymbolsLower.is_open())
    {
        int currentIter = 0;
        std::string indexSymbolsLower;
        while(std::getline(pianoIndexSymbolsLower,indexSymbolsLower))
        {
            keyboardCharacters[currentIter].setFont(pianoIndexFont);
            keyboardCharacters[currentIter].setCharacterSize(30);
            keyboardCharacters[currentIter].setFillColor(sf::Color::Black);
            keyboardCharacters[currentIter].setOutlineColor(sf::Color::White);
            keyboardCharacters[currentIter].setOutlineThickness(2);
            keyboardCharacters[currentIter].setString(indexSymbolsLower);
            keyboardCharacters[currentIter].setPosition(sf::Vector2f(xPositionSymbolsWhite,yPositionSymbolsWhite));

            currentIter++;
            xPositionSymbolsWhite += 53.28;
        }
    }
    else
    {
        std::cerr << "Unable to open file." << std::endl;
    }
    pianoIndexSymbolsLower.close();

    // START OF PIANO INDEX SYMBOLS INITIALIZATION (special characters, uppercase letters)
    float xPositionSymbolsBlack = 44;
    float yPositionSymbolsBlack = 800;
    std::ifstream pianoIndexSymbolsUpper("../assets/textFiles/pianoIndexLetters_BlackKeys.txt");
    if(pianoIndexSymbolsUpper.is_open())
    {
        int currentIter = 36;
        std::string indexSymbolsUpper;
        while(std::getline(pianoIndexSymbolsUpper,indexSymbolsUpper))
        {
            if(xPositionSkip.find(currentIter) != xPositionSkip.end())
            {
                xPositionSymbolsBlack += 53.28;
            }
            keyboardCharacters[currentIter].setFont(pianoIndexFont);
            keyboardCharacters[currentIter].setCharacterSize(20);
            keyboardCharacters[currentIter].setFillColor(sf::Color::Black);
            keyboardCharacters[currentIter].setOutlineColor(sf::Color::White);
            keyboardCharacters[currentIter].setOutlineThickness(2);
            keyboardCharacters[currentIter].setString(indexSymbolsUpper);
            keyboardCharacters[currentIter].setPosition(sf::Vector2f(xPositionSymbolsBlack,yPositionSymbolsBlack));

            currentIter++;
            xPositionSymbolsBlack += 53.28;
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
        keyboardNotes[iter].setSize(sf::Vector2f(53.28,320));
        keyboardNotes[iter].setOutlineThickness(2);
        keyboardNotes[iter].setOutlineColor(sf::Color::Black);
        keyboardNotes[iter].setTexture(&whiteKeyTexture);
        xPositionWhiteKeys += 53.28;
    }

    //BLACK KEYS INITIALIZED BELOW
    float xPositionBlackKeys = 37;
    float yPositionBlackKeys = 700;
    for(int iterator = 36; iterator < 61; iterator++)
    {
        if(xPositionSkip.find(iterator) != xPositionSkip.end())
        {
            xPositionBlackKeys += 53.28;
        }
        keyboardNotes[iterator].setPosition(xPositionBlackKeys,yPositionBlackKeys);
        keyboardNotes[iterator].setSize(sf::Vector2f(32,160));
        keyboardNotes[iterator].setFillColor(sf::Color::Black);
        keyboardNotes[iterator].setOutlineThickness(2);
        keyboardNotes[iterator].setOutlineColor(sf::Color::Black);
        keyboardNotes[iterator].setTexture(&blackKeyTexture);
        xPositionBlackKeys += 53.28;
    }
}


void Keyboard::keyboardEvent(char presetOption)
{
    std::cout << presetOption << "reset Option" << std::endl;
    sf::Event events{};

    std::ifstream presetNotes("../assets/textFiles/presetMusicNotes.txt");

    if(!presetNotes.is_open())
    {
        std::cerr << "Unable to open preset music file." << std::endl;
    }

    while(keyboardWindow.pollEvent(events))
    {

        sf::Uint32 unicodeConvert;
        char currentChar;

        if(sf::Event::KeyPressed)
        {
            while(presetNotes.get(currentChar))
            {
                unicodeConvert = static_cast<sf::Uint32>(currentChar);

                int soundIndex = charDetectASCII(unicodeConvert);

                //accounts for gaps in the ASCII range, where there are no corresponding keyboard inputs for the piano simulator
                if (soundIndex == -1) { break; }

                //suppose a white key was pressed, change white key texture
                if(soundIndex <= 35)
                {
                    piano.playSound(soundIndex);
                    keyboardNotes[soundIndex].setTexture(&whiteKeyTextureDark);
                }
                    //suppose a black key was pressed, change black key texture
                else
                {
                    piano.playSound(soundIndex);
                    keyboardNotes[soundIndex].setTexture(&blackKeyTextureLight);
                }
                sf::sleep(sf::milliseconds(100));
            }
        }
    }
}


// for default simulator event
// void Keyboard::keyboardEvent(int)

/** Everything to do with the keys, from texture changes,
 *  playing sounds, and detecting mouse presses in response to input
 */
void Keyboard::keyboardEvent(int defaultOption)
{ //test for events
    sf::Event events{};
    while (keyboardWindow.pollEvent(events)) {

        //loops reset the textures of all the notes when not pressed
        for (int iter = 0; iter < 36; iter++) {
            keyboardNotes[iter].setTexture(&whiteKeyTexture);
        }
        for (int iterator = 36; iterator < 61; iterator++) {
            keyboardNotes[iterator].setTexture(&blackKeyTexture);
        }

        // Handle Keyboard Events
        switch (events.type){
            case sf::Event::KeyPressed:
                if(events.key.code == sf::Keyboard::Escape) {
                    keyboardWindow.close();
                }
                piano.soundFunctions();//volume,pitch
            break;

            case sf::Event::TextEntered:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Grave)) {
                    std::cout<<events.text.unicode<<"\n";
                    int soundIndex = charDetectASCII(events.text.unicode);
                    std::cout<<soundIndex<<"\n";
                    if (soundIndex != -1) {
                        piano.loopSwitch(soundIndex);
                    }
                }
                //suppose the valid range of inputs for all 61 notes
                else if(events.text.unicode >= 33 && events.text.unicode <= 122) {
                    //method will find the corresponding piano index for the given keyboard input, assigned to variable soundIndex
                    int soundIndex = charDetectASCII(events.text.unicode);

                    //accounts for gaps in the ASCII range, where there are no corresponding keyboard inputs for the piano simulator
                    if (soundIndex == -1) {
                        break;
                    }
                    //suppose a white key was pressed, change white key texture
                    if (soundIndex <= 35) {
                        piano.playSound(soundIndex);
                        keyboardNotes[soundIndex].setTexture(&whiteKeyTextureDark);
                    }
                    //suppose a black key was pressed, change black key texture
                    else {
                        piano.playSound(soundIndex);
                        keyboardNotes[soundIndex].setTexture(&blackKeyTextureLight);
                    }
                }
                else {
                    std::cout << "Error! Try again." << std::endl; // Invalid character
                }
                break;

            // Mouse clicks
            case sf::Event::MouseButtonPressed:
                std::cout << "Touch is enabled at position ("
                          << events.mouseButton.x << "," << events.mouseButton.y << ")\n";
                piano.playSound(events, keyboardNotes); // Play sound based on mouse click
                break;

            default: ;
        }
    }
}

/** detects ASCII characters entered
 *
 * @param unicodeDetect we pass the unicode to this function
 * @return return numerical value of button pressed
 */
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

/** Draws the keyboard, each key, etc.
 *
 */
void Keyboard::drawKeyboard()
{
    keyboardWindow.draw(backgroundImage);
    for(int iterate = 0; iterate < 61; iterate++)
    {
        keyboardWindow.draw(keyboardNotes[iterate]);
    }
    for(int iterator = 0; iterator < 61; iterator++)
    {
        keyboardWindow.draw(keyboardCharacters[iterator]);
    }
}

/** Renders the window
 *
 */
void Keyboard::renderWindow() {
    keyboardWindow.clear();
    drawKeyboard();
    keyboardWindow.display();
}

/** Runs the keyboard
 *
 */
void Keyboard::runKeyboard()
{
    //POTENTIAL POLYMORPHIC PROGRAM TOO HANDLE DIFFERENT PIANO SIMULATION OPTIONS
    int userDecision;
    char presetDecision = 'P';
    int defaultDecision = 1;

    std::cout << "Default mode[1] or preset mode[other]?";
    std::cin >> userDecision;

    if(userDecision == defaultDecision)
    {
        while (keyboardWindow.isOpen())
        {
            keyboardEvent(defaultDecision);
            renderWindow();
        }
    }

    else
    {
        while (keyboardWindow.isOpen())
        {
            keyboardEvent(presetDecision);
            renderWindow();

        }
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