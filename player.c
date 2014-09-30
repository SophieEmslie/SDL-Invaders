#include "player.h"

struct Player* createPlayer(int _x, int _y, int _width, int _height)
{
    struct Player* player = 0;
    player = malloc(sizeof(struct Player));

    // Initial player position
    player->bounds.x = _x;
    player->bounds.y = _y;

    // Player size
    player->bounds.w = _width;
    player->bounds.h = _height;

    return player;
}

void movePlayer(struct Player* _player, int _offsetX, int _offsetY)
{
    _player->bounds.x += _offsetX;
    _player->bounds.y += _offsetY;
}
