# Source, Executable, Includes, Library Defines
SRC  = src/lorenzAttractor.c
OBJ  = $(SRC:.c=.o)
LIBS = -lm
EXE  = bin/lorenzAttractor

# Compiler, Linker Defines
CPP      = /usr/bin/gcc
CPPFLAGS = -Wall -ansi -pedantic -g -O3 -funroll-loops

LIBPATH  =

INCLPATH = -I./include/ 

RM       = /bin/rm -f

# Compile and Assemble C Source Files into Object Files
%.o: %.c
	$(CPP) $(INCLPATH) $(CPPFLAGS) -c $< -o $@

# Link all Object Files with external Libraries into Binaries
$(EXE): $(OBJ)
	$(CPP) -o $(EXE) $(OBJ) $(LIBPATH) $(LIBS)

# Objects depend on these Libraries
$(OBJ):

# Clean Up Objects, Exectuables, Dumps out of source directory
clean:
	$(RM) $(OBJ) $(EXE) src/*.o

