import java.util.*;

// creating this class which we will be going to use to understand this algorithm.
class Node5 implements Comparator<Node5> {
	int source;
	int dest;
	int weight;
	Node5(){}
	Node5(int s, int d, int w){
		this.source =s;
		this.dest =d;
		this.weight =w;
	}
  // we implements Comparator interface so thet's why we need to override compare() method, that used to sort this class
  // according to the weight.
	@Override
	public int compare(Node5 o1, Node5 o2) {
		// TODO Auto-generated method stub
		if(o1.weight > o2.weight) {
			return 1;
		}
		if(o1.weight < o2.weight) {
			return -1;
		}
		return 0;
	}
}
public class Kruskals_Algo {
  //here V stands for total number of vertices.
	int V;
	Kruskals_Algo(int v){
		this.V=v;
	}
	public static void main(String[] args) {
		Kruskals_Algo ob = new Kruskals_Algo(6);
    
    //we have to sort the PrirityQueue according to the weight of the node.  
		PriorityQueue<Node5> pq = new PriorityQueue<Node5>(new Node5());
    //creating nodes and adding in the PriorityQueue
		pq.add(new Node5(0, 1, 1));
		pq.add(new Node5(0, 2, 2));
		pq.add(new Node5(1, 2, 3));
		pq.add(new Node5(1, 4, 7));
		pq.add(new Node5(2, 4, 5));
		pq.add(new Node5(2, 3, 3));
		pq.add(new Node5(4, 5, 6));
		pq.add(new Node5(4, 3, 2));
		pq.add(new Node5(3, 5, 4));
    //call this function to get the answer ans passing the priorityQueue thet we have created.
		ob.minimumSpanningTree(pq);
	}
	int findPar(int[] parent,int data) {
    //checking data of the ith element in i, then its the actual parent of the data that is provided.
		if(parent[data]==data) {
			return parent[data];
		}
    //else changing the parent and going deep with parent of the data.
		return parent[data]=findPar(parent,parent[data]);
	}
  //this function is used for connection tho vertices by changing their parents.
	void union(int[] parent, int[] rank, int a, int b) {
		a=findPar(parent,a);
		b=findPar(parent,b);
		if(rank[a]>rank[b]) {
			parent[b]=a;
		}
		else if(rank[b]>rank[a]) {
			parent[a]=b;
		}
		else {
			parent[b]=a;
			rank[b]++;
		}
	}
	void minimumSpanningTree(PriorityQueue<Node5> pq) {
		//creating parent & key array to store the parent of the vertices & their rank.
		int key[] = new int[V];
		int parent[] = new int[V];
    
    //modifying each ith element of the array with i. So that, we can identify the main parent of each vertices.
		for(int i=0;i<V;i++) {
			parent[i]=i;
			key[i]=0;
		}
    //creating ArrayList to store our answer. So that, we can print whenever needed.
		ArrayList<Node5> al = new ArrayList<Node5>();
    //define the sum variable to get the total weight of the minimum spanning tree.
		int sum=0;
    //used while loop, that will execute untill the PriorityQueue is not empty.
		while(! pq.isEmpty()) {
      /*polling each node and checking the parent of source & destination.
        if they are same that means they are somehow connected 
        if they are not same that means they are not connected and we have to connect them.*/
			Node5 curr = pq.poll();
			if(findPar(parent,curr.source) != findPar(parent,curr.dest)) {
        // adding the weight because its the minimum one which is available in the priorityqueue & add the node in the ArrayList.
				sum+=curr.weight;
				al.add(curr);
        //Now, we are connecting them by making their parent same.
				union(parent,key,curr.dest,curr.source);
			}
		}
		for(Node5 it : al) {
      //printing the minimum spanning tree with source, destination & weight.
			System.out.println(it.source+" , "+it.dest+" --> "+it.weight);
		}
    // printing the total weight of the minimum spanning tree
		System.out.print("Total weight of minimum spanning tree is : "+sum);
	}
}
