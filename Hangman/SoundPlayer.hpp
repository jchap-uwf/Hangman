#ifndef SOUND_PLAYER_HPP
#define SOUND_PLAYER_HPP
#include "raylib.h"
#include <iostream>
#include <string>

class SoundPlayer
{

Sound efx  ;


public:
void setSound(std::string soundFile);
void playSound();
SoundPlayer();




};
#endif
SoundPlayer::SoundPlayer(){

  InitAudioDevice();



}

void SoundPlayer::playSound(std::string soundFile){

   efx = LoadSound(soundFile.c_str());

  PlaySound(efx);

}
