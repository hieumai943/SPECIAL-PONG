all:
	g++ -Isrc/include -Lsrc/lib -o binvadll/main main.cpp  object.cpp menu.cpp game.cpp  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

