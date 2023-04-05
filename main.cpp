#include <iostream>
#include <string>
#include "ChatUser.h"

int main(){
  ChatUser * vlad = new ChatUser();
  ChatUser * vladislav = new ChatUser("vlad", "vladislav", "123456");
  vladislav -> ChatEnter("vladislav", "123456");
  vladislav -> ChatEnter("vladislav", "1236");
  return 0;
}
