#ifndef PLAYERSCORE_HPP
#define PLAYERSCORE_HPP

#include <string>
#include <cctype> 
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

class PlayerScore {
private:
    int score;
    std::string s;
    std::stringstream ss;

    // Calculate initial score based on the amount of vowels and consonants
    void calculateInitialScore(const std::string& word) {
        int vowelsCount = 0;
        for (char character : word) { 
            if (std::isalpha(character)) {
                character = std::tolower(character);
                if (character == 'a' || character == 'e' || character == 'i' || character == 'o' || character == 'u') {
                    vowelsCount++;
                }
            }
        }
        int consonantsCount = word.length() - vowelsCount;
        
        //Score calculator
        score = (vowelsCount * 5) + (consonantsCount * 10) + (static_cast<int>(word.length()) * 10) + 10;
    }

public:
    PlayerScore() : score(0) {}

    // Initializes the score for a new game based on the provided word
    void startNewGame(const std::string& word) {
        calculateInitialScore(word);
    }

    // Adjusts the score depending on if word or letter was guessed incorrectly
    void adjustScore(bool correct, bool isWordGuess) {
    if (isWordGuess) {
        // Word Guesses
        if (!correct) {
            score -= 10; // Severely decrease score for incorrect word guess
        } else {
            // Increases score by 10 if word is guessed correctly
            score += 50; // Increase score by 10 for correct word guess
        }
    } else { // Letter guesses
        if (correct) {
            score -= 1; // Decreases score slightly for correct letter guess 
        } else {
            score -= 5; // Greatly decreases score for incorrect letter guess
        }
    }
    if (score < 0) score = 0; // Ensure the score never becomes negative
}


    // Displays the current score
    void displayScore() const {
        
    
        // defDrawText("Current Score: ",200, 220, 30, BLACK);
       
          
    }

    // Getter
    int getScore() const {
        return score;
    }
};

#endif 
