///////////////////////////////////////////////////////////////
//  FPSCounter.hpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 26/12/2020                         
//  Based on SFML Game Development Book
////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>

#ifndef AIRCRAFT_SHOOTER_FPSCOUNTER_HPP
#define AIRCRAFT_SHOOTER_FPSCOUNTER_HPP

namespace yu {


    //////////////////////////////////////////
    /// \brief Displays the frames per second of the game
    ///
    ///  and time of the last frame update.
    ///
    /////////////////////////////////////////

    class FPSCounter  {
    public:

        FPSCounter();

        //////////////////////////////////////////
        /// \brief Sets the text to be changed
        ///
        /// \param Text where the FPS will be displayed
        ///
        /////////////////////////////////////////
        void setText(sf::Text &text);

        //////////////////////////////////////////
        /// \brief Updates the fps display
        ///
        ///  \param Time elapsed since the last frame
        ///
        /////////////////////////////////////////
        void updateFrame( sf::Time deltaTime);


    private:

        sf::Time    m_updateTime;
        sf::Text*   m_fpsText;
        size_t      m_frames;
    };
}

#endif //AIRCRAFT_SHOOTER_FPSCOUNTER_HPP
