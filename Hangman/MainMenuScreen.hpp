#ifndef MAINMENU_HPP
#define MAINMENU_HPP

#include "raylib.h"
#include "TextInputBox.hpp"

class MainMenuScreen {
    public:
        MainMenuScreen();
        void update();
        void draw();

        void updateWordSelection();
        void drawWordSelection();

        int getUserConfirmedChoice(); // 0 (no choice yet), 1, 2, 3, or 4
        int getUserConfirmedWordChoice();
    private:
        bool userConfirmed;
        int confirmedChoice;
        int userChoice;
};
#endif