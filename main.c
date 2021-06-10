#include<stdio.h>
#define P 4
int floydwarshall(int graph[][P])
{
	int dist[P][P], i, j, k;
	for (i = 0; i < P; i++)
		for (j = 0; j < P; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < P; k++)
	{
		for (i = 0; i < P; i++)
		{
			for (j = 0; j < P; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	prtshrtpath(dist);
	return 0;
}
int prtshrtpath(int dist[][P])
{
	printf ("The MATRIX is  :: \n");
	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < P; j++)
		{
			if (dist[i][j] == 9999999)
				printf("%7s", "~");
			else
				printf ("%7d", dist[i][j]);
		}
		printf("\n");
	}
	return 0;
}

int main()
{
	int graph[P][P] = { {0, 7, 5, 9999999},
						{9999999, 0, 7, 6},
						{9999999, 9999999, 0, 9999999},
						{4, 1, 11, 0}
					};

	floydwarshall(graph);
	return 0;
}