#include <SDL2/SDL.h>
#include <stdio.h>

#define TITLE "freeshooter"
#define SCREEN_W 640
#define SCREEN_H 480
#define MAIN_R 0xAA
#define MAIN_G 0xAA
#define MAIN_B 0xAA

int init ();
int load ();
void quit ();
int gameloop ();
void process_event();
int draw ();

SDL_Window *main_window;
SDL_Surface *main_surface;
SDL_bool main_run;
Uint32 main_color;

SDL_Event e;

SDL_Surface *pic;

int main (int argc, char** argv)
{
        if (init () < 0)
                goto ErrorExit;
        
        if (gameloop () < 0)
                goto ErrorExit;
        
        quit ();
        return 0;
ErrorExit:
        printf ("Error: %s\n", SDL_GetError ());
        return -1;
}

int draw ()
{
        if (SDL_BlitSurface (pic, NULL, main_surface, NULL) < 0)
                goto Error;
       
        return 0;
Error:
        return -1;
}

void process_event ()
{
        switch (e.type) {
        case SDL_QUIT:
                main_run = SDL_FALSE;
                break;
        }
}

int gameloop ()
{
        main_run = SDL_TRUE;
        while (main_run == SDL_TRUE) {
                while (SDL_PollEvent (&e))
                        process_event();

                if (SDL_FillRect (main_surface, NULL, main_color) < 0) 
                        goto Error;

                if (draw () < 0)
                        goto Error;

                if (SDL_UpdateWindowSurface (main_window) < 0)
                        goto Error;
        }

        return 0;
Error:
        return -1;
}

int load ()
{
        pic = SDL_LoadBMP ("bmps/pic.bmp");
        if (pic == NULL)
                goto Error;

       return 0;
Error:
        return -1;
}

int init ()
{
        if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
                goto Error;

        main_window = SDL_CreateWindow (TITLE,
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                SCREEN_W,
                SCREEN_H,
                SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
        if (main_window == NULL)
                goto Error;
        
        main_surface = SDL_GetWindowSurface (main_window);
        if (main_surface == NULL)
                goto Error;
        
        if (load () < 0)
                goto Error;
        
        main_color = SDL_MapRGB (main_surface->format, MAIN_R, MAIN_G, MAIN_B);

        return 0;
Error:
        return -1;
}

void quit ()
{
        SDL_FreeSurface (pic);
        SDL_DestroyWindow (main_window);
        SDL_Quit ();
}