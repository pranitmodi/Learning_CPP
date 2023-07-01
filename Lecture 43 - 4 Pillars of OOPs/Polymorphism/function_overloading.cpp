#include <bits/stdc++.h>
using namespace std;
void okay()
{
    cout << "Nothing!";
}
void okay(string name)
{
    cout << name << ": What nothing?" << endl;
}
void okay(string name1, string name2)
{
    cout << name1 << ", said ";
    okay();
    cout << " to " << name2 << endl;
}
int main()
{
    okay();
    cout << endl;
    okay("Pranit");
    okay("Jai", "Veeru");
    return 0;
}
