#pragma once

#include <iostream>

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool initialize(); // Setup OpenGL
    void draw();       // Render the scene
    void shutdown();   // Cleanup resources
};
