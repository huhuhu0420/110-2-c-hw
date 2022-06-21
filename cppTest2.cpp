#include<iostream>                  
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int n;
void two_bit(int r[100],int p[1000]) 
{
	int i=n-1,j=0,c=n;
	while(r[j]>=0)
	{	
		while(c!=0)
		{
			p[i]=r[j]%2;
			r[j]=r[j]/2;
			i=i-1;
			c=c-1;	
		}
		i=i+(2*n);
		j=j+1;
		c=n;
	}
	i=i-n+1;
	p[i]=-1;
}
//------------------------------------------------------------
void no_part(int no[100],int y[100])
{
	int i=0,j=0,k;
	while(y[i]>=0)
	{
		for(j=0;no[j]>=0;j++)
			if(no[j]==y[i])
			{
				for(k=j;no[k-1]>=0;k++)
					no[k]=no[k+1];
				no[k]=0;
			}
		i=i+1;
	} 
}
//------------------------------------------------------------
void ch_num(string str,int s[100])
{
	int i=0,j=0,k=0,c=0,d=n-1,a='a';
	while(str[i]!='\0')
	{
	
		if(str[i]=='+')
		{
			i=i+1;
			k=k+n;
			d=d+n;
			
		}
		if(str[i]=='\'')
		{
			if(str[i+1]=='+')
			{
				k=k+n;
				i=i+1;
				d=d+n;
				
			}
			if(str[i+1]=='\0')
			{
				while(c<=d)
				{
					s[c]=2; 
					c=c+1;
				}	
				break;
			}
			i=i+1;
			
		}
		j=k+str[i]-a;
		s[j]=1;
		while(c<j)
		{
			s[c]=2; 
			c=c+1;
		}
		if(str[i+1]=='\'')	
		{
			s[j]=0;	
			if((str[i+1]=='\0'))
			{
				while(c<=d)
				{
					c=c+1;
					s[c]=2; 
				}
			}
		} 
			
				
		i=i+1;
		c=c+1;
	}
	s[c]=-1;
}
//------------------------------------------------------------
bool compare(int a[100],int b[100],int c)
{
	int comp_b[100],comp_c[100]={0},d[100],d2[100][100];
	int i=0,j=0,k=0,count=0,count2=0,count3=0;
	while(a[i]>=0)
		i=i+1;
	while(b[count]>=0)
	{
		for(j=0;j<i;j++)
		{
			comp_b[j]=b[count];
			if(count%n==n-1)
				count-=n;
			count=count+1;
		}
		count+=n;
		for(j=0;j<i;j++)
		{
			comp_c[j]=0;
			if((a[j]==2)||(comp_b[j]==2)||(a[j]==comp_b[j]))
				comp_c[j]=1;
		}
		//--------------------------------------------------------
		for(j=0;j<i;j++)
		{
			if(j%n==0)
			{
				count2=j;
				j=j+1;
			}
			comp_c[count2]=comp_c[count2]&comp_c[j];
		}	
		//--------------------------------------------------------
		if(c==1)
		{
			count3=0;
			for(j=0;j<i;j++)
			{
				if(j%n==0)
				{
					d2[k][count3]=comp_c[j];
					count3+=1;
				}
			}
			k=k+1;
			for(j=0;j<count3;j++)
			{
				for(int l=1;l<k;l++)
					d2[0][j]=d2[0][j]|d2[l][j];	
			}
		}
		//--------------------------------------------------------
		if(c==0)
		{
			count3=0;
			for(j=0;j<i;j++)
			{
				if(j%n==0)
				{
					d[count3]=comp_c[j];
					if(d[count3]==1)
						return 0;
					count3+=1;
				}
			}
		}	
	}
	if(c==1)
	{
		for(j=0;j<count3;j++)
			if(d2[0][j]==0)
				return 0;
	}
	return 1;
}
//------------------------------------------------------------
int main(void)
{
	cout<<"n = :";
	cin>>n;
	cout<<"minterms(-1 end):";
	int a[100],a2[100],abit[1000],d[100],no[100]={0},no2[100],no_bit[1000],c1=0,c2=0,r,i,j,k=1;
	for(i=0;i<n;i++)
		k*=2;
	for(i=0;i<k;i++)
	{
		cin>>a[i];
		a2[i]=a[i];
		if(a[i]<0)
			break;
	}  
	for(i=0;a[i]>=0;i++)  
		c1=c1+1;
    two_bit(a2,abit);
    //-------------------------------------------------
	cout<<"don’t care terms(-1 end)";
    for(i=0;i<k;i++)
	{
		cin>>d[i];
		if(d[i]<0)
			break;
	}
	//-------------------------------------------------
    for(i=0;i<k;i++)
    	no[i]=i;
    no[k]=-1;
    no_part(no,a);
    no_part(no,d);
    for(i=0;i<k;i++)
   		no2[i]=no[i];
	for(i=0;no[i]>=0;i++)
		c2+=1;	
    two_bit(no2,no_bit);                                 
    //-------------------------------------------------
    i=1;
    cin.get();
    do
    {
    	string str;
    	cout<<"ans = :";
    	getline(cin,str);
    	int s[1000]={0};
    	ch_num(str,s);
    	/*for(int i=0;i<20;i++)
    		cout<<s[i];
		cout<<endl<<"----------------------"<<endl;*/ 
    	//-------------------------------------------------
    	if(compare(s,no_bit,0)==0)
    		cout<<"no"<<endl;
    	else
    	{
    		if(compare(abit,s,1)==1)
    			cout<<"yes"<<endl;
    		else
    			cout<<"no"<<endl;
		}
		cout<<"continue(0 or 1): ";
		cin>>i;
		cin.sync();
	}while(i!=0);
	
	system("pause");
	return 0;
}

