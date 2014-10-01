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


    //player state
    player->state = NOTFIRING;


//    //projectile size
//    player->projectile.w = _width/2;
//    player->projectile.h = _height/2;

//    // Initial projectile position
//    player->projectile.x = _x+_width/2;
//    player->projectile.y = _y;

    return player;
}

void movePlayer(struct Player* _player, int _offsetX, int _offsetY)
{
//    if( _player->state == NOTFIRING )
//    {
//        _player->projectile.x = _player->bounds.x;
//    }

    _player->bounds.x += _offsetX;
    _player->bounds.y += _offsetY;
}

void moveProjectile(struct Player* _player, int _offsetY)
{
    if(_player->state == FIRING)
    {
        _player->projectile.y -= _offsetY;
    }
}

void fireProjectile(struct Player* _player)
{
    _player->state = FIRING;

    int width = _player->bounds.w;
    int height = _player->bounds.h;

    int x = _player->bounds.x;
    int y = _player->bounds.y;

    //projectile size
    _player->projectile.w = width/2;
    _player->projectile.h = height/2;

    // Initial projectile position
    _player->projectile.x = x + width/2;
    _player->projectile.y = y;
}
