const int MAX_PR = 1e5;
vi smallestfactor(MAX_PR);

void smallestFactorSieve(int hi)
{
    rep(i, hi) smallestfactor[i] = i;
    for (int i = 0; i < hi; i += 2) smallestfactor[i] = 2;

    repp(i, 3, min(hi + 0., ceil(sqrt(hi)) + 10))
    {
        if (smallestfactor[i] == i)
        {
            for (size_t j = i * i; j < hi; j += i)
            {
                if (smallestfactor[j] == j) smallestfactor[j] = i;
            }
        }
    }
}

// Factor n in log(n) times
vi GetFactors(int n)
{
    vi factors;
    int k = n;
    while (k != 1 && k != 0)
    {
        factors.push_back(smallestfactor[k]);
        k /= smallestfactor[k];
    }
    return factors;
}