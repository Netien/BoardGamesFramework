
CC = g++
CFLAGS = -Wall -std=c++11
INCLUDES =
LIBS =
OBJ_FILES= Joueur.o Piece.o Case.o Plateau.o Regles.o Affichage.o Jeu.o Plateau_De_Stratego.o R_Stratego.o Afficheur_Stratego.o Jeu_De_Stratego.o Plateau_Echecs.o Regles_Echecs.o Afficheur_Echecs.o Jeu_Echecs.o Stratego_Move_Exception.o Input_Taker.o Input_Exception.o

all: main test

clean :
	rm main test $(OBJ_FILES) *.~ *.gch

main : $(OBJ_FILES) main.o
	$(CC) -o main $(OBJ_FILES) main.o $(LIBS)

test: $(OBJ_FILES) main_test.o
	$(CC) -o test $(OBJ_FILES) main_test.o $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

PHONY:
	rm *.o ; rm *~ ; rm *.gch
