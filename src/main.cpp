#include <iostream>
#include "mmu/mmu.h"
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    std::cout << "Hello World!\n";

    auto mmu = std::make_unique<MMU>();
    mmu->loadRom("resources/roms/gbalooprom.gba");


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // 2. Create a Window
    SDL_Window* window = SDL_CreateWindow(
        "SDL2 Starter Window",           // Window title
        SDL_WINDOWPOS_CENTERED,          // Initial x position
        SDL_WINDOWPOS_CENTERED,          // Initial y position
        800, 600,                        // Width, Height
        SDL_WINDOW_SHOWN                 // Flags
    );

    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // 3. Create a Renderer (to draw things)
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // 4. Main Loop
    bool quit = false;
    SDL_Event e;

    while (!quit) {
        // Handle events on queue
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // --- DRAWING SECTION ---
        SDL_SetRenderDrawColor(renderer, 0x21, 0x21, 0x21, 0xFF); // Dark Gray
        SDL_RenderClear(renderer);

        // (Add your drawing code here)

        SDL_RenderPresent(renderer);
    }

    // 5. Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}