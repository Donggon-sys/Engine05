//
//  Renderer.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#pragma once
namespace CA {
class MetalLayer;
}
namespace MTL {
class Device;
class CommandQueue;
}

class Renderer {
private:
    MTL::Device *m_Device;
    CA::MetalLayer *m_Layer;
    MTL::CommandQueue *m_CommandQueue;
    
public:
    explicit Renderer(MTL::Device *device, CA::MetalLayer *layer);
    void render();
    ~Renderer();
};
