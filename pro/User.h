#pragma once
#include <string>

using namespace std;
class User
{

	string _userName;
	string _userPassword;
	const string _userLogin;
public:
	User(const string& userLogin, const string& userPassword, const string& userName) :_userLogin(userLogin), _userPassword(userPassword), _userName(userName)
	{}

	//getters:

	const string& getUserName()
		const
	{
		return _userName;
	}
	const string& getUserLogin()
		const
	{
		return _userLogin;
	}
	const string& getUserPassword()
		const
	{
		return _userPassword;
	}

	//setters:

	void setUserName(const string& userName)
	{
		_userName = userName;
	}


	void setUserPassword(const string& userPassword)
	{
		_userPassword = userPassword;
	}
};
