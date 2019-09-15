###########################
# MAKEFILE PROGRAMME TEST #
###########################

############
# VARIABLE #
############

CC = gcc
CFLAGS = -W -Wall
LDFLAGS =

EXEC = visualisation3D

SRC := $(wildcard ./src/*.c)
OBJ := $(patsubst ./src/%.c,./obj/%.o,$(SRC))

#########################
# REGLES DE COMPILATION #
#########################

all : programm test

info :
	@echo "Compiler le programme --> make programm"
	@echo "Compiler les tests --> make test"
	@echo "Nettoyer les fichier générés --> make cleanall"
	@echo "Supprimer l'executable --> make cleanexec"
	@echo "Supprimer les fichiers objets --> make cleanobj"

programm : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LDFLAGS) $(CFLAGS)

test : $(OBJ)
	@make --directory=./test all

./obj/%.o : ./src/%.c
	$(CC) -o $@ -c $^

#################
# REGLES AUTRES #
#################

.PHONY : info cleanall cleanobj cleanexec

cleanall : cleanobj cleanexec

cleanobj :
	@echo "suppression des objets"
	@rm -f ./obj/*.o

cleanexec :
	@echo "suppression de l'executable"
	@rm -f ./$(EXEC)

print-% :
	@echo $* = $($*)

############################################
# MAKEFILE PROJET VISUALISATION 3D CONVEXE #
############################################
# Réalisé par BESSAI Sofiane ###############
############################################