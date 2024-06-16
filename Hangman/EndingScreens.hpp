#ifndef ENDSCREEN_HPP
#define ENDSCREEN_HPP

#include "raylib.h"
#include <string>

class EndingScreens {
    public:
    EndingScreens();
    void setUser(std::string username);
    void setScore(std::string score);
    void drawLoseScreen();
    void drawWinScreen();

    private:
        std::string username;
        std::string score;
        std::string gameOver;
        std:: string youWin;
        std::string yourScore;
        std::string playAgain;
        
};

#endif