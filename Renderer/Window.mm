//
//  Window.mm
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

#include "Window.hpp"
#include "Renderer.hpp"
#include "FRController.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_COCOA
#include <GLFW/glfw3native.h>

#include <Metal/Metal.h>
#include <QuartzCore/CAMetalLayer.h>


Window::Window(MTL::Device *device, CA::MetalLayer *layer) : m_Layer(layer), m_Device(device) {
    createWindow();
    createRenderer();
    createFRContoller();
    m_FRController->init();
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

void Window::createFRContoller() {
    m_FRController = std::make_unique<FRController>();
}

void Window::setCursorPos() {
    int width, height;
    glfwGetWindowSize(m_Window, &width, &height);
    glfwSetCursorPos(m_Window, static_cast<double>(width / 2), static_cast<double>(height / 2));
}

void Window::renderLoop() {
    glfwShowWindow(m_Window);
    
    int initCount = 0;
    FrameSize frameSize;
    while (!glfwWindowShouldClose(m_Window)) {
        glfwPollEvents();
        
        switch (initCount) {
            case 0: {
                setCursorPos();
                initCount++;
            }
                break;
                
            default:
                break;
        }
        
        if (m_FRController->needTORender()) {
            glfwGetFramebufferSize(m_Window, &frameSize.width, &frameSize.height);
            m_Renderer->render(&frameSize);
        }
    }
}

Window::~Window() {
    glfwTerminate();
}
