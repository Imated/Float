#pragma once
#include "SDL2/SDL.h"
#include "glm/glm/glm.hpp"
using namespace glm;

class Window
{
public:
    Window(int width, int height, const char* title);

    void Update();

    bool IsOpen() const;
    vec2 GetSize() const;

private:
    int _width;
    int _height;
    const char* _title;
    bool _isRunning;
    
    SDL_Window* _window;
};
