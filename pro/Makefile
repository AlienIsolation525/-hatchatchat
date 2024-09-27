all: chatt

chatt: Chat.o Main.o Chat.h Message.h User.h
	g++ Chat.o Main.o Chat.h Message.h User.h -o chatt

Chat.o: Chat.cpp
	g++ -c Chat.cpp

Main.o: Main.cpp
	g++ -c Main.cpp

clean:
	rm -rf *.o chatt
