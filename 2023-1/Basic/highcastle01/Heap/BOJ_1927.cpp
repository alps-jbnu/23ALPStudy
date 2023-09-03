#include<iostream>

using namespace std;

#define MAX_ELEMENT 100001

class HeapNode
{
	int key;
	public:
		HeapNode(int k = 0) : key(k){}
		void setKey(int k){key = k;}
		int getKey(){return key;}
		void display(){cout << key << "\n";}
};

class MinHeap : public HeapNode
{
	HeapNode node[MAX_ELEMENT];
	int size;
public:
	MinHeap() : size(0){}
	bool isEmpty(){return size == 0;}
	bool isFull(){return size == MAX_ELEMENT -1;}
	HeapNode& getParent(int i){return node[i/2];}
	HeapNode& getLeft(int i){return node[i*2];}
	HeapNode& getRight(int i){return node[i*2+1];}
	int getSize(){return size;}
	
	void display()
    {
        node[1].display();
    }
	
	void insert(int key)
	{
		if(isFull())
		{
			return;
		}
		
		int i = ++size;
		while(i != 1 && key < getParent(i).getKey())
		{
			node[i] = getParent(i);
			i /= 2;
		}
		
		node[i].setKey(key);
	}
	
	HeapNode remove()
	{
		if(isEmpty())
		{
			return NULL;
		}
		HeapNode root = node[1];
		HeapNode last = node[size--];
		
		int parent = 1;
		int child = 2;
		
		while(child <= size)
		{
			if(child < size && getLeft(parent).getKey() > getRight(parent).getKey())
			{
				child++;
			}
			if(last.getKey() <= node[child].getKey())
			{
				break;
			}
			
			node[parent] = node[child];
			parent = child;
			child *= 2;
		}
		
		node[parent] = last;
		
		return root;
	}
};

int main(void)
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, i, x;
	MinHeap min;
	
	cin >> n;
	
	for(i = 1; i <= n; i++)
	{
		cin >> x;
		
		if(x == 0)
		{
			if(min.isEmpty())
			{
				cout << "0\n";
			}
			else
			{
				min.display();
				min.remove();
			}
		}
		else if(x > 0)
		{
			min.insert(x);
		}
	}
		
	return 0;
}
