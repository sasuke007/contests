#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
#include <chrono>
#include <cmath>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define endl "\n"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvl;
bool check_palindrome(vector<int> &input, int val) {
  int n = input.size();
  int start = 0, end = n - 1;
  bool is_palindrome = true;
  while (start <= end) {
    if(input[start]==val and input[end]==val){
      ++start;
      --end;
      continue;
    }
    if(input[start]==val){
      ++start;
      continue;
    }
    if(input[end]==val){
      --end;
      continue;
    }
    if(input[start]!=input[end]){
      is_palindrome=false;
    }
    ++start;
    --end;
  }
  return is_palindrome;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#ifdef D_DEBUG
  freopen("input.txt", "r", stdin)
#endif
      int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; ++i) {
      cin >> input[i];
    }
    int start = 0, end = n - 1;
    string answer = "YES";
    while (start <= end) {
      if (input[start] != input[end]) {
        bool is_palindrome = check_palindrome(input, input[start]) or
                             check_palindrome(input, input[end]);
        if (!is_palindrome) {
          answer = "NO";
        }
        break;
      }
      ++start;
      --end;
    }
    cout<<answer<<endl;
  }
}