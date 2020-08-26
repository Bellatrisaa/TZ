SRC_DIR = src/
EXEC_DIR = bin/
cflags = -Wall -Werror
comp = g++
src = $(SRC_DIR)main.cpp $(SRC_DIR)convert.cpp $(SRC_DIR)Alphabet.cpp

.PHONY: exec clean tests

exec: 
	$(comp) $(cflags) -o $(EXEC_DIR)AlphabetWords.exe $(src)
clean:
	rm -rf $(EXEC_DIR)*.exe