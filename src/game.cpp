#include "../headers/game.h"
#include <iostream>

game::game(){
    SDL_CreateWindowAndRenderer(680, 480, SDL_WINDOW_RESIZABLE, &_window, &_renderer);
    SDL_SetWindowTitle(_window, "Game");

    _player.init(_renderer, 10, 10);
}

game::~game(){
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void game::game_loop(){
    bool game_loop2 = true;
    while(game_loop2){
        while(SDL_PollEvent(&_e) > 0){
            switch(_e.type){
                case SDL_QUIT:
                    game_loop2 = false;
                    break;
                
            }

            update(1.0/60.0);
            draw();
        }
    }
}

void game::update(double delta_time){
    _player.update(delta_time);
}

void game::draw(){
    SDL_RenderClear(_renderer);

    _player.draw(_renderer);

    SDL_RenderPresent(_renderer);
}