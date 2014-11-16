class Data
{
private:
	vector<Document> *rel_docs;
	vector<Document> *nrel_docs;
	Document *query;
	int num_rel;
	int num_not_rel;
public:
	void inputData();


};