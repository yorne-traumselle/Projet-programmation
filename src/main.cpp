
#include <iostream>
#include <SDL2/SDL.h>

#include "game/Game.h"

int main(int argc, char **argv)
{
    std::cout << "Lancement du jeu ESIR1 " << std::endl;

    Game game(JeuESIR::screenWidth, JeuESIR::screenHeight);
    game.run();

    return 0;

}