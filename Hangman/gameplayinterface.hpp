#ifndef GAMEPLAYINTERFACE_HPP
#define GAMEPLAYINTERFACE_HPP

#include <iostream>
#include <string>

// Abstract interface for gameplay
class GameplayInterface{
public:
    virtual void startNewGame() = 0;
    virtual int playGame() = 0;
    virtual void endGame() = 0;
    virtual ~GameplayInterface() {}
};

#endif