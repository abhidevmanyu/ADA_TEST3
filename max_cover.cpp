 #include <iostream>
using namespace std;
#define U 5
#define V 5
bool Graph[U][V];
int show[U][V];
bool bipMax(int u, bool visited[], int a[]) {
for (int v = 0; v < V; v++) {
if (Graph[u][v] && !visited[v]) {
visited[v] = true;
if (a[v] < 0 || bipMax(a[v], visited, a)) {
a[v] = u;
show[u][v]=1;
return true;
}
}
}
return false;
}
int maxPair() {
int a[V];
for(int i = 0; i<V; i++)
a[i] = -1;
int Count = 0;
for (int u = 0; u < U; u++) {
bool visited[V];
for(int i = 0; i<V; i++)
visited[i] = false;
if (bipMax(u, visited, a))
Count++;
}
return Count;
}
int main() {
cout<<"Enter the adjacency matrix for the specified:"<<endl;
for(int i=0;i<U;i++)
{
    cout<<"Row "<<i+1<<" Elements :"<<endl; 
    for(int j=0;j<V;j++)
    {
        cin>>Graph[i][j];
    }
}
cout << "Maximum number of applicants matching for a particular problem " << maxPair()<<endl;;
for(int i=0;i<U;i++)
{
    for(int j=0;j<V;j++)
    {
        cout<<show[i][j]<<" ";
    }
    cout<<"\n"; 
}
return 0;
}
