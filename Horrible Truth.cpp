#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <bitset>
#include <vector>
#include <sstream>
#include <queue>
#include <fstream>
#include <map>

typedef long long Long;
using namespace std;

inline Long readLong()
{
    Long value=0, sign=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')sign=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){value=value*10+ch-'0';ch=getchar();}
    return value*sign;
}

map< pair<int,int> ,int> coordinateMap;
vector<pair<int,int> > coordinateVector;

int main()
{
    freopen("horrible.in","r",stdin);
    freopen("horrible.out","w",stdout);

    int num=readLong();

    if(num==1)
    {
        printf("1\n");
        printf("1 0\n");
        return 0;
    }

    coordinateVector.push_back(make_pair(2,-1));

    for(int i=1;i<=num;i++)
    {
        coordinateVector.push_back(make_pair(i,0));
        int counter = 0;
        int flag  = 1;

        while(flag)
        {
            flag=0;
            counter++;
            if(counter%2==1)
            {
                flag=0;
                for(int inner=1;inner<=num;inner++)
                {
                    if(i==inner)
                        continue;
                    if(coordinateMap[make_pair(inner,i)])
                        continue;
                    coordinateMap[make_pair(inner,i)]=1;
                    coordinateVector.push_back(make_pair(inner,i));
                    flag=1;
                    break;
                }
            }
            else
            {
                flag=0;
                for(int outer=i+1;outer<=num;outer++)
                {
                    for(int inner=1;inner<=num;inner++)
                    {
                        if(inner==outer)
                            continue;
                        if(coordinateMap[make_pair(inner,-outer)])
                            continue;
                        coordinateMap[make_pair(inner,-outer)]=1;
                        coordinateVector.push_back(make_pair(inner,-outer));
                        flag=1;
                        break;
                    }
                    if(flag)
                        break;
                }
            }
        }
    }
    printf("%d\n",coordinateVector.size());
    for(int i=0;i<coordinateVector.size();i++)
        printf("%d %d\n",coordinateVector[i].first,coordinateVector[i].second);

}

