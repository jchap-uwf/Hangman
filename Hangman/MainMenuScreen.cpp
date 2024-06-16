#include "MainMenuScreen.hpp"

MainMenuScreen::MainMenuScreen()
{
    confirmedChoice = 0;
    userChoice = 0;
    userConfirmed = false;
}

void MainMenuScreen::update()
{
    if (userConfirmed)
        userConfirmed = false;

    if (IsKeyPressed(KEY_ONE))
    {
        userChoice = 1;
    }
    else if (IsKeyPressed(KEY_TWO))
    {
        userChoice = 2;
    }
    else if (IsKeyPressed(KEY_THREE))
    {
        userChoice = 3;
    }
    else if (IsKeyPressed(KEY_FOUR)){
        userChoice = 4;
    }
    else if (IsKeyPressed(KEY_ENTER))
    {
        if (userChoice != 0)
        {
            confirmedChoice = userChoice;
            userConfirmed = true;
        }
    }
}

void MainMenuScreen::draw()
{
    ClearBackground(BLUE);
    DrawText("MAIN MENU SCREEN", 20, 20, 40, ORANGE);

    if (userChoice == 0)
    {
        DrawText("Welcome to Hangman!", 60, 50, 45, BLACK);
        DrawText("1. Log in with an existing account", 70, 95, 40, BLACK);
        DrawText("2. Log in with the default account", 70, 140, 40, BLACK);
        DrawText("3. View Leaderboard", 70, 185, 40, BLACK);
        DrawText("4. Exit", 70, 230, 40, BLACK);
    }
    else if (userChoice == 1)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. Log in with an existing account", 70, 95, 40, ORANGE);
        DrawText("2. Log in with the default account", 70, 140, 40, BLACK);
        DrawText("3. View Leaderboard", 70, 185, 40, BLACK);
        DrawText("4. Exit", 70, 230, 40, BLACK);
    }
    else if (userChoice == 2)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. Log in with an existing account", 70, 95, 40, BLACK);
        DrawText("2. Log in with the default account", 70, 140, 40, ORANGE);
         DrawText("3. View Leaderboard", 70, 185, 40, BLACK);
        DrawText("4. Exit", 70, 230, 40, BLACK);
    }
    else if (userChoice == 3)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. Log in with an existing account", 70, 95, 40, BLACK);
        DrawText("2. Log in with the default account", 70, 140, 40, BLACK);
        DrawText("3. View Leaderboard", 70, 185, 40, ORANGE);
        DrawText("4. Exit", 70, 230, 40, BLACK);
    } else {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. Log in with an existing account", 70, 95, 40, BLACK);
        DrawText("2. Log in with the default account", 70, 140, 40, BLACK);
        DrawText("3. View Leaderboard", 70, 185, 40, BLACK);
        DrawText("4. Exit", 70, 230, 40, ORANGE); 
    }
}

void MainMenuScreen::updateWordSelection()
{
    if (userConfirmed)
        userConfirmed = false;

    if (IsKeyPressed(KEY_ONE))
    {
        userChoice = 1;
    }
    else if (IsKeyPressed(KEY_TWO))
    {
        userChoice = 2;
    }
    else if (IsKeyPressed(KEY_THREE))
    {
        userChoice = 3;
    }
    else if (IsKeyPressed(KEY_FOUR))
    {
        userChoice = 4;
    }
    else if (IsKeyPressed(KEY_FIVE))
    {
        userChoice = 5;
    }
    else if (IsKeyPressed(KEY_SIX))
    {
        userChoice = 6;
    }
    else if (IsKeyPressed(KEY_SEVEN))
    {
        userChoice = 7;
    }
    else if (IsKeyPressed(KEY_ENTER))
    {
        if (userChoice != 0)
        {
            confirmedChoice = userChoice;
            userConfirmed = true;
        }
    }
}

void MainMenuScreen::drawWordSelection()
{
    ClearBackground(BLUE);
    DrawText("Word Bank Selection", 20, 20, 40, ORANGE);

    if (userChoice == 0)
    {
        DrawText("Which word bank do you want to use?", 10, 50, 42, BLACK);
        DrawText("1. random", 70, 95, 40, BLACK);
        DrawText("2. dog breeds", 70, 140, 40, BLACK);
        DrawText("3. pokemon", 70, 185, 40, BLACK);
        DrawText("4. tech", 70, 235, 40, BLACK);
        DrawText("5. Physics", 70, 275, 40, BLACK);
        DrawText("6. Anime", 70, 320, 40, BLACK);
        DrawText("7. All", 70, 365, 40, BLACK);
    }
    else if (userChoice == 1)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. random", 70, 95, 40, ORANGE);
        DrawText("2. dog breeds", 70, 140, 40, BLACK);
        DrawText("3. pokemon", 70, 185, 40, BLACK);
        DrawText("4. tech", 70, 235, 40, BLACK);
        DrawText("5. Physics", 70, 275, 40, BLACK);
        DrawText("6. Anime", 70, 320, 40, BLACK);
        DrawText("7. All", 70, 365, 40, BLACK);
    }
    else if (userChoice == 2)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. random", 70, 95, 40, BLACK);
        DrawText("2. dog breeds", 70, 140, 40, ORANGE);
        DrawText("3. pokemon", 70, 185, 40, BLACK);
        DrawText("4. tech", 70, 235, 40, BLACK);
        DrawText("5. Physics", 70, 275, 40, BLACK);
        DrawText("6. Anime", 70, 320, 40, BLACK);
        DrawText("7. All", 70, 365, 40, BLACK);
    }
    else if (userChoice == 3)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. random", 70, 95, 40, BLACK);
        DrawText("2. dog breeds", 70, 140, 40, BLACK);
        DrawText("3. pokemon", 70, 185, 40, ORANGE);
        DrawText("4. tech", 70, 235, 40, BLACK);
        DrawText("5. Physics", 70, 275, 40, BLACK);
        DrawText("6. Anime", 70, 320, 40, BLACK);
        DrawText("7. All", 70, 365, 40, BLACK);
    }
    else if (userChoice == 4)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. random", 70, 95, 40, BLACK);
        DrawText("2. dog breeds", 70, 140, 40, BLACK);
        DrawText("3. pokemon", 70, 185, 40, BLACK);
        DrawText("4. tech", 70, 235, 40, ORANGE);
        DrawText("5. Physics", 70, 275, 40, BLACK);
        DrawText("6. Anime", 70, 320, 40, BLACK);
        DrawText("7. All", 70, 365, 40, BLACK);
    }
    else if (userChoice == 5)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. random", 70, 95, 40, BLACK);
        DrawText("2. dog breeds", 70, 140, 40, BLACK);
        DrawText("3. pokemon", 70, 185, 40, BLACK);
        DrawText("4. tech", 70, 235, 40, BLACK);
        DrawText("5. Physics", 70, 275, 40, ORANGE);
        DrawText("6. Anime", 70, 320, 40, BLACK);
        DrawText("7. All", 70, 365, 40, BLACK);
    }
    else if (userChoice == 6)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. random", 70, 95, 40, BLACK);
        DrawText("2. dog breeds", 70, 140, 40, BLACK);
        DrawText("3. pokemon", 70, 185, 40, BLACK);
        DrawText("4. tech", 70, 235, 40, BLACK);
        DrawText("5. Physics", 70, 275, 40, BLACK);
        DrawText("6. Anime", 70, 320, 40, ORANGE);
        DrawText("7. All", 70, 365, 40, BLACK);
    }
    else if (userChoice == 7)
    {
        DrawText("Press ENTER to confirm", 60, 50, 45, BLACK);
        DrawText("1. random", 70, 95, 40, BLACK);
        DrawText("2. dog breeds", 70, 140, 40, BLACK);
        DrawText("3. pokemon", 70, 185, 40, BLACK);
        DrawText("4. tech", 70, 235, 40, BLACK);
        DrawText("5. Physics", 70, 275, 40, BLACK);
        DrawText("6. Anime", 70, 320, 40, BLACK);
        DrawText("7. All", 70, 365, 40, ORANGE);
    }
}

int MainMenuScreen::getUserConfirmedChoice()
{
    if (userConfirmed)
        return confirmedChoice;
    else
        return 0;
}


int MainMenuScreen::getUserConfirmedWordChoice()
{
    if (userConfirmed)
        return confirmedChoice;
    else
        return -1;
}