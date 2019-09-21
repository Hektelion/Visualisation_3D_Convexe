###########################
# MAKEFILE PROGRAMME TEST #
###########################

############
# VARIABLE #
############

CC = gcc
CFLAGS = -W -Wall
LDFLAGS =

EXEC = ../visualisation3D_test

SRC := $(wildcard ./src/*.c)
OBJ := $(patsubst ./src/%.c,./obj/%.o,$(SRC))

#########################
# REGLES DE COMPILATION #
#########################

all : programm

programm : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS) $(CFLAGS)

./obj/%.o : ./src/%.c
	$(CC) -o $@ -c $^

#################
# REGLES AUTRES #
#################

.PHONY : info cleanall cleanobj cleanexec

cleanall : cleanobj cleanexec

cleanobj :
	@rm -f ./obj/*.o

cleanexec :
	@rm -f $(EXEC)

print-% :
	@echo $* = $($*)

############################################
# MAKEFILE PROJET VISUALISATION 3D CONVEXE #
############################################
# Réalisé par BESSAI Sofiane ###############
############################################