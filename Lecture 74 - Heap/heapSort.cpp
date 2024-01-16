#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        if(left<=n && arr[left]>arr[largest])
            largest = left;
        if(right<=n && arr[largest]<arr[right])
            largest = right;
            
        if(largest != i)
        {
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
        
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=n/2-1; i>=0; i--)
        {
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n); // first transforming array into heap
        
        int size = n-1; // when zero indexing
        while(size >= 0)
        {
            swap(arr[size],arr[0]);
            size--;
            
            heapify(arr,size,0);
        }
    }
};