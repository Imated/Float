#include "pch.h"
#include "Window.h"
#include "SDL2/SDL.h"

Window::Window(int width, int height, const char* title): _width(width), _height(height), _title(title)
{
    _window = SDL_CreateWindow(_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_SHOWN);
    _isRunning = true;
}

void Window::Update()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
        case SDL_KEYDOWN:
            if(e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                _isRunning = false;
            break;
        case SDL_QUIT:
            _isRunning = false;
            break;
        default: ;
        }
    }
}

bool Window::IsOpen() const
{
    return _isRunning;
}

vec2 Window::GetSize() const
{
    return { _width, _height };
}
