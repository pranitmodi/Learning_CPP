#include <bits/stdc++.h>
using namespace std;
class TimeMap {
public:
    map<string,map<int,string>> store;
    map<string,vector<int>> vap;

    TimeMap() 
    {

    }
    
    void set(string key, string value, int timestamp) 
    {
        store[key][timestamp] = value;
        vap[key].push_back(timestamp);
    }
    
    string get(string key, int timestamp)
    {
        // if(store.find(key) != store.end() && (!store[key].empty()))
        // {
        //     string ans = "";
        //     for(auto i:store[key])
        //     {
        //         if(i.first<=timestamp)
        //         {
        //             ans = i.second;
        //             if(i.first > timestamp)
        //                 return ans;
        //         }
        //     }
        //     return ans;
        // }
        // else
        // {
        //     return NULL;
        // }

        string ans = "";
        if((store.find(key) != store.end()) && (!store[key].empty())) 
        {
            if((store[key].begin())->first <= timestamp)
            {
                for (auto it = store[key].rbegin(); it != store[key].rend(); it++)
                {
                    if(it->first <= timestamp) 
                    {
                        ans = it->second;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
int main()
{
    TimeMap *t = new TimeMap();
    string key = "okay";
    string value = "no";
    (*t).set(key,value,1);
    (*t).set(key,value,1);
    (*t).set(key,value,56);
    (*t).set(key,value,6);
    (*t).set(key,value,8);
    (*t).set(key,value,2);
    (*t).set("okay","yess",7);
    (*t).set("okay","yess",81);
    (*t).set("okay","yess",3);
    (*t).set("okay","yess",4);

    string str = (*t).get(key,1);
    cout << "Ans: " << str << endl;
}