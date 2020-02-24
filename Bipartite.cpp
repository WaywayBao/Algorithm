#include<iostream>
#include<vector>
using namespace std;
//DFS
bool Bipartite(vector<int> match[], int v, bool visited[], int set[]){  // O(V)
    for (size_t i = 0; i < match[v].size(); ++i) {
		int u = match[v].at(i);
        if (!visited[u]) {  // O(E)
            visited[u] = true;
            set[u] = !set[v];
            if (!Bipartite(match, u, visited, set))
                return false;
        }else if (set[u] == set[v])
            return false;
    }
    return true;
}

int main(){
	int N, v1, v2;
	cin >> N;
	vector<int> match[N];
	bool* visited = new bool[N]();
	int* set = new int[N]();

	while(cin >> v1 >> v2){
		match[v1].push_back(v2);
		match[v2].push_back(v1);
	}

//	for(int i = 0; i<N; ++i)
//		cout<<set[i]<<endl;

	set[0] = 0;
	cout<<Bipartite(match, 0, visited, set)<<endl;
	return 0;
}
/*
input:
	6
	0 1
	0 2
	5 4
	3 0
	4 3
	2 5

output:
	0
*/

