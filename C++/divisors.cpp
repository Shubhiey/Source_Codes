#include <bits/stdc++.h>
using namespace std;
#define loi unsigned long long

set<loi> printDivisors(loi n)
{
    set<loi> s;
	for (loi i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{
			if (n/i == i)
			    s.insert(i);
			else
			    s.insert(i), s.insert(n / i);
		}
	}
	return s;
}

int main()
{
loi t;
cin >> t;
while(t--)
{
    loi A, M;
    cin >> A >> M;
    set <loi> s = printDivisors(M);
    loi cnt = 0;
    set<loi> s1;
    set<loi> :: iterator it;
    for(it = s.begin(); it != s.end(); it++)
    {
        if((*it) == 1)
            continue;
        else{
            if(((*it) - 1) % A == 0)
            {
               cnt++;
               loi y = *it;
               loi ans;
               if(y == M)
               {
                   ans = (M - 1) / A;
               }
               else
               {
                   ans = (y - 1) / A;
                   ans *= (M / y);
               }
               s1.insert(ans);
            }
        }
    }
    cout << cnt << "\n";
    for(it = s1.begin(); it != s1.end(); it++)
        cout << *it << " ";
    cout << "\n";
    s.clear();
    s1.clear();
}
	return 0;
}
