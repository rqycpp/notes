// Source : https://leetcode.com/problems/reverse-words-in-a-string/
// Author : RQY
// Date   : 2016-11-17
/**********************************************************************************
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
 **********************************************************************************/
 class Solution {
 public:
 	void reverseWords(string &s) {
 		if (s.empty())
 			return;
 		size_t i, index = 0;
 		lstrip(s); rstrip(s);
 		unique_ws(s);
 		s.append(" ");//结尾补一个空格，便于下面的for循环查找white space
 		for (i = 0; i < s.length(); i = index + 1) {
 			index = s.find(' ', i);
 			reverse(s.begin() + i, s.begin() + index);
 		}
 		s.pop_back();
 		reverse(s.begin(), s.end());
 	}
 	void lstrip(string &s) {//去掉开头连续空格
 							// auto beg = s.begin();
 		auto i = s.find_first_not_of(' ');
 		if (i == string::npos)
 			s.clear();
 		else
 			s.erase(s.begin(), s.begin() + i);

 	}
 	void rstrip(string &s) {//去掉结尾连续空格
 		auto i = s.find_last_not_of(' ');
 		if (i != string::npos) {
 			s.erase(s.begin() + i + 1, s.end());
 		}
 	}
 	void unique_ws(string &s) {//消除两单词间的多余空格
 		if (s.empty())
 			return;
 		auto first = s.begin(), last = s.end();
 		string::iterator result = first;

 		while (++first != last) {
 			if (*result == ' ' && *first == ' ')
 				continue;
 			else
 				*(++result) = *first;
 		}
 		s.erase(++result, last);
 	}
 };
