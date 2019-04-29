#include <iostream>
using namespace std;
#define N 4
class matrix
{
private:
  int**p;
  int rows;
  int cols;
public:
  matrix();
  matrix(int*m,int r,int c);
  matrix(int r,int c);
  int get(int r,int c);
  matrix multiply(matrix m);//assuming that conditiopn for multiply is satisfied
  void adjoint(matrix m,int d);
  int determinant(matrix m,int k);
  void getCoFactor(matrix& m(N,N),matrix& n(N,N),int a,int b,int c);
  void setRows(int r);
  void setCols(int c);
  int getRows();
  int getCols();
  void make();
  void initialize();
  void initialize(int*m);
  void print();
  ~matrix();
};
matrix::matrix()
{
  setRows(5);
  setCols(5);
  make();
  initialize();
}
matrix::matrix(int*m,int r,int c)
{
  setRows(r);
  setCols(c);
  make();
  initialize(m);
}
matrix::matrix(int r,int c)
{
  setRows(r);
  setCols(c);
  make();
  initialize();
}
int matrix::get(int r,int c)
{
  return p[r-1][c-1];
}
matrix matrix::multiply(matrix m)
{
  //creating a new matrix for result
  // cout<<"Printing result matrix"<<endl;
  matrix result(rows,m.cols);
  //result.print();
  // cout<<"Ending printing result matrix"<<endl;
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<m.cols;j++)
    {
      for(int k=0;k<cols;k++)
      {
        result.p[i][j]+=this->p[i][k]*m.p[k][j];
        // cout<<"m.p[i][k]:"<<m.p[i][k]<<endl;
        // cout<<"this->p[i][k]"<<this->p[i][k]<<endl;
        // cout<<"i,j"<<i<<":"<<j<<":"<<result.p[i][j]<<endl;
      }
    }
  }
  result.print();
}
void matrix::getCoFactor(matrix& m(N,N),matrix& n(N,N),int a,int b,int c)
{
  int i=0;
  int j=0;
  for(int row=0;row<c;row++)
  {
    for(int col=0;col<c;col++)
    {
      if(row!=a&&col!=b)
      {
        n.p[i][j++] = m.p[row][col];
        if(j==c-1)
        {
          i++;
          j=0;
        }
      }
    }
  }
}
int matrix::determinant(matrix m,int k)
{
  if(k==1)
  {
    return m.p[0][0];
  }
  matrix temp(N,N);
  int sign = 1;
  int det = 0;
  for(int i=0;i<k;i++)
  {
    getCoFactor(m,temp,0,i,k);
    det+=sign*m.p[0][i]*determinant(temp,k-1);
    cout<<det<<endl;
    sign = -sign;
  }
  return det;
}
void adjoint(matrix m,int d)
{
  matrix temp//to stroe the cofactor values
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      getCoFactor(m,temp,i,j,d);
      m.p[j][i] = determinant(temp,d);
    }
  }
}
void matrix::setRows(int r)
{
  rows = r;
}
void matrix::setCols(int c)
{
  cols = c;
}
int matrix::getRows()
{
  return rows;
}
int matrix::getCols()
{
  return cols;
}
void matrix::make()
{
  p = new int*[rows];
  for(int i=0;i<rows;i++)
  {
    p[i] = new int[cols];
  }
}
void matrix::initialize()
{
  //initializing every element to zero
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      p[i][j]=0;
    }
  }
}
void matrix::initialize(int*m)
{
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      p[i][j] = *(m+i*cols+j);
    }
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
matrix::~matrix()
{
  for(int i=0;i<cols;i++)
  {
    delete []p[i];
  }
  delete[]p;
}
void Test_multiply()
{
  int array[2][2]={{1,2},{3,4}};
  int*p = &array[0][0];
  matrix m1(p,2,2);
  int array2[2][2] = {{5,6},{7,8}};
  int *m = &array2[0][0];
  matrix p1(m,2,2);
  matrix result(2,2);
  m1.multiply(p1);
  //result.print();
}
void Test_get()
{
  int rows = 4;
  int cols = 4;
  int array[rows][cols];
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      array[i][j] = i*j;
    }
  }
  int*p = &array[0][0];
  matrix m(p,rows,cols);
  m.print();
  cout<<m.get(2,2)<<endl;
  cout<<m.get(1,1)<<endl;
  cout<<m.get(2,4)<<endl;
}
void Test_default()
{
  matrix m1;
  m1.print();
  int rows=6;
  int cols=6;
  int array[rows][cols];
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++)
    {
      array[i][j] = 5;
    }
  }
  int *p = &array[0][0];
  matrix m2(p,rows,cols);
  m2.print();
  matrix m3(4,4);
  m3.print();
}
void Test_Det()
{
  int rows=2;
  int cols=2;
  int array[N][N];
  int k=1;
  for(int i=0;i<rows;i++)
  {
    for(int j=0;j<cols;j++,k++)
    {
      array[i][j]=k;
      cout<<array[i][j]<<" ";
    }
    cout<<endl;
  }
  int*p = &array[0][0];
  matrix m(p,N,N);
  m.print();
  cout<<m.determinant(m,2)<<endl;

}

int main()
{
   // Test_default();
   // Test_get();
   // Test_multiply();
   Test_Det();
  return 0;
}
