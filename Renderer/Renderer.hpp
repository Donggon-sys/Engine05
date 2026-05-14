//
//  Renderer.hpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#pragma once
#include "../EventBus/EventBus.hpp"
namespace CA {
class MetalLayer;
}
namespace MTL {
class Device;
class CommandQueue;
}
//typedef struct CGSize CGSize;
//typedef struct {int width; int height;} EventWindowReSize;
struct FrameSize {
    int width;
    int height;
};

class Renderer {
private:
    MTL::Device *m_Device;
    CA::MetalLayer *m_Layer;
    MTL::CommandQueue *m_CommandQueue;
    
public:
    explicit Renderer(MTL::Device *device, CA::MetalLayer *layer);
    void render(FrameSize *size);
    void build();
    void viewportReSize(EventWindowReSize size);
    ~Renderer();
};
