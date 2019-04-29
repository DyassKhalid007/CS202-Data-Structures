#include <iostream>
#include <vector>
using namespace std;

template<class t>
class set
{
private:
  vector<t>v;
public:
  set();
  void add(t item);
  void remove(t item);
  int size();
  bool isMember(t item);
  void print();
};
template<class t>
set<t>::set()
{

}
template<class t>
void set<t>::add(t item)
{
  bool find = false;
  typename std::vector<t>::iterator p;
  for(p=v.begin();p!=v.end();p++)
  {
    if(*p==item)
    {
      find = true;
    }
  }
  if(!find)
  {
    v.push_back(item);
  }
}
template<class t>
void set<t>::remove(t item)
{
  for(int i=0;i<v.size();i++)
  {
    if(v[i]==item)
    {
      v.erase(v.begin()+i);
    }
  }

}
template<class t>
int set<t>::size()
{
  return v.size();
}
template<class t>
bool set<t>::isMember(t item)
{
  typename std::vector<t>::iterator p;
  for(p=v.begin();p!=v.end();p++)
  {
    if(*p==item)
    {
      return true;
    }
  }
  return false;
}
template<class t>
void set<t>::print()
{
  typename std::vector<t>::iterator p;
  for(p=v.begin();p!=v.end();p++)
  {
    cout<<*p<<endl;
  }
}
void Test()
{
  set<int> s;
  s.add(5);
  s.add(9);
  s.add(5);//check for duplicate
  s.add(9);//check for duplicate
  s.remove(1);
  s.remove(9);
  // s.remove(5);
  s.print();
  cout<<s.size()<<endl;
  cout<<s.isMember(11)<<endl;
  cout<<s.isMember(5)<<endl;

}
int main()
{
  Test();
  return 0;
}
