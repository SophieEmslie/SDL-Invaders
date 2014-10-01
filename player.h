#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>

// Constants
//const int PLAYER_SIZE_X = 64;
//const int PLAYER_SIZE_Y = 64;

//const int PLAYER_WIDTH  = 64;
//const int PLAYER_HEIGHT = 64;

enum PlayerState { NOTFIRING, FIRING };

struct Player
{
    SDL_Rect bounds;    // Position/Size
    SDL_Rect projectile;
    enum PlayerState state;
};

// Forward declarations
struct Player* createPlayer(int _x, int _y, int _width, int _height);
void movePlayer(struct Player* _player, int _offsetX, int _offsetY);
void moveProjectile(struct Player* _player, int _offsetY);

void fireProjectile(struct Player* _player);











#endif // PLAYER_H

