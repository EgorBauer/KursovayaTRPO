all: bin/Work
  
bin/Work: build/Main.o 
	g++ -std=c++11 -Wall -Werror build/src/Main.o -o bin/Work -lsfml-graphics -lsfml-window -lsfml-system
	
build/Main.o: src/Main.cpp
	g++ -std=c++11 -Wall -Werror -c src/Main.cpp -o build/src/Main.o 	

