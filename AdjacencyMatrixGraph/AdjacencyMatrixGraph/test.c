#include "AMGraph.h"

int main()
{
	MGraph G;
	GraphChoice(&G);
	PrintMatrix(G);

	if (G.kind == 2)
	{
		BFSTraverse(&G);
		DFSTraverse(&G);
	}

	return 0;
}