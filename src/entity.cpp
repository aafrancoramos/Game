#include "../headers/entity.h"

#include <iostream>

entity::entity(){};

entity::~entity(){
    SDL_DestroyTexture(_texture);
};

void entity::init(SDL_Renderer *renderer, int x, int y){
    _texture = IMG_LoadTexture(renderer, "./res/gragas.png");

    if(_texture == NULL){
        std::cout << "Could not open file." << std::endl;
    }

    _src.x = 0;
    _src.y = 0;
    _src.w = 128;
    _src.h = 128;

    _dst.x = x;
    _dst.y = y;
    _dst.h = 128;
    _dst.w = 128;
}

void entity::update(double delta_time){
    // _dst.x = _x;
    // _dst.y = _y;
}

void entity::draw(SDL_Renderer *renderer){
    SDL_RenderCopy(renderer, _texture, &_src, &_dst);
}