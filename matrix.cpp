#include<iostream>
#include<stdlib.h>
#include<process.h>

using namespace std;

template<class X> class ETMatrix
{
	int row;
	int column;
	X* Matrix;
	public:
		friend istream &operator>>(istream& input,ETMatrix &m)
		{
			cout<<"Enter Row:";
			cin>>m.row;
			cout<<"Enter Column:";
			cin>>m.column;
			m.Matrix=new X[m.row*m.column];
			cout<<"Enter Matrix:\n";
			for(int row=0;row<m.row;row++)
			{
				for(int column=0;column<m.column;column++)
				{
				   cin>>*(m.Matrix + row * m.column + column);
				}
			}
			return input;
		}	
		friend ostream &operator<<(ostream& output,ETMatrix &m)
		{
			for(int row=0;row<m.row;row++)
		    {
		    	for(int column=0;column<m.column;column++)
		    	{
		    		cout<<*(m.Matrix + row * m.column + column)<<" ";
				}
				cout<<"\n";
			}
			return output;
		}
		ETMatrix operator+(ETMatrix &m)
		{
			if(row!=m.row || column!=m.column)
			{
				cout<<"Dimensions aren't equal!";
				exit(0);
			}
			ETMatrix <X>temp;
			temp.row=row;
			temp.column=column;
			temp.Matrix=new X[row*column];
			for(int frow=0;frow<m.row;frow++)
			{
				for(int fcolumn=0;fcolumn<m.column;fcolumn++)
				{
				   *(temp.Matrix + frow *column + fcolumn)=*(Matrix + frow*column + fcolumn)+ *(m.Matrix+ frow*column+fcolumn);
				}
			}
			return temp;
		}
		~ETMatrix()
		{
			delete Matrix;
		}
};

int main()
{
	ETMatrix <int>first;
	ETMatrix <int>result;
	cin>>first;
	result=first+first;
	cout<<result;
}
