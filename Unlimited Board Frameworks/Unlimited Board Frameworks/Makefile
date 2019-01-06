
CC = g++
CFLAGS = -Wall -std=c++11
INCLUDES =
LIBS =
OBJ_FILES= Joueur.o Piece.o Case.o Plateau.o Regles.o Affichage.o Jeu.o Input_Taker.o Input_Exception.o Stratego_Move_Exception.o
STRATEGO= Plateau_De_Stratego.o R_Stratego.o Afficheur_Stratego.o Jeu_De_Stratego.o
ECHECS= Plateau_Echecs.o Regles_Echecs.o Afficheur_Echecs.o Jeu_Echecs.o  


all: main test

clean :
	rm main test $(OBJ_FILES) $(STRATEGO) $(ECHECS) *.~ *.gch

main : $(OBJ_FILES) $(STRATEGO) $(ECHECS) main.o
	$(CC) -o main $(OBJ_FILES) $(STRATEGO) $(ECHECS) main.o $(LIBS)

test: $(OBJ_FILES) $(STRATEGO) main_test.o
	$(CC) -o test $(OBJ_FILES) $(STRATEGO) main_test.o $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

PHONY:
	rm *.o ; rm *~ ; rm *.gch
