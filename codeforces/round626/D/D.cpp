#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> ii;
typedef std::pair<int, ii> iii;
typedef std::pair<ull, ull> ull2;
typedef std::pair<ll, ll> ll2;
typedef std::pair<double, double> dd;

int freq[20000003], freq_cum[20000003];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N;
    std::cin>>N;
    std::vector<ll> a(N);
    for(int i=0;i<N;i++) std::cin>>a[i];

    ll res = 0;
    ll bit_num = 0;
    ll carries = 0;
    for(int k=0;k<24;k++){
        bit_num = carries;
        carries = 0;
        ll lim = 1 << (k + 1);
        for(int i=0;i<=lim;i++) freq[i] = 0;
        int o = 0;
        for(int i=0;i<N;i++){
            freq[a[i] % lim]++;
            o += (a[i] >> k) & 1;
        }
        bit_num += o * (N - o);
        // std::cout<<"dir="<<(o*(N-o))<<"\n";
        freq_cum[lim-1] = freq[lim-1];
        for(int i=lim-2;i>=0;i--) freq_cum[i] = freq[i] + freq_cum[i+1];
        for(int i=1;i<lim;i++){
            // std::cout<<freq[i]<<" "<<freq_cum[std::max((ll)i+1, lim-i)]<<"\n";
            if(2 * i >= lim)
                carries += (ll)freq[i] * (ll)(freq[i] - 1) / 2;
            carries += (ll)freq[i] * (ll)freq_cum[std::max((ll)i+1, lim-i)];
        }
        // for(int i=0;i<=lim;i++)
        //     std::cout<<freq[i]<<" ";
        // std::cout<<"\n";
        // for(int i=0;i<=lim;i++)
        //     std::cout<<freq_cum[i]<<" ";
        // std::cout<<"\n";
        // std::cout<<"- "<<bit_num<<" "<<carries<<"\n";
        res |= (bit_num % 2) << k;
    }
    std::cout<<res<<"\n";
}
