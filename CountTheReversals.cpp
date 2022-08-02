//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends



int countRev (string s)
{
    if(s.length()%2){return -1;}
   stack<char>st;
   int l=0, r=0;
   
   for(char &c: s){
       if(!st.empty() && st.top()=='{' && c=='}'){
           st.pop();
       }
       else{
           st.push(c);
       }
   }
   
   while(!st.empty()){
       if(st.top()=='{'){l++;}
       else{r++;}
       st.pop();
   }
   
   return (l+1)/2 + (r+1)/2;
}
