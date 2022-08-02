//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    string ans=A.substr(0,1);
     vector<int> vis(26,0);
     queue<char> q;
     q.push(A[0]);
     vis[A[0]-'a']=1;
     for(int i=1;i<A.length();++i)
     {
         vis[A[i]-'a']++;
         if(vis[A[i]-'a']==1)q.push(A[i]);
         while(!q.empty() && vis[q.front()-'a']>1) q.pop();
         if(q.empty()) ans+='#';
         else ans+=q.front();
         
     }
     return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
