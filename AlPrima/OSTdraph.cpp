#include "stdafx.h"
#include "OSTdraph.h"


OSTgraph::OSTgraph()
{
}


OSTgraph::~OSTgraph()
{
}
OSTgraph::OSTgraph(int size, int perc)
{

	vv.resize(size);
	for (int i = 0; i < size; i++)
		vv[i].resize(i+1, 0);

	vector<int> tops(size);
	vector<int> subtops;

	for (int i = 0; i < size; i++)
		tops[i] = i;

	int temp = rand() % size;
	subtops.push_back(temp);
	tops.erase(tops.begin() + temp);


	for (int i = 0; i < size - 1; i++)
	{
		int temp1 = rand() % tops.size();
		int temp2 = rand() % subtops.size();
		if (tops[temp1] < subtops[temp2])
			vv[subtops[temp2]][tops[temp1]] = rand()% MAX+1;
		else vv[tops[temp1]][subtops[temp2]] = rand()% MAX+1;

		subtops.push_back(tops[temp1]);
		tops.erase(tops.begin() + temp1);
	}

	int fllng = size*(size + 1)*0.5*perc*0.01 - (size - 1);

	vector <pair<int, int>> nlls;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			if (vv[i][j] == 0)
				nlls.push_back(make_pair(i, j));
		}
	}

	for (int i = 0; i< fllng; i++)
	{
		int tempN = rand() % nlls.size();
		vv[nlls[tempN].first][nlls[tempN].second] = rand()% MAX+1;
		nlls.erase(nlls.begin() + tempN);
	}

}

OSTgraph OSTgraph::Grffg()
{

}