# build executable for K-means classifier called run
output: main.o kMeans.o
	g++ -v -Wall -Wextra main.o kMeans.o -o run

main.o: main.cpp
	g++ -v -c main.cpp

kMeans.o: kMeans.cpp kMeans.h
	g++ -v -c kMeans.cpp

clean:
	rm *.o run