#include "EndingScreens.hpp"

EndingScreens::EndingScreens(){
    youWin = "YOU WIN";
    gameOver = "GAME OVER";
    score = "[NO_SCORE]";
    yourScore = "Your Score:" + score;
    playAgain = "Press Enter to return to Main Menu";

    username = "[NO_NAME]";
    
}

void EndingScreens::setUser(std::string username){
    this->username = username;
}

void EndingScreens::setScore(std::string score){
    this->score = score;
    yourScore = "Your Score: " + score;
}



void EndingScreens::drawLoseScreen(){
    ClearBackground(MAROON);
    
    int textOffset = MeasureText(gameOver.c_str(), 50)/2;
    DrawText(gameOver.c_str(), 410 - textOffset, 180, 50, BLACK);

    textOffset = MeasureText(yourScore.c_str(), 40)/2;
    DrawText(yourScore.c_str(), 410 - textOffset, 235, 40, DARKGRAY);

    textOffset = MeasureText(playAgain.c_str(), 25)/2;
    DrawText(playAgain.c_str(), 410 - textOffset, 280, 25, DARKGRAY);
}

void EndingScreens::drawWinScreen(){
    ClearBackground(LIME);
    
    int textOffset = MeasureText(youWin.c_str(), 50)/2;
    DrawText(youWin.c_str(), 410 - textOffset, 180, 50, WHITE);

    textOffset = MeasureText(yourScore.c_str(), 40)/2;
    DrawText(yourScore.c_str(), 410 - textOffset, 235, 40, WHITE);

    textOffset = MeasureText(playAgain.c_str(), 25)/2;
    DrawText(playAgain.c_str(), 410 - textOffset, 280, 25, WHITE);
}