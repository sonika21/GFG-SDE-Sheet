//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int>v;
       fun(v,nums,0,nums.size()-1);
       return v;
    }
     void fun(vector<int>&v, vector<int>& v1, int l, int h)
   {
       if(l<=h)
       {
           int m=l+(h-l)/2;
           v.push_back(v1[m]);
           fun(v,v1,l,m-1);
           fun(v,v1,m+1,h);
       }
   }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
