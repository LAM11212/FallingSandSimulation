#include <iostream>
#include <SFML/Graphics.hpp>
#include "myWindow.h"

int main()
{

    myWindow window;

    while (window.running())
    {
        window.update();
        window.render();
    }
    return 0;
}