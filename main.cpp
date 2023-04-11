#include <iostream>
#include <string>
#include "ChatUser.h"
#include "DynamicArray.h"

int main(){
  const int users_amount = 100;
  ChatUser users[users_amount];
  bool processing = true;
  int option = 0;
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

        break;
      case 2:

        break;
      case 3:
        break;
      case 4:
        break;

      case 5:
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
