#include <iostream>
#include <SDL3/SDL.h>

int main(){
    const int width = 900;
    const int height = 600
;
    SDL_Window* window = SDL_CreateWindow("Image Window" , width , height , 0);
    SDL_Surface* surface = SDL_GetWindowSurface(window);

    Uint8 r,g,b;
    r = 0xFF;
    g = b = 0;

    const SDL_PixelFormatDetails* format_details = SDL_GetPixelFormatDetails(surface->format);
    Uint32 color = SDL_MapRGB(format_details , NULL , r , g , b);

    SDL_Rect pixel = (SDL_Rect){0 , 0 , 1 , 1};

    for(int i = 0 ; i < width ; i++){
        for(int j = 0 ; j < height ; j++){
            pixel.x = i;
            pixel.y = j;

            SDL_FillSurfaceRect(surface , &pixel , color);
        }
    }

    SDL_UpdateWindowSurface(window);

    SDL_Delay(3000);
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return -1;
}