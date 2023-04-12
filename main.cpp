#include <iostream>
#include <string>
#include "ChatUser.h"
//#include "DynamicArray.h"
#include <vector>

int main(){
  const int users_amount = 100;
  ChatUser users[10];
  bool processing = true;
  int option = 0;
  std::string user_name;
  std::string user_login;
  std::string user_password;

  while(processing){
    std::cout << "Welcome to our app! Please, choose the option: " << std::endl;
    std::cout << "1 -- New User registration" << std::endl;
    std::cout << "2 -- Enter by login & password" << std::endl;
    std::cout << "3 -- Send message to user" << std::endl;
    std::cout << "4 -- Send message to all users" << std::endl;
    std::cout << "5 -- Check your messages" << std::endl;
    std::cout << "6 -- Exit" << std::endl;

    std::cin >> option;
    switch(option){
      case 1:
        std::cout << "Please, enter user name, login and password" << std::endl;
        std::cout << "User name: ";
        std::cin >> user_name;
        std::cout << "Login: ";
        std::cin >> user_login;
        std::cout << "Password: ";
        std::cin >> user_password;
        for (int i = 0; i < users.get_size(); i++){
          
        }
        users[0] = ChatUser(user_name, user_login, user_password);
        break;

      case 2:
        std::cout << "case 2" << std::endl;
        break;
      case 3:
        std::cout << "case 3" << std::endl;
        break;
      case 4:
        std::cout << "case 4" << std::endl;
        break;

      case 5:
        std::cout << "case 5" << std::endl;
        break;

      case 6:
        std::cout << "Bye!" << std::endl;
        processing = false;
        break;

      default:
        std::cout << "This option is not avaliable yet...";
    }
  }
  return 0;
}
