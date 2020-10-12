CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wconversion -Wpedantic `sdl2-config --cflags --libs` -lSDL2_image -lSDL2_mixer -Iincludes -Imodules
OBJECTS = objects

PlantsVzZombies: clean filesystem.o gfx sfx.o entities move
	$(CC) -o PlantsVsZombies main.c $(CFLAGS) $(OBJECTS)/blitting.o $(OBJECTS)/collision-detection.o $(OBJECTS)/filesystem.o $(OBJECTS)/input.o $(OBJECTS)/plants.o $(OBJECTS)/sfx.o $(OBJECTS)/timing.o $(OBJECTS)/zombies.o -lm
clean:
	rm -rf $(OBJECTS)
	mkdir $(OBJECTS)

move:
	mv *.o $(OBJECTS)

filesystem.o:
	$(CC) $(CFLAGS) -c modules/filesystem/filesystem.c

gfx: blitting.o timing.o

blitting.o:
	$(CC) $(CFLAGS) -c modules/gfx/blitting/blitting.c

timing.o:
	$(CC) $(CFLAGS) -c modules/gfx/timing/timing.c

sfx.o:
	$(CC) $(CFLAGS) -c modules/sfx/sfx.c

entities: plants.o collision-detection.o zombies.o

plants.o: input.o
	$(CC) $(CFLAGS) -c modules/entities/plants/plants.c

input.o:
	$(CC) $(CFLAGS) -c modules/entities/plants/input/input.c

collision-detection.o:
	$(CC) $(CFLAGS) -c modules/entities/collision-detection/collision-detection.c

zombies.o:
	$(CC) $(CFLAGS) -c modules/entities/zombies/zombies.c