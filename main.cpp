#include <SDL2/SDL.h>
#include <iostream>
#include <window.h>
#include <game.h>

#define WINDOW_WIDTH 512 * 2
#define WINDOW_HEIGHT 288 * 2

int frameCount, timerFPS, lastFrame, fps;
int lastTime;

bool isRunning;
bool isFullscreen;

int w = 16 * 4;
int h = 9 * 4;
int sizeX = WINDOW_HEIGHT / h;
int sizeY = WINDOW_WIDTH / w;

Window window;
Game game;

void update() {
    window.SetFullscreen(isFullscreen);
}

void input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) isRunning = false;
    }
    const Uint8 *keyStatus = SDL_GetKeyboardState(NULL);
    if (keyStatus[SDL_SCANCODE_ESCAPE]) isRunning = false;
    if (keyStatus[SDL_SCANCODE_F11]) isFullscreen = !isFullscreen;

    if (keyStatus[SDL_SCANCODE_R]) game.ReInit();
}

void draw() {
    window.ClearDrawables();

    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            int cell = game.GetCell(i, j);
            if(cell >= 1) {
                IDrawable drawable;
                SDL_Rect rect = {i * sizeX, j * sizeY, sizeX, sizeY};
                drawable.SetRect(rect);
                window.AddToDraw(drawable);
            }
        }
    }

    window.Draw();
}

unsigned int lastTime1 = 0, currentTime;

int main(int argc, char *argv[]) {
    isRunning = true;

    window.Init(WINDOW_WIDTH, WINDOW_HEIGHT);
    game.Init(w, h, 100);
    
    while (isRunning) {
        lastFrame = SDL_GetTicks();
        if(lastFrame >= lastTime1 + 1000) {
            lastTime1 = lastFrame;
            fps = frameCount;
            frameCount = 0;
        }

        currentTime = SDL_GetTicks();
        if (currentTime > lastTime + 1000) {
            game.Run();
            lastTime = currentTime;
        }

        update();
        input();
        draw();

        frameCount++; 
        timerFPS = SDL_GetTicks() - lastFrame;
        if(timerFPS < (1000 / 60)) {
            SDL_Delay((1000 / 60) - timerFPS);
        }
    }
    window.Quit();

    return 0;
}