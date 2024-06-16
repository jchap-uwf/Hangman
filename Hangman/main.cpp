// #include "raylib.h" feature for later sprints
#include <iostream>
#include <string>
#include "raylib.h"
#include "gamemenu.hpp"
#include "hangmanLogin.hpp"
#include "TextInputBox.hpp"
#include "word-selection.hpp"
#include "singleplayergame.hpp"
#include "MainMenuScreen.hpp"
#include "LoginScreen.hpp"
#include "LeaderboardScreen.hpp"
#include "EndingScreens.hpp"

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
typedef enum GameScreen
{
    LOGO = 0,
    LOGIN,
    MAIN_MENU,
    WORD_SELECTION,
    SINGLE_PLAYER_GAME,
    ENDING,
    LEADERBOARD
} GameScreen;

struct LoginInfo
{
    char *name;
    int letterCount;
    int loginFramesCount;
};

using namespace std;
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 820;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Hangmania");

    GameScreen currentScreen = LOGO;

    GameMenu menu;
    std::string chosenWord;

    MainMenuScreen mainMenu;
    MainMenuScreen *wm = new MainMenuScreen();
    TextInputBox InputBox(500, 100, 300, 30, 15);
    string text;

    LoginScreen loginScreen;
    std::string username = "";
    std::string password = "";

    LeaderboardScreen leaderboardScreen;
    EndingScreens endingScreens;

    hangmanLogin userAccount;

    SinglePlayerGame *sp = new SinglePlayerGame();

    word_selection *ws = new word_selection();
    // TODO: Initialize all required variables and load all required data here!

    TextInputBox usernameBox(screenWidth / 2.0f - 50, 220, 250, 50, 15);
    TextInputBox passwordBox(screenWidth / 2.0f - 50, 300, 250, 50, 15);

    int framesCounter = 0; // Useful to count frames
    bool mostRecentgameWon = false;
    std::vector<std::string> wordList;
    bool gameStarted = false;

    std::vector<std::string> words;

    int choice;

    SetTargetFPS(10); // Set desired framerate (frames-per-second)
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch (currentScreen)
        {
        case LOGO:
        {
            // TODO: Update LOGO screen variables here!

            framesCounter++; // Count frames

            // Wait for 2 seconds (20 frames) before jumping to TITLE screen
            if (framesCounter > 20)
            {
                framesCounter = 0;
                currentScreen = MAIN_MENU;
            }
        }
        break;
        case MAIN_MENU:
        {
            framesCounter++;
            mainMenu.update();

            switch (mainMenu.getUserConfirmedChoice())
            {
            case 0:
            {
                // do nothing
                break;
            }
            case 1:
            {
                framesCounter = 0;
                currentScreen = LOGIN;
                break;
            }
            case 2:
            {
                framesCounter = 0;
                userAccount.login("Default", "AdminPasswd");
                ws->readWordbank();
                currentScreen = WORD_SELECTION;

                break;
            }
            case 3:
            {
                framesCounter = 0;
                currentScreen = LEADERBOARD;
                break;
            }
            case 4:
            {
                framesCounter = 0;
                exit(0);
                break;
            }
            }
        }
        break;
        case LOGIN:
        {
            framesCounter++;

            loginScreen.update();

            if (loginScreen.FieldsConfirmed() && framesCounter > 6)
            {
                framesCounter = 0;
                if (userAccount.login(loginScreen.getUsernameField(), loginScreen.getPasswordField()))
                {
                    ws->readWordbank();
                    currentScreen = WORD_SELECTION;
                }
                else
                {
                    loginScreen.resetFields();
                    currentScreen = MAIN_MENU;
                }
            }
        }
        break;
        case LEADERBOARD:
        {
            framesCounter++;
            if (framesCounter > 5 && (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_ESCAPE)))
            {
                framesCounter = 0;
                currentScreen = MAIN_MENU;
            }
        }
        break;
        case WORD_SELECTION:
        {
            framesCounter++;
            wm->updateWordSelection();

            switch (wm->getUserConfirmedWordChoice())
            {
            case 0:
            {
                ws->setChosenWordBank("0");
                wordList = ws->getRandomWords(5, 1);
                if (!wordList.empty())
                {
                    chosenWord = wordList[0];
                }
                currentScreen = SINGLE_PLAYER_GAME;
            }
            break;
            case 1:
            {
                ws->setChosenWordBank("1");
                wordList = ws->getRandomWords(1, 1);
                if (!wordList.empty())
                {
                    chosenWord = wordList[0];
                }
                currentScreen = SINGLE_PLAYER_GAME;
            }
            break;
            case 2:
            {
                ws->setChosenWordBank("2");
                wordList = ws->getRandomWords(2, 1);
                if (!wordList.empty())
                {
                    chosenWord = wordList[0];
                }
                currentScreen = SINGLE_PLAYER_GAME;
            }
            break;
            case 3:
            {
                ws->setChosenWordBank("3");
                wordList = ws->getRandomWords(3, 1);
                if (!wordList.empty())
                {
                    chosenWord = wordList[0];
                }
                currentScreen = SINGLE_PLAYER_GAME;
            }
            break;
            case 4:
            {
                ws->setChosenWordBank("4");
                wordList = ws->getRandomWords(4, 1);
                if (!wordList.empty())
                {
                    chosenWord = wordList[0];
                }
                currentScreen = SINGLE_PLAYER_GAME;
            }
            break;
            case 5:
            {
                ws->setChosenWordBank("5");
                wordList = ws->getRandomWords(5, 1);
                if (!wordList.empty())
                {
                    chosenWord = wordList[0];
                }
                currentScreen = SINGLE_PLAYER_GAME;
            }
            break;
            case 6:
            {
                ws->setChosenWordBank("6");
                wordList = ws->getRandomWords(6, 1);
                if (!wordList.empty())
                {
                    chosenWord = wordList[0];
                }
                currentScreen = SINGLE_PLAYER_GAME;
            }
            break;
            }
        }
        break;
        case SINGLE_PLAYER_GAME:
        {
            // TODO: Update GAMEPLAY screen variables here!

            framesCounter++;

            if (!gameStarted)
            {
                // Only start a new game if it hasn't been started yet
                sp->startNewGame(chosenWord);
                gameStarted = true; // Set the flag to true so we don't start again
            }

            InputBox.update();
            text = InputBox.getText();

            sp->playGame(text);

            if (IsKeyPressed(KEY_ENTER))
            {
                InputBox.setText("");
            }

            sp->drawHangman(sp->getMistakes());

            if (sp->getGameOver())
            {
                mostRecentgameWon = sp->getPlayerWin();
                currentScreen = ENDING;
            }
        }
        break;
        case ENDING:
        {
            // Press enter to return to TITLE screen
            if (IsKeyPressed(KEY_ENTER))
            {
                currentScreen = MAIN_MENU;
                gameStarted = false;
            }
        }
        break;
        default:
            break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BEIGE);

        switch (currentScreen)
        {
        case LOGO:
        {
            // TODO: Draw LOGO screen here!
            DrawText("HANGMANIA", 20, 20, 40, LIGHTGRAY);
            DrawText("Developed by Group 4", 290, 220, 20, GRAY);
        }
        break;
        case MAIN_MENU:
            mainMenu.draw();
            break;

        case LOGIN:
        {
            loginScreen.draw();
        }
        break;

        case LEADERBOARD:
        {
            leaderboardScreen.display();
        }
        break;

        case WORD_SELECTION:
        {
            wm->drawWordSelection();
        }
        break;

        case SINGLE_PLAYER_GAME:
        {
            // TODO: Draw GAMEPLAY screen here!
            sp->drawHangman(0);
            InputBox.draw();
        }
        break;
        case ENDING:
        {
            if (mostRecentgameWon)
                endingScreens.drawWinScreen();
            else
                endingScreens.drawLoseScreen();
        }
        break;
        default:
            break;
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // TODO: Unload all loaded data (textures, fonts, audio) here!

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
