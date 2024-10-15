#include "pch.h"
#include "Window.h"
#include "SDL2/SDL.h"

int init()
{
    printf("Initializing SDL...\n");
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Could not initialize SDL: %s.\n", SDL_GetError());
        return -1;
    }
    printf("SDL Successfully Initialized. \n");
    return 0;
}

int main(int argc, char* argv[])
{
    int exitCode = init();
    if(exitCode < 0)
    {
        printf("Failed To Initialize. Shutting Down...");
        return exitCode;
    }
    auto window = Window(1920, 1080, "Float");
    while (window.IsOpen())
    {
        window.Update();
    }
    SDL_Quit();
    return 0;
}
