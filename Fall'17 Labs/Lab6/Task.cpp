//set class implemented using dynamic arrays
//all functions work
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class set
{
private:
  int*p;
  int size;
  int current_capacity;
public:
  set();
  set(int array[],int s);
  void add(int e);
  void remove(int e);
  void shuffle();
  bool check_equal(set s);
  int getElement(int index);
  void print();
  bool find(int e);
  int getCurrentCap();
  ~set();
};
set::set()
{
  size = 5;
  current_capacity = 0;
  p = new int[size];
}
set::set(int array[],int s)
{
  size = s;
  current_capacity = 0;
  p = new int[size];
  for(int i=0,j=0;i<size;i++)
  {
    //cout<<"Iterating for:"<<array[i]<<endl;
    if(!find(array[i]))
    {
      //cout<<"I entered the conditional for"<<array[i]<<endl;
      p[j] = array[i];
      j++;
      current_capacity++;
    }
  }
}
void set::add(int e)
{
  if(current_capacity!=size)
  {
    if(!find(e))
    {
      p[current_capacity] = e;
      current_capacity++;
    }
  }
  else
  {
    cout<<"Cannot add any more element:"<<endl;
    cout<<"Cap:"<<current_capacity<<endl;
    cout<<"Size:"<<size<<endl;
  }
}
void set::remove(int e)
{
  if(find(e))
  {
    for(int i=0;i<current_capacity;i++)
    {
      if(p[i]==e)
      {

        for(int j = i;j<current_capacity-1;j++)
        {
          p[j] = p[j+1];
        }
      }
    }
  current_capacity--;
  }
  else
  {
    cout<<"Element not in the set to remove"<<endl;
  }
}
void set::shuffle()
{
  srand(time(0));
  for(int i=0;i<current_capacity;i++)
  {
    //same rand()%(max-min+1)+min
    int j = rand()%(current_capacity+1);
    int temp = p[i];
    p[i] = p[j];
    p[j] = temp;
  }
}
bool set::check_equal(set s)
{
  if(current_capacity!=s.getCurrentCap())
  {
    return false;
  }
  for(int i=0;i<current_capacity;i++)
  {
    if(!find(s.p[i]))
    {
      return false;
    }
  }
  return true;
}
int set::getElement(int index)
{
  if(index>current_capacity-1||index<0)
  {
    cout<<"Invalid index send."<<endl;
    cout<<"Returning -1 from function"<<endl;
    return -1;
  }
  return p[index];

}
void set::print()
{
  for(int i=0;i<current_capacity;i++)
  {
    cout<<p[i]<<endl;
  }
}
bool set::find(int e)
{
  for(int i=0;i<current_capacity;i++)
  {
    if(p[i]==e)
    {
       //cout<<"Searched"<<p[i]<<endl;
      return true;
    }
  }
  return false;
}
int set::getCurrentCap()
{
  return current_capacity;
}
set::~set()
{
  delete []p;
}

void Test_remove()
{
  int array[9]={4,3,4,9,8,0,1,5,1};
  set s(array,9);
  s.print();
  s.remove(4);
  cout<<endl;
  s.print();
  cout<<endl;
  s.remove(8);
  s.print();
  cout<<endl;
  s.remove(5);
  s.print();
  s.remove(99);
}
void Test_shuffle()
{
  int array[9]={4,3,4,9,8,0,1,5,1};
  set s(array,9);
  s.print();
  s.shuffle();
  cout<<endl;
  s.print();
}
void test_checkEqual()
{
  int array[5] = {1,2,3,4,5};
  int array2[5] = {5,3,1,2,4};
  set s1(array,5);
  set s2(array2,5);
  cout<<s1.check_equal(s2)<<endl;
}
void test_getelement()
{
  int array[5] = {1,2,3,4,5};
  set s1(array,5);
  cout<<s1.getElement(-1)<<endl;
  cout<<s1.getElement(5)<<endl;
  cout<<s1.getElement(4)<<endl;
  cout<<s1.getElement(2)<<endl;
  cout<<s1.getElement(100)<<endl;

}
int main()
{
  test_getelement();
  return 0;
}
