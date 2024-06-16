#ifndef HANGMANWORD_HPP
#define HANGMANWORD_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

enum guessCodes { CORRECT_GUESS, INCORRECT_GUESS, INVALID_GUESS, REPEATED_GUESS, SOMETHING_WENT_REALLY_REALLY_WRONG };
static std::string guessCodesAsStrings[] = { "CORRECT_GUESS", "INCORRECT_GUESS", "INVALID_GUESS", "REPEATED_GUESS", "SOMETHING_WENT_REALLY_REALLY_WRONG" };


class HangmanWord {
public:
    HangmanWord(std::string word);
    int guessLetter(char letter);
    int guessWord(std::string word);

    std::string getObscuredWord();
    std::string getCompletedWord();

    void resetHangmanWord(); // clears the lists of guessed letters and words and fully obscures the word with dashes once again.

private:
    std::string completedWord;
    std::string obscuredWord;

    std::vector<char> guessedLetters;
    std::vector<std::string> guessedWords;

    void updateObscuredWord(char letter);
};

HangmanWord::HangmanWord(std::string word) {
    this->completedWord = word;
    this->obscuredWord = word;

    for (int i = 0; i < obscuredWord.length(); i++) {
        obscuredWord[i] = '_';
    }
}

void HangmanWord::updateObscuredWord(char letter) {
    char lowerLetter = char(tolower(letter));

    for (int i = 0; i < obscuredWord.length(); i++) {
        if (tolower(completedWord[i]) == lowerLetter) {
            obscuredWord[i] = completedWord[i];
        }
    }
}

void HangmanWord::resetHangmanWord() {
    guessedLetters.clear();
    guessedWords.clear();
    for (int i = 0; i < obscuredWord.length(); i++) {
        obscuredWord[i] = '_';
    }
}

int HangmanWord::guessLetter(char letter) {
    if (!isalpha(letter)) {
        return INVALID_GUESS;
    }

    char guess = char(tolower(letter));
    std::string lowerWord = completedWord;
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    if (std::count(guessedLetters.begin(), guessedLetters.end(), guess) != 0) {
        return REPEATED_GUESS;
    }

    guessedLetters.push_back(guess);

    if (lowerWord.find(guess) != std::string::npos) {
        updateObscuredWord(guess);
        return CORRECT_GUESS;
    }
    else {
        return INCORRECT_GUESS;
    }
}

int HangmanWord::guessWord(std::string word) {
    for (char c : word) {
        if (!isalpha(c)) return INVALID_GUESS;
    }

    std::string guess = word;
    std::transform(guess.begin(), guess.end(), guess.begin(), ::tolower);

    std::string loweredCompletedWord = completedWord;
    std::transform(loweredCompletedWord.begin(), loweredCompletedWord.end(), loweredCompletedWord.begin(), ::tolower);


    if (std::count(guessedWords.begin(), guessedWords.end(), guess) != 0) {
        return REPEATED_GUESS;
    }

    if (guess == loweredCompletedWord) {
        return CORRECT_GUESS;
    }
    else {
        guessedWords.push_back(guess);
        return INCORRECT_GUESS;
    }
}

std::string HangmanWord::getCompletedWord() { return completedWord; }
std::string HangmanWord::getObscuredWord() { return obscuredWord; }


#endif // HANGMANWORD_HPP