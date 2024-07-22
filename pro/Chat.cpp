#include "Chat.h"
#include <iostream>

shared_ptr<User>Chat::getUserLOgin(const string& userLogin)const
{
    for (auto& user : _userList)
    {
        if (userLogin == user.getUserLogin())
            return make_shared<User>(user);
    }
    return nullptr;
}
shared_ptr<User>Chat::getUserName(const string& userName)const
{
    for (auto& user : _userList)
    {
        if (userName == user.getUserName())
            return make_shared<User>(user);
    }
}
void Chat::logIn()
{
    string login, password;
    char chatItem;

    //do  while
    do
    {
        cout << "Login: ";
        cin >> login;
        cout << "Password: ";
        cin >> password;
        _currentUser = getUserLOgin(login);

        if (_currentUser == nullptr || (password != _currentUser->getUserPassword()))
        {
            _currentUser = nullptr;
            cout << "ACHTUNG login is wrong, try again" << endl;
            cout << "exit (0), repeat (any key)";
            cin >> chatItem;
            if (chatItem == '0')
                break;
        }
    } while (!_currentUser);

}
void Chat::signUp()
{
    string name, login, password;
    cout << "Name: ";
    cin >> name;
    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;

    if (login == "all")
    {
        throw UserLoginIsExist();
    }
    if (name == "all")
    {
        throw UserNameIsExist();
    }
    User user = User(login, password, name);
    _userList.push_back(user);
    _currentUser = make_shared<User>(user);

}
void Chat::showLoginMenu()
{
    _currentUser = nullptr;
    char chatItem;
    do
    {
        cout << "(1) LogIn" << endl;
        cout << "(2) SignUp" << endl;
        cout << "(0) EXIT" << endl;
        cin >> chatItem;
        switch (chatItem)
        {
        case '1':
            logIn();
            break;
        case '2':
            try
            {
                signUp();
            }
            catch (const exception& e)
            {
                cout << e.what() << endl;
            }
            break;
        case '0':
            _isOnline = false;
            break;
        default:
            cout << "1 or 2..." << endl;
            break;
        }
    } while (!_currentUser && _isOnline);
}
void  Chat::showAllUsers() const
{
    for (auto& user : _userList)
    {
        cout << " " << user.getUserLogin() << endl;;

    }

}
void Chat::showUserMenu()
{
    char item;
    cout << "Hello,    " << _currentUser->getUserName() << endl;
    while (_currentUser)
    {
        cout << "Menu: (1) View Chat  | (2) Add message  | (3) User List  | (0) Exit ";
        cout << endl;
        cout << ">>";
        cin >> item;
        switch (item)
        {
        case '1':
            viewChat();
            break;
        case '2':
            addMessage();
            break;
        case '3':
            showAllUsers();
            break;
        case '0':
            _currentUser = nullptr;
            break;
        default:
            cout << " enter item..." << endl;
            break;
        }
    }
}



void Chat::addMessage()
{
    string to, text;
    cout << "To (User Name or ALL): ";
    cin >> to;
    cout << "text:  ";
    cin.ignore();
    getline(cin >> to, text);
    if (!(to == "all" || getUserName(to)))
    {
        cout << "error send message: can not find" << to << endl;
        return;
    }
    if (to == "all")
    {
        _messageList.push_back(Message(_currentUser->getUserLogin(), "all", text));
    }
    else
    {
        _messageList.push_back(Message(_currentUser->getUserLogin(), getUserName(to)->getUserLogin(), text));
    }
}

void Chat::viewChat() const
{
    string from, to;
    cout << "-----------chat-----------" << endl;
    for (auto& mess : _messageList)
    {
        if (_currentUser->getUserLogin() == mess.getFromUser() || _currentUser->getUserLogin() == mess.getToUser() || mess.getToUser() == "all")
        {
            from = (_currentUser->getUserLogin() == mess.getFromUser()) ? "me" : getUserLOgin(mess.getFromUser())->getUserName();
        }
        if (mess.getToUser() == "all")
        {
            to = "(all)";
        }
        else
        {
            to = (_currentUser->getUserLogin() == mess.getToUser()) ? "me" : getUserLOgin(mess.getToUser())->getUserName();
        }
        cout << "Message from" << from << "to" << to << endl;
        cout << "text:       " << mess.getMessageText() << endl;
    }
    cout << "" << endl;
}