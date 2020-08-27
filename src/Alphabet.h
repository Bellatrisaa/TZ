#pragma once

#include <vector>
#include <forward_list>
#include <string>


class Alphabet
{
	typedef std::vector<std::string>          Buffer;
	typedef std::forward_list<std::string>    SortedWords;

	Buffer       buffer;
	SortedWords  *words;

public:
	explicit Alphabet(const char* path);

	~Alphabet() { if (!words) delete words; }

	void show() const;

	void toFile() const;

private:
	inline std::string getClearString(const std::string& dirtyString) const;

	inline std::string stringToLower(std::string& string) const;

	void setWordsInList();

	void loadingEmulation() const;

};
