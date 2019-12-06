#############################################
#     MAKEFILE FOR A GENERIC C PROJECT      #
#############################################
#                                           #
# This is a simple Projectmanagement script #
#     written and maintained by asktobi     #
#                                           #
#                                           #
#                                           #
# Im writing this for everyone so pls feel  #
# free to edit, modify and change the whole #
#        Makefile as much as u like.        #
#                                           #
#            git-contributers :             #
#                                           #
#                                           #
#                                           #
#############################################


# The main git repository
 GITREPO = https://github.com/asktobi/urban.git

# The C compiler u wanna use
 CC      = gcc
 LD      = gcc

# General Optimization flags
 CCFLAGS =
 LDFLAGS =

# Library flags
 LIBS    = -lpthread -lncurses -ltinfo

# Different executeables you can build
 MAIN    = ../bin/urban
 TESTS   =

# Source files
 SRC    := $(wildcard *.c)

# Header files
 HDR    := $(wildcard *.h)

# Debugging flags
 DEBUG   =

# Lets make know these are not meant to be files
.PHONY: all debug getdeps clean  

# first rule is the one executed when make has no Arguments
all: $(MAIN)

debug:
	$(CC) $(DEBUG) $(CCFLAGS) $(LKFLAGS) -o ../bin/debug

# Compiling the main executable
$(MAIN): $(SRC) $(HDR)
	$(CC) $(CCFLAGS) $(LDFLAGS) $(LIBS) -o $@ $(SRC)

# Tests
$(TESTS):
	$(CC) $(DEBUG) $(CCFLAGS) $(LKFLAGS) -o $@ 

# Some stuff that was usefull in the past and might be in the future
#
#$(SRC): %.o : %.c $(HDR) 
#	$(CC) $(CCFLAGS) -o $@ $<

getdeps: 
	echo "BIN: $(MAIN) $(TESTS)"
	echo "SRC: $(SRC)"
	echo "HDR: $(HDR)"

# Clean the project from any build and temporary files
clean:
	rm -rf $(MAIN) 
