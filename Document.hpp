#include<vector>
#include<string>
using namespace std;
class Document
{
	public:
	vector<string> words;
	bool relevant;
	double score;
	int index;
	vector<string>& getWords();
	void add(string word);
};
