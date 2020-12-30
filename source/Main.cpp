///////////////////////////////////////////////////////////////
//  Main.hpp
//  AIRCRAFT_SHOOTER
//
//  Created by Yuan Sambo on 23/12/2020
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////


#include "../include/Game.hpp"

    //////////////////////////////////////////
    /// \brief The main entrypoint of the game
    /////////////////////////////////////////
    int main() {


        try{
            Game::instance()->run();

        } catch (std::runtime_error& e) {

            printf("Exception %s \n",e.what());

        }

        return EXIT_SUCCESS;
   }

