#pragma once
#include <vector>
#include <exception>
#include "Message.h"
#include <memory>
#include "User.h"

using namespace std;
class UserNameIsExist :public exception
{
public:
	const char* what() 	const noexcept 	override
	{
		return "the User Name is exist";
	}
};
class UserLoginIsExist :public exception
{
public:
	const char* what() const noexcept override
	{
		return "the User login is busy";
	}
};



class Chat
{
	bool _isOnline = false;
	vector<User>_userList;
	vector<Message>_messageList;
	shared_ptr<User>_currentUser = nullptr;
	void logIn();
	void signUp();
	void viewChat() const;
	void showAllUsers()const;
	void addMessage();
	vector<User>& getAllUsers()
	{
		return _userList;
	}
	vector <Message>& getAllMessages()
	{
		return _messageList;
	}
	shared_ptr<User> getUserLOgin(const string& userLogin) const;
	shared_ptr<User>getUserName(const string& userName)const;

public:
	//void Start();
	bool const isOnline()
		const
	{
		return _isOnline;
	}
	shared_ptr<User> getCurrentUser()
		const
	{
		return _currentUser;
	}
	void showLoginMenu();
	void showUserMenu();
};

#pragma once
