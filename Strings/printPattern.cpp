#include <bits/stdc++.h> 
using namespace std;

vector<string> printPattern(int n)
{
	vector<string> ans;
	int limit = n*n;
	int j=0;
	for(int i=1; i<=limit; i=i+n){
        string str = "";
		for(int j=i; j<i+n; j++){
			str = str+to_string(j)+" ";
		}
		ans.push_back(str);
	}

    vector<string> res;
    int k;
    for(k=0; k<n; k=k+2){
        res.push_back(ans[k]);
    }
    
    int l;
    if (n%2==0)
        l=k-1;
    else
        l=k-3;
    for(l; l>0; l=l-2){
        res.push_back(ans[l]);
    }

    return res;
}

int main(){
    vector<string> ans = printPattern(5);
    for(string str: ans)
        cout<<str<<endl;

}