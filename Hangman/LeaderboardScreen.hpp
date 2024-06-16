#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP
#include "raylib.h"
#include "HangmanScoreReader.hpp"

class LeaderboardScreen {
    public:
        LeaderboardScreen();
        void display();

    private:
        HangmanScoreReader reader;
};

LeaderboardScreen::LeaderboardScreen(){

}

void LeaderboardScreen::display(){
    ClearBackground(DARKBLUE);

    DrawText("Top Scores", 450, 10, 45, WHITE);
    
    int numLinesToDisplay = reader.getLineCount();
    if (numLinesToDisplay > 8) numLinesToDisplay = 8;

    for(int i = 0; i < numLinesToDisplay; i++) {
        string username = reader.getUser(i);
        string highScore = std::to_string(reader.getScore(i));

        string textToDisplay = "------------------------------";
        textToDisplay.replace(textToDisplay.begin(),textToDisplay.begin() + username.length(), username);

        textToDisplay.replace(textToDisplay.end() - highScore.length() ,textToDisplay.end(), highScore);

        DrawText(textToDisplay.c_str(), 70, 45*i + 50, 40, WHITE);

    }

}

#endif
