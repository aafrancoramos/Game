#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class entity {
    public:
        entity();
        ~entity();
        
        void init(SDL_Renderer *renderer, int x, int y);

        void update(double delta_time);

        void draw(SDL_Renderer *renderer);

    private:
        SDL_Texture *_texture;
        SDL_Rect _src;
        SDL_Rect _dst;
};