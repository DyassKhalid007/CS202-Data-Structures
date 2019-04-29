#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
//bubble sort
void bubble_sort(int array[],int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size-i;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
            }
        }
    }
}
//quick sort
void split(int array[],int first,int last,int &pos)
{
    int left = first;
    int right = last;
    int pivot = array[left];
    while(left<right)
    {
        while(array[right]>pivot)
        {
            right--;
        }
        while(left<right&&array[left]<=pivot)
        {
            left++;
        }
        if(left<right)
        {
            swap(array[left],array[right]);
        }
    }
    pos = left;
    array[first] = array[pos];
    array[pos] = pivot;
}
void quick_sort(int array[],int first,int last)
{
    int pos;
    if(first<last)
    {
        split(array,first,last,pos);
        quick_sort(array,first,pos-1);
        quick_sort(array,pos+1,last);
    }
}
//insertion sort
void insertion_sort(int array[],int size)
{
    for(int i=1;i<size;i++)
    {
        int j = i;
        while(j>0&&array[j]>array[j-1])
        {
            int temp = array[j-1];
            array[j-1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}
//shell sort
void shell_sort(int array[],int size)
{
    for(int gap=size/2;gap>0;gap=gap/2)
    {
        for(int i=gap;i<size;i++)
        {
            int j = i;
            while(array[j]<array[j-gap]&&(j-gap)>=0)
            {
                swap(array[j],array[j-gap]);
                j-=gap;
            }
        }
    }
}
//merge sort
void mergeElement(int x[],int start1,int end1,int start2,int end2)
{
    int size = end2-start1+1;
    int i = start1;
    int j = start2;
    int count=0;
    int *y = new int[size];
    while(i<=end1&&j<=end2)
    {
        if(x[i]>=x[j])
        {
            y[count++]=x[i++];
        }
        else
        {
            y[count++]=x[j++];
        }
    }
    while(i<=end1)
    {
        y[count++]=x[i++];
    }
    while(j<=end2)
    {
        y[count++]=x[j++];
    }
    for(int m=0;m<count;m++)
    {
        x[start1+m] = y[m];
    }
    delete []y;
}
void mergeSort(int x[],int first,int last)
{
    if(first<last)
    {
        int middle = (first+last)/2;
        mergeSort(x,first,middle);
        mergeSort(x,middle+1,last);
        mergeElement(x,first,middle,middle+1,last);
    }
}
struct myPair{
	int x;
	int y;
};

bool isLess(myPair* p1, myPair *p2){
	return (p1->x > p2->x) ? false : true;
}


bool isLessY(myPair* p1, myPair *p2){
	return (p1->y > p2->y) ? false : true;
}


template <class T>
void  func(T p1, T p2,  bool (*isLess)(T,T) ) {
	if (isLess(p1,p2))
	{
		cout << "myPair 1 is smaller" << endl;
	} else {
		cout << "myPair 2 is smaller" << endl;
	}
}


//int main() {
//	myPair *p1 = new myPair;
//	myPair* p2 = new myPair;
//
//	p1->x = 1;
//	p2->x = 2;
//	p1->y = 4;
//	p2->y = -1;
//	func(p1,p2,isLess);
//	func(p1,p2,isLessY);
//}

int main()
{
    int size = 10;
    int array[size];
    srand(time(0));
    for(int i=0;i<size;i++)
    {
        array[i] = rand();
    }
    //mergeSort(array,0,size-1);
    //cout<<"After sorting algorithm:"<<endl;
    mergeSort(array,0,size-1);
    for(int i=0;i<size;i++)
    {
        cout<<array[i]<<endl;
    }
}

