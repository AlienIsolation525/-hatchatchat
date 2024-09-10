#pragma once
#include <string>

using namespace std;
class Message
{
	const string _fromUser;
	const string _toUser;
	const string _text;
public:
	Message(const string& fromUser, const string toUser, const string text) :_fromUser(fromUser), _toUser(toUser), _text(text)
	{}
	//getter
	const string& getFromUser()
		const
	{
		return _fromUser;
	}
	const string& getToUser()
		const
	{
		return _toUser;
	}
	const string& getMessageText()
		const
	{
		return _text;
	}
};

#pragma once
