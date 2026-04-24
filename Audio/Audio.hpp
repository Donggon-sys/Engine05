//
//  Audio.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#pragma once
//#include <memory>
#include <miniaudio.h>

class Audio {
private:
    ma_engine m_AudioEngine;
    ma_sound *m_Sound;
    
public:
    Audio();
    ~Audio();
    void playLoop();
};
