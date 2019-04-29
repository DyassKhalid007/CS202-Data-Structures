//bracket matching using stack
#include "stack.h"
#include <vector>
#include <string>
bool BMatching(string v);
int main()
{
  cout<<"Please enter your parenthetical expression:";
  string expression;
  cin>>expression;
  //Now printing for check that the expression is entered correctly
  bool result=BMatching(expression);
  cout<<"Brackets are stable:"<<result<<endl;
}
bool BMatching(string v)
{
  stack s;
  for(int i=0;i<v.length();i++)
  {

    if(v[i]=='['||v[i]=='{'||v[i]=='(')
    {
      string p(1,v[i]);
      // cout<<"I ented first condition:"<<v[i]<<endl;
      // cout<<"Pusing into stack:"<<p<<endl;
      s.push(p);
    }
    else if(v[i]==']'||v[i]=='}'||v[i]==')')
    {
      // cout<<"I ented second condition:"<<v[i]<<endl;
      // cout<<"s.top():"<<s.top()<<endl;
      if(s.isEmpty())
      {
        return false;
      }
      if(s.top()=="("&&v[i]==')')
      {
        // cout<<"I entered the second first:"<<endl;

        //cout<<"Top:"<<s.top()<<endl;
        s.pop();
      }
      else if(s.top()=="["&&v[i]==']')
      {
        // cout<<"I entered the second first:"<<endl;
        //cout<<"Top:"<<s.top()<<endl;
        s.pop();
      }
      else if(s.top()=="{"&&v[i]=='}')
      {
        // cout<<"I entered the second first:"<<endl;
        // cout<<"Top:"<<s.top()<<endl;
        s.pop();
      }
    }
  }
  // s.print();
  return s.isEmpty();
}
