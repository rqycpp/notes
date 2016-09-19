#include <iostream>
using namespace std;

#define INF 1000000
#define MAXN 20

int n;
int Edge[MAXN][MAXN];

int S[MAXN];//S集合，存放已经找到最短路径的顶点
int dist[MAXN];//源点V0到其他各顶点的最短距离
int path[MAXN];//采用“导向追踪”的方法存放路径

void Dijkstra(int v0) {
	int i, j, k;
	for (i = 0; i < n; ++i) {
		dist[i] = Edge[v0][i];//将v0的那一行初始化给dist
		S[i] = 0;//集合初始化为空
		if (i != v0 && dist[v0] < INF) {//不是源点但与源点相连
			path[i] = v0;//该点的可由v0到达
		}
		else {
			path[i] = -1;
		}
	}

	S[v0] = 1; dist[v0] = 0;

	for (i = 0; i < n - 1; ++i) {//进行n-1轮循环（将其余n-1个顶点加入集合）
		int min = INF, u = v0;

		//选择当前集合T中的最短路径的顶点u
		for (j = 0; j < n; ++j) {
			if (!S[j] && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		S[u] = 1; //将u加入集合

		//修改T集合中顶点的dist和path数组元素值
		for (k = 0; k < n; ++k) {
			//不在S集合，存在一条u-k的边，v0-u-k的距离< v0-k
			if (!S[k] && Edge[u][k] < INF && dist[u] + Edge[u][k] < dist[k]) {
				dist[k] = dist[u] + Edge[u][k];
				path[k] = u;
			}
		}
	}
}

//初始化邻接矩阵
void init(int n) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (i == j) {
				Edge[i][j] = 0;
			}
			else {
				Edge[i][j] = INF;
			}
		}
	}
}

//输出顶点0到其他各顶点的最短距离，并输出具体路径
void printDist(int n) {
	int shortest[MAXN];
	for (int i = 1; i < n; ++i) {
		cout << dist[i] << " ";
		memset(shortest, 0, sizeof(shortest));
		int k = 0;
		shortest[k] = i;
		while (path[shortest[k]] != 0) {
			++k;
			shortest[k] = path[shortest[k - 1]];
		}
		++k;
		shortest[k] = 0;

		for (int i = k; i > 0; --i) {
			cout << shortest[i] << "->";
		}
		cout << shortest[0] << endl;
	}
}
int main()
{
	int i, j;
	int u, v, w;
	cin >> n;
	init(n);
	while (true)
	{
		cin >> u >> v >> w;
		if (u == -1)
			break;
		Edge[u][v] = w;
	}
	Dijkstra(0);
	printDist(n);
	return 0;
}
