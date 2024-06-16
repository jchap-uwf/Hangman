#ifndef HANGMAN_HPP
#define HANGMAN_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::fstream;
using std::ios;
using std::vector;
using std::to_string;

class hangmanLogin {
    private:
    std::string accountFileName;
    bool loggedIn = false;

    std::string username;
    std::string password;
    int highScore;
    
    public:
    hangmanLogin();

    bool doesAccountExist(std::string username);
    bool createAccount(std::string username, std::string password);

    bool login(std::string username, std::string password);
    bool logout();

    int getHighScore();
    bool setHighScore(int score);

};

hangmanLogin::hangmanLogin(){
    accountFileName = "hangmanFiles/userdata/userdata.txt";
}

bool hangmanLogin::doesAccountExist(string username){
    ifstream fin(accountFileName);
    string nameToCheck = "";

    if(!fin.is_open()){
        cout << "Error opening account data file." << endl;
        return false;
    }

    bool found = false;
    while(fin >> nameToCheck){
        if (nameToCheck == username){
            return true;
        }
        getline(fin, nameToCheck);
    }
    fin.close();
    return false;
}

bool hangmanLogin::createAccount(string username, string password){
    if (!doesAccountExist(username)){
        fstream fout;
        fout.open(accountFileName, ios::app);
        if(!fout) {cout << "Failed to access data file for account creation." << endl; return false;}

        fout << username << " " << password << " " << 0 << endl;
        fout.close();

        if (doesAccountExist(username)) return true;
        else {cout << "Data saved improperly." << endl; return false;}
    }
    return false;
}

bool hangmanLogin::login(string username, string password){
    if (doesAccountExist(username)){
        fstream fin;
        fin.open(accountFileName, ios::in);
        if(!fin) {cout << "Failed to access data file for account login." << endl; return false;}
       
        string nameToCheck;
        string passwordToCheck;

        while(fin >> nameToCheck){
            if (nameToCheck == username){
                fin >> passwordToCheck;
                if (password == passwordToCheck){
                    this->password = password;
                    loggedIn = true;
                    string temp;
                    fin >> temp;
                    highScore = stoi(temp);
                } 
                else {
                    fin.close();
                    return false;
                }
            }
            getline(fin, nameToCheck);
        }

        fin.close();
        return true;
    }
    return false;
}

bool hangmanLogin::logout(){
    if (loggedIn){
        username = "";
        password = "";
        highScore = 0;
        loggedIn = false;
        return true;
    }
    else return false;
}

int hangmanLogin::getHighScore(){
    if (loggedIn) return highScore;
    else return false;
}

bool hangmanLogin::setHighScore(int score){
    if(loggedIn){
        vector<string> lines;
        string line;
        fstream fin;

        fin.open(accountFileName, ios::in);
        if(!fin) {cout << "Failed to access data file to set high score." << endl; return false;}

        while(getline(fin, line)){
            lines.push_back(line);
        }
        fin.close();

        for (int i = 0; i < lines.size(); i ++){
            // search for line to overwrite
            if (lines[i].find(username) != string::npos){
                lines[i] = username + " " + password + " " + to_string(score); // overwrite the line
                highScore = score;
            }
        }

        fstream fout;
        fout.open(accountFileName, ios::trunc);
        for (string s: lines){
            fout << s << endl;
        }

        fout.close();
        return true;
    }
    return false;
}
#endif