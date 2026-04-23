//
//  Window.mm
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#include "Window.hpp"
#include "Renderer.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_COCOA
#include <GLFW/glfw3native.h>

#include <Metal/Metal.h>
#include <QuartzCore/CAMetalLayer.h>


Window::Window(MTL::Device *device, CA::MetalLayer *layer) : m_Layer(layer), m_Device(device) {
    createWindow();
    createRenderer();
}

void Window::createWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    m_Window = glfwCreateWindow(960, 600, "window", NULL, NULL);
    
    if (!m_Window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    NSWindow *window = glfwGetCocoaWindow(m_Window);
    window.contentView.layer = (__bridge CAMetalLayer *)m_Layer;
    window.contentView.wantsLayer = YES;
}

void Window::createRenderer() {
    m_Renderer = std::make_unique<Renderer>(m_Device, m_Layer);
}

void Window::renderLoop() {
    glfwShowWindow(m_Window);
    
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
        m_Renderer->render();
    }
}

Window::~Window() {
    
}
