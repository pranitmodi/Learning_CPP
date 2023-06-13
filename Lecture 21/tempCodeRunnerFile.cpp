vector <int> res;
    if(temp[0] == 0)
    {
        for(int i=1; i<temp.size(); i++)
            res.push_back(temp[i]);
    }
    else 
        res = temp;