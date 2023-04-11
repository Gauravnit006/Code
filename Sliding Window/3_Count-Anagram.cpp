#include <bits/stdc++.h>
using namespace std;

/*
int countOccurencesOfAnagrams(string str, string pattern) {
    int ans=0, k = pattern.size();
    unordered_map<char, int> map;
    //building the map
    for(auto i: pattern)
      map[i]++;
    // storing no of distinct/unique elements in map
    int countDistinct = map.size();
    //sliding window
    int ws=0;  //window start
    for(int we=ws; we<str.size(); we++) {
      // calculations/storing area
      if(map.count(str[we]) > 0) { //IF KEY PRESENT IN MAP, then only do the operations!
        map[str[we]]--;
        if(map[str[we]] == 0)
          countDistinct--;
      }

      //window hit area
      if(we >= k-1) {
        if(countDistinct == 0) ans++; // ans
        // adjust calculations before shifting ws
        if(map.count(str[ws]) > 0) {
          map[str[ws]]++;
          if(map[str[ws]] == 1)
            countDistinct++;
        }

        ws++; // shift
      }
    }
    return ans;
  }
*/
/*
  vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>m;

        vector<int>v;

        for(int i=0;i<p.size();i++)m[p[i]]++;

        int count=m.size(),i=0,j=0,k=p.size();

        while(j<s.size()){
            if(m.find(s[j])!=m.end()){
                m[s[j]]--;
                if(m[s[j]]==0)count--;
            }

            if(j-i+1<k) j++;

            else if(j-i+1==k){
                if(count==0)v.push_back(i);

                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]==1)count++;
                }
                i++;
                j++;
            }
        }
        return v;
    }
*/

int countOccurencesOfAnagrams(string str, string pat)
{
  unordered_map<char, int> m;
  int k=pat.size(), n=str.size();
  for(int i=0; i<k; i++){
    m[str[i]]++;
  }
  int count = m.size();
  int i=0, j=0, ans=0;
  while(j<n){
    if(m.count(str[j])>0){
      m[str[j]]--;
      if(m[str[j]]==0){
        count--;
      }
    }
    if(j-i+1<k){
      j++;
    }
    else if(j-i+1==k){
      if(count==0) ans++;
      if(m.count(str[i])>0){
        m[str[i]]++;
        if(m[str[i]]==1){
          count++;
        }
      }
      i++;
      j++;
    }
  }
  return ans;
}
int main()
{
  string str = "fororfrdofr";
  string ptr = "for";
  int x = countOccurencesOfAnagrams(str, ptr);
  cout<<x<<endl;
}