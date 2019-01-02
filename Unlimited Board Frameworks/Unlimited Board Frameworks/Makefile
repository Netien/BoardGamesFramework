all: main
c = g++ -Wall -std=c++11

main: main.o Joueur.o Piece.o Case.o Plateau.o R_Stratego.o
	$c -o main main.o R_Stratego.o Plateau.o Case.o Piece.o Joueur.o

main.o: main.cpp Regles.hpp Plateau.hpp Case.hpp Piece.hpp Joueur.hpp
	$c -c main.cpp Regles.hpp Plateau.hpp Case.hpp Piece.hpp Joueur.hpp

R_Stratego.o: R_Stratego.cpp Regles.hpp Plateau.hpp Case.hpp Piece.hpp Joueur.hpp
	$c -c R_Stratego.cpp Regles.hpp Plateau.hpp Case.hpp Piece.hpp Joueur.hpp

Plateau.o: Plateau.cpp Plateau.hpp Case.hpp Piece.hpp Joueur.hpp
	$c -c Plateau.cpp Plateau.hpp Case.hpp Piece.hpp Joueur.hpp

Case.o: Case.cpp Case.hpp Piece.hpp Joueur.hpp
	$c -c Case.cpp Case.hpp Piece.hpp Joueur.hpp

Piece.o: Piece.cpp Piece.hpp Joueur.hpp
	$c -c Piece.cpp Piece.hpp Joueur.hpp

Joueur.o: Joueur.cpp Joueur.hpp 
	$c -c Joueur.cpp Joueur.hpp

clean:
	rm *.o *.gch *~

PHONY:
	rm *.o ; rm *~ ; rm *.gch
