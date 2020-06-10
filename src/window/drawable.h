#include <SDL2/SDL.h>

class IDrawable {
    protected:
        SDL_Rect rect;
    public:
        void SetRect(const SDL_Rect& rect) {
            IDrawable::rect = rect;
        };
        void Draw(SDL_Renderer* renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(renderer, &rect);
        };
};
