#include "game.hpp"

using namespace blit;


const int GRID_SIZE_X = 60; // must be divisible by 480
const int PIXEL_SIZE = 480 / GRID_SIZE_X;
const int GRID_SIZE_Y = 320 / PIXEL_SIZE; //40; // must be divisible by 320

int grid[GRID_SIZE_X][GRID_SIZE_Y] = {0};

///////////////////////////////////////////////////////////////////////////
//
// init()
//
// setup your game here
//
void init() {
    set_screen_mode(ScreenMode::hires);
}


struct textCoords {
    int x = 0;
    int y = 0;
} textCoords;


///////////////////////////////////////////////////////////////////////////
//
// render(time)
//
// This function is called to perform rendering of the game. time is the 
// amount of milliseconds elapsed since the start of your game
//
void render(uint32_t time) {

    // clear the screen -- screen is a reference to the frame buffer and can be used to draw all things with the 32blit
    screen.clear();

    // draw some text at the top of the screen
    screen.alpha = 255;
    screen.mask = nullptr;
    screen.pen = Pen(255, 255, 255);
    screen.rectangle(Rect(0, 0, 320, 480));
    screen.pen = Pen(0, 0, 0);
    screen.text("Hello 32blit!", minimal_font, Point(textCoords.x, textCoords.y));

    screen.pen = Pen(0, 255, 0);
    for (int row = 0; row < GRID_SIZE_X; row++) {
        for (int col = 0; col < GRID_SIZE_Y; col++) {
            // printf("Checking %d %d\n", row, col);
            if (grid[row][col] == 0) {
                screen.rectangle(Rect((row * PIXEL_SIZE) + 1, (col * PIXEL_SIZE) + 1, PIXEL_SIZE - 2, PIXEL_SIZE - 2));
            }
        }
    }


}

///////////////////////////////////////////////////////////////////////////
//
// update(time)
//
// This is called to update your game state. time is the 
// amount of milliseconds elapsed since the start of your game
//
void update(uint32_t time) {
    if (blit::buttons & blit::Button::DPAD_RIGHT) {
        // Move character right
        textCoords.x++;
    }
    if (blit::buttons & blit::Button::DPAD_LEFT) {
        // Move character right
        textCoords.x--;
    }
    if (blit::buttons & blit::Button::DPAD_UP) {
        // Move character right
        textCoords.y--;
    }

    if (blit::buttons & blit::Button::DPAD_DOWN) {
        // Move character right
        textCoords.y++;
    }


}