#include <bits/stdc++.h>
using namespace std;

// Heap = complete binary tree + heap order property
// 0th indexing
// node = i; left child = (2*i) + 1; right child = (2*i) + 2;
// parent => (i/2)-1

class Heap
{
    public:
        int arr[100];
        int size;

        Heap()
        {
            size = -1;
        }

        void insertInHeap(int val)
        {
            size++;
            arr[size] = val;
            int i = size;

            while(i > 0)
            {
                int parent = i%2 == 0 ? (i-2)/2 : (i-1)/2;
                if(arr[parent] < arr[i])
                {
                    swap(arr[parent],arr[i]);
                    i = parent;
                }
                else    
                    return;
            }
        }

        void heapify(int arr[], int i, int size)
        {
            int largest = i;
            int left = (2*i) + 1;
            int right = (2*i) + 2;

            if(left<=size && arr[left]>arr[i])
                largest = left;
            if(right<=size && arr[right]>arr[largest])
                largest = right;

            if(largest != i)
            {
                swap(arr[largest],arr[i]);
                heapify(arr,largest,size);
            }
        }

        void deleteFromHeap()
        {
            arr[0] = arr[size];
            size--;

            heapify(arr,0,size);
        }

        void printHeap(int arr[], int n)
        {
            for(int i=0; i<n; i++)
                cout << arr[i] << " ";
            cout << endl;
        }

        void buildHeap(int arr[], int n)
        {
            n--;
            
            int parent = (n/2)-1;
            for(int i=parent; i>=0; i--)
                heapify(arr,i,n);
        }

        void heapSort(int arr[], int n)
        {
            // arrays need to be a heap - buildHeap()

            int s = n-1;
            while(s>0)
            {
                swap(arr[s--],arr[0]);
                heapify(arr,0,s);
            }
        }
};
int main()
{
    Heap h1;
    h1.insertInHeap(1);
    h1.insertInHeap(2);
    h1.insertInHeap(6);
    h1.insertInHeap(2);
    h1.insertInHeap(3);
    h1.printHeap(h1.arr,h1.size+1);

    h1.deleteFromHeap();
    h1.printHeap(h1.arr,h1.size+1);
    
    h1.heapSort(h1.arr,h1.size+1);
    h1.printHeap(h1.arr,h1.size+1);
}