SRC_DIR = src/
EXEC_DIR = bin/
TEST_DIR = test/
TEST_LIB_DIR = third-party/
cflags = -Wall -Werror
comp = g++
src = $(SRC_DIR)main.cpp $(SRC_DIR)convert.cpp $(SRC_DIR)Alphabet.cpp
tests = $(TEST_DIR)main.cpp $(SRC_DIR)Alphabet.cpp $(TEST_DIR)methods_test.cpp $(TEST_DIR)convert_test.cpp $(TEST_DIR)global_test.cpp

.PHONY: release app clean tests

release:
	$(comp) $(cflags) -o $(EXEC_DIR)AlphabetWords.exe $(src)
	$(comp) -I $(SRC_DIR) -I $(TEST_LIB_DIR) $(cflags) -o $(EXEC_DIR)Tests $(tests) $(SRC_DIR)convert.cpp
	./$(EXEC_DIR)Tests
app: 
	$(comp) $(cflags) -o $(EXEC_DIR)AlphabetWords.exe $(src)
clean:
	rm -rf $(EXEC_DIR)*.exe
tests:
	$(comp) -I $(SRC_DIR) -I $(TEST_LIB_DIR) $(cflags) -o $(EXEC_DIR)Tests $(tests) $(SRC_DIR)convert.cpp