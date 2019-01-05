CC = g++
CFLAGS = -Wall -std=c++11
EXEC_NAME = main
INCLUDES =
LIBS =
OBJ_FILES= main.o Joueur.o Piece.o Case.o Plateau.o Regles.o Affichage.o Jeu.o Plateau_De_Stratego.o R_Stratego.o Afficheur_Stratego.o Jeu_De_Stratego.o Move_Exception.o Input_Taker.o Input_Exception.o

all: $(EXEC_NAME)

clean :
	rm $(EXEC_NAME) $(OBJ_FILES) *.~ *.gch

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

PHONY:
	rm *.o ; rm *~ ; rm *.gch
