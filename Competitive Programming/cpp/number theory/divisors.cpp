
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
ull getDivisorcount(vector<ull> factors, bool isSorted = false)
{
    if (!isSorted) sort(all(factors));

    ull ans = 1;
    ull f = factors[0];
    int i = 0;
    while (i < factors.size())
    {
        int start = factors[i];
        int cnt = 0;
        while (i < factors.size() && factors[i] == start)
        {
            cnt++;
            i++;
        }
        ans *= cnt + 1;
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