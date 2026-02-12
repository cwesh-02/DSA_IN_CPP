#include<iostream>
#include<vector>
using namespace std;

void InsertHeap(vector<int> &MaxHeap)
{
    int index = MaxHeap.size()-1; //last eleemnt
    int parent;
    while(index>0)
    {
        parent = (index-1)/2;
        if(MaxHeap[index]>MaxHeap[parent])
        {
            int temp = MaxHeap[index];
            MaxHeap[index] = MaxHeap[parent];
            MaxHeap[parent]=temp;
            index=parent;
        }
        else break;
    }
}

int main()
{
    vector<int> MaxHeap;
    int n;
    cin>>n;
    int element;
    for(int i=0;i<n;i++)
    {
        cin>>element;
        MaxHeap.push_back(element);
        InsertHeap(MaxHeap);
    }

    for(int i=0;i<MaxHeap.size();i++)
    {
        cout<<MaxHeap[i];
    }
    return 0;
}