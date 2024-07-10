// Philips exam question - Aditya
class AltTab
{
    public int[] altTab(int input1, int input2, int[] input3)
    {
        if(input2<=0)
            return input3;

        int n = input2 % input1;

        if(n==0)
            n = input1;

        int ele = input3[n-1];
        for(int i=n-1; i>=1; i--)
        {
            input3[i] = input3[i-1];
        }
        input3[0] = ele;

        return input3;
    }
}


