#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP

#include "raylib.h"
#include <string>
using std::string;

class TextInputBox {
public:
	TextInputBox();
	TextInputBox(int x, int y, int width, int height, int maxChars);
	void update();
	void draw();
	string getText();
	void setText(string text);
private:
	int textSize;
	int yOffset;
	int maxChars;
	string text;

	Rectangle textBox; // x, y, width, height
	
	bool mouseOnText;
	unsigned long framesCounter;
};

#endif