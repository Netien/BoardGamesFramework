all: main
c = g++ -Wall -std=c++11

main: main.o Joueur.o Piece.o Case.o Plateau.o Regles.o Plateau_De_Stratego.o R_Stratego.o
	$c -o main main.o R_Stratego.o Plateau_De_Stratego.o Plateau.o Regles.o Case.o Piece.o Joueur.o

main.o: main.cpp R_Stratego.hpp Plateau_De_Stratego.hpp Case.hpp Piece.hpp Joueur.hpp
	$c -c main.cpp R_Stratego.hpp Plateau_De_Stratego.hpp Case.hpp Piece.hpp Joueur.hpp

R_Stratego.o: R_Stratego.cpp R_Stratego.hpp
	$c -c R_Stratego.cpp R_Stratego.hpp

Plateau_De_Stratego.o: Plateau_De_Stratego.cpp Plateau_De_Stratego.hpp
	$c -c Plateau_De_Stratego.cpp Plateau_De_Stratego.hpp

Regles.o: Regles.cpp Regles.hpp
	$c -c Regles.cpp Regles.hpp

Plateau.o: Plateau.cpp Plateau.hpp
	$c -c Plateau.cpp Plateau.hpp

Case.o: Case.cpp Case.hpp
	$c -c Case.cpp Case.hpp

Piece.o: Piece.cpp Piece.hpp
	$c -c Piece.cpp Piece.hpp

Joueur.o: Joueur.cpp Joueur.hpp 
	$c -c Joueur.cpp Joueur.hpp

clean:
	rm *.o *.gch *~ $ main 

PHONY:
	rm *.o ; rm *~ ; rm *.gch
