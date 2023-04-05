#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int v, f;

struct Question
{
	char title[301];
	char variants[8][301];
	int answer;
};

void print_question (Question &q)
{
	cout <<"Use:"<<endl;
	cout << "	q-exit"<<endl;
	
	if (v>0) 
	{ 
		cout <<"	v-extra life"<<endl;
	}
	
	if (f>0)
	{
		cout <<"	f-50/50"<<endl<<endl;
	}
	 
	cout<<q.title<<endl;
	cout<<"1 - "<<q.variants[0]<<endl;
	cout<<"2 - "<<q.variants[1]<<endl;
	cout<<"3 - "<<q.variants[2]<<endl;
	cout<<"4 - "<<q.variants[3]<<endl;
}

bool is_real_earning (int money)
{
	int real_earnings[100]={500, 2000, 10000, 50000, 250000};
	int nr = sizeof(real_earnings)/sizeof(real_earnings[0]);
	int i;
	
	for (i=0; i<nr; i++)
	{
		if (money==real_earnings[i])
		{
			return true;
		}
	}
	
	return false;
}

void print_50 (Question &q)
{
	int k, i;
	k = 0;
	
/*	for (i=0; i<4; i++)
	{
		while (k!=0)
		{
			if (q.variants[i]!=q[i].answer)
			{
				k--;
			}
			
			else
			{
				cout<<i+1<<"-"<<q.variants[i]<<endl;
			}
			
		}	
	}
}*/

	for (i=0; i<=4; i++)
	{
		if ( i == q.answer+1)
		{
			cout << q.variants[i];
		}
			
		else
		{ 
			if (k<1)
			{
				cout <<q.variants[i];
				k++;
			}
		}
		
		i++;
	}
	
		
}


int main ()
{
	ifstream fin("questions.in");
	Question q[100];
	int n, i, j, earning, real_earning;
	char choice;
	char temp[301];
	int money[100]={100,200,500,1000,2000,5000,10000,25000,50000,100000,250000,500000,1000000};
	bool life_used = false;
	bool fifty_used = false;
	
	
	fin.getline(temp, 10);
	
	n = atoi(temp);
	
	v = 1;
	f = 1;
	
	for (i=0; i<n; i++)
	{
		fin.getline(q[i].title, 300);
		fin.getline(q[i].variants[0], 300);
		fin.getline(q[i].variants[1], 300);
		fin.getline(q[i].variants[2], 300);
		fin.getline(q[i].variants[3], 300);
		fin.getline(temp, 300);
		q[i].answer = atoi(temp);
	}

	earning = 0;
	real_earning = 0;
	
	for (i=0; i<n; i++)
	{
		system ("cls");
		
		cout <<"Real earning: "<<real_earning<<endl;
		
		cout <<"Cost: "<< money[i] << endl << endl;
		
		print_question(q[i]);
		
		cout << endl <<"Introduceti raspunsul: ";
		cin >> choice;
		
		if (choice == 'v'|| choice == 'V')
		{
			if (v > 0)
			{
				life_used = true;
				cout <<"Ai folosit viata"<<endl;
				cout <<"Alege varianta"<<endl;
				cin >> choice;
				v--;
			}
			
			else 
			{
				cout <<"Nu mai aveti vieti"<<endl;
				i--;
				system ("pause");
				continue;
			}
		}
		
		if (choice == 'f' || choice == 'F')
		{
			if (f > 0)
			{
				fifty_used = true;
				system ("cls");
				
				print_50(q[i]);
				
				cout <<"Ai folosit 50/50"<<endl;
				
				cout <<"Alege varianta"<<endl;
				cin >> choice;
			}
			
			else 
			{
				cout <<"Nu mai aveti 50/50"<<endl;
				i--;
				system ("pause");
				continue;
			}
		}
		
		if (choice == 'q'|| choice == 'Q')
		{
			cout <<"Castigul tau= "<<earning;
			return 0;
		}
		
		
		
		if (choice-48 != q[i].answer)
		{
			if (life_used == true)
			{
				cout <<"Gresit - mai incearca"<<endl;
				system ("pause");
				life_used = false;
				i--;
			}
			
			else
			{
				cout <<"Gresit\a"<<endl;
				cout <<"Castigul tau= "<<real_earning;
				return 0;
			}
			
		}
		
		if (is_real_earning(money[i]))
		{	
			real_earning = money[i];
		}
		
		earning = money[i];
	}
	
	cout <<"Ai castigat! Esti MILIONAR!"<<endl;
	
}
