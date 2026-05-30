#include<iostream>
#include<vector>
using namespace std;

void checkheap(vector<int> &heap)
{
    int i =heap.size()-1;
    while(i>0)
    {
        if(heap[i/2]<heap[i])
        {
            swap(heap[i/2] , heap[i]);
        }
        i=i/2;
    }
}

int main()
{
    int n;
    cin>>n;

    vector<int> heap(n);

    int element;

    for(int i =0;i<n;i++)
    {
        cin>>element;
        heap[i]=element;
        checkheap(heap);
    }

    for(int i =0;i<n;i++)
    cout<<heap[i]<<" ";

    return 0;
}