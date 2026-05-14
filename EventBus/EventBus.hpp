//
//  EventBus.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/5/14.
//

#pragma once
#include <vector>
#include <functional>

//typedef std::function<void(int, int)> WindowReSizeFunc;

//class EventBus {
//private:
//    EventBus();
//    std::vector<WindowReSizeFunc> m_WindowReSizeFun;
//    
//public:
//    ~EventBus();
//    static EventBus &getInstance();
//    void registerWindowReSize(int width, int height);
//    void subScribeWindowReSize(WindowReSizeFunc func);
//};

template <typename Event>
class EventBus {
private:
    EventBus() = default;
    std::vector<std::function<void(const Event &)>> m_funcList;
    
public:
    ~EventBus() = default;
    EventBus(const EventBus&) = delete;
    EventBus& operator=(const EventBus&) = delete;
    static EventBus &getInstance() {
        static EventBus<Event> instance;
        return instance;
    }
    
    void publish(Event &event) {
        for (auto &func : m_funcList) {
            func(event);
        }
    }
    
    void subScribe(std::function<void(Event event)> func) {
        m_funcList.push_back(func);
    }
};
