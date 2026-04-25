//
//  FRController.cpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/24.
//

#include "FRController.hpp"

void FRController::init() {
    m_LastTime = std::chrono::steady_clock::now();
}

void FRController::setDuration(int frameRate) {
    if (frameRate <= 0) {
        return;
    }
    
    int64_t time = 1000000 / frameRate;
    std::chrono::duration<int64_t, std::micro> d(time);
    m_DurationTime = d;
}

FRController::FRController() {
    int64_t time = 1E6 / 60;
    std::chrono::duration<int64_t, std::micro> d(time);
    m_DurationTime = d;
}

void FRController::update() {
    m_LastTime = std::chrono::steady_clock::now();
}

bool FRController::needTORender() {
    m_CurrentTime = std::chrono::steady_clock::now();
    if (m_CurrentTime - m_LastTime >= m_DurationTime) {
        m_LastTime = m_CurrentTime;
        return true;
    } else {
        return false;
    }
}
