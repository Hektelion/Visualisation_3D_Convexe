################################
# MAKEFILE PROGRAMME PRINCIPAL #
################################

############
# VARIABLE #
############

CC = gcc
CFLAGS = -W -Wall
LDFLAGS = `sdl-config --cflags --libs` 

EXEC = visualisation3D

HEADER := $(wildcard ./header/*.h)
SRC := $(wildcard ./src/*.c)
OBJ := $(patsubst ./src/%.c,./obj/%.o,$(SRC))

#########################
# REGLES DE COMPILATION #
#########################

# $@ désigne le fichier cible courant
# $* désigne le fichier cible courant privé de son suffixe
# $< désigne le fichier qui a provoqué l'action

all : programm test

info :
	@echo "Compiler le programme et tests   --> make all"
	@echo "Compiler le programme            --> make programm"
	@echo "Compiler les tests               --> make test"
	@echo "Nettoyer les fichiers générés    --> make cleanall"
	@echo "Supprimer l'executable           --> make cleanexec"
	@echo "Supprimer les fichiers objets    --> make cleanobj"

programm : $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(LDFLAGS)

test : $(OBJ)
	@make --directory=./test all

./obj/%.o : ./src/%.c $(HEADER)
	$(CC) -o $@ -c $< $(CFLAGS)

#################
# REGLES AUTRES #
#################

.PHONY : info cleanall cleanobj cleanexec cleantest cleanobjtest

cleanall : cleanobj cleanexec cleantest cleanobjtest

cleanobj :
	@echo "suppression des objets"
	@rm -f ./obj/*.o

cleanexec :
	@echo "suppression de l'executable"
	@rm -f ./$(EXEC)

cleantest :
	@echo "suppression de l'executable de test"
	@make --directory=./test cleanexec

cleanobjtest :
	@echo "suppression des objets test"
	@make --directory=./test cleanobj

print-% :
	@echo $* = $($*)

############################################
# MAKEFILE PROJET VISUALISATION 3D CONVEXE #
############################################
# Réalisé par BESSAI Sofiane ###############
############################################