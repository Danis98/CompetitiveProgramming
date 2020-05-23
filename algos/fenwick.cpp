#define LSB(i) ((i) & -(i))

// 1-INDEXED !!!

int sum(std::vector<ll>& A, int i){
    ll sum = 0;
    while (i > 0)
        sum += A[i], i -= LSB(i);
    return sum;
}

void add(std::vector<ll>& A, int i, ll k){
    while (i <= N)
        A[i] += k, i += LSB(i);
}