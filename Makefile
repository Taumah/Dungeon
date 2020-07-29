CC=gcc
executable=bin/Dungeon
files=src/*.c src/include/*.h

ext=-Wall -Wextra -Werror
debug=gdb3

build:
	@echo "*********** Compilation execution *********** "
	@/usr/bin/time --format="Build Duration: %E" make -s compile && \
	echo "Compilation successful" || \
	echo "Compilation unsuccessful"
	
	

compile: ${files} Makefile
	@${CC} -o ${executable} ${files} -ggdb3 -lSDL ${ext}

run: 
	@echo "Lauching Dungeon"
	@./${executable}

all: 
	@make -s compile && make -s run
