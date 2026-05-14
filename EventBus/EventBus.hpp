//
//  EventBus.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/5/14.
//

#pragma once
#include <vector>
#include <functional>

typedef std::function<void(int, int)> WindowReSizeFunc;

class EventBus {
private:
    EventBus();
    std::vector<WindowReSizeFunc> m_WindowReSizeFun;
    
public:
    ~EventBus();
    static EventBus &getInstance();
    void registerWindowReSize(int width, int height);
    void subScribeWindowReSize(WindowReSizeFunc func);
};
