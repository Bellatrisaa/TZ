comp = g++
cflags = -Wall -Werror
obj_t = build/test/
obj_s = build/src/
objects = build/src/singleList.o build/src/main.o build/src/alphabetMethods.o build/src/tools.o
objects_test = $(obj_t)IsItLetter_test.o $(obj_t)main_test.o $(obj_s)tools.o $(obj_t)returntostart_test.o $(obj_t)countsymbols_test.o $(obj_t)sizet_countsymbols_test.o $(obj_s)singleList.o $(obj_t)method_push_test.o $(obj_t)method_tolower_test.o $(obj_t)method_sort_alphabet_test.o $(obj_t)method_filtoarray_test.o $(obj_s)alphabetMethods.o $(obj_t)method_deletepuncmark_test.o
test = bin/test
.PHONY: all clean $(test)

all: bin/AlphabetWords

bin/AlphabetWords: $(objects)
	$(comp) $(cflags) -o bin/AlphabetWords $(objects)
$(test): $(objects_test)
	$(comp) $(cflags) -o $(test) $(objects_test) 
$(obj_s)singleList.o: src/singleList.cpp
	$(comp) $(cflags) -o $(obj_s)singleList.o -c src/singleList.cpp
$(obj_s)main.o: src/main.cpp
	$(comp) $(cflags) -o $(obj_s)main.o -c src/main.cpp
$(obj_s)alphabetMethods.o: src/alphabetMethods.cpp
	$(comp) $(cflags) -o $(obj_s)alphabetMethods.o -c src/alphabetMethods.cpp
$(obj_s)tools.o: src/tools.cpp
	$(comp) $(cflags) -o $(obj_s)tools.o -c src/tools.cpp

$(obj_t)main_test.o: test/main_test.cpp
	$(comp) -I third-party $(cflags) -o build/test/main_test.o -c test/main_test.cpp
$(obj_t)IsItLetter_test.o: test/tools_test/IsItLetter_test.cpp
	$(comp) -I third-party -I src $(cflags) -o $(obj_t)IsItLetter_test.o -c test/tools_test/IsItLetter_test.cpp
$(obj_t)returntostart_test.o: test/tools_test/returntostart_test.cpp
	$(comp) -I third-party -I src $(cflags) -o $(obj_t)returntostart_test.o -c test/tools_test/returntostart_test.cpp
$(obj_t)countsymbols_test.o: test/tools_test/countsymbols_test.cpp
	$(comp) -I third-party -I src -I test/tools_test/test_txt_files $(cflags) -o $(obj_t)countsymbols_test.o -c test/tools_test/countsymbols_test.cpp
$(obj_t)sizet_countsymbols_test.o: test/tools_test/sizet_countsymbols_test.cpp
	$(comp) -I third-party -I src $(cflags) -o $(obj_t)sizet_countsymbols_test.o -c test/tools_test/sizet_countsymbols_test.cpp
$(obj_t)method_push_test.o: test/singleList_methods_test/method_push_test.cpp
	$(comp) -I third-party -I src $(cflags) -o $(obj_t)method_push_test.o -c test/singleList_methods_test/method_push_test.cpp
$(obj_t)method_tolower_test.o: test/singleList_methods_test/method_tolower_test.cpp
	$(comp) -I third-party -I src $(cflags) -o $(obj_t)method_tolower_test.o -c test/singleList_methods_test/method_tolower_test.cpp
$(obj_t)method_sort_alphabet_test.o: test/singleList_methods_test/method_sort_alphabet_test.cpp
	$(comp) -I third-party -I src $(cflags) -o $(obj_t)method_sort_alphabet_test.o -c test/singleList_methods_test/method_sort_alphabet_test.cpp
$(obj_t)method_filtoarray_test.o: test/alphabet_methods_test/method_filetoarray_test.cpp
	$(comp) -I third-party -I src $(cflags) -o $(obj_t)method_filtoarray_test.o -c test/alphabet_methods_test/method_filetoarray_test.cpp
$(obj_t)method_deletepuncmark_test.o: test/alphabet_methods_test/method_deletepuncmark_test.cpp
	$(comp) -I third-party -I src $(cflags) -o $(obj_t)method_deletepuncmark_test.o -c test/alphabet_methods_test/method_deletepuncmark_test.cpp
clean:
	rm -rf bin/*.exe build/src/*.o build/test/*.o