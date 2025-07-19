hello: main.cpp
	g++ -Wall -Wextra -Werror -Wpedantic \
		-std=c++23 \
		-o hello \
		main.cpp \
		-lsfml-system -lsfml-graphics -lsfml-window
