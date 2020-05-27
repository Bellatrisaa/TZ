comp = g++
cflags = -Wall 
objects = build/src/singleList.o build/src/main.o build/src/alphabetMethods.o build/src/tools.o

.PHONY: all clean 

all: bin/AlphabetWords

bin/AlphabetWords: $(objects)
	$(comp) $(cflags) -o bin/AlphabetWords $(objects)
build/src/singleList.o: src/singleList.cpp
	$(comp) $(cflags) -o build/src/singleList.o -c src/singleList.cpp
build/src/main.o: src/main.cpp
	$(comp) $(cflags) -o build/src/main.o -c src/main.cpp
build/src/alphabetMethods.o: src/alphabetMethods.cpp
	$(comp) $(cflags) -o build/src/alphabetMethods.o -c src/alphabetMethods.cpp
build/src/tools.o: src/tools.cpp
	$(comp) $(cflags) -o build/src/tools.o -c src/tools.cpp
clean:
	rm -rf bin/*.exe build/src/*.o