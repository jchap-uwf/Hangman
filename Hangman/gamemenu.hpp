#ifndef GAMEMENU_HPP
#define GAMEMENU_HPP
#include <raylib.h>
#include <string>
#include <sstream>

#define MAX_INPUT_CHARS 1

#include <iostream>
#include <string>

#include <stdlib.h>


class GameMenu {

public:
    void displayLoginMenu(){
        
    }

    void displayOptionsMenu(){
        DrawText("Welcome to Hangman: ", 60, 50, 45, BLACK);
        DrawText("1. Log in with an existing account", 70, 95, 40, BLACK);
        DrawText("2. Log in with the default account", 70, 140, 40, BLACK);
        DrawText("3. Exit", 70, 185, 40, BLACK);
    }

    void endGameMenu(){
        DrawText("End of game menu ", 60, 50, 45, BLACK);
        DrawText("1. Start a game with the same word bank.", 70, 95, 40, BLACK);
        DrawText("2. Return to Main menu", 70, 140, 40, BLACK);
        DrawText("3. Exit game", 70, 185, 40, BLACK);        
    }

    int getUserChoice(int numChoices = 2) {
            
        return numChoices;
    
    }

    void getUsername(){
        DrawText("Enter your username: ", 35, 220, 25, BLACK);
    }

     void getPassword(){
        DrawText( "Enter your password: ", 35, 300, 25, BLACK);
    }
 

    void printLogo(){
    std::cout << " _\n";                                             
    std::cout << "| |\n";                                            
    std::cout << "| |__   __ _ _ __   __ _ _ __ ___   __ _ _  __\n";  
    std::cout << "| '_ \\ / _` | '_ \\ / _` | '_ ` _  \\/ _` | '_  \\\n"; 
    std::cout << "| | | | (_| | | | | (_| | | | | | | (_| | | | |\n";
    std::cout << "|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_|\n";
    std::cout << "                    __/ |\n";                      
    std::cout << "                   |___/\n";               
    // from https://ascii.co.uk/art/hangman
    }
};

#endif