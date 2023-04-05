#pragma once
#include <string>
#include <iostream>

class ChatUser{
public:
  ChatUser();
  ChatUser(std::string user_name, std::string user_login, std::string user_password);
  ~ChatUser();
  void ChatEnter(std::string user_login, std::string user_password);
  void LogOut();
private:
  std::string user_name;
  std::string user_login;
  std::string user_password;

  bool online = false;
};
