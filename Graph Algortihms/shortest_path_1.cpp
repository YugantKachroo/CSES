#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main() {
	
	fastIO;
	
	int N,M;
	cin >> N >> M;
	vector <pair <int,int>> adj[N+1];
	for (int i=0;i<M;i++) {
		int u,v, w;
		cin >> u >> v >> w;
		adj[u].push_back ({v,w});
		adj[v].push_back ({u,w});
	}
	
	vector <int> dis (N+1,INT_MAX);
	vector <bool> vis(N+1,false);
	dis[1] = 0;
	
	priority_queue <pair <int,int> ,vector <pair <int,int>>, greater<pair <int,int>>> pq;
	pq.push ({0,1});
	
	while (!pq.empty()) {
		pair <int,int> curr = pq.top();
		pq.pop();
		
		if (curr.first != dis[curr.second]) continue;
		
		for (int i=0;i<(int)adj[curr.second].size();i++) {
			int neighbor = adj[curr.second][i].first;
			int neighborWeight = adj[curr.second][i].second;
			
			if (dis[neighbor] > dis[curr.second] + neighborWeight) {
				dis[neighbor] = dis[curr.second] + neighborWeight;
				pq.push({dis[neighbor],neighbor});
			}
		}

	}
	
	for (int i=1;i<=N;i++) cout << dis[i] << " ";
	cout << endl;
	
	return 0;
}

