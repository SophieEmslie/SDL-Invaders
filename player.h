#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

// Constants
//const int PLAYER_SIZE_X = 64;
//const int PLAYER_SIZE_Y = 64;

//const int PLAYER_WIDTH  = 64;
//const int PLAYER_HEIGHT = 64;

struct Player
{
    SDL_Rect bounds;    // Position/Size
};

// Forward declarations
struct Player* createPlayer(int _x, int _y, int _width, int _height);
void movePlayer(struct Player* _player, int _offsetX, int _offsetY);

#endif // PLAYER_H
