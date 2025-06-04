#include<iostream> 
#include<vector> 
#include<unordered_map>
#include<string> 


using namespace std; 

class Solution{
public: 
       unordered_map<string, bool> memo; 
       bool possiblyEqual(string s1, string s2){
         return backtrack(s1,s2,0,0,0); 
       }
       bool backtrack(string& s1, string& s2, int i, int j, int diff){
         int m = s1.size(); 
         int n = s2.size(); 
         if(i==m && j==n) return diff==0; 
         string key = to_string(i)+ "," + to_string(j)+ "," +to_string(diff); 
         if(memo[key]) return memo[key]; 
         if(i<m && isdigit(s1[i])){
           int val=0; 
           for(int k=i; k<m && isdigit(s1[k]); ++k){
             val = val*10 + s1[k]-'0'; 
             if(backtrack(s1,s2, k+1, j, diff-val)) return memo[key]=true; 
           }
         }
         if(j<n && isdigit(s2[j])){
           int val=0; 
           for(int k=j; k<n && isdigit(s2[k]); ++k){
             val = val*10+s2[k]-'0'; 
             if(backtrack(s1,s2,i,k+1, diff+val)) return memo[key]=true; 
           }
         }
         if(diff==0 && i<m && j<n && s1[i]==s2[j]) {
           if(backtrack(s1,s2,i+1,j+1,0)) return memo[key]=true;
           
         } 
         if(diff>0 && i<m && !isdigit(s1[i])){
           if(backtrack(s1,s2, i+1,j , diff-1)) return memo[key]=true; 
         }
         if(diff<0 && j<n && !isdigit(s2[j])){
           if(backtrack(s1,s2,i,j+1, diff+1)) return memo[key]=true; 
         }
         return memo[key]=false; 
       }
};
int main(){
  string s1 = "internationalization";
  string s2 ="i18n";
  Solution sol; 
  cout << boolalpha << sol.possiblyEqual(s1,s2) << endl; 
  return 0; 
}
