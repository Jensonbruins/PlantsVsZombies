CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wconversion -Wpedantic `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_ttf
OBJECTS = objects

all: clean filesystem.o gfx input.o entities move
	$(CC) -o PlantsVsZombies main.c $(CFLAGS) $(OBJECTS)/blitting.o $(OBJECTS)/collision-detection.o $(OBJECTS)/filesystem.o $(OBJECTS)/input.o $(OBJECTS)/plants.o $(OBJECTS)/timing.o $(OBJECTS)/zombies.o -lm

blitting.o:
	$(CC) $(CFLAGS) -c modules/gfx/blitting/blitting.c

clean:
	rm -rf $(OBJECTS)
	mkdir $(OBJECTS)

collision-detection.o:
	$(CC) $(CFLAGS) -c modules/entities/collision-detection/collision-detection.c

entities: plants.o collision-detection.o zombies.o

filesystem.o:
	$(CC) $(CFLAGS) -c modules/filesystem/filesystem.c

gfx: blitting.o timing.o

input.o: plants.o
	$(CC) $(CFLAGS) -c modules/input/input.c

move:
	mv *.o $(OBJECTS)

plants.o: filesystem.o
	$(CC) $(CFLAGS) -c modules/entities/plants/plants.c

timing.o:
	$(CC) $(CFLAGS) -c modules/gfx/timing/timing.c

zombies.o:
	$(CC) $(CFLAGS) -c modules/entities/zombies/zombies.c