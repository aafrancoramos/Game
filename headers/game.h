#include <SDL2/SDL.h>

#include "entity.h"

class game {
    public:
        game();
        ~game();

        void game_loop();

        void update(double delta_time);

        void draw();

    private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        SDL_Event _e;

        entity _player;
};