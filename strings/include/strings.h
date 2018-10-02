#ifndef __STRINGS_H__
#define __STRINGS_H__ 

#include<string>
#include<unordered_map>
#include<vector>

using std::vector;
using std::string;
using std::unordered_map;



namespace strings
{
	//PREP VIDEO
	void reverseString(string& s);
	void reverseString(string& s, size_t beg, size_t end);

	bool isPalindrone(const string& s);
	bool isPalindrone(const string& s, size_t l, size_t r);

	int isSubString(const string& s, const string& p);
////////////////////////////////////////////////////////////////////////
	//TEST #1
	string reverse_ordering_of_words(string& s);
	void reverse(string& s, size_t i, size_t j);

	//TEST #2
	string move_letters_to_left(string s);
	bool isAlphaChar(char c);

	//HW #1
	bool isMatch(const string& word, const string& pattern);

	//HW#2
	vector<int> KMP(const string& s, const string& pattern);
	vector<int> createLpsTable(const string& pattern);

	//HW#3
	string longestSubStrWith2DistChars(const string& s);

	//vector<string> join_words_to_make_a_palindrome(const vector<string>& words);

	vector<string> neuronyms(const string& word);
//	void neuronyms(const string& word, vector<string>& words, size_t i, size_t j);
	void printAll(string st);


	
	
		

}
#endif
