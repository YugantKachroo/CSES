#include <bits/stdc++.h>
#include <iostream>
using namespace std;
long long int getmid(long long int ss, long long int se)
{
    return ss+(se-ss)/2;
}
long long int minval(long long int x, long long int y)
{
    return (x<y)?x:y;
}
long long int getxorutil(long long int *st, long long int ss, long long int se, long long int qs, long long int qe, long long int si)
{
    if(qs<=ss && qe>=se)
    {
        return st[si];
    }
    if(qs>se || qe<ss)
    {
        return 0;
    }
    long long int mid = getmid(ss,se);
    return getxorutil(st,ss,mid,qs,qe,2*si+1) ^ getxorutil(st,mid+1,se,qs,qe,2*si+2);
}

long long int getxor(long long int *st, long long int n, long long int qs, long long int qe)
{
    if(qs<0 || qe>n-1 || qs>qe)
    {
        return -1;
    }
    return getxorutil(st,0,n-1,qs,qe,0);
}
long long int constructutil(long long int a[], long long int ss, long long int se, long long int *st, long long int si)
{
    if(se==ss)
    {
        st[si]=a[ss];
        return a[ss];
    }
    long long int mid=getmid(ss,se);
    st[si]=(constructutil(a,ss,mid,st,2*si+1) ^ constructutil(a,mid+1,se,st,2*si+2));
    return st[si];
}
long long int *construct(long long int a[], long long int n)
{
    long long int x = (long long int)(ceil(log2(n)));
    long long int maxi = 2*(long long int)pow(2,x)-1;
    long long int *st = new long long int[maxi];
    constructutil(a,0,n-1,st,0);
    return st;
}

int main()
{
	long long int n,q;
    cin>>n>>q;
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    long long int *st=construct(a,n);
    while(q--)
    {
       long long int x,y;
        cin>>x>>y;
        x--;
        y--;
        cout<<getxor(st,n,x,y)<<"\n";

    }
	return 0;
}
