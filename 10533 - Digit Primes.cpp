/*
A prime number is a positive number, which is divisible by exactly two different integers. A digit prime
is a prime number whose sum of digits is also prime. For example the prime number 41 is a digit prime
because 4 + 1 = 5 and 5 is a prime number. 17 is not a digit prime because 1 + 7 = 8, and 8 is not
a prime number. In this problem your job is to find out the number of digit primes within a certain
range less than 1000000.


Input

First line of the input file contains a single integer N (0 < N ≤ 500000) that indicates the total number
of inputs. Each of the next N lines contains two integers t1 and t2 (0 < t1 ≤ t2 < 1000000).


Output

For each line of input except the first line produce one line of output containing a single integer that
indicates the number of digit primes between t1 and t2 (inclusive).


Sample Input

3
10 20
10 100
100 10000


Sample Output

1
10
576

Note: You should at least use scanf() and printf() to take input and produce output for this
problem. cin and cout is too slow for this problem to get it within time limit
*/

#include<iostream>
using namespace std;

int N = 1000000;
int sieve[1000005];
int cumul[1000005];

int disect(int n){
    int sum = 0;
    while(n){
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void createsieve(){
    long long i,j;
    for(i = 0; i <= N; i++){
        sieve[i] = 1;
        cumul[i] = 0;
    }
    sieve[0] = sieve[1] = 0;
    for(i = 2; i <= N; i++){
        cumul[i] = cumul[i-1];
        if(sieve[i]){
            if(sieve[disect(i)])    
                ++cumul[i];
            for(j = i*i; j <= N; j+=i)
                sieve[j] = 0;
        }
    }
}

int main(){
    createsieve();
    int n;
    scanf("%d",&n);
    while(n--){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        printf("%d\n",cumul[t2]-cumul[t1-1]);
    }
    return 0;
}
