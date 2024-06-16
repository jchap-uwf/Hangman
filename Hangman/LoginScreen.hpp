#ifndef LGSCREEN_HPP
#define LGSCREEN_HPP

#include <string>
#include "raylib.h"
#include "TextInputBox.hpp"


class LoginScreen {
    public:
        LoginScreen();
        void update();
        void draw();

        std::string getUsernameField();
        std::string getPasswordField();

        void resetFields();

        bool FieldsConfirmed();

    private:
        TextInputBox usernameBox;
        TextInputBox passwordBox;
        
        std::string username;
        std::string password;

        bool fieldsConfirmed;
};
#endif