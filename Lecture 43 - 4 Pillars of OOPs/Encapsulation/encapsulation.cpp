#include <bits/stdc++.h>
using namespace std;
class Student
{
    private:
        string name;
        int age;

    public:
        int getAge()
        {   
            return this->age;
        }
};
int main()
{
    Student s1;
    cout << "Age: " << s1.getAge() << endl; //returns garbage value
    return 0;
}