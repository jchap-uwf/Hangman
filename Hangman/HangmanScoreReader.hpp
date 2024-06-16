#ifndef LEAD_READ_HPP
#define LEAD_READ_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using std::pair;
using std::vector;
using std::string;

class HangmanScoreReader {
    public:
        HangmanScoreReader(); // Uses account login file
        int getLineCount(); // Get total number of lines in the file
        int getScore(int lineNumber); // returns a particular line's score (0 is highest score, getLineCount() -1 is lowest score)
        std::string getUser(int lineNumber); // returns username associated with a particular score
    private:
        std::vector<std::string> usernames;
        std::vector<int> highScores;
        int lineCount;
        std::string leaderboardFileName = "hangmanFiles/userdata/userdata.txt";
        static bool sortByScore(const pair<string, int>& a, const pair<string, int>& b);

};

HangmanScoreReader::HangmanScoreReader(){
    std::vector<int> unsortedScores;
    std::vector<std::string> unsortedNames;

    std::fstream fin;
    fin.open(leaderboardFileName, std::ios::in);

    std::string username;
    std::string highScore;
    while(fin >> username){ // should be username
        fin >> highScore; // this is the password, overwrite this 
        fin >> highScore; // correct high score
        unsortedNames.push_back(username);
        unsortedScores.push_back(stoi(highScore));
    }

    lineCount = unsortedNames.size();
    fin.close();

    vector<pair<string, int>> combined;
    for(int i = 0; i < unsortedNames.size(); i++) {
        combined.push_back(make_pair(unsortedNames[i], unsortedScores[i]));
    }

    std::sort(combined.begin(), combined.end(), sortByScore);

    for(int i = 0; i < combined.size(); i++) {
        usernames.push_back(combined[i].first);
        highScores.push_back(combined[i].second);
    }
}

int HangmanScoreReader::getLineCount(){
    return lineCount;
}

std::string HangmanScoreReader::getUser(int lineNumber){
    if(lineNumber >= 0 && lineNumber < usernames.size()){
        return usernames.at(lineNumber);
    } else return "";
}

int HangmanScoreReader::getScore(int lineNumber){
    if(lineNumber >= 0 && lineNumber < highScores.size()){
        return highScores.at(lineNumber);
    } else return -1;
}

bool HangmanScoreReader::sortByScore(const pair<string, int>& a, const pair<string, int>& b){
    return a.second > b.second;
}



#endif