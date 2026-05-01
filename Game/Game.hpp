//
//  Game.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/5/1.
//

#pragma once
#include <queue>
#include <mutex>
#include <thread>
#include <atomic>
#include <condition_variable>

class Game {
private:
    std::queue<int32_t> m_Keys;
    std::mutex m_mtx;
    std::condition_variable m_cv;
    std::thread m_WorkThread;
    std::atomic<bool> m_running;
    
public:
    Game();
    ~Game();
    void addInputMessages(int32_t input);
    void work();
    void destroy();
};
