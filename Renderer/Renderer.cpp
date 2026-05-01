//
//  Renderer.cpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#include "Renderer.hpp"
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

Renderer::Renderer(MTL::Device *device, CA::MetalLayer *layer) : m_Device(device), m_Layer(layer) {
    m_CommandQueue = m_Device->newCommandQueue();
}

void Renderer::render(FrameSize *size) {
    m_Layer->setDrawableSize(CGSizeMake(size->width, size->height));
    
    NS::AutoreleasePool *pool = NS::AutoreleasePool::alloc()->init();
    
    CA::MetalDrawable *drawable = m_Layer->nextDrawable();
    if (!drawable) {
        return;
    }
    MTL::CommandBuffer *pCommandBuffer = m_CommandQueue->commandBuffer();
    
    MTL::RenderPassDescriptor *pass = MTL::RenderPassDescriptor::alloc()->init();
    pass->colorAttachments()->object(NS::UInteger(0))->setTexture(drawable->texture());
    pass->colorAttachments()->object(NS::UInteger(0))->setClearColor(MTL::ClearColor(0.0, 0.0, 0.0, 1.0));
    pass->colorAttachments()->object(NS::UInteger(0))->setLoadAction(MTL::LoadActionClear);
    pass->colorAttachments()->object(NS::UInteger(0))->setStoreAction(MTL::StoreActionStore);
    
//    MTL::RenderCommandEncoder *encoder = pCommandBuffer->renderCommandEncoder(pass);
//    encoder->endEncoding();
    MTL::ParallelRenderCommandEncoder *encoder = pCommandBuffer->parallelRenderCommandEncoder(pass);
    encoder->endEncoding();
    
    pCommandBuffer->presentDrawable(drawable);
    pCommandBuffer->commit();
    
    pass->release();
    pool->release();
}

Renderer::~Renderer() {
    m_CommandQueue->release();
}
