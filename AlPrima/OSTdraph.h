#pragma once
#include <queue>
#include <vector>
#define MAX 20

using namespace std;

class OSTgraph
{
	vector<vector<int>> vv;

public:
	OSTgraph();
	OSTgraph(int, int);
	~OSTgraph();

	OSTgraph Grffg();
};

