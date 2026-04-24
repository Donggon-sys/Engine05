//
//  Audio.cpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#include "Audio.hpp"
#include <miniaudio.h>
#include <Foundation/Foundation.hpp>
#include <string>


Audio::Audio() {
    ma_result rel = ma_engine_init(NULL, &m_AudioEngine);
    if (rel != MA_SUCCESS) {
        
        return;
    }
    std::string resourcePath = NS::Bundle::mainBundle()->resourcePath()->utf8String();
    resourcePath = resourcePath + "/";
    std::string filePath = resourcePath + "test.wav";
    
    m_Sound = new ma_sound();
    rel = ma_sound_init_from_file(&m_AudioEngine, filePath.c_str(), 0, NULL, NULL, m_Sound);
    if (rel != MA_SUCCESS) {
        return;
    }
    playLoop();
}

Audio::~Audio() {
    ma_sound_uninit(m_Sound);
    ma_engine_uninit(&m_AudioEngine);
    delete m_Sound;
}

void Audio::playLoop() {
    ma_sound_start(m_Sound);
}
