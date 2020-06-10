#include <game.h>
#include <stdlib.h> 
#include <ctime>

#include <iostream>

int Game::GetNeighborhoodCount(int x, int y) {
    int neighborhoodCount = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int curX = x + i;
            int curY = y + j;
            if(curX >= 0 && curX < w && curY >= 0 && curY < h) {
                if(i == 0 && j == 0) {
                    continue;
                }
                if(array[curX][curY] == 1) {
                    neighborhoodCount++;
                }
            }
        }
    }
    return neighborhoodCount;
}

void Game::SetCell(int x, int y) {
    array[x][y] = 1;
}

void Game::RemoveCell(int x, int y) {
    array[x][y] = 0;
}

void Game::Init(int width, int height, int cellAmount) {
    w = width;
    h = height;
    c = cellAmount;
    array = new int*[w];
    for (int i = 0; i < w; i++) {
        array[i] = new int[h];
    }

    ReInit();
}

void Game::ReInit() {
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            array[i][j] = 0;
        }
    }

    srand(time(0));

    for(int i = 0; i < c;) {
        int randX = rand() % w;
        int randY = rand() % h;

        if(array[randX][randY] != 1) {
            array[randX][randY] = 1;
            i++;
            std::cout << randX << " " << randY << std::endl;
        }
    }
}

int Game::GetCell(int x, int y) {
    return array[x][y];
}

void Game::Run() {
    for(int i = 0; i < w; i++) {
        for(int j = 0; j < h; j++) {
            int neighborhoodCount = GetNeighborhoodCount(i, j);
            if((neighborhoodCount == 2 && array[i][j] == 1) || neighborhoodCount == 3) {
                array[i][j] = 1;
            }
            else {
                array[i][j] = 0;
            }
        }
    }
}
