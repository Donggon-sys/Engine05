//
//  Window.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#pragma once
#include <memory>

typedef struct GLFWwindow GLFWwindow;
class Renderer;
class Input;
class Game;
class FRController;
namespace CA {
class MetalLayer;
}
namespace MTL {
class Device;
}

class Window {
private:
    GLFWwindow *m_Window;
    Input *m_Input;
    MTL::Device *m_Device;
    CA::MetalLayer *m_Layer;
    std::unique_ptr<Renderer> m_Renderer;
    std::unique_ptr<FRController> m_FRController;
//    std::weak_ptr<Game> m_Game;
    
public:
    explicit Window(MTL::Device *device, CA::MetalLayer *layer);
    void createWindow();
    void createRenderer();
    void setCursorPos();
    void setGameObject(std::shared_ptr<Game> game);
    void createFRContoller();
    void createInput();
    void renderLoop();
    ~Window();
};
