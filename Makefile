OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

all: program.exe

program.exe: Fotografia.o Album_en_curs.o Coleccio.o program.o Arbre.o
	g++ -o program.exe *.o	
	
Arbre.o: Arbre.cc
	g++ -c Arbre.cc $(OPCIONS)

Fotografia.o: Fotografia.cc
	g++ -c Fotografia.cc $(OPCIONS)

Album_en_curs.o: Album_en_curs.cc
	g++ -c Album_en_curs.cc $(OPCIONS)

Coleccio.o: Coleccio.cc
	g++ -c Coleccio.cc $(OPCIONS)

program.o: program.cc
	g++ -c program.cc $(OPCIONS)

clean:
	rm *.o *.exe
	
tar: 
	tar -cvf practica.tar Makefile *.cc *.hh html.zip
