#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[20];
    int size;
    cout << "Enter the number of elements: " << endl;
    cin >> size;

    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    // int c1=0;
    // int c2=0;
    // int i=0;
    // int j=size-1;
    // while(i<size)
    // {   
    //     if(arr[i] == 0)
    //         i++;
    //     else if(arr[i] == 1 && arr[j] == 0)
    //     {
    //         arr[i] = 0;
    //         c1++;
    //         i++;
    //         j--;
    //     }
    //     else if(arr[i] == 2 && arr[j] == 0)
    //     {
    //         arr[i] = 0;
    //         c2++;
    //         i++;
    //         j--;
    //     }
    //     else if(arr[j] == 1)
    //     {
    //         c1++;
    //         j--;
    //     }
    //     else if(arr[j] == 2)
    //     {
    //         c2++;
    //         j--;
    //     }
    //     if((i+c1+c2) == size-1)
    //     {
    //         if(arr[i] == 1)
    //             c1++;
    //         else if(arr[i] == 2)
    //             c2++;
    //         else
    //             i++;
    //         cout << "Total One's: " << c1 << endl;
    //         cout << "Total Two's: " << c2 << endl;
    //         while(c1>0)
    //         {
    //             c1--;
    //             arr[i++] = 1;
    //         }
    //         while(c2>0)
    //         {
    //             c2--;
    //             arr[i++] = 2;
    //         }
    //         break;
    //     }
    //     // cout << "i= " << i << ", j= " << j << ", c1=" << c1 << " ,c2= " << c2 << endl;
    // }

    int low = 0, mid = 0, high = size-1;
    
    while(mid<=high)
    {

      switch (arr[mid]) 
      {
         case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;
         case 1:
            mid++;
            break;
         case 2:
            swap(arr[mid], arr[high]);
            high--; 
            //No mid++ -> because the swaped value that is coming in place of mid also needs to be checked, because our main focus is only leaving 1's in between and swapping 0's and 2's.
            break;
      }
   }

    cout << "Sorted array: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}