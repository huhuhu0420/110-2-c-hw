#include<cstdlib>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
class kmap
{
	protected:
		int var;
		vector<int>min;
		vector<int>dcare;
		int min_num;
		int dcare_num;
	public:
		void var_set()
		{
			cin>>var;
            cout << var << "\n";
		}
		void min_set()
		{
			int i,minval;
			char ch;
			for(i=0;i<100;i++)
			{
				cin>>minval;
				min.push_back(minval);
                scanf("%c", &ch);
				if(ch=='\n')
				{
					min_num=i;
					break;
				}
			}
            for (i=0; i<=min_num; i++)  cout << min[i];
            cout << '\n';
		}
		
		void dcare_set()
		{
			int i,dcareval;
			char ch;
			for(i=0;i<100;i++)
			{
				cin>>dcareval;
				dcare.push_back(dcareval);
                scanf("%c", &ch);
				if(ch=='\n')
				{
					dcare_num=i;
					break;
				}
			}
            for (i=0; i<=dcare_num; i++)  cout << dcare[i];
            cout << '\n';
		}
		
		void dec_to_bin(int a,vector<int> )//a is var. b is dec
		{
			// int a=1,sum=0,i;
			// for(i=0;i<)
			// do
			// {
			// 	sum+=(dec%2*a);
			// 	a*=10;
			// 	dec=dec/2;
			// }while(dec!=0);
			// *result2=sum;
		}
        int isTrue (int variable[]) {
            int i, outcome = 0;
            for (i=0; i<min.size(); i++) {
                cout << min[i] << '\n';
                
            }
        }
        void process () {
            int i, variable[10];
            std::string ans;
            std::cin >> ans;
            cout << ans << '\n';
        }
	
 } ;
 class varies
 {
 	
 };
 class min {

};
 
 int main(void)
 {
 	class kmap m1;
 	int a;
 	cout<<"n = :";
 	m1.var_set();
 	cout<<"minterns = :";
 	m1.min_set();
 	cout<<"dont care = :";
 	m1.dcare_set();
    m1.process();
 }

