#include<vector>
#include<string>
#include"Document.hpp"
using namespace std;
class Document;
vector<string>& Document::getWords()
{
	return words;
}
void Document::add(string word)
{
	words.push_back(word);
}