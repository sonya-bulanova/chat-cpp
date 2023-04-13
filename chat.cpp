#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// Шаблонная функция для получения ввода от пользователя с обработкой исключений
template <typename T>
T getInput(const std::string& prompt) {
    std::cout << prompt;
    T input;
    std::cin >> input;
    while (std::cin.fail()) {
        std::cout << "Некорректный ввод. Пожалуйста, попробуйте еще раз." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << prompt;
        std::cin >> input;
    }
    return input;
}

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string username, std::string password) : username(username), password(password) {}

    std::string getUsername() const {
        return username;
    }

    std::string getPassword() const {
        return password;
    }
};

class Chat {
private:
    std::vector<User> users;
    std::unordered_map<std::string, std::vector<std::string>> messages;

public:
    void addUser(User user) {
        users.push_back(user);
    }

    bool authenticateUser(std::string username, std::string password) {
        for (const auto& user : users) {
            if (user.getUsername() == username && user.getPassword() == password) {
                return true;
            }
        }
        return false;
    }

    void registerUser(std::string username, std::string password) {
        User user(username, password);
        users.push_back(user);
        std::cout << "Пользователь " << username << " успешно зарегистрирован." << std::endl;
    }

    void sendMessage(std::string sender, std::string recipient, std::string message) {
        messages[recipient].push_back(sender + ": " + message);
    }

    void printMessages(std::string recipient) {
        std::cout << "Сообщения для " << recipient << ":" << std::endl;
        for (const auto& message : messages[recipient]) {
            std::cout << message << std::endl;
        }
        std::cout << std::endl;
    }

    void broadcastMessage(std::string sender, std::string message) {
        for (const auto& user : users) {
            if (user.getUsername() != sender) {
                messages[user.getUsername()].push_back(sender + ": " + message);
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Chat chat;
    std::string username;
    std::string password;

    while (true) { // цикл для регистрации новых пользователей или входа в систему
        char choice = getInput<char>("Введите 'r', чтобы зарегистрировать нового пользователя, или 'l', чтобы войти в систему: ");
        try {
            if (choice == 'r') { // если пользователь выбрал 'r', то регистрируем нового пользователя
                std::string username = getInput<std::string>("Введите новое имя пользователя: ");
                std::string password = getInput<std::string>("Введите новый пароль: ");
                chat.registerUser(username, password);
            }
            else if (choice == 'l') { // если пользователь выбрал 'l', то запрашиваем данные для входа в систему
                while (true) {
                    std::string username = getInput<std::string>("Введите имя пользователя: ");
                    std::string password = getInput<std::string>("Введите пароль: ");
                    if (chat.authenticateUser(username, password)) { // если данные для входа правильные, то выходим из цикла
                        break;
                    }
                    else {
                        std::cout << "Неверное имя пользователя или пароль. Попробуйте еще раз." << std::endl; // иначе сообщаем об ошибке
                    }
                }
                std::cout << "Вы вошли в систему как " << username << "." << std::endl; // сообщаем о успешном входе

                while (true) { // основной цикл чата
                    char choice = getInput<char>("Введите 's', чтобы отправить сообщение, 'p', чтобы показать свои сообщения, или 'b', чтобы отправить сообщение всем: ");


                        try {
                        if (choice == 's') { // если пользователь выбрал 's', то запрашиваем получателя и сообщение
                            std::string recipient = getInput<std::string>("Введите имя получателя: ");
                            std::string message = getInput<std::string>("Введите ваше сообщение: ");
                            chat.sendMessage(username, recipient, message); // отправляем сообщение
                            std::cout << "Сообщение отправлено " << recipient << "." << std::endl;
                        }
                        else if (choice == 'p') { // если пользователь выбрал 'p', то показываем все его сообщения
                            chat.printMessages(username);
                        }
                        else if (choice == 'b') { // если пользователь выбрал 'b', то запрашиваем сообщение и отправляем его всем пользователям
                            std::string message = getInput<std::string>("Введите сообщение для всех: ");
                            chat.broadcastMessage(username, message);
                            std::cout << "Сообщение отправлено всем пользователям." << std::endl;
                        }
                    }
                    catch (const std::out_of_range& e) { // обрабатываем исключение при попытке доступа к сообщениям несуществующего пользователя
                        std::cerr << "Ошибка: " << e.what() << std::endl;
                    }
                }

                return 0;
            }
        }
        catch (const std::exception& e) { // обрабатываем любые другие исключения
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
    }

    return 0;
}