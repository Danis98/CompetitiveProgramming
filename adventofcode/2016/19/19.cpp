#include <bits/stdc++.h>

int N;

//AVL
//TODO: iterative functions
template<typename K, typename V>
struct AVL_tree{
    struct AVL_node{
        AVL_node *left=NULL, *right=NULL, *parent=NULL;
        K key;
        V value;
        int balance=0;
        int height=1;
        int sub=1;
        AVL_node(K key, V value): key(key), value(value){}
        void adjust_height(){
            int lh, rh;
            lh=(left==NULL?0:left->height);
            rh=(right==NULL?0:right->height);
            height=std::max(lh, rh)+ 1;
            balance=rh-lh;
            sub=(left==NULL?0:left->sub)+(right==NULL?0:right->sub)+ 1;
        }
        int pos(){
            return left==NULL?0:left->sub;
        }
    };

    AVL_node *root=NULL;

    AVL_tree(){}

    void insert(K key, V value){
        root=_insert(key, value, root);
    }
    void erase(K key){
        root=_erase(key, root);
    }
    AVL_node *find(K key){
        return _find(key, root);
    }
    void insert_at(int pos, V value){
        root=_insert_at(pos, value, root);
    }
    void erase_at(int pos){
        root=_erase_at(pos, root);
    }
    AVL_node *find_at(int pos){
        return _find_at(pos, root);
    }
    void print_tree(){
        _print_tree(root, 0, 0);
    }

    AVL_node *_insert(K key, V value, AVL_node *node){
        if(node==NULL)
            return new AVL_node(key, value);
        if(key==node->key){
            node->value=value;
            return node;
        }
        if(key<node->key){
            node->left=_insert(key, value, node->left);
            node->left->parent=node;
        } else{
            node->right=_insert(key, value, node->right);
            node->right->parent=node;
        }

        node->adjust_height();
        node=rebalance(node);
        return node;
    }

    AVL_node *_erase(K key, AVL_node *node){
        if(!node) return NULL;
        if(key<node->key && node->left!=NULL){
            node->left=_erase(key, node->left);
            if(node->left!=NULL)node->left->parent=node;
        } else if(key>node->key && node->right!=NULL){
            node->right=_erase(key, node->right);
            if(node->right!=NULL)node->right->parent=node;
        } else if(key==node->key){
            if(node->left==NULL && node->right==NULL)
                return NULL;
            if(node->left==NULL && node->right!=NULL)
                return node->right;
            if(node->left!=NULL && node->right==NULL)
                return node->left;
            AVL_node *min_left=node->left;
            AVL_node *par=node;
            while(min_left->right){
                par=min_left;
                min_left=min_left->right;
            }
            node->key=min_left->key;
            node->value=min_left->value;
            if(par==node){
                par->left=_erase(key, min_left);
                if(node->left!=NULL)node->left->parent=node;
            } else{
                par->right=_erase(key, min_left);
                if(node->right!=NULL)node->right->parent=node;
            }

            while(par!=node){
                par->adjust_height();
                if(par->parent!=NULL){
                    if(par->parent==node)
                        par->parent->left=rebalance(par);
                    else
                        par->parent->right=rebalance(par);
                }
                par=par->parent;
            }
        }

        node->adjust_height();
        node=rebalance(node);

        return node;
    }

    AVL_node *_find(K key, AVL_node *node){
        if(!node)
            return NULL;
        if(node->key==key)
            return node;
        if(key<node->key)
            return find(key, node->left);
        else
            return find(key, node->right);
    }

    AVL_node *_insert_at(int pos, V value, AVL_node *node){
        if(node==NULL)
            return new AVL_node(0, value);
        if(pos<=node->pos()){
            node->left=_insert_at(pos, value, node->left);
            node->left->parent=node;
        } else{
            node->right=_insert_at(pos-node->pos()-1, value, node->right);
            node->right->parent=node;
        }

        node->adjust_height();
        node=rebalance(node);
        return node;
    }

    AVL_node *_erase_at(int pos, AVL_node *node){
        if(!node) return NULL;
        if(pos<node->pos()&& node->left!=NULL){
            node->left=_erase_at(pos, node->left);
            if(node->left!=NULL)node->left->parent=node;
        } else if(pos>node->pos()&& node->right!=NULL){
            node->right=_erase_at(pos-node->pos()-1, node->right);
            if(node->right!=NULL)node->right->parent=node;
        } else if(pos==node->pos()){
            if(node->left==NULL && node->right==NULL)
                return NULL;
            if(node->left==NULL && node->right!=NULL)
                return node->right;
            if(node->left!=NULL && node->right==NULL)
                return node->left;
            AVL_node *min_left=node->left;
            AVL_node *par=node;
            while(min_left->right){
                par=min_left;
                min_left=min_left->right;
            }
            node->key=min_left->key;
            node->value=min_left->value;
            if(par==node){
                par->left=_erase_at(pos-1, min_left);
                if(par->left!=NULL)par->left->parent=node;
            } else{
                par->right=_erase_at(min_left->pos(), min_left);
                if(par->right!=NULL)par->right->parent=node;
            }

            while(par!=node){
                par->adjust_height();
                if(par->parent!=NULL){
                    if(par->parent==node)
                        par->parent->left=rebalance(par);
                    else
                        par->parent->right=rebalance(par);
                }
                par=par->parent;
            }
        }

        node->adjust_height();
        node=rebalance(node);

        return node;
    }

    AVL_node *_find_at(int pos, AVL_node *node){
        if(!node)
            return NULL;
        if(node->pos()== pos)
            return node;
        if(pos<node->pos())
            return _find_at(pos, node->left);
        else
            return _find_at(pos-node->pos()-1, node->right);
    }

    AVL_node *_left(AVL_node *node){
        if(node==NULL) return node;
        AVL_node *ppar=node->parent;
        AVL_node *T2=node->right;
        AVL_node *Y=T2->left;
        T2->left=node;
        if(node!=NULL) node->parent=T2;
        node->right=Y;
        if(Y!=NULL) Y->parent=node;
        node=T2;
        if(node!=NULL) node->parent=ppar;
        node->left->adjust_height();
        node->adjust_height();

        return node;
    }

    AVL_node *_right(AVL_node *node){
        if(node==NULL) return node;
        AVL_node *ppar=node->parent;
        AVL_node *T1=node->left;
        AVL_node *Y=T1->right;
        T1->right=node;
        if(node!=NULL) node->parent=T1;
        node->left=Y;
        if(Y!=NULL) Y->parent=node;
        node=T1;
        if(node!=NULL) node->parent=ppar;
        node->right->adjust_height();
        node->adjust_height();
        return node;
    }

    AVL_node *rebalance(AVL_node *node){
        int b=node->balance;
        if(b>=-1 && b<=1)
            return node;
        if(b==2){
            if(node->right->balance ==-1)node->right=_right(node->right);
            node=_left(node);
        } else if(b ==-2){
            if(node->left->balance==1)node->left=_left(node->left);
            node=_right(node);
        }
        return node;
    }

    bool is_balanced(AVL_node *node){
        if(node==NULL) return true;
        node->adjust_height();
        if(node->balance<=-2 || node->balance>=2) return false;
        return is_balanced(node->right) && is_balanced(node->left);
    }

    void _print_tree(AVL_node *node, int indent, int s){
        if(node==NULL) return;
        for(int i=0; i<indent-(s==0?0:1); i++)std::cout<<"|";
        std::cout<<(s ==-1?"L":s==1?"R":"")<<"{"<<node->key<<", "<<node->value<<"}-"<<node->pos()<<" "<<node->sub<<"\n";
        _print_tree(node->left, indent+1,-1);
        _print_tree(node->right, indent+1, 1);
    }

    int size(){
        return root->sub;
    }
};

int main(){
    freopen("input.txt", "r", stdin);
    AVL_tree<int, int> arr;
    std::cin>>N;
    for(int i=0;i<N;i++)
        arr.insert_at(i, i+1);

    int cur=0;
    while(arr.size()>1){
        int targ=(cur+N/2)%N;
        arr.erase_at(targ);
        if(targ<cur) cur--;
        N--;
        cur=(cur+1)%N;
    }
    std::cout<<arr.root->value<<"\n";
}
