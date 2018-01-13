#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include<limits>


#define MAX std::numeric_limits<int>::max()

using namespace std;


class Graph{
	
	public:
	
	int nodes;
	int edges;
	int ** adj;

	int count =0;
	


	struct Node{
    	int vertex;
    	int weight;
		int parent = -1;
	};

	struct Edge{
		int u,v;
		int weight;

	};

	struct Vertex{
		
		int parent;
		int rank =0;

	};

	int *pos; // keeps position of nodes in heap

	struct Node ** arr; // node array for heap

	struct Vertex ** varr; // vertex array

	struct Edge ** earr; // edge array for heap

	struct Edge ** earr_s; // sorted edge array

	Graph(int,int);


	//Prim
	
	void heapify(int);
	int heap_pop();
	void sift_up(int);
	void Prim();

	//Kruskal

	void heapsort_edges();
	void build_min_heap_edges();
	Edge * heap_pop_edges(int);
	void heapify_edges(int,int);
	void link_set(int,int);
	int find_set(int);
	void Kruskal();

	// Display and link vertices
	
	void display();
	void link(int,int);
	void link(int,int,int);

	// Graph traversal
	
	void BFS(int);
	void DFS();
	void DFS_visit(int,bool *);


};

Graph::Graph(int n,int e){
	
	

	nodes =n;
	edges =e;
	
	adj = new int *[n];
	pos = new int[n];
	arr = new Node* [n];
	varr = new Vertex *[n];
	earr = new Edge *[e];
	earr_s = new Edge *[e];
	
	for(int i =0; i<n ; i++){
		adj[i] = new int [n];
		}
	
	for(int i =0 ; i< n; i++){
        arr[i] = new Node;
    }
	

	for(int i =0 ; i< n; i++){
        varr[i] = new Vertex;
    }

	

	for(int i =0 ; i< e; i++){
        earr[i] = new Edge;
    }

	

	for(int i =0 ; i< e; i++){
        earr_s[i] = new Edge;
    }

	
}

void Graph::display(){
	
	for(int i = 0; i< nodes ; i++){
		for(int j =0 ; j < nodes ; j++)
			cout << adj[i][j] << " - " ;
		cout<< endl;
		}
}

void Graph::link(int u, int v){
	
	adj[u][v] = 1;
	adj[v][u] = 1;
}

void Graph::link(int u, int v, int val){
	
	adj[u][v] = val;
	adj[v][u] = val;
}

void Graph::BFS(int source){

	bool visited[nodes];
	for(int i = 0; i < nodes ; i++)
		visited[i] = false;
	
	queue <int> q;

	visited[source] = true;
	q.push(source);
	int temp;
	while(!q.empty()){

		temp = q.front();

		cout << temp << " -- ";

		for(int i =0 ; i< nodes ; i++){
			if(adj[temp][i] != 0 && visited[i]!=true){
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();

	}


}


void Graph::DFS(){

	bool visited[nodes];

	for(int i = 0; i < nodes ; i++)
		visited[i] = false;

	for(int i =0 ; i < nodes ; i++){
		if(visited[i] == false){
			DFS_visit(i,visited);
		}
	}

}


void Graph::DFS_visit(int source, bool * visited){

	cout << source << " -- ";

	visited[source] = true;

	for(int i =0; i < nodes ; i++){
		if(adj[source][i] != 0 && visited[i] == false){
			DFS_visit(i,visited);
		}
	}
}


//------------- MST ------------//



void Graph::heapify(int root){
    int smallest = root;
    int left = 2*root + 1;
    int right = 2*root +2;

    if(left < count && arr[left]->weight < arr[root]->weight)
        smallest = left;
    if(right < count && arr[right]->weight < arr[smallest]->weight)
        smallest = right;
    if(smallest!=root){
        Node * temp;
        temp = arr[root];
        arr[root] = arr[smallest];
        pos[arr[root]->vertex] = root;
        arr[smallest] = temp;
        pos[arr[smallest]->vertex] = smallest;
        heapify(smallest);
    }
}


int Graph::heap_pop(){
    Node * temp = arr[0];
    arr[0] = arr[count-1];
    pos[arr[0]->vertex] = 0;
    arr[count-1] = temp;
    arr[count-1]->weight = MAX;
    pos[arr[count-1]->vertex] = count-1;
    count--;
    heapify(0);
	return temp->vertex;
}

void Graph::sift_up(int vertex){

    int p = pos[vertex];
    Node * temp;

    int weight = arr[p]->weight;

    while( p >= 0 && weight < arr[(p-1)/2]->weight){

        
        temp = arr[(p-1)/2];
        arr[(p-1)/2] = arr[p];
        pos[arr[(p-1)/2]->vertex] = (p-1)/2;
        arr[p] = temp;
        pos[arr[p]->vertex] = p;

        p = (p-1)/2;

    }

}

void Graph::Prim(){

	int curr,parent;
	bool visited[nodes];

	for(int i = 0; i < nodes ; i++)
		visited[i] = false;

	arr[0]->vertex = 0;
	arr[0]->weight = 0;
	arr[0]->parent = -1;

	count = nodes;

	for(int i =1 ; i< nodes; i++){

        arr[i]->vertex = i;
        arr[i]->weight = MAX;
		arr[0]->parent = -1;
        pos[i] = i;
        
    }

	

	while(count!=0){
		
		curr = heap_pop();
		visited[curr] = true;
		//cout << curr << count <<endl;

		for(int i = 0; i< nodes ;i++){
			if(visited[i] == false && adj[curr][i]!=0 && adj[curr][i] < arr[pos[i]]->weight){
				arr[pos[i]]->weight = adj[curr][i];
				arr[pos[i]]->parent = curr;
				sift_up(i);
				//cout << curr << "  " << i << endl;
				
			}
		}
		parent = arr[pos[curr]]->parent;

		if(parent != -1)
			cout << curr << " -- " << parent << " --- " << adj[curr][parent] << endl;
	}




}

// --------- Kruskal -------------//


void Graph::Kruskal(){

	for(int i =0; i< nodes ; i++){
		
		varr[i]->parent = i;
	}

	int ecount = 0;

	for(int i = 0 ; i< nodes ; i++){
		for(int j = i; j< nodes ;j++){
			if(adj[i][j]!=0 && ecount < edges){
				earr[ecount]->u = i;
				earr[ecount]->v = j;
				earr[ecount]->weight = adj[i][j];
				ecount++;
			}
		}
	}
	
	int n = nodes - 1;
	

	heapsort_edges();

	for(int i =0; i<edges ; i++){

		if(n == 0)
			break;

		int u,v,up,vp;
		u = earr_s[i]->u;
		v = earr_s[i]->v;


		up = find_set(u);
		vp = find_set(v);

		if(up != vp){
			link_set(up,vp);
			n--;
			cout << u << " ----- " << v << " -- " << adj[u][v] << endl;
		}

	}

}




int Graph::find_set(int u){
	if(varr[u]->parent != u){
		varr[u]->parent = find_set(varr[u]->parent);

	}

	return varr[u]->parent;
}

void Graph::link_set(int u, int v){
	if(varr[u]->rank > varr[v]->rank){
		varr[v]->parent = u;

	}
	else{
		varr[u]->parent = v;
		if(varr[u]->rank == varr[v]->rank)
			varr[v]->rank = varr[v]->rank + 1;
	}
}







void Graph::build_min_heap_edges(){
	
    for(int i =(edges/2) - 1 ; i >= 0 ; i-- ){
        heapify_edges(i,edges);
    }
}

void Graph::heapify_edges(int root,int  ecount){
	int smallest = root;
    int left = 2*root + 1;
    int right = 2*root +2;

    if(left < ecount && earr[left]->weight < earr[root]->weight)
        smallest = left;
    if(right < ecount && earr[right]->weight < earr[smallest]->weight)
        smallest = right;
    if(smallest!=root){
        Edge * temp;
        temp = earr[root];
        earr[root] = earr[smallest];
        
        earr[smallest] = temp;
        
        heapify_edges(smallest,ecount);
    }
}

Graph::Edge * Graph::heap_pop_edges(int ecount){
    Edge * temp = earr[0];
    earr[0] = earr[ecount-1];
    
    earr[ecount-1] = temp;
    //earr[ecount-1]->weight = MAX;

	return temp;
}

void Graph::heapsort_edges(){

	int ecount = edges;

	build_min_heap_edges();

	for(int i=0; i<edges ;i++){
		earr_s[i] = heap_pop_edges(ecount);
		
		ecount--;
		heapify_edges(0,ecount);
	}


}





int main(){
	
	int n,e;
	int option;
	cout << "Create graph\nEnter no. of vertices and edges(vertices <space> edges)" << endl;
	cin >> n >> e;

	Graph G(n,e);
	
	int count = 0;
	int src;
	int u,v,w;

	cout << "Link edges of graph\nEnter vertex <space> vertex <space> weight" << endl;


	while(count<e){
		cin >> u >> v >> w;
		G.link(u,v,w);
		count++;
		}
	
	G.display();
	while(option!=5){
		cout << "1. BFS\n 2. DFS\n3. Prim's MST\n4. Kruskal MST\n5. Exit" << endl;
		cin >> option;

		switch(option){

			case 1:
				cout << "Enter source"<<endl;
				cin >> src;
				G.BFS(src);
				cout << endl;
				break;
			case 2:
				G.DFS();
				cout << endl;
				break;
			case 3:
				cout << "Vertex \t Vertex \t Weight" << endl;
				G.Prim();
				cout << endl;
				break;
			case 4:
				cout << "Vertex \t Vertex \t Weight" << endl;
				G.Kruskal();
				cout << endl;
				break;
			default:
				break;




		}
	}

}
