#define ll long long int
int N=1e5+1;
const int MOD=1e9+7;
ll fact[N];
ll invfact[N];

ll mod_exp(ll a,ll b)
{
   if(b==0) return 1;

   int t=mod_exp(a,b/2);

   if(b%2!=0)
   return (t*t*a)%MOD;
   else
   {
       return (t*t)%MOD;
   }
}

ll mod_inverse(ll a)
{
    return mod_exp(a,MOD-2);
}
void precompute()
{
    fact[0]=invfact[0]=1;
    for(int i=1;i<=N;++i)
    {
        fact[i]=fact[i-1]*i;
        invfact[i]=mod_inverse(fact[i])%MOD;
    }


}

ll ncr(ll n,ll r)
{
    if(r>n)
    return 0;

    return ((fact[n]*invfact[r])%MOD * (invfact[n-r])%MOD)%MOD;
}