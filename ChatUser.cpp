#include "ChatUser.h"

ChatUser::ChatUser(){
  this -> username = "username";
  this -> password = "password";
  this -> login = "login";
}

std::string ChatUser::getUsername(){
    return username;
}

std::string ChatUser::getPassword(){
  return password;
}

std::string ChatUser::getLogin(){
  return login;
}
