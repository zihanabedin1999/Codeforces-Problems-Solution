#include <bits/stdc++.h>
using namespace std;

#define MAX_NODES 50000001
#define ll long long int

ll visited[MAX_NODES];
const ll N = 2319;

// Function to insert edges into the tree
void insertEdges(set<pair<ll,ll>>& tree, ll graph[][N], ll n) {
    for(ll i=n-1; i>=0; i--) {
        for(ll j=1; tree.size()<n-1 && j<n; j++) {
            ll u = graph[0][i];
            ll v = graph[u][j];
            if(u > v)
                swap(u,v);
            if(tree.find({u,v}) == tree.end()) {
                tree.insert({u,v});
                break;
            }
        }
    }
}

// Function to print tree edges
void printTreeEdges(const set<pair<ll,ll>>& tree) {
    for(const auto& edge : tree) {
        cout << edge.first + 1 << " " << edge.second+1 << '\n';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n;
    cin >> t;

    while(t--) {
        cin >> n;
        ll graph[N][N];
        set<pair<ll,ll>> tree;

        // read graph
        for(ll i=0; i<n; i++) {
            for(ll j=0; j<n; j++) {
                cin >> graph[i][j];
                graph[i][j]--;
            }
        }

        insertEdges(tree, graph, n);
        printTreeEdges(tree);
    }

    return 0;
}

