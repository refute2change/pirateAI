make: compile link clean

compile:
	g++ -c $(wildcard *.cpp) $(wildcard */*.cpp)

link:
	g++ $(wildcard *.o) $(wildcard */*.o) -o main 

clean:
	del /Q *.o