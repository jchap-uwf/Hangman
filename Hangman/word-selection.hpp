#ifndef WORD_SELECTION_HPP
#define WORD_SELECTION_HPP

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

class word_selection
// a class that generates words banks and returns them for the games
{
private:
    vector<vector<string>> wordBank;
    vector<string> guessWords;
    vector<string> chosenWords;
    TextInputBox *ti = new TextInputBox(515, 390, 30, 30, 2);
    stringstream ss;
    int chosenWordBank{};
    int wordAmount{};
    int num{};

public:
    word_selection(){};

    // reads from word bank files and places the words in a vector of word banks
    void readWordbank()
    {
        std::ifstream myfile;
        std::string myline;

        wordBank.resize(5);

        for (int i = 1; i < 6; ++i)
        {

            std::string fname = "hangmanFiles/wordbanks/wordbank" + std::to_string(i) + ".txt";

            myfile.open(fname);

            while (myfile)
            {
                std::getline(myfile, myline);
                wordBank[i - 1].push_back(myline);
            }
            myfile.close();
        }
    };

    // ask user for their input about what word banks they want and how many words
    vector<string> selectWords(string n)
    {
        readWordbank();

        setChosenWordBank(n);

        return getRandomWords(chosenWordBank - 1, wordAmount);
    };

    void setChosenWordBank(std::string s){
        try {
        chosenWordBank = std::stoi(s); // Convert to integer
    } catch (...) {
        throw std::invalid_argument("Invalid argument for chosenWordBank");
    }
    }
    int getChosenWordBank() const{
        return this->chosenWordBank;
    }

    void setWordAmount(int n){
        this->wordAmount = n;
    }

    int getWordAmount(){
        return this->wordAmount;
    }

    // returns all wordbanks
    vector<string> getAllWordBanks()
    {

        vector<string> Allwords;

        int wBankSize = wordBank.size();

        for (int i = 0; i < wBankSize - 1; i++)
        {
        
         int innerWBankSize = wordBank.at(i).size();
            for (int j = 0; j < innerWBankSize - 1; j++)
            {

                Allwords.push_back(wordBank.at(i).at(j));
            }
        }
        return Allwords;
    };

    // returns random words placed in a vector
    vector<string> getRandomWords(int chosenBank, int amountofWords)
    {
        if (chosenBank == -1)
        {
            chosenBank = getRandomWordBank();
        }

        else if (chosenBank == 5)
        {

            srand(time(0));
            for (int i = 0; i < amountofWords;)
            {

                int k = rand() % getAllWordBanks().size();

                if (!(std::find(chosenWords.begin(), chosenWords.end(), getAllWordBanks().at(k)) != chosenWords.end()))
                {

                    guessWords.push_back(getAllWordBanks().at(k));
                    chosenWords.push_back(getAllWordBanks().at(k));

                    ++i;
                }
            }
        }
        else
        {

            srand(time(0));
            for (int i = 0; i < amountofWords;)
            {

                int k = rand() % wordBank.at(chosenBank).size();

                if (!(std::find(chosenWords.begin(), chosenWords.end(), wordBank.at(chosenBank).at(k)) != chosenWords.end()))
                {
                    guessWords.push_back(wordBank.at(chosenBank).at(k));
                    chosenWords.push_back(wordBank.at(chosenBank).at(k));
                    ++i;

                }
            }
        }

        return guessWords;
    };

    std::string GetRandomWord(std::vector<std::string> words, int amountOfWords)
    {
        if (amountOfWords <= 0) {
        throw std::invalid_argument("amountOfWords must be greater than zero.");
        amountOfWords = 1;
        }
        if (words.empty()) {
        throw std::out_of_range("The word list is empty.");
        }


        srand(time(0));
        int k = rand() % std::min(amountOfWords, static_cast<int>(words.size()));
        //int k = rand() % amountOfWords;
        
        if (k < 0 || k >= static_cast<int>(words.size())) {
        throw std::out_of_range("Random index is out of range.");
        }

        return words.at(k);
    }

    // returns a random word bank
    int getRandomWordBank()
    {

        srand(time(0));

        int k = rand() % 2; // wordBank.size();

        if (k > 1) // if k is greater that the amount of words
        {
            k -= 1;
        }

        return k;
    };


    // retarts the vector that has the worlds for the user to guess
    void guessBankRestart()
    {

        int currSize = guessWords.size();
        for (int i = 0; i < currSize; i++)
        {
            guessWords.pop_back();
        }
    };
};

#endif