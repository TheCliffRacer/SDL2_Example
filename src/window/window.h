#include <SDL2/SDL.h>
#include <drawable.h>
#include <list>
#include <iostream>

class Window {
    private:
        SDL_Renderer* renderer;
        SDL_Window* window;

        int width;
        int height;

        std::list<IDrawable> drawables;

        void DrawBackground();
    public:
        void Init(int width, int height);
        void AddToDraw(IDrawable drawable);
        void ClearDrawables();
        void Draw();
        void Quit();

        void SetFullscreen(bool fullscreen);
};