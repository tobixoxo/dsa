//GRAPH IMPLEMENTATION
//TAKING INPUT AND DEPTH FIRST TRAVERSAL

#include<iostream>
using namespace std;

void Print(int** edges, int n ,int starting_vertex, bool* visited)  
{
    cout << starting_vertex <<  " " ;
    visited[starting_vertex] = true;        //updatign the visited array
    for(int i = 0 ; i < n; i++){            //traversing on that idx = startvertex, to check adj vertex
        if (i == starting_vertex) continue;  
        
        if(edges[starting_vertex][i] == 1){ //if found, we print that first
            if(visited[i] == true) continue;//if already visited continue  
            Print(edges,n,i,visited);                   
        }
    }
}


int main(){
    int n,e;            //n -> vertices   e-> edges
    cin >> n >> e;

    int** edges = new int*[n];      //a 2D array dynamically allocated, of shape nxn

    for(int i = 0; i < n; i++){     //traversing in the array, removing the garbage value
        edges[i] = new int[n];
        for(int j = 0 ; j <n; j++){
            edges[i][j] = 0;        //setting each entry to 0, which means false
        }                           // i and j are NOT connected yet
    }

    bool* visited = new bool[n];    //keeps track if a vertice is visited or not
    for(int i = 0 ; i < n ; i++){   //type is bool
        visited[i] = false;         //will be used in printing function
    }

    for(int i = 0; i < e; i++){     //asking for adjacent vertices 'e' times
        int first, second; 
        cin >> first >> second;
        edges[first][second] = 1;   //updating both places to one
        edges[second][first] = 1;   
    }

    Print(edges,n,0,visited);
    return 0;
    
}
