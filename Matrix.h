/*README FILE
  default matrix 3x3
  can be invoked using matrix1 m1(2,2),m2,m3(4,4);
  addition(m3=m1+m2)
  subtraction(m3=m1-m2)
  multiplication(m3=m1*m2)
  scalar multiplication(m3=m1*5)
  addition compatibility(addcomp(m1,m2) ----- returns boolean value)
  multiplication compatibility(multcomp(m1,m2) ----- returns boolean value)
  input(cin>>m1)
  output(cout<<m1)
  transpose(m2=transpose(m1))
  cofactor(m2=cofactor(m1,0,0)  ----- returns a cofactor matrix of element (0,0) of m1)
  determinant(x=determinant(m1) ----- returns a float value)
  adjoint(m2=adjoint(m1) ----- transpose of cofactor value of every element in matrix,the cofactor value wll have alternating signs(+ve,-ve))
  inverse(m2=inverse(m1) ----- inverse(m1)=adjoint(m1)/det(m1))


  */










// #include<iostream>
using namespace std;
class matrix1
{
    float **p;
    int r,c;
    public:
        matrix1()
        {
            r=3;
            c=3;
            p=new float*[r];
            for(int i=0;i<r;i++)
                p[i]=new float[c];
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                    p[i][j]=0;
            }
        }
        matrix1(int m,int n)
        {
            r=m;
            c=n;
            p=new float*[r];
            for(int i=0;i<m;i++)
                p[i]=new float[c];
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    p[i][j]=0;
            }

        }

        matrix1 operator +(matrix1 m)
        {
            matrix1 res;
            res.r=r;
            res.c=c;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                    res.p[i][j]=p[i][j]+m.p[i][j];
            }
            return res;

        }

        matrix1 operator -(matrix1 m)
        {
            matrix1 res;
            res.r=m.r;
            res.c=m.c;
            for(int i=0;i<m.r;i++)
            {
                for(int j=0;j<m.c;j++)
                    res.p[i][j]=p[i][j]-m.p[i][j];
            }
            return res;

        }

        matrix1 operator *(matrix1 m1)
        {
            matrix1 res;
            res.r=m1.r;
            res.c=m1.c;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    res.p[i][j]=0;
                    for(int k=0;k<r;k++)
                    {
                        res.p[i][j]=res.p[i][j]+(p[i][k] * m1.p[k][j]); 

                    }
                }
            }
            return res;
        }

        matrix1 operator *(int x)
        {
            matrix1 res;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    res.p[i][j]=p[i][j]*x;
                }
            }
            return res;
        }

        

        friend bool addcomp(matrix1 m1,matrix1 m2);
        friend bool multcomp(matrix1 m1,matrix1 m2);
        friend istream & operator >>(istream &x,matrix1 &m);
        friend ostream & operator <<(ostream &x,matrix1 &m);
        friend matrix1 transpose(matrix1 m);
        friend matrix1 cofactor(matrix1 m,int x,int y);
        friend float determinant(matrix1 m);
        friend matrix1 adjoint(matrix1 m);
        friend matrix1 inverse(matrix1 m);

};

istream & operator >>(istream &x,matrix1 &m)
{
    for(int i=0;i<m.r;i++)
    {
        for(int j=0;j<m.c;j++)
            x>>m.p[i][j];
    }
    return x;

}

ostream& operator <<(ostream &x,matrix1 &m)
{
    for(int i=0;i<m.r;i++)
    {
        for(int j=0;j<m.c;j++)
            cout<<m.p[i][j]<<"\t";
        cout<<"\n";
    }
    return x;
}

bool addcomp(matrix1 m1,matrix1 m2)
{
    if(m1.r==m2.r && m1.c==m2.c)
        return 1;
    else
        return 0;
}

bool multcomp(matrix1 m1,matrix1 m2)
{
    if(m1.r==m2.c || m1.c==m2.r)
        return 1;
    else
        return 0;
}

matrix1 transpose(matrix1 m)
{
    matrix1 res;
    res.r=m.r;
    res.c=m.c;
    for(int i=0;i<m.r;i++)
    {
        for(int j=0;j<m.c;j++)
            res.p[i][j]=m.p[j][i];
    }
    return res;

}

matrix1 cofactor(matrix1 m,int x,int y)
{
    matrix1 res;
    res.r=m.r-1;
    res.c=m.c-1;
    int row=0,col=0;
    for(int i=0;i<m.r;i++)
    {
        for(int j=0;j<m.c;j++)
        {
            if(i!=x && j!=y)
            {
                res.p[row][col++]=m.p[i][j];

                if(col==m.c-1)
                {
                    col=0;
                    row++;
                }
            }
        }
    }
    return res;

}

float determinant(matrix1 m)
{
    float res=0;
    if(m.r==1 && m.c==1)
        return m.p[0][0];
    else if(m.r==2 && m.c==2)
        return ((m.p[0][0]*m.p[1][1])-(m.p[0][1]*m.p[1][0]));
    else
    {
        int sign=1;
        for(int i=0;i<m.r;i++)
        {
            matrix1 cofac=cofactor(m,0,i);
            res=res+((sign)*(m.p[0][i])*(determinant(cofac)));
            sign=-sign;
        }
    }
    return res;
}

matrix1 adjoint(matrix1 m)
{
    matrix1 res1,res2;
    res1.r=m.r;
    res1.c=m.c;
    res2.r=m.r;
    res2.c=m.c;
    float sign=1;
    if(res1.r==2)
    {
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<2;j++)
                res1.p[i][j]=m.p[i][j];
        }
        float temp1,temp2;
        temp1=res1.p[0][0];
        res1.p[0][0]=res1.p[1][1];
        res1.p[1][1]=temp1;

        res1.p[0][1]=-res1.p[0][1];
        res1.p[1][0]=-res1.p[1][0];

        return res1;

    }
    else
    {
        for(int i=0;i<m.r;i++)
        {
            for(int j=0;j<m.c;j++)
            {
                matrix1 cofac=cofactor(m,i,j);
                res1.p[i][j]=sign*determinant(cofac);
                sign=-sign;
            }
        }
        res2=transpose(res1);
        return res2;
    }
}

matrix1 inverse(matrix1 m)
{
    matrix1 res1,adj;
    res1.r=m.r;
    res1.c=m.c;
    adj.r=m.r;
    adj.c=m.c;
    adj=adjoint(m);
    float det=determinant(m);
    for(int i=0;i<m.r;i++)
    {
        for(int j=0;j<m.c;j++)
        {
            res1.p[i][j]=(adj.p[i][j])/(det);
        }
    }
    return res1;

}

// int main()
// {
//     matrix1 m1(2,2),m2(2,2),m3;
//     cin>>m1;  
//     m2=inverse(m1);
//     cout<<m2;   
//     return 0;
// }


