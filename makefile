main: main.cpp Shape.o Square.o Vector.o Button.o
	g++ main.cpp Shape.o Square.o Vector.o Button.o -o main -lGL -lglut -lGLU -lm -lSOIL
	@echo "Cleanning..."
	rm *.o

Shape.o src/Shape.cpp:
	g++ -c src/Shape.cpp -o Shape.o

Square.o src/Square.cpp:
	g++ -c src/Square.cpp -o Square.o

Vector.o src/Vector.cpp:
	g++ -c src/Vector.cpp -o Vector.o

Button.o src/Button.cpp:
	g++ -c src/Button.cpp -o Button.o