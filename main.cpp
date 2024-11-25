#include "keyboard.h"

int main() {
    Keyboard keyboardObj, *keyboardPtr = &keyboardObj;//object of keyboard class, ptr named keyboardPtr set to the address of the object
    keyboardPtr->runKeyboard();// start by pointer

    return 0;
}