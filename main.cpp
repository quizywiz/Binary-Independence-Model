#include "BinaryIndependenceModel.hpp"
#include <cstring>
int main(int argv, char *argc[])
{
	if(argv>1)
	{
		if(strcmpi(argc[1],"-h"==0 || strcmpi(argc[1],"--help")==0)
			std::cout<<"enter input: format is\nr\n<_doc1word1_doc1word2...>\n<doc2word1_doc2word2...>\n...\nn\n<_doc1word1_doc1word2...>\n<doc2word1_doc2word2...>\n...\n";
	}
	BinaryIndependenceModel.run_program();
	return 0;
}