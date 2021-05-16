#include <bits/stdc++.h>
using namespace std;

int countPsubstring(string a){

	int n = a.size();
	if(n == 1)
		return 1;

	vector<vector<bool>> isPalindrome(n, vector<bool>(n)); // store if a[i..j] is palindrome
	vector<vector<int>> count(n, vector<int>(n)); // store count of palinSS from a[i..j]
	isPalindrome[0][0] = true;
	count[0][0] = 1;
	for(int i = 1; i < n; i++){
		isPalindrome[i][i] = isPalindrome[i][i-1] = true;
		count[i][i] = 1;
	}

	for(int i = n-1; i >= 0; i--){
		for(int j = i+1; j < n; j++){
			count[i][j] = count[i][j-1] + count[i+1][j] - count[i+1][j-1];
			if(isPalindrome[i+1][j-1] && a[i] == a[j]){
				isPalindrome[i][j] = true;
				count[i][j]++;
			}
		}
	}
	return count[0][n-1];
}

int main()
{
	string a;
	cin>>a;
	cout<<countPsubstring(a)<<endl;
	return 0;
}
