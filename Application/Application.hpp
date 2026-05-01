//
//  Application.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#pragma once
#include <memory>

class Audio;
class Window;
class Game;
namespace CA {
class MetalLayer;
}
namespace MTL {
class Device;
}

class Application {
private:
    std::unique_ptr<Window> m_Window;
    CA::MetalLayer *m_Layer;
    MTL::Device *m_Device;
    std::unique_ptr<Audio> m_Audio;
    std::shared_ptr<Game> m_Game;
    
public:
    Application();
    void runLoop();
    void build();
    ~Application();
};
