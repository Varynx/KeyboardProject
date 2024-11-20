#include <iostream>
#include <filesystem>
#include "keyboard.h"

int main() {
    std::cout << "Current working directory: " << std::filesystem::current_path();// to see current directory, can be deleted

    Keyboard keyboardObj, *keyboardPtr = &keyboardObj;//object of keyboard class, ptr named keyboardPtr set to the address of the object
    keyboardPtr->runKeyboard();// start by pointer

    return 0;
}