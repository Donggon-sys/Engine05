//
//  Input.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/5/1.
//

#pragma once
#include <map>
#include <memory>
class Game;
typedef struct GLFWwindow GLFWwindow;

class Input {
private:
    std::map<int, uint32_t> m_KeyTOMap;
    std::weak_ptr<Game> m_Game;
    
public:
    Input(std::shared_ptr<Game> game);
    ~Input();
    void sendMessage(uint32_t message);
    static void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void cursorCallBack(GLFWwindow* window, double xpos, double ypos);
    static void cursorEnterCallBack(GLFWwindow* window, int entered);
};
