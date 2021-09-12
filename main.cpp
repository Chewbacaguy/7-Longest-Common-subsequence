#include <iostream>
#include <vector>
#include <string>

using namespace std;

//he longest common subsequence(LCS) problemis the problem of finding the longest subsequencecommon to all sequences in a set of sequences (often just two sequences). This problem not required occupyingconsecutive positionswithin the original sequences.


void solve(string string1, string string2){

  int LCS[string1.length()][string2.length()];
  int n = string1.length();
  int m = string2.length();
  if(string1[0] == string2[0]){
    LCS[0][0] = 1;
  }
  else{
    LCS[0][0] = 0;
  }
  
  for(int i = 1; i<=n-1; i++){
    if(string1[i] == string2[0]){
      LCS[i][0] = 1;
    }
    else{
      LCS[i][0] = LCS[i-1][0];
    }
  }
  for(int j=1; j<=m-1;j++){
    if(string1[0] == string2[j]){
      LCS[0][j] = 1;
    }
    else{
      LCS[0][j] = LCS[0][j-1];
    }
  }
  for(int i=1; i<=n-1; i++){
    for(int j =1; j<=m-1;j++){
      if(string1[i] == string2[j]){
        LCS[i][j] = LCS[i-1][j-1] +1 ;
      }
      else{
        //asignar el maximo de lcs en la pos [i-1][j] 
        LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
      }
    }
  }
  cout << LCS[n-1][m-1] << endl;
}

int main() {
  string string1, string2;
  int casos;
  int aux = 1;
  cin >> casos;
  while(casos--){
    cin >> string1 >> string2;
    if((string1.length() > 0 && string2.length() > 0) && (string1.length() <= 1000 && string2.length() <= 1000)){
      cout << "Case " << aux++ << ": " ;
      solve(string1, string2);
    }
  }
}