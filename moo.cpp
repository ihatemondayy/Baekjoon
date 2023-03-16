
#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence(1, 3);

int length(int k){  // s(k)의 길이를 구하는 함수
  if(k==0) return sequence[0];
  else{
    for(int i=1; i<=k; i++){
        vector<int> temp_sequence(i+1);
        for(int j=0; j<i; j++){
          temp_sequence[j] = sequence[j];
        }
    temp_sequence[i] = sequence[i-1]*2+k+3;
    sequence = temp_sequence;
    }
    return sequence[k];
  }
}

int recursive(int n){
  int k=0;
  while(length(k)<n){
    length(k); k++;
  }
  return k;
}

char compare(int n, int k){
  // n이 s(k-1)+1이면 "m"
  if(n==length(k-1)+1) return 'm';
  // n이 s(k-1)+1보다 크고 s(k-1)+k+3보다 작거나 같으면 "o"
  else if(length(k-1)+1<n && n<=(length(k-1)+k+3)) return 'o';
  else return compare(n-(length(k-1)+k+3), recursive(n-(length(k-1)+k+3)));
}

int main(void){
  int n, k=0; cin >> n;
  recursive(n);
  cout << compare(n, recursive(n));
  return 0;
}