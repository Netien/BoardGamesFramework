all: main
c = g++ -Wall -std=c++11

main: main.o Joueur.o Piece.o Case.o Plateau.o Regles.o Plateau_De_Stratego.o R_Stratego.o Afficheur_Stratego.o Affichage.o Jeu_De_Stratego.o Jeu.o
	$c -o main main.o R_Stratego.o Plateau_De_Stratego.o Plateau.o Regles.o Case.o Piece.o Joueur.o Afficheur_Stratego.o Affichage.o Jeu_De_Stratego.o Jeu.o

main.o: main.cpp 
	$c -c main.cpp

R_Stratego.o: R_Stratego.cpp
	$c -c R_Stratego.cpp

Plateau_De_Stratego.o: Plateau_De_Stratego.cpp
	$c -c Plateau_De_Stratego.cpp

Regles.o: Regles.cpp
	$c -c Regles.cpp

Plateau.o: Plateau.cpp
	$c -c Plateau.cpp

Case.o: Case.cpp
	$c -c Case.cpp

Piece.o: Piece.cpp
	$c -c Piece.cpp

Joueur.o: Joueur.cpp
	$c -c Joueur.cpp

Afficheur_Stratego.o : Afficheur_Stratego.cpp
	$c -c Afficheur_Stratego.cpp

Affichage.o : Affichage.cpp
	$c -c Affichage.cpp

Jeu_De_Stratego.o : Jeu_De_Stratego.cpp
	$c -c Jeu_De_Stratego.cpp

Jeu.o : Jeu.cpp
	$c -c Jeu.cpp

clean:
	rm *.o *.gch *~ $ main 

PHONY:
	rm *.o ; rm *~ ; rm *.gch
