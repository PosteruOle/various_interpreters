#include<cstring>
#include<iostream>
#include<stdio.h>
#include<vector>

#ifndef __NODE_H__
#define __NODE_H__

FILE* f=fopen("asembler.s","w");
int ind=0;
int label=1;

typedef enum {CONST, VAR, OP, NAREDBE, RET, DEKL, IF, IFELSE, DODELA} nodeType;

typedef struct condition {
	char znak;
	struct node *izrazlevo;
	struct node *izrazdesno;
} condition;

condition* makeCondition(char znak, node *l, node *d){
	condition* c=(condition*)malloc(sizeof(condition));
	c->znak = znak;
	c->izrazlevo = l;
	c->izrazdesno = d;
	return c;
}

typedef struct node {

	nodeType type;
	union{
	        
	        std::vector<node*>* clanovi;
	
		int vred;
		int ret_value;
		
		struct promen{
		
			char id[64];
			int indeks;
			int vrednost;
		}promen;
		
		
		struct nodegrananje{
			struct condition *c;
			struct node *truenaredbe;
			struct node *falsenaredbe;
		}nodegrananje;
		
		struct nodeOp{
			int oper;
			int numOperands;
			struct node** operands;
		}op;
		
		
		struct dodela{
			char iden[64];
			node *izraz;
			int ind;
		}dodela;
				
			
	}data;
	
	void dodajNaredbu(node* naredba){
		
		if(type==NAREDBE || type==DEKL)
			data.clanovi->push_back(naredba);
		
	}
	
	void action(){
		if(type==NAREDBE){
		   if(ind==0){
			ind=1;
			fprintf(f, ".intel_syntax noprefix\n\n.text\n\t.globl main\n\nmain:\n\n\tpush rbp\n\tmov rbp, rsp\n");
		   } 
		   for(long unsigned int i=0; i<(*(data.clanovi)).size(); i++)
			(*(data.clanovi))[i]->action();
		} 
		else  if(type==RET){
		
			fprintf(f,"\tpop rbp\n\tmov rax,%d\n\tret\n",data.ret_value);
			
		} else if(type==OP){
			
			if(data.op.oper=='+'){
				data.op.operands[0]->action();
				fprintf(f,"\tpush rax\n");
				data.op.operands[1]->action();
				fprintf(f,"\tpop rcx\n");
				fprintf(f,"\tadd rax, rcx\n");
			}else if(data.op.oper=='-'){
				data.op.operands[0]->action();
				fprintf(f,"\tpush rax\n");
				data.op.operands[1]->action();
				fprintf(f,"\tpop rcx\n");
				fprintf(f,"\tsub rax, rcx\n");
			}else if(data.op.oper=='*'){
				data.op.operands[0]->action();
				fprintf(f,"\tpush rax\n");
				data.op.operands[1]->action();
				fprintf(f,"\tpop rcx\n");
				fprintf(f,"\timul rcx\n");
			}else if(data.op.oper=='/'){
				data.op.operands[0]->action();
				fprintf(f,"\tpush rax\n");
				data.op.operands[1]->action();
				fprintf(f,"\tpop rcx\n");
				fprintf(f,"\tcqo\n");
				fprintf(f,"\tidiv rcx\n");
			}else if(data.op.oper=='%'){
				data.op.operands[0]->action();
				fprintf(f,"\tpush rax\n");
				data.op.operands[1]->action();
				fprintf(f,"\tpop rcx\n");
				fprintf(f,"\tcqo\n");
				fprintf(f,"\tidiv rcx\n");
				fprintf(f,"\tmov rax, rdx\n");
			}
		}else if(type==CONST){
		
			fprintf(f,"\tmov rax, %d\n", data.vred);
		}else if(type==DEKL){
			
			fprintf(f,"\tmov QWORD PTR [rbp-%d], %d\n",data.promen.indeks,data.promen.vrednost);
		}else if(type==VAR){
		
			fprintf(f,"\tmov rax, QWORD PTR [rbp-%d]\n",data.promen.indeks);
		}else if(type==DODELA){
			data.dodela.izraz->action();
			fprintf(f,"\tmov QWORD PTR [rbp-%d], rax\n",data.dodela.ind);
		}else if(type==IF){
		        
		        
		        if(data.nodegrananje.c->znak=='='){
		        
				data.nodegrananje.c->izrazlevo->action();
				fprintf(f,"\tmov rcx, rax\n");
				data.nodegrananje.c->izrazdesno->action();
				fprintf(f,"\tcmp rcx, rax\n");
				fprintf(f,"\tjne label%d\n",label);
				int tmp=label;
				label+=1;
				data.nodegrananje.truenaredbe->action();
				fprintf(f,"label%d:\n",tmp);
			
			}else if(data.nodegrananje.c->znak=='>'){
				
				data.nodegrananje.c->izrazlevo->action();
				fprintf(f,"\tmov rcx, rax\n");
				data.nodegrananje.c->izrazdesno->action();
				fprintf(f,"\tcmp rcx, rax\n");
				fprintf(f,"\tjle label%d\n",label);
				int tmp=label;
				label+=1;
				data.nodegrananje.truenaredbe->action();
				fprintf(f,"label%d:\n",tmp);
			
			}else if(data.nodegrananje.c->znak=='<'){
				
				data.nodegrananje.c->izrazlevo->action();
				fprintf(f,"\tmov rcx, rax\n");
				data.nodegrananje.c->izrazdesno->action();
				fprintf(f,"\tcmp rcx, rax\n");
				fprintf(f,"\tjge label%d\n",label);
				int tmp=label;
				label+=1;
				data.nodegrananje.truenaredbe->action();
				fprintf(f,"label%d:\n",tmp);
			}else if(data.nodegrananje.c->znak=='n'){
				
				data.nodegrananje.c->izrazlevo->action();
				fprintf(f,"\tcmp rax, 0\n");
				fprintf(f,"\tjne label%d\n",label);
				int tmp=label;
				label+=1;
				data.nodegrananje.truenaredbe->action();
				fprintf(f,"label%d:\n",tmp);
			}
		}else if(type==IFELSE){
		
		
			if(data.nodegrananje.c->znak=='='){
		        
				data.nodegrananje.c->izrazlevo->action();
				fprintf(f,"\tmov rcx, rax\n");
				data.nodegrananje.c->izrazdesno->action();
				fprintf(f,"\tcmp rcx, rax\n");
				fprintf(f,"\tjne label%d\n",label);
				int tmp=label;
				label+=1;
				data.nodegrananje.truenaredbe->action();
				fprintf(f,"\tjmp label%d\n",tmp+1);
				label+=1;
				fprintf(f,"label%d:\n",tmp);
				data.nodegrananje.falsenaredbe->action();
				fprintf(f,"label%d:\n",tmp+1);
			
			}else if(data.nodegrananje.c->znak=='>'){
				
				data.nodegrananje.c->izrazlevo->action();
				fprintf(f,"\tmov rcx, rax\n");
				data.nodegrananje.c->izrazdesno->action();
				fprintf(f,"\tcmp rcx, rax\n");
				fprintf(f,"\tjle label%d\n",label);
				int tmp=label;
				label+=1;
				data.nodegrananje.truenaredbe->action();
				fprintf(f,"\tjmp label%d\n",tmp+1);
				label+=1;
				fprintf(f,"label%d:\n",tmp);
				data.nodegrananje.falsenaredbe->action();
				fprintf(f,"label%d:\n",tmp+1);
			
			}else if(data.nodegrananje.c->znak=='<'){
				
				data.nodegrananje.c->izrazlevo->action();
				fprintf(f,"\tmov rcx, rax\n");
				data.nodegrananje.c->izrazdesno->action();
				fprintf(f,"\tcmp rcx, rax\n");
				fprintf(f,"\tjge label%d\n",label);
				int tmp=label;
				label+=1;
				data.nodegrananje.truenaredbe->action();
				fprintf(f,"\tjmp label%d\n",tmp+1);
				label+=1;
				fprintf(f,"label%d:\n",tmp);
				data.nodegrananje.falsenaredbe->action();
				fprintf(f,"label%d:\n",tmp+1);
			}else if(data.nodegrananje.c->znak=='n'){
				
				data.nodegrananje.c->izrazlevo->action();
				fprintf(f,"\tcmp rax, 0\n");
				fprintf(f,"\tjne label%d\n",label);
				int tmp=label;
				label+=1;
				data.nodegrananje.truenaredbe->action();
				fprintf(f,"\tjmp label%d\n",tmp+1);
				label+=1;
				fprintf(f,"label%d:\n",tmp);
				data.nodegrananje.falsenaredbe->action();
				fprintf(f,"label%d:\n",tmp+1);
		
			}
		}
	}

}node;

node* makeNode(nodeType tip){
	node* n=(node*)malloc(sizeof(node));
	n->type = tip;
	return n;
}

node* makeNodeConst(int vred){
	node* n=makeNode(CONST);
	n->data.vred=vred;
	return n;
}

node* makeNodeVar(const char* id,int ind, int vr){
	node* n=makeNode(VAR);
	strncpy(n->data.promen.id, id, 63);
	n->data.promen.indeks=ind;
	n->data.promen.vrednost=vr;
	return n;
}

node* makeNodeOperator(int numOperands){
	node *n=makeNode(OP);
	n->data.op.numOperands = numOperands;
	n->data.op.operands = (node**)malloc(numOperands*sizeof(node*));
	return n;
}

node* makeNodeBinOperator(int oper, node* op1, node* op2){
	node *n=makeNodeOperator(2);
	n->data.op.oper=oper;
	n->data.op.operands[0]=op1;
	n->data.op.operands[1]=op2;
	return n;
}

node* makeNodeRet(int ret_value){
	node* n=makeNode(RET);
	n->data.ret_value=ret_value;
	return n;
}

node* makeNodeNaredbe(){
	node* n=makeNode(NAREDBE);
	n->data.clanovi=new std::vector<node*>();
	return n;
}

node* makeNodeDekl(const char* id,int ind, int vr){
	node* n=makeNode(DEKL);
	strncpy(n->data.promen.id, id, 63);
	n->data.promen.indeks=ind;
	n->data.promen.vrednost=vr;
	return n;
}


node* makeNodeIfElse(condition *c, node* truenaredbe, node* falsenaredbe){
       node* n=makeNode(IFELSE);
       n->data.nodegrananje.c=c;
       n->data.nodegrananje.truenaredbe=truenaredbe;
       n->data.nodegrananje.falsenaredbe=falsenaredbe;
       return n;
}
node* makeNodeIf(condition *c, node* truenaredbe){
       node* n=makeNode(IF);
       n->data.nodegrananje.c=c;
       n->data.nodegrananje.truenaredbe=truenaredbe;
       return n;
}



node* makeNodeDodela(const char* id, node *izraz, int ind){
       node* n=makeNode(DODELA);
       strncpy(n->data.dodela.iden, id, 63);
       n->data.dodela.izraz=izraz;
       n->data.dodela.ind=ind;
       return n;
}



#endif
