#include <window.h>

void Window::DrawBackground() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect rect = { 0, 0, width, height };
    SDL_RenderFillRect(renderer, &rect);
}

void Window::Init(int width, int height) {
    Window::width = width;
    Window::height = height;

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) std::cout << "Failed at SDL_Init()" << std::endl;
    if(SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer) < 0) std::cout << "Failed at SDL_CreateWindowAndRenderer()" << std::endl;
    SDL_SetWindowTitle(window, "SDL Example");
    SDL_ShowCursor(1);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2");
}

void Window::AddToDraw(IDrawable drawable) {
    drawables.push_back(drawable);
}

void Window::ClearDrawables() {
    drawables.clear();
}

void Window::Draw() {
    SDL_RenderClear(renderer);
    DrawBackground();
    for (auto iter = drawables.begin(); iter != drawables.end(); iter++) {
        iter->Draw(renderer);
    }
    SDL_RenderPresent(renderer);
}

void Window::Quit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::SetFullscreen(bool fullscreen) {
    if (fullscreen) SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
    if (!fullscreen) SDL_SetWindowFullscreen(window, 0);
}