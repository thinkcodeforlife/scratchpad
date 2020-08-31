
# mymain: mymain.c mylib.c
# 	gcc mymain.c mylib.c -o mybinary.exe

# clean:
# 	rm mybinary.exe


# ==============================
# # SDL Example from stackoverflow

# # use := not =
# # convention: objects, exec are lower-case because they're private
# objects := $(patsubst %.c,%.o,$(wildcard *.c))
# CFLAGS := $(shell pkg-config --cflags sdl2 SDL2_image)
# LIBS := $(shell pkg-config --libs sdl2 SDL2_image)

# # Don't define CC, because the default (cc) is fine
# # It's probably linked to gcc on your system anyway

# # = or := doesn't matter here
# exec = main

# # must use = here
# depflags = -MF $(patsubst %.o,%.d,$@) -MMD -MP
# -include $(wildcard *.d)

# $(exec): $(objects)
#     $(CC) $(LDFLAGS) $^ $(LIBS) -o $@

# %.o: %.c
#     $(CC) $(depflags) -c $(CCFLAGS) $< -o $@

# .PHONY: clean
# clean:
#     rm -f *.o *.d $(exec)


# ===========================================================================
# gcc slddeneme.c `sdl-config --libs` -o mybinary
# gcc -o mybinary slddeneme.c -lSDL
# gcc -o mybinary slddeneme.c `sdl2-config --cflags --libs`


# ===========================================================================
# # A simple Makefile for compiling small SDL projects
# # set the compiler

# CC := gcc


# # set the compiler flags

# CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_mixer -lSDL2_ttf -lm
# LDFLAGS= -L /lib -l SDL2_image-2.0.5

# # add header files here
# HDRS := structs.h common.h main.h init.h defs.h input.h drawIssue.h texture.h stage.h map.h fileOperation.h camera.h move.h check.h

# # add source files here
# SRCS := main.c init.c input.c drawIssue.c texture.c stage.c map.c fileOperation.c camera.c move.c check.c

# # generate names of object files
# OBJS := $(SRCS:.c=.o)

# # name of executable
# EXEC := game

# # default recipe
# all: $(EXEC)

# showfont: showfont.c Makefile
# $(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

# glfont: glfont.c Makefile
# $(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

# # recipe for building the final executable
# $(EXEC): $(OBJS) $(HDRS) Makefile
# $(CC) -o $@ $(OBJS) $(CFLAGS)

# # recipe for building object files
# #$(OBJS): $(@:.o=.c) $(HDRS) Makefile
# # $(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# # recipe to clean the workspace
# clean:
# rm -f $(EXEC) $(OBJS)
# .PHONY: all clean


# ======================================================================================
# # #OBJS specifies which files to compile as part of the project
# OBJS = 01_hello_SDL.cpp

# #OBJ_NAME specifies the name of our exectuable
# OBJ_NAME = 01_hello_SDL

# #This is the target that compiles our executable
# all : $(OBJS)
# 	g++ $(OBJS) -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o $(OBJ_NAME)

# ======================================================================================
# #OBJS specifies which files to compile as part of the project
# OBJS = 01_hello_SDL.cpp

# #CC specifies which compiler we're using
# CC = g++

# #INCLUDE_PATHS specifies the additional include paths we'll need
# INCLUDE_PATHS = -IC:\mingw_dev_lib\include\SDL2

# #LIBRARY_PATHS specifies the additional library paths we'll need
# LIBRARY_PATHS = -LC:\mingw_dev_lib\lib

# #COMPILER_FLAGS specifies the additional compilation options we're using
# # -w suppresses all warnings
# # -Wl,-subsystem,windows gets rid of the console window
# COMPILER_FLAGS = -w -Wl,-subsystem,windows

# #LINKER_FLAGS specifies the libraries we're linking against
# LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

# #OBJ_NAME specifies the name of our exectuable
# OBJ_NAME = 01_hello_SDL

# #This is the target that compiles our executable
# all : $(OBJS)
# 	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)


# ======================================================================================
#OBJS specifies which files to compile as part of the project
# the 4th best
OBJS = slddeneme.c

#CC specifies which compiler we're using
CC = gcc

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IC:\box\env\sdk\cli\gnu\MinGW\include\SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LC:\box\env\sdk\cli\gnu\MinGW\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -w -Wl,-subsystem,windows

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = mybinary

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)


# ======================================================================================
# #OBJS specifies which files to compile as part of the project
# OBJS = 01_hello_SDL.cpp

# #OBJ_NAME specifies the name of our exectuable
# OBJ_NAME = 01_hello_SDL

# #This is the target that compiles our executable
# all : $(OBJS)
# 	g++ $(OBJS) -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o $(OBJ_NAME)


# ======================================================================================
# the 2nd best
gcc slddeneme.c -IC:\box\env\sdk\cli\gnu\MinGW\include\SDL2 -LC:\box\env\sdk\cli\gnu\MinGW\lib -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o mybinary

# ======================================================================================
# the best
gcc slddeneme.c -IC:\box\env\sdk\cli\gnu\MinGW\include\SDL2 -LC:\box\env\sdk\cli\gnu\MinGW\lib -lmingw32 -lSDL2main -lSDL2 -o mybinary


# ======================================================================================
#OBJS specifies which files to compile as part of the project
# the 3rd best
OBJS = slddeneme.c

#CC specifies which compiler we're using
CC = gcc

#INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -IC:\box\env\sdk\cli\gnu\MinGW\include\SDL2

#LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -LC:\box\env\sdk\cli\gnu\MinGW\lib

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
# -Wl,-subsystem,windows gets rid of the console window
COMPILER_FLAGS = -G -wall

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = mybinary

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)