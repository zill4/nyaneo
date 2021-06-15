#OBJS specifies which files to compile as part of the project
#OBJS = src/main.cpp src/graphics.cpp src/game.cpp src/animatedSprite.cpp src/sprite.cpp src/input.cpp

#OBJ_NAME specifies the name of our exectuable
#OBJ_NAME = game

#This is the target that compiles our executable for development
# Doesn't work for Windows Subsystem for Linux 2 (My development OS)
# Uncomment
# dev : $(OBJS)
# 	g++ $(OBJS) -w -lSDL2 -o $(OBJ_NAME) -I includes

# dev : $(OBJS)
# 	em++ -o app.html $(OBJS) -Wall -I includes -g -lm -s USE_SDL=2 -s ERROR_ON_UNDEFINED_SYMBOLS=0
# 	python3 -m http.server
# clean :
# 	rm -r app.js app.html app.wasm


# IDIR =includes
# CC=em++
# CFLAGS=-I$(IDIR)

# ODIR=obj
# LDIR =lib

# LIBS=-lm

# _DEPS = animatedSprite.h game.h globals.h graphics.h main.h rectangle.h sprite.h
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# _OBJ = main.o animatedSprite.o game.o graphics.o input.o sprite.o
# OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


# $(ODIR)/%.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# main: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
# 	python3 -m http.server
# .PHONY: clean

# clean:
# 	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
# 	rm -r app.js app.html app.wasm


NAME = game

#	src / obj files
SRC	=  main.cpp graphics.cpp game.cpp  input.cpp snake.cpp apple.cpp
OBJ	= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

#	compiler
CC	= emcc
CFLAGS	= -Wall -Wextra -g


#	directories
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(NAME)
	python3 -m http.server

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.cpp
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $< -s USE_SDL=2


$(NAME): $(OBJ)
	$(CC) -o app.html $(OBJ) -lm -s USE_SDL=2 

clean:
		rm -rf $(OBJDIR)
		rm -r app.js app.html app.wasm
fclean:
		rm -rf $(NAME)
		make clean

re: fclean all
.PHONY: clean fclean all re