//
//  Input.cpp
//  Engine05
//
//  Created by Chenruyi on 2026/5/1.
//

#include "Input.hpp"
#include "../Game/Game.hpp"
#include <GLFW/glfw3.h>

Input::Input(std::shared_ptr<Game> game) {
    m_Game = game;
}

Input::~Input() {
    
}

void Input::sendMessage(uint32_t message) {
    if (auto game = m_Game.lock()) {
        game->addInputMessages(message);
    }
}

void Input::keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods) {
    Input *input = static_cast<Input *>(glfwGetWindowUserPointer(window));
    
    if (key == GLFW_KEY_W) {
        input->sendMessage(12);
    }
}

void Input::cursorCallBack(GLFWwindow* window, double xpos, double ypos) {
    Input *input = static_cast<Input *>(glfwGetWindowUserPointer(window));
    input->sendMessage(static_cast<uint32_t>(xpos));
    input->sendMessage(static_cast<uint32_t>(ypos));
}

void Input::cursorEnterCallBack(GLFWwindow* window, int entered) {
    Input *input = static_cast<Input *>(glfwGetWindowUserPointer(window));
    if (entered == GLFW_TRUE) {
        input->sendMessage(1324);
    } else {
        input->sendMessage(1000);
    }
}
