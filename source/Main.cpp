///////////////////////////////////////////////////////////////
//  Main.hpp
//  AIRCRAFT_SHOOTER
//
//  Created by Yuan Sambo on 23/12/2020
//  Copyright (c) 2020 Yuan Sambo All rights reserved.
////////////////////////////////////////////////////////////////


#include "Game.hpp"

    //////////////////////////////////////////
    /// \brief The main entrypoint of the game
    /////////////////////////////////////////
    int main() {

        Game::instance()->run();


        return EXIT_SUCCESS;
   }
