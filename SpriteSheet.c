#include <SDL.h>
#include <SDL_image.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "player.h"

const int WIDTH = 800;
const int HEIGHT = 600;

int main()
{
  // initialise SDL and check that it worked otherwise exit
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
  {
    printf("%s\n",SDL_GetError());
    return EXIT_FAILURE;
  }

  // we are now going to create an SDL window
  SDL_Window *win = 0;
  win = SDL_CreateWindow("Sprite Sheet", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  if (win == 0)
  {
    printf("%s\n",SDL_GetError());
    return EXIT_FAILURE;
  }

  // the renderer is the core element we need to draw, each call to SDL for drawing will need the
  // renderer pointer
  SDL_Renderer *renderer = 0;
  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == 0)
  {
    printf("%s\n",SDL_GetError() );
    return EXIT_FAILURE;
  }

  // Pointer to keyboard state
  const Uint8 *KEY = SDL_GetKeyboardState(NULL);

  // now we are going to loop forever, process the keys then draw
  int quit=0;

  struct Player* p1 = createPlayer(800 / 2, 600 - 64 - 64, 64, 64);

  const int xOffset = 8;
  const int yOffset = 2;

  while (quit !=1)
  {
    // grab the SDL event (this will be keys etc)
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
      // look for the x of the window being clicked and exit
      if (event.type == SDL_QUIT)
      {
        quit= 1;
      }

      if(KEY[ SDL_SCANCODE_ESCAPE ]) {
          quit= 1;
      }
    }// end PollEvent loop

    // Read input
    if(KEY[SDL_SCANCODE_LEFT])  { movePlayer(p1, -xOffset,        0); }
    if(KEY[SDL_SCANCODE_RIGHT]) { movePlayer(p1,  xOffset,        0); }
    if(KEY[SDL_SCANCODE_UP])    { movePlayer(p1,        0, -yOffset); }
    if(KEY[SDL_SCANCODE_DOWN])  { movePlayer(p1,        0,  yOffset); }

    // Do player boundary checks
    const int playerWidth = p1->bounds.w;
    const int playerHeight = p1->bounds.h;

    if(p1->bounds.x < 0)                            { p1->bounds.x = 0; }
    if(p1->bounds.y > (HEIGHT-playerHeight))        { p1->bounds.y = HEIGHT - playerHeight; }

    if(p1->bounds.x > (WIDTH-playerWidth))          { p1->bounds.x = WIDTH - playerWidth; }
    if(p1->bounds.y < (HEIGHT-(playerHeight*3)))    { p1->bounds.y = (HEIGHT-(playerHeight*3)); }

    // now we clear the screen (will use the clear colour set previously)
    SDL_RenderClear(renderer);

    // This will copy the texture to the screen, at present we use 0,0 for the Source and Destination
    // rectangles this will copy the whole of the src (tex) to the whole of the dst (screen)
    // the main task you have is to get the correct src / dst SDL_Rect values filled in
    //SDL_RenderCopy(renderer, sprite, &spriteAnimation, &spritePosition);

    SDL_RenderDrawRect(renderer, &p1->bounds);

    // Up until now everything was drawn behind the scenes.
    // This will show the new, red contents of the window.
    SDL_RenderPresent(renderer);
  } // end while

  // exit SDL nicely and free resources
  SDL_Quit();
  return EXIT_SUCCESS;
}
