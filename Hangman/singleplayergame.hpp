#include "raylib.h"
#include "word-selection.hpp"
#include "HangmanWord.hpp"
#include "PlayerScore.hpp"
#include "TextInputbox.hpp"
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class SinglePlayerGame
{
private:
    word_selection ws;
    std::vector<std::string> words;
    std::string chosenWord;
    HangmanWord *hangmanWord = nullptr;
    PlayerScore playerScore;
    char *score;
    std::string input;
    int mistakes = 0;
    bool gameOver = false;
    bool playerWin;

public:
    void startNewGame(std::string w)
    {
        chosenWord = w;
        std::string randomWord = w;
        hangmanWord = new HangmanWord(randomWord);
        playerScore.startNewGame(randomWord);
        mistakes = 0;
        input = "";
        setGameOver(false);
    }

    void playGame(string w)
    {
        if (!getGameOver())
        {

            input = w;
            cout << chosenWord << endl;
            cout << input << endl;
            DrawText(hangmanWord->getObscuredWord().c_str(), 50, 50, 30, BLACK);

            if (IsKeyPressed(KEY_ENTER))
            {
                if (!input.empty())
                {
                    if (input.length() == 1)
                    {
                        processGuess(input);
                    }
                    else if (input.length() > 1)
                    {
                        processGuess(input);
                    }
                    input = "";
                }
            }
            else
            {
                char key = GetCharPressed();
                while (key)
                {
                    if (isalpha(key))
                    {
                        input += tolower(key);
                    }
                    key = GetCharPressed();
                }
            }

            playerScore.displayScore();
            DrawText("Your letter or word guess:", 50, 100, 30, BLACK);
            DrawText("Lives left: ", 10, 170, 30, BLACK);
            DrawText("||||||" + mistakes, 200, 170, 30, BLACK);

            if (mistakes == 6)
            {
                DrawText("Game Over!", 100, 200, 50, RED);
                setPlayerWin(false);
                setGameOver(true);
            }
            if (hangmanWord->getObscuredWord() == hangmanWord->getCompletedWord() || input == chosenWord)
            {
                DrawText("You Win!", 100, 200, 50, GREEN);
                setPlayerWin(true);
                setGameOver(true);
            }
        }
    }

    void processGuess(const std::string &guess)
    {
        if (guess.length() == 1)
        {
            if (hangmanWord->guessLetter(guess[0]))
            {
                playerScore.adjustScore(true, false);
                mistakes++;
                setMistakes(mistakes);
            }
            else
            {
                playerScore.adjustScore(false, false);
            }
        }
        else
        { // Word guess
            if (hangmanWord->guessWord(guess))
            {
                playerScore.adjustScore(true, true);
                mistakes++;
                setMistakes(mistakes);
            }
            else
            {
                playerScore.adjustScore(false, true);
            }
        }
    }

    void setMistakes(int m)
    {
        this->mistakes = m;
    }

    int getMistakes()
    {
        return this->mistakes;
    }

    void setGameOver(bool b)
    {
        this->gameOver = b;
    }

    bool getGameOver()
    {
        return this->gameOver;
    }

    void setPlayerWin(bool w)
    {
        this->playerWin = w;
    }

    bool getPlayerWin()
    {
        return this->playerWin;
    }

    void drawLimb0()
    {
        int x = 300, y = 200;
        DrawLine(x, y, x, y + 200, BLACK);
        DrawLine(x, y, x + 100, y, BLACK);
        DrawLine(x + 100, y, x + 100, y + 50, BLACK);
    }

    void drawLimb1()
    {
        int x = 300, y = 200;
        drawLimb0();
        DrawCircle(x + 100, y + 70, 20, BLACK);
    }

    void drawLimb2()
    {
        int x = 300, y = 200;
        drawLimb0();
        drawLimb1();
        DrawLine(x + 100, y + 90, x + 100, y + 150, BLACK);
    }

    void drawLimb3()
    {
        int x = 300, y = 200;
        drawLimb0();
        drawLimb1();
        drawLimb2();
        DrawLine(x + 100, y + 100, x + 70, y + 130, BLACK);
    }

    void drawLimb4()
    {
        int x = 300, y = 200;
        drawLimb0();
        drawLimb1();
        drawLimb2();
        drawLimb3();
        DrawLine(x + 100, y + 100, x + 130, y + 130, BLACK);
    }

    void drawLimb5()
    {
        int x = 300, y = 200;
        drawLimb0();
        drawLimb1();
        drawLimb2();
        drawLimb3();
        drawLimb4();
        DrawLine(x + 100, y + 150, x + 70, y + 180, BLACK);
    }

    void drawLimb6()
    {
        int x = 300, y = 200;
        drawLimb0();
        drawLimb1();
        drawLimb2();
        drawLimb3();
        drawLimb4();
        drawLimb5();
        DrawLine(x + 100, y + 150, x + 130, y + 180, BLACK);
    }

    void drawLimb7()
    {
        int x = 300, y = 200;
        drawLimb0();
        drawLimb1();
        drawLimb2();
        drawLimb3();
        drawLimb4();
        drawLimb5();
        drawLimb6();
        DrawLine(x + 100, y + 150, x + 130, y + 180, BLACK);
    }

    void drawHangman(int wrong)
    {

        switch (wrong)
        {
        case 0:
            drawLimb0();
            break;
        case 1:
            drawLimb1();
            break;
        case 2:
            drawLimb2();
            break;
        case 3:
            drawLimb3();
            break;
        case 4:
            drawLimb4();
            break;
        case 5:
            drawLimb5();
            break;
        case 6:
            drawLimb6();
            break;
        case 7:
            drawLimb7();
            break;
        case 8:
            break;
        }
    }
};