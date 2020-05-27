comp = g++
cflags = -Wall 
objects = build/src/singleList.o build/src/main.o build/src/alphabetMethods.o build/src/tools.o
objects_test = build/test/IsItLetter_test.o build/test/main_test.o build/src/tools.o
test = bin/test
.PHONY: all clean $(test)

all: bin/AlphabetWords

bin/AlphabetWords: $(objects)
	$(comp) $(cflags) -o bin/AlphabetWords $(objects)
$(test): $(objects_test)
	$(comp) $(cflags) -o $(test) $(objects_test) 
build/src/singleList.o: src/singleList.cpp
	$(comp) $(cflags) -o build/src/singleList.o -c src/singleList.cpp
build/src/main.o: src/main.cpp
	$(comp) $(cflags) -o build/src/main.o -c src/main.cpp
build/src/alphabetMethods.o: src/alphabetMethods.cpp
	$(comp) $(cflags) -o build/src/alphabetMethods.o -c src/alphabetMethods.cpp
build/src/tools.o: src/tools.cpp
	$(comp) $(cflags) -o build/src/tools.o -c src/tools.cpp

build/test/main_test.o: test/main_test.cpp
	$(comp) -I third-party $(cflags) -o build/test/main_test.o -c test/main_test.cpp
build/test/IsItLetter_test.o: test/tools_test/IsItLetter_test.cpp
	$(comp) -I third-party -I src $(cflags) -o build/test/IsItLetter_test.o -c test/tools_test/IsItLetter_test.cpp
clean:
	rm -rf bin/*.exe build/src/*.o build/test/*.o