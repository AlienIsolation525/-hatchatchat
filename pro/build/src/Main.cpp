#include "Message.h"
#include "Chat.h"

using namespace std;


auto main() -> int
{
	Chat chat;
	//chat.Start();
	while (true)
	{
		chat.showLoginMenu();
		while (chat.getCurrentUser())
		{
			chat.showUserMenu();
		}

	}
	return 0;
}
