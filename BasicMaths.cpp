#include <iostream>
#include <cstring>
#define MAX 100
#define ll long long
using namespace std;

int primes[MAX];

//Basic sieve of eratosthenes to generate primes upto MAX
//Complexity ==> O(nlglgn).
void sieve()
{
  memset(primes,1,sizeof(primes));
  primes[0] = primes[1] = 0;
  for(int i=2;i*i<MAX;++i)
  {
    if(primes[i])
    {
	for(int j=i;j*i<MAX;++j)
	  primes[j*i]=0;
    }
  }
}

/**
Eculidiean Algorithm to find GCD of 2 number 
T(n) = O(logmin(a,b))
**/
long long gcd(long long a, long long b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}

/**
 Recursive Eculidiean Algorithm to find GCD of 2 number 
T(n) = O(logmin(a,b))
**/
long long gcd_r(long long a, long long b)
{
   if(b==0)
     return a;
   return gcd(b,a%b);
}

/**
 T(n) = O(logmin(a,b)) + O(1) ==> O(logmin(a,b))
**/
long long lcm(long long a, long long b)
{
  return (a/gcd(a,b))*b;
}

/**
Function to generate Bezout's Coefficients x and y
Function follows Extended Euclidiean Algorithm
T(n) = O(logmin(a,b)) 
Its same as gcd, we get coefficients for free ie O(1), just 1 multiplication.
**/
int gcd(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

/**
Function is used to multiply 2 big intergers and return mod p
i.e a*b mod p
Function takes care of overflow during multiplications.
**/
ll bigmul(ll a, ll b, ll p)
{
	ll res=0;
	a%=p;
	while(b)
	{
		if(b&1)
			res = (res+a)%p;
		a=((2%p)*(a%p))%p;
		b>>=1;
	}
	return res;
}
