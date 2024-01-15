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

        void deleteFromHeap()
        {
            // from the root node
            arr[1] = arr[size];
            size--;

            int i = 1;
            while(i<size)
            {
                int left = 2*i;
                int right = (2*i)+1;
                if(left<=size && arr[left] > arr[i])
                {
                    swap(arr[left],arr[i]);
                    i = left;
                }
                else if(right<=size && arr[right] > arr[i])
                {
                    swap(arr[right],arr[i]);
                    i = right;
                }
                else    
                    return;
            }
        }

        void print()
        {
            for(int i=1; i<=size; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[largest] < arr[left])
        largest = left;
    else if(right < n && arr[largest] < arr[right])
        largest = right;

    if(largest != i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}

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

    int arr[] = {-1,54,56,734,53,45};
    int n = 5;
    for(int i=n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }
}