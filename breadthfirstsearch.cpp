#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<bool> v;
vector<vector<int>> g;
void beadthfirst(int b)
{
    queue<int> q;
    q.push(b);
    v[b] = true;
    cout<<"*******************************************\n";
    cout<<"\t-:The BFS Traversal is:-\n";
    while (!q.empty())
    {
        int a = q.front();
        q.pop(); 
        for (auto j = g[a].begin(); j != g[a].end(); j++)
        {
            if (!v[*j])
            {
                v[*j] = true;
                q.push(*j);
            }
        }
        cout << a << " - ";
    }
}
void edge(int a, int b)
{
    g[a].push_back(b);
}
int main()
{
    int n, e;
    cout<<"**************************************\n";
	cout<<"    *****Breadth-First Search *****\n";
    cout<<"**************************************\n";
    cout<<"Enter Total no. of Vertices ";
    cin>>n;
    cout<<"Enter Total no. of Edges ";
    cin>>e;
    v.assign(n, false);
    g.assign(n, vector<int>());
    int a, b, i;
    cout<<"Enter Source and Target Vertex:\n";
    for (i = 0; i < e; i++)
    {
        cin >> a >> b;
        edge(a, b);
    }
    for (i = 0; i < n; i++)
    {
        if (!v[i])
        {
            beadthfirst(i);
        }
    }
    cout<<"\n*******************************************\n";
    return 0;
}