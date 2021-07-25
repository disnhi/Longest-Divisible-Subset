OPTS = -Wall

all: ldp

ldp: longestDivisiblePair.cpp
	g++ -std=c++11 ${OPTS} -o ldp longestDivisiblePair.cpp
