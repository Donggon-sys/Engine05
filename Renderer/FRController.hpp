//
//  FRController.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/24.
//

#pragma once
#include <chrono>

class FRController {
private:
    std::chrono::steady_clock::time_point m_LastTime;
    std::chrono::steady_clock::time_point m_CurrentTime;
    std::chrono::steady_clock::duration m_DurationTime;
    
public:
    FRController();
    ~FRController() = default;
    void init();
    void setDuration(int frameRate);
    void update();
    bool needTORender();
};
