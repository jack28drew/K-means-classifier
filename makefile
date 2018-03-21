# build executable for K-means classifier called run
output: main.o kMeans.o
	g++ -Wall -Wextra main.o kMeans.o -o run

main.o: main.cpp
	g++ -c main.cpp

kMeans.o: kMeans.cpp kMeans.h
	g++ -c kMeans.cpp

clean:
	rm *.o run