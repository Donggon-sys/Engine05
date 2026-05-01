//
//  Game.cpp
//  Engine05
//
//  Created by Chenruyi on 2026/5/1.
//

#include "Game.hpp"
#include <iostream>

Game::Game(): m_running(true) {
    m_WorkThread = std::thread(&Game::work, this);
}

Game::~Game() {
    if (m_WorkThread.joinable()) {
        m_WorkThread.join();
    }
}

void Game::addInputMessages(int32_t input) {
    {
        std::unique_lock lock(m_mtx);
        m_Keys.push(input);
    }
    m_cv.notify_one();
}

void Game::work() {
    while (m_running) {
        std::unique_lock lock(m_mtx);
        m_cv.wait(lock, [&] {
            return !m_Keys.empty() || !m_running;
        });
        if (!m_Keys.empty()) {
            int32_t value = m_Keys.front();
            m_Keys.pop();
            std::cout << "input: " << value << std::endl;
        }
    }
}

void Game::destroy() {
    {
        std::unique_lock lock(m_mtx);
        m_running = false;
    }
    m_cv.notify_one();
}
