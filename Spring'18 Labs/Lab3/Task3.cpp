//matrix class including multiplication
#include <iostream>
using namespace std;

class matrix
{
private:
  int **p;
  int rows;
  int cols;
public:
  matrix();
  matrix(int*m,int r,int c);
  int getElement(int r,int c);
  void multiply(matrix n);
  void print();
  int getCols();
  int getRows();
  ~matrix();
};
matrix::matrix()
{
  rows = 5;
  cols = 5;
  p = new int*[rows];
  for(int i=0;i<rows;i++)
  {
    p[i] = new int[cols];
  }
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      p[i][j] = 0;
    }
  }
}
matrix::matrix(int*m,int r,int c)
{
  rows = r;
  cols = c;
  cout<<"Rows:"<<rows<<endl;
  cout<<"Cols:"<<cols<<endl;
  cout<<cols<<endl;
  p = new int*[rows];
  for(int i=0;i<rows;i++)
  {
    p[i] = new int[cols];
  }
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      p[i][j] = *(m+i*cols+j);
    }
  }
}
int matrix::getElement(int r,int c)
{
  return p[r][c];
}
void matrix::multiply(matrix m)
{
  if(this->cols==m.rows)
  {
    int array[rows][m.getCols()];
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<m.getCols();j++)
      {
        array[i][j] = 0;
      }
    }
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<m.getCols();j++)
      {
        for(int k=0;k<cols;k++)
        {
          array[i][j]+=p[i][k]*m.p[k][j];
        }
      }
    }
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<m.getCols();j++)
      {
        cout<<array[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  else
  {
    cout<<"Matrix are not suitable for multiplication"<<endl;
  }

}

void matrix::print()
{
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      cout<<p[i][j]<<" ";
    }
    cout<<endl;
  }
}
int matrix::getRows()
{
  return rows;
}
int matrix::getCols()
{
  return cols;
}
matrix::~matrix()
{
  for(int i=0;i<cols;i++)
  {
    delete []p[i];
  }
  delete []p;
}
void Test_Matrix_default()
{
  matrix m;
  m.print();

}
void Test_Matrix_parameterized()
{
  int rows = 5;
  int cols = 5;
  int array[5][5];
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      array[i][j] = i*j;
    }
  }
  int *p = &array[0][0];
  matrix m(p,rows,cols);
  m.print();
  rows=5;
  cols=4;
  int array2[rows][cols];
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      array2[i][j]=1;
    }
  }
  int*pp=&array2[0][0];
  matrix m2(pp,rows,cols);
  m2.print();
  m2.multiply(m);
}
int main()
{
  Test_Matrix_parameterized();
}
