
void setDivisors(ull n, ull i, vector<ull>& divisors, vector<pair<ull, ull>>& factors) {
    ull j, x, k;
    for (j = i; j < factors.size(); j++) {
        x = factors[j].first * n;
        for (k = 0; k < factors[j].second; k++) {
            divisors.push_back(x);
            setDivisors(x, j + 1, divisors, factors);
            x *= factors[j].first;
        }
    }
}
vector<ull> getDivisors(vector<ull> primes)
{
    unordered_map<ull, ull> primeCount;
    repe(prime, primes) primeCount[prime]++;
    vector<pair<ull, ull>> factorCount;
    repe(p, primeCount) factorCount.emplace_back(p);
    vector<ull> ret;
    setDivisors(1, 0, ret, factorCount);
    ret.push_back(1);
    return ret;
}

#include "factorsieve.cpp"
#include "factor.cpp"
ull getDivisorcount(ull a)
{
    // TODO: optimize (do not use map)
    // map is probably faster than unordered, since we only have log(a) prime factors
    map<ull, int> factorCount;
    // Either use factor(a) to use pollard's rho or GetFactors() to use sieve
    repe(f, GetFactors(a)) factorCount[f]++;
    ull ans = 1;

    repe(factor, factorCount)
    {
        ans = ((ans) * (factor.second + 1));
    }
    return ans;
}
// Find all divisors in sqrt(a) time. pretty bad
vi getDivsSlow(ll a)
{
    vi ret;
    int i;
    for (i = 1; i * i < a; i++) {
        if (a % i == 0)
            ret.push_back(i);
    }
    if (i - (a / i) == 1) {
        i--;
    }
    for (; i >= 1; i--) {
        if (a % i == 0)
            ret.push_back(a / i);
    }
    return ret;
}