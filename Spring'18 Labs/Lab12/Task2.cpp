#include <iostream>
#include <map>
using namespace std;

class student
{
private:
  map<int,string>m;
public:
  student();
  void insert(int key,string val);
  void remove(int key);
  void check(string val);
  void print();
};
student::student()
{

}
void student::insert(int key,string val)
{
  m.insert(pair<int,string>(key,val));
}
void student::remove(int key)
{
  std::map<int, string>::iterator p;
  p = m.find(key);
  if(p!=m.end())
  {
    m.erase(p);
  }
  else
  {
    cout<<"Key not found"<<endl;
  }
}
void student::check(string val)
{
  std::map<int, string>::iterator p;
  for(p=m.begin();p!=m.end();p++)
  {
    if(p->second==val)
    {
      cout<<"Key"<<p->first<<endl;
      cout<<"Value"<<p->second<<endl;
    }
  }
}
void student::print()
{
  std::map<int, string>::iterator p;
  for(p=m.begin();p!=m.end();p++)
  {
    cout<<p->first<<":"<<p->second<<endl;
  }

}
void Test()
{
  student s;
  s.insert(1,"DK");
  s.insert(2,"YK");
  s.insert(3,"PK");
  s.remove(100);
  s.remove(1);
  s.print();
  s.check("YK");
  s.check("DK");

}
int main()
{
  Test();
  return 0;
}
