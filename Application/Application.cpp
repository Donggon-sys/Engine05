//
//  Application.cpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#include "Application.hpp"
#include "../Renderer/Window.hpp"
#include "../Audio/Audio.hpp"
#include "../Game/Game.hpp"
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

Application::Application() {
    m_Device = MTL::CreateSystemDefaultDevice();
    m_Layer = CA::MetalLayer::layer();
    m_Layer->setDevice(m_Device);
    m_Layer->setPixelFormat(MTL::PixelFormatBGRA8Unorm);
    
    m_Window = std::make_unique<Window>(m_Device, m_Layer);
    m_Audio = std::make_unique<Audio>();
    m_Game = std::make_shared<Game>();
}

void Application::build() {
    m_Window->setGameObject(m_Game);
}

void Application::runLoop() {
    m_Window->renderLoop();
}

Application::~Application() {
    m_Layer->release();
    m_Device->release();
    m_Game->destroy();
}
