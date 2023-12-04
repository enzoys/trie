#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
int main(){
	int N, i, idade;
	char ID[31], nome[1001], comando=0;
	
	Cadastro *usuario;
	
	Nodo *trie=criaNodo();
	
	FILE *arq=NULL;
	
	arq=fopen("banco.txt", "r");
	
	fscanf(arq, "%d\n", &N);
		
	for(i=0; i<N; i++){
		fscanf(arq, "%s %1000[A-Z,a-z, ] %d", ID, nome, &idade);
		
		remove_espaco(nome);
			
		usuario=criaCadastro(nome, idade);
			   
		Insere(trie, ID, usuario);
	}
	
	fclose(arq);
	
	while(comando!='F'){
        scanf("%c", &comando);

		if(comando=='?'){
            scanf("%s", ID);
			
			usuario=Busca(trie, ID);
			
			if(usuario==NULL)
				printf("ID %s nao encontrado.\n", ID);
			else
				printf("(%s|%s|%d)\n", ID, usuario->Nome, usuario->Idade);
        }

        else if(comando=='+'){
			scanf("%s %1000[A-Z,a-z, ] %d", ID, nome, &idade);
			
			remove_espaco(nome);
			
            usuario=criaCadastro(nome, idade);
           
	        Insere(trie, ID, usuario);
			
	        printf("Inserido (%s|%s|%d)\n", ID, nome, idade);
        }
        
        else if(comando=='-'){
            scanf("%s", ID);
			
			usuario=Busca(trie, ID);
			
			if(usuario==NULL)
				printf("ID %s nao encontrado.\n", ID);
			else{
				Remove(trie, ID);
				
				printf("Removido (%s|%s|%d)\n", ID, usuario->Nome, usuario->Idade);
			}
        }

        else if(comando=='P'){
			N=0;
			
			Imprime(trie, ID, &N);
        }
		
        else if(comando=='S'){
            arq=fopen("banco.txt", "w");
			N=0;
			
			fprintf(arq, "%d\n", Tamanho(trie));
			
			Salva(arq, trie, ID, &N);
			
			fclose(arq);
			
			printf("banco.txt salvo\n");
        }	
	}
	
	Esvazia(trie);
	
	return 0;
}