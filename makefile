all: bin/Work
  
bin/Work: build/Main.o build/Menu.o 
	g++ -std=c++11 -Wall -Werror build/src/Main.o build/src/Menu.o -o bin/Work -lsfml-graphics -lsfml-window -lsfml-system
	
build/Main.o: src/Main.cpp
	g++ -std=c++11 -Wall -Werror -c src/Main.cpp -o build/src/Main.o 
	
build/Menu.o: src/RadioBut.hpp src/Menu.cpp 
	g++ -std=c++11 -Wall -Werror -c src/Menu.cpp -o build/src/Menu.o
	
build/RadioBut.o: src/RadioBut.hpp	
	g++ -std=c++11 -Wall -Werror build/src/RadioBut.hpp -o build/src/RadioBut.o -lsfml-graphics -lsfml-window -lsfml-system		
