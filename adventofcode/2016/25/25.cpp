#include <bits/stdc++.h>

typedef long long int ll;

int N;

int instr_ptr=0;
std::map<std::string, ll> reg;
std::vector<std::vector<std::string>> code;

bool is_reg(std::string s){
    return s[0]>='a' && s[0]<='d';
}

ll get_val(std::string s){
    if(is_reg(s))
        return reg[s];
    else
        return (ll)std::stoi(s);
}

int main(){
    freopen("input.txt", "r", stdin);
    std::cin>>N;
    std::string instr, op1, op2;
    code.resize(N);
    for(int i=0;i<N;i++){
        std::cin>>instr>>op1;
        code[i].push_back(instr);
        code[i].push_back(op1);
        if(instr=="cpy" || instr=="jnz" || instr=="mul"){
            std::cin>>op2;
            code[i].push_back(op2);
        }
        if(instr=="mul"){
            std::string op3;
            std::cin>>op3;
            code[i].push_back(op3);
        }
    }
    while(instr_ptr<N){
        //std::cout<<instr_ptr<<" : "<<reg["a"]<<" "<<reg["b"]<<" "<<reg["c"]<<" "<<reg["d"]<<"\n";
        instr=code[instr_ptr][0];
        if(instr=="cpy"){
            op1=code[instr_ptr][1];
            op2=code[instr_ptr][2];
            ll val=get_val(op1);
            if(!is_reg(op2)){
                instr_ptr++;
                continue;
            }
            reg[op2]=val;
        }
        else if(instr=="inc"){
            op1=code[instr_ptr][1];
            reg[op1]++;
        }
        else if(instr=="dec"){
            op1=code[instr_ptr][1];
            reg[op1]--;
        }
        else if(instr=="jnz"){
            op1=code[instr_ptr][1];
            op2=code[instr_ptr][2];
            ll val=get_val(op1);
            int jmp_off=get_val(op2);
            if(val!=0)
                instr_ptr+=jmp_off-1;
        }
        else if(instr=="tgl"){
            op1=code[instr_ptr][1];
            int off=get_val(op1);
            int mod_addr=instr_ptr+off;
            if(mod_addr<0 || mod_addr>=N){
                instr_ptr++;
                continue;
            }
            std::string orig_instr=code[mod_addr][0];
            if(orig_instr=="dec" || orig_instr=="tgl")
                code[mod_addr][0]="inc";
            else if(orig_instr=="inc")
                code[mod_addr][0]="dec";
            else if(orig_instr=="jnz")
                code[mod_addr][0]="cpy";
            else if(orig_instr=="cpy")
                code[mod_addr][0]="jnz";
        }
        //Multiply instr, because GOTTA GO FAST
        else if(instr=="mul"){
            op1=code[instr_ptr][1];
            op2=code[instr_ptr][2];
            std::string op3=code[instr_ptr][3];
            ll v1=get_val(op1), v2=get_val(op2);
            ll res=v1*v2;
            if(is_reg(op3))
                reg[op3]+=res;
        }
        else if(instr=="out"){
            op1=code[instr_ptr][1];
            ll out_val=get_val(op1);
            std::cout<<"[STDOUT] "<<out_val<<"\n";
        }
        instr_ptr++;
    }

    std::cout<<reg["a"]<<" "<<reg["b"]<<" "<<reg["c"]<<" "<<reg["d"]<<"\n";
}
