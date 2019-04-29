#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//Rule of thumb: Use only srand(time(NULL)) only once for seeding
class Tool
{
private:
  int strength;
  char type;
public:
  Tool();
  Tool(int s,char t);
  void setStrength(int s);
  void setType(char t);
  int getStrength();
  char getType();
  virtual bool fight(Tool*t);
};
Tool::Tool()
{
  // cout<<"Deafult:Tool"<<endl;
  strength = 1;
  type = 'r';
}
Tool::Tool(int s,char t)
{
  // cout<<"Parameterized:Tool"<<endl;
  if(t=='r'||t=='p'||t=='s')
  {
    strength = s;
    type = t;
  }
}
void Tool::setStrength(int s)
{
  strength = s;
}
void Tool::setType(char t)
{
  type = t;
}
int Tool::getStrength()
{
  return strength;
}
char Tool::getType()
{
  return type;
}
bool Tool::fight(Tool*t)
{

}
class Rock:public Tool
{
public:
  Rock();
  Rock(int s);
  bool fight(Tool* t);
};
Rock::Rock()
{
  setType('r');
  setStrength(1);
}
Rock::Rock(int s):Tool(s,'r')
{

}
bool Rock::fight(Tool* t)
{
  if(t->getType()=='r')
  {
    if(t->getStrength()>getStrength())
    {
      return 0;
    }
    return 1; //even if strength is equal this object wins
  }
  else if(t->getType()=='p')
  {
    if(t->getStrength()>getStrength()/2)
    {
      return 0;
    }
    return 1;//even if strength is equal this object wins
  }
  else if(t->getType()=='s')
  {
    if(t->getStrength()>getStrength()*2)
    {
      return 0;
    }
    return 1;
  }
  //if none of the above is satisfied returning 0
  return 0;
}
class Paper:public Tool
{
public:
  Paper();
  Paper(int s);
  bool fight(Tool* t);
};
Paper::Paper()
{
  setType('p');
}
Paper::Paper(int s):Tool(s,'p')
{

}
bool Paper::fight(Tool* t)
{
  if(t->getType()=='p')
  {
    if(t->getStrength()>getStrength())
    {
      return 0;
    }
    return 1;
  }
  else if(t->getType()=='r')
  {
    if(t->getStrength()>getStrength()*2)
    {
      return 0;
    }
    return 1;
  }
  else if(t->getType()=='s')
  {
    if(t->getStrength()>getStrength()/2)
    {
      return 0;
    }
    return 1;
  }
  return 0;
}
class Scissor:public Tool
{
public:
  Scissor();
  Scissor(int s);
  bool fight(Tool* t);
};
Scissor::Scissor()
{
  // cout<<"Deafult:Scissor"<<endl;
  setType('s');
}
Scissor::Scissor(int s):Tool(s,'s')
{
  // cout<<"Parameterized:Scissor"<<endl;
  // setType('s');
  // setStrength(sic);
}
bool Scissor::fight(Tool* t)
{
  if(t->getType()=='s')
  {
    if(t->getStrength()>getStrength())
    {
      return 0;
    }
    return 1;
  }
  else if(t->getType()=='p')
  {
    if(t->getStrength()>getStrength()*2)
    {
      return 0;
    }
    return 1;
  }
  else if(t->getType()=='r')
  {
    if(t->getStrength()>getStrength()/2)
    {
      return 0;
    }
    return 1;
  }
  return 0;
}
class RPSPlay
{
private:
  Tool*comp;
  Tool*hum;
  int human_wins;
  int compputer_wins;
  //no ties due to bool function
public:
  RPSPlay();
  void play();
};
RPSPlay::RPSPlay()
{
  human_wins = 0;
  compputer_wins = 0;
}
void RPSPlay::play()
{
  int chose_comp = 0;
  int chose_hum = 0;
  int max=3;
  int min = 1;
  chose_comp = rand()%(max-min+1)+min;
  chose_hum = rand()%(max-min+1)+min;
  if(chose_comp==1)
  {
    cout<<"Rock is selected for computer:"<<endl;
    cout<<"Default strength is 5:"<<endl;
    Rock R(5);
    comp = &R;
  }
  else if(chose_comp==2)
  {
    cout<<"Paper is selected for computer:"<<endl;
    cout<<"Default strength is 5:"<<endl;
    Paper P(5);
    comp = &P;
  }
  else if(chose_comp==3)
  {
    cout<<"Scissor is selected for computer:"<<endl;
    cout<<"Default strength is 5:"<<endl;
    Scissor S(5);
    comp = &S;
  }
  if(chose_hum==1)
  {
    cout<<"Rock is selected for computer:"<<endl;
    cout<<"Default strength is 5:"<<endl;
    Rock R2(5);
    hum = &R2;
  }
  else if(chose_hum==2)
  {
    cout<<"Paper is selected for computer:"<<endl;
    cout<<"Default strength is 5:"<<endl;
    Paper P2(5);
    hum = &P2;
  }
  else if(chose_hum==3)
  {
    cout<<"Scissor is selected for computer:"<<endl;
    cout<<"Default strength is 5:"<<endl;
    Scissor S2(5);
    hum = &S2;
  }
  bool result = hum->fight(comp);
  if(result)
  {
    human_wins++;
  }
  else
  {
    compputer_wins++;
  }
  cout<<"Human Wins:"<<human_wins<<endl;
  cout<<"Computer Wins:"<<compputer_wins<<endl;
}
void Test()
{
  Tool*S = new Scissor(5);
  cout<<S->getType()<<":"<<S->getStrength()<<endl;
  Tool*P=new Paper(7);
  cout<<P->getType()<<":"<<P->getStrength()<<endl;
  Tool*R = new Rock(15);
  cout<<R->getType()<<":"<<R->getStrength()<<endl;
  delete S;
  delete P;
  delete R;
}
void Test_RPSPlay()
{
  //Rule of thumb: Use random number seed only once.
  srand(time(NULL));
    RPSPlay R;
    R.play();
    R.play();
    R.play();
    R.play();
    R.play();
}
int main()
{
  Test();
  // Test_RPSPlay();
  return 0;
}
