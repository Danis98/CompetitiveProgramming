#include <bits/stdc++.h>

int N;

int instr_ptr=0;
std::map<std::string, int> reg;
std::vector<std::vector<std::string>> code;

int main(){
    freopen("input.txt", "r", stdin);
    std::cin>>N;
    std::string instr, op1, op2;
    code.resize(N);
    for(int i=0;i<N;i++){
        std::cin>>instr>>op1;
        code[i].push_back(instr);
        code[i].push_back(op1);
        if(instr=="cpy" || instr=="jnz"){
            std::cin>>op2;
            code[i].push_back(op2);
        }
    }
    while(instr_ptr<N){
        //std::cout<<instr_ptr<<" : "<<reg["a"]<<" "<<reg["b"]<<" "<<reg["c"]<<" "<<reg["d"]<<"\n";
        instr=code[instr_ptr][0];
        if(instr=="cpy"){
            op1=code[instr_ptr][1];
            op2=code[instr_ptr][2];
            int val;
            if(op1[0]>='a' && op1[0]<='d')
                val=reg[op1];
            else
                val=std::stoi(op1);
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
            int val;
            if(op1[0]>='a' && op1[0]<='d')
                val=reg[op1];
            else
                val=std::stoi(op1);
            int jmp_off;
            jmp_off=std::stoi(op2);
            if(val!=0)
                instr_ptr+=jmp_off-1;
        }
        instr_ptr++;
    }

    std::cout<<reg["a"]<<" "<<reg["b"]<<" "<<reg["c"]<<" "<<reg["d"]<<"\n";
}
