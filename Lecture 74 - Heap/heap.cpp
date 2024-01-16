#include <bits/stdc++.h>
using namespace std;
class Heap
{
    public:
        int size;
        int arr[100];

        Heap()
        {
            size = 0;
        }

        void insert(int val)
        {
            size++;
            arr[size] = val;

            int index = size;
            while(index > 1)
            {
                int parent = index/2;

                if(arr[parent] < arr[index])
                {
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else
                    return;
            }
        }

        void heapify(int arr[], int n, int i) //making sure that element at i, finds it correct position
        {
            int largest = i;
            int left = 2*i;
            int right = 2*i + 1;

            if(left <= n && arr[largest] < arr[left])
                largest = left;
            if(right <= n && arr[largest] < arr[right])
                largest = right;

            if(largest != i)
            {
                swap(arr[largest],arr[i]);
                heapify(arr,n,largest);
            }
        }

        void deleteFromHeap()
        {
            // from the root node
            arr[1] = arr[size];
            size--;

            int i = 1;
            heapify(arr,size,i);
        }

        void print()
        {
            for(int i=1; i<=size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        //Function to build a Heap from array.
        void buildHeap(int arr[], int n)  
        { 
            n--;
            for(int i=n/2; i>=0; i--)
            {
                heapify(arr,n,i);
            }
        }

        //Function to sort an array using Heap Sort. 
        void heapSort(int arr[], int size)
        {
            // buildHeap(arr,size); // if array is already a heap
            while(size > 1)
            {
                swap(arr[1],arr[size]);
                size--;

                int i = 1;
                heapify(arr,size,i);
            }
        }
};

int main()
{
    Heap h;
    h.insert(23);
    h.insert(35);
    h.insert(1);
    h.insert(345);
    h.insert(34);
    h.print();
    h.deleteFromHeap();
    h.print();
    h.deleteFromHeap();
    h.print();
}