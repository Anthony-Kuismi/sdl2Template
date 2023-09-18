#include <iostream>
#include <SDL.h>
int main([[maybe_unused]] int argc, [[maybe_unused]] char* args[]) {
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }
    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          680, 480,
                                          0);
    if(!window){
        std::cout << "Failed to create window\n";
        return -1;
    }
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    if(!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    }
    SDL_UpdateWindowSurface(window);
    SDL_Event event;
    bool running = true;
    while(running){
        /* Poll for events. SDL_PollEvent() returns 0 when there are no  */
        /* more events on the event queue, our while loop will exit when */
        /* that occurs.                                                  */
        while( SDL_PollEvent( &event ) ) {
            /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
            switch (event.type) {
                case SDL_KEYDOWN:
                    if(event.key.keysym.sym == 27){
                        running = false;
                    }
                    break;

                case SDL_KEYUP:
                    printf("Key release detected\n");
                    break;

                default:
                    break;
            }
        }
    }

    return 0;
}
