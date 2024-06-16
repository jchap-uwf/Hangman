#include "TextInputBox.hpp"

#include <iostream>

TextInputBox::TextInputBox(){
	
}

TextInputBox::TextInputBox(int x, int y, int width, int height, int maxChars) {
	textBox = { (float)x, (float)y, (float)width, (float)height };

	textSize = textBox.height * 0.8;
	yOffset = textBox.height * 0.16;

	this->maxChars = maxChars;
	framesCounter = 0;
	mouseOnText = false;

	text = "";
}

void TextInputBox::update() {
	if (CheckCollisionPointRec(GetMousePosition(), textBox)) mouseOnText = true;
	else mouseOnText = false;

	if (mouseOnText) {
		int key = GetCharPressed();

		while (key > 0) {
			// NOTE: Only allow keys in range [32..125]
			if ((key >= 32) && (key <= 125) && (text.length() < maxChars))
			{
				text.push_back((char)key);
			}
			key = GetCharPressed();
		}
		

		if (IsKeyPressed(KEY_BACKSPACE)) {
			if (text.length() > 0) {
				text.pop_back();
			}
		}
	}
	else {
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
	}

	if (mouseOnText) framesCounter++;
	else framesCounter = 0;
}

void TextInputBox::draw() {
	DrawRectangleRec(textBox, LIGHTGRAY);
	if (mouseOnText) DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, RED);
	else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, DARKGRAY);

	DrawText(text.c_str(), (int)textBox.x + 5, (int)textBox.y + yOffset, textSize, MAROON);

	if (mouseOnText) {
		if (text.length() < maxChars) {
			if (((framesCounter / 20) % 2) == 0) {
				DrawText("_", (int)textBox.x + 8 + MeasureText(text.c_str(), 40), (int)textBox.y + yOffset, textSize, MAROON);
			}
		}
		// draws if text box is full
		else DrawRectangleLines((int)textBox.x, (int)textBox.y, (int)textBox.width, (int)textBox.height, YELLOW);
	}

}

string TextInputBox::getText() {
	return text;
}

void TextInputBox::setText(string text) {
	this->text = text;
}

bool IsAnyKeyPressed()
{
	bool keyPressed = false;
	int key = GetKeyPressed();

	if ((key >= 32) && (key <= 126)) keyPressed = true;

	return keyPressed;
}