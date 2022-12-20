#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <iostream> 
#include <inttypes.h>
#include<string.h>
#include<vector>
#include <deque>

using namespace std; 

struct group
{
	string s;
	long long c;
	long long t;
	long long k;
	long long timein;
	long long timeout;
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	long long N;//number of types
    long long Q;//number of groups
    deque<group>Group;
    group temp;

    cin >> N;
    cin >> Q;

    vector<long long>type(N,0);//output的值

    for(long long i = 0; i < Q; i++)
    {
    	cin >> temp.s;//front or back
    	cin >> temp.c;//people in the group
    	cin >> temp.t;//type of the group
    	cin >> temp.k;//people change by the group
    	temp.timein = i;
    	temp.timeout = Q;

    	if(i == 0)
    	{
    		temp.k = 0;
    		Group.push_front(temp);
    	}
    	else
    	{
			temp.c += temp.k;
			if(temp.s == "front")//從頭影響
			{
				while(temp.k != 0)
				{
					if(Group[0].c <= temp.k)//全部轉換type
					{
						temp.k -= Group[0].c;
						type[Group[0].t-1] += Group[0].c * (i - Group[0].timein);
						Group.pop_front();

					}
					else//部分轉換
					{
						type[Group[0].t-1] += Group[0].c * (i - Group[0].timein);
						Group[0].c -= temp.k;
						Group[0].timein = i;
						temp.k = 0;
					}
				}
				Group.push_front(temp);
				// type[Group[0].t-1] += Group[0].c;
			}
			else
			{
				while(temp.k != 0)
				{
					if(Group[Group.size()-1].c <= temp.k)//全部轉換type
					{
						temp.k -= Group[Group.size()-1].c;
						type[Group[Group.size()-1].t-1] += Group[Group.size()-1].c * (i - Group[Group.size()-1].timein);
						Group.pop_back();
					}
					else//部分轉換
					{
						type[Group[Group.size()-1].t-1] += Group[Group.size()-1].c * (i - Group[Group.size()-1].timein);
						Group[Group.size()-1].c -= temp.k;
						Group[Group.size()-1].timein = i;
						temp.k = 0;
					}
				}
				// for(long long j = 1; j <= Group.size(); j++)
				// {
				// 	type[Group[Group.size()-j].t-1] += Group[Group.size()-j].c;
				// }
				Group.push_back(temp);
				// type[Group[Group.size()-1].t-1] += Group[Group.size()-1].c;
			}
    	}
    	
    }
	for(long long j = 0; j < Group.size(); j++)
	{
		type[Group[j].t-1] += Group[j].c * (Group[j].timeout - Group[j].timein);
	}

    for(long long i = 0; i < type.size(); i++)
	{
		printf("%lld ", type[i]);
	}

    return 0;
}