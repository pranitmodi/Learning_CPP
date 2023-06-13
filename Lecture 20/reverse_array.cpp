#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr={1,2,3,4,5,6};
    int m = 3; // reverse after this position

    // Dont overcomplicate things when there is no need
    int j = arr.size() - 1;
	int i = m + 1;
	while(i<j)
	{
		swap(arr[i],arr[j]);
		i++;
		j--;
	}

    cout << "Output: ";
    for(int i=0; i<6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
