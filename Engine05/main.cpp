//
//  main.cpp
//  Engine05
//
//  Created by Chenruyi on 2026/4/23.
//

//MARK: - Metal-cpp实现
#define NS_PRIVATE_IMPLEMENTATION
#define CA_PRIVATE_IMPLEMENTATION
#define MTL_PRIVATE_IMPLEMENTATION
#include <Foundation/Foundation.hpp>
#include <Metal/Metal.hpp>
#include <QuartzCore/QuartzCore.hpp>

//MARK: - miniaudiop实现
#define MINIAUDIO_IMPLEMENTATION
#include <miniaudio.h>

#include "../Application/Application.hpp"

int main(int argc, char *argv[ ]) {
    Application app;
    app.build();
    app.runLoop();
    
    return 0;
}
