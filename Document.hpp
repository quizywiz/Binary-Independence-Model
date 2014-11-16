class Document
{
private:
	vector<string> words;
	bool relevant;
public:
	string getSentence();
	vector<string> getWords()
	{
		return words;
	}

};