all:
	g++ -I sdl/include -I /src -I /headers -L sdl/lib -o main main.cpp src/*.cpp headers/*.h -lmingw32 -lSDL2main -lSDL2 -lSDL2 -lSDL2_image