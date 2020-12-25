///////////////////////////////////////////////////////////////
//  FPSCounter.cpp
//  Aircraft-Shooter
//  
//  Created by Yuan Sambo on 26/12/2020                         
//  Copyright (c) 2020 Yuan Sambo All rights reserved.     
////////////////////////////////////////////////////////////////

#include "FPSCounter.hpp"

yu::FPSCounter::FPSCounter() :
     m_updateTime()
    ,m_frames()
    ,m_fpsText(){

}


void yu::FPSCounter::updateFrame(sf::Time deltaTime) {
    m_updateTime += deltaTime;
    m_frames += 1;
    if (m_updateTime >= sf::seconds(1.0f)) {

        m_fpsText->setString(
                "FPS = " + std::to_string(m_frames) + "\n" +
                "Time / Update = " + std::to_string(m_updateTime.asMicroseconds() / m_frames) +
                "us");

        m_updateTime -= sf::seconds(1.0f);
        m_frames = 0;

    }
}

void yu::FPSCounter::setText(sf::Text &text) {
    m_fpsText = &text;
}

