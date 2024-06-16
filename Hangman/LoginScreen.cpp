#include "LoginScreen.hpp"

LoginScreen::LoginScreen() {
    TextInputBox usernameBox(360, 220, 250, 50, 15);
    TextInputBox passwordBox(360, 300, 250, 50, 15);

    this->usernameBox = usernameBox;
    this->passwordBox = passwordBox;

    fieldsConfirmed = false;
}

void LoginScreen::update(){
    fieldsConfirmed = false;
    usernameBox.update();
    passwordBox.update();
    username = usernameBox.getText();
    password = passwordBox.getText();

    if(IsKeyPressed(KEY_ENTER)){
        fieldsConfirmed = true;
    }
}  

void LoginScreen::draw(){
    ClearBackground(GREEN);

    DrawText("Enter your username: ", 35, 220, 25, BLACK);
    DrawText( "Enter your password: ", 35, 300, 25, BLACK);
    DrawText("Press Enter to submit", 10, 10, 30, BLACK);

    usernameBox.draw();
    passwordBox.draw();
}

bool LoginScreen::FieldsConfirmed() {return fieldsConfirmed;}

std::string LoginScreen::getPasswordField() {return password;}
std::string LoginScreen::getUsernameField() {return username;}

void LoginScreen::resetFields(){
    username = "";
    password = "";

    usernameBox.setText("");
    passwordBox.setText("");
}