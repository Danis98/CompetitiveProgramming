#include <bits/stdc++.h>

typedef long long int ll;
#define MAXN 1073741823

struct sparse_range_tree{
    struct sparse_range_tree_node{
        sparse_range_tree_node *left=NULL, *right=NULL;
        ll count=0;
    };

    sparse_range_tree_node *root;

    sparse_range_tree(){
        root=new sparse_range_tree_node();
    }

    void update(ll a, ll b, ll p, sparse_range_tree_node *node){
        if(p<a || b<p || b<a) return;
        if(a==b){
            node->count++;
            return;
        }
        int m=(a+b)/2;
        if(node->left==NULL) node->left=new sparse_range_tree_node();
        if(node->right==NULL) node->right=new sparse_range_tree_node();
        update(a, m, p, node->left);
        update(m+1, b, p, node->right);
        node->count=node->left->count+node->right->count;
    }

    ll query(ll a, ll b, ll qa, ll qb, sparse_range_tree_node *node){
        if(node==NULL) return 0;
        if(b<qa || qb<a) return 0;
        if(qa<=a && b<=qb) return node->count;
        int m=(a+b)/2;
        return query(a, m, qa, qb, node->left)+query(m+1, b, qa, qb, node->right);
    }
};

ll N, X, K;
ll res=0;
sparse_range_tree tree;
ll A[100000];

int main(){
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif

    std::cin>>N>>X>>K;
    for(int i=0;i<N;i++){
        std::cin>>A[i];
        tree.update(0, MAXN, A[i], tree.root);
    }
    for(int i=0;i<N;i++){
        ll low, high;
        if(A[i]%X==0 && K==0){low=high=0;}
        else{
            low=std::min(A[i], std::max(0LL, A[i]-A[i]%X-X*K+1));
            high=std::min(A[i], std::max(0LL, A[i]-A[i]%X-X*(K-1)));
        }
        res+=tree.query(0, MAXN, low, high, tree.root);
        //std::cout<<A[i]<<" "<<low<<" "<<high<<"\n";
    }
    std::cout<<res<<"\n";
}
