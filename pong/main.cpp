#include "game.h"

int main() {
    InitGame();

    while (!ShouldCloseGame()) {
        UpdateGame();
        DrawGame();
    }

    UnloadGame();
    return 0;
}
