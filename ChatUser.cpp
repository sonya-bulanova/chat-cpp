#include "ChatUser.h"

ChatUser::ChatUser(){
  this -> user_name = "default";
  this -> user_login = "login";
  this -> user_password = "password";
  std::cout << "Welcome, " << user_name << "! Your login is " << user_login << std::endl;
}

ChatUser::ChatUser(std::string user_name, std::string user_login, std::string user_password){
  this -> user_name = user_name;
  this -> user_login = user_login;
  this -> user_password = user_password;
  std::cout << "Welcome, " << user_name << "! Your login is " << user_login << std::endl;
}

void ChatUser::ChatEnter(std::string user_login, std::string user_password){
  if (this -> user_login == user_login && this -> user_password == user_password){
    std::cout << "Welcome to chat, " << this -> user_name << std::endl;
    online = true;
  } else {
    std::cout << "Wrong combination of login & password!" << std::endl;
  }
}

void ChatUser::LogOut(){
  std::cout << "Bye, " << this -> user_name << std::endl;
  online = false;
}
