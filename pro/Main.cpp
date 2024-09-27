#include "Message.h"
#include "Chat.h"
#include <windows.h>
#include <Lmcons.h>
#include <iostream>

#if defined(_WIN32) 
#define PLATFORM_NAME "windows 32-bit" // Windows 32-bit
#elif defined(_WIN64)
#define PLATFORM_NAME "windows 64-bit" // Windows 64-bit
#elif defined(__ANDROID__)
#define PLATFORM_NAME "android"   // Android 
#elif defined(__linux__)
#include <sys/utsname.h> // Для uname()
#define PLATFORM_NAME "linux"     // Debian, Ubuntu, Gentoo, Fedora, openSUSE, RedHat, Centos и другие
#elif TARGET_OS_IPHONE == 1
#define PLATFORM_NAME "ios"       // Apple iOS
#elif TARGET_OS_MAC == 1
#define PLATFORM_NAME "osx"       // Apple OSX
#else
#define PLATFORM_NAME  "OS not detected" // ОС не распознана
#endif

using namespace std;
void ShowSystemInfo()
{
	cout << "SYSTEM INFO" << endl;
	//linux
	#if defined(__linux__)
	struct utsname utsname;
	uname(&utsname);
	cout << "OS name: " << utsname.sysname << endl;
	cout << "Host name: " << utsname.nodename << endl;
	cout << "OS release: " << utsname.release << endl;
	cout << "OS version: " << utsname.version << endl;
	cout << "Machine name: " << utsname.machine << endl;
	#endif
	//windows
	if (PLATFORM_NAME == "windows 32-bit" || PLATFORM_NAME == "windows 64-bit")
	{
		int bi;
		if (PLATFORM_NAME == "windows 32-bit") bi = 32;
		else bi = 64;
		TCHAR name[UNLEN + 1];
		DWORD size = UNLEN + 1;
		cout << "OS name: Windows " << bi << " bit" << endl;
		if (GetUserName((TCHAR*)name, &size))
			wcout << L"Host name: " << name << L"\n";
	}
	cout << "SYSTEM INFO" << endl;
}

auto main() -> int
{
	ShowSystemInfo();
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
