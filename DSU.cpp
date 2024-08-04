// Problem-LINK: 
// https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/disjoint-set-union/?purpose=login&source=problem-page&update=google

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 2 ; 
int parent[N] ; 

void print(priority_queue < int, vector < int >, greater < int > > &q)
{
    while ( q.size() )
    {
        cout << q.top() << " " ; 
        q.pop() ;
    }

    cout << "\n" ; 
}

int find_parent(int node)
{
    if ( parent[node] < 0 ) 
        return node ; 

    return parent[node] = find_parent(parent[node]) ; 
}

void join(int a, int b)
{
    int p1 = find_parent(a) ; 
    int p2 = find_parent(b) ; 

    if ( p1 == p2 ) 
        return ; 

    if ( parent[p1] > parent[p2] ) 
        swap(p1, p2) ; 

    parent[p1] += parent[p2] ; 
    parent[p2] = p1 ; 
}

int main()
{
    int n, m ; 
    cin >> n >> m ; 

    memset(parent, -1, sizeof(parent)) ; 

    for ( int i=0 ; i < m ; i ++ ) 
    {
        int a, b ; 
        cin >> a >> b ;

        join(a, b) ; 
        vector < bool > seen ( n + 1 ) ; 
        priority_queue < int, vector < int >, greater < int >  > q ;

        for ( int node = 1 ; node <= n ; node ++ ) 
        {
            int p = find_parent(node) ; 
            int sz = -parent[p] ; 

            if (seen[p] == false)
            {
                seen[p] = true ; 
                q.push(sz) ; 
            }
        }

        print(q) ; 
    }

    return 0 ;
}
