#OBJS specifies which files to compile as part of the project
OBJS = src/main.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = game

#This is the target that compiles our executable for development
# Doesn't work for Windows Subsystem for Linux 2 (My development OS)
# Uncomment if your running on Ubuntu/Mac
# dev : $(OBJS)
# 	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME) -I includes

all : $(OBJS)
	emcc -o app.html $(OBJS) -Wall -I includes -g -lm -s USE_SDL=2 
	python3 -m http.server
	
clean :
	rm -r app.js app.html game app.wasm