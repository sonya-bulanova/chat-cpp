#include "ChatArray.h"
#include "ChatUser.h"

ChatArray::ChatArray(){
  std::cout << "Создан пустой чат." << std::endl;
}

ChatArray::ChatArray(std::vector<ChatUser> usrs){
  std::copy(usrs.begin(), usrs.end(), this -> users.begin());
}

ChatArray::ChatArray(ChatArray &ch){
  std::copy(this -> users.begin(), this -> users.end(), ch.users.begin());
}

ChatArray::~ChatArray(){
  if(users.size() != 0) {
    users.clear();
  }
  if(messages.size() != 0){
    messages.clear();
  }
}

void ChatArray::addUser(ChatUser user){
  users.push_back(user);
}

bool ChatArray::authenticateUser(std::string username, std::string password){
  for (auto& user : users) {
      if (user.getUsername() == username && user.getPassword() == password) {
          return true;
      }
  }
  return false;
}

void ChatArray::registerUser(std::string username, std::string password, std::string login){
  ChatUser user(username, password, login);
  users.push_back(user);
  std::cout << "Пользователь " << username << " успешно зарегистрирован." << std::endl;
}

void ChatArray::sendMessage(std::string sender, std::string recipient, std::string message){
  messages[recipient].push_back(sender + ": " + message);
}

void ChatArray::printMessages(std::string recipient){
  std::cout << "Сообщения для " << recipient << ":" << std::endl;
  for (auto& message : messages[recipient]) {
      std::cout << message << std::endl;
  }
  std::cout << std::endl;
}

void ChatArray::broadcastMessage(std::string sender, std::string message){
  for (auto& user : users) {
      if (user.getUsername() != sender) {
          messages[user.getUsername()].push_back(sender + ": " + message);
      }
  }
}
