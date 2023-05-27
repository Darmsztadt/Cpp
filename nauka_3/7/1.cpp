#include <iostream>
using namespace std;

int iterate(int tab[],int left,int right, int find)
{
    int x=left;
    int y=right;
    for (int i = 0; i < right; i++)
    {
        int mid=(x+y)/2;
        if(mid==find)return i;
        else if(find>mid)x=mid+1;
        else if(find<mid)y=mid-1;
        else return right+1;
    }

}

int main()
{
    int size = 6;
    int tab[] = {11, 13, 8, 1, 15, 6};
    int find;
    cin>>find;
    int result=iterate(tab,0,size-1,find);
    if(result==size)cout<<"\nNie znaleziono liczby";
    else cout<<"\nIndeks szukanej liczby to: "<<result;
}