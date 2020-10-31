#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	long long int n,ele;
    cin>>n;
    vector<long long int> vec;
    for(int i=0;i<n;i++)
    {
        cin>>ele;
        auto it = upper_bound(vec.begin(),vec.end(),ele);
        if(it == vec.end())
            vec.push_back(ele);
        else
            *it=ele;

    }
    cout<<vec.size()<<"\n";
	return 0;
}
