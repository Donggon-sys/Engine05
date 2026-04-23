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
namespace CA {
class MetalLayer;
}
namespace MTL {
class Device;
}

class Window {
private:
    GLFWwindow *m_Window;
    MTL::Device *m_Device;
    CA::MetalLayer *m_Layer;
    std::unique_ptr<Renderer>(m_Renderer);
    
public:
    explicit Window(MTL::Device *device, CA::MetalLayer *layer);
    void createWindow();
    void createRenderer();
    void renderLoop();
    ~Window();
};
