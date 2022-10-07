all:
	g++ -I sdl/include -L sdl/lib -I/headers -o main *.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2 -lSDL2_image