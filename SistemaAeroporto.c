#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*----------- STRUCTS -----------*/

typedef struct aviao {
    int id;
    struct aviao *prox;
} Aviao;

typedef struct header {
    Aviao *hLdisp;
    Aviao *hFdec;
    Aviao *hFate;
    Aviao *hLNoAr;
} Header;

/*----------- FUNCTIONS -----------*/

void menu(){

  printf("\n");

  printf("Entre a opcao desejada: \n\n");
  printf(" 1. Inserir aviao em LDISP; \n");
  printf(" 2. Inserir aviao em LNoAR; \n");
  printf(" 3. Autorizar decolagem; \n");
  printf(" 4. Autorizar aterrissagem; \n");
  printf(" 5. Aterrissar; \n");
  printf(" 6. Decolar; \n");
  printf(" 7. Proximas aterrisagens; \n");
  printf(" 8. Proximas decolagens; \n");
  printf(" 9. Avioes no terminal; \n");
  printf(" 10. Avioes no ar; \n");
  printf(" 11. Imprimir relatorio; \n");
  printf(" 12. Remover aviao de LDISP; \n");
  printf(" 13. Remover aviao de LNoAr; \n");
  printf("  0. Sair; \n");
}

Aviao *insereFila(Aviao **p, int i){

  Aviao *n = (Aviao *) malloc(sizeof(Aviao));

  n->id = i;
  n->prox = NULL;


  if( *p == NULL ){
    n->prox = *p;
    *p = n;

    return *p;
  } else {
      Aviao *h = *p;

      while( h != NULL && (h)->prox != NULL){
        h = h->prox;
      }

      h->prox = n;
    }

  return *p;
}

Aviao *removerFila(Aviao **p){
	if(*p == NULL){
		return NULL;
	}
	
	Aviao* aux = *p;
	*p = (*p)->prox;

	free(aux);
	return *p;
}

int qualAterrissar(Aviao **p){
	Aviao* aux = (Aviao*) malloc(sizeof(Aviao));
	int i;
	
	if(*p == NULL){
		return 0;
	}
	
	aux=*p;
	i = (int) aux->id;
	
  return i;
}

int qualDecolar(Aviao **p){
	Aviao* aux = (Aviao*) malloc(sizeof(Aviao));
	int i;
	
	if(*p == NULL){
		return 0;
	}
	
	aux=*p;
	i = (int) aux->id;

  return i;
}

Aviao *removerPosLista(Aviao **p, int i){

  Aviao *h = *p;
  Aviao *a = *p;

  if(h->id == i){
    *p = h->prox;
    return *p;
  }

  while((h)->prox != NULL){
    if(h->id == i){
      a->prox = h->prox;
      return *p;
    }

    a = h;
    h = h->prox;
  }

  if((h)->prox == NULL && (h)->id == i){
    a->prox = NULL;
    return *p;
  } else if((h)->id == i) {
    a->prox = h->prox;
    return *p;
  }
  return *p;
}

Aviao *insereLista(Aviao **p, int i){

    Aviao *n = (Aviao*)malloc(sizeof(Aviao));

    n->id = i;
    n->prox = NULL;

    if( *p == NULL ){
        n->prox = *p;
        *p = n;
		printf("%d",i);
        return *p;
    }

    if( i < (*p)->id){
        n->prox  = *p;
        *p = n;
    }

    Aviao *h = *p;

    while(h->prox != NULL && h->prox->id < i){
        h = h->prox;
        
    }

    if(h->prox == NULL){
        h->prox = n;
        printf("%d",i);
        return *p;
    } else {
        n->prox = h->prox;
        h->prox = n;
        }
	printf("%d",i);
    return *p;
}

Aviao *adicionarInicioFila(Aviao **p, int i){

  Aviao *n = (Aviao *) malloc(sizeof(Aviao)); 

  n->id = i; 
  n->prox = NULL;

  if( *p == NULL ){
    n->prox = *p;
    *p = n;

    return *p;
  } else {

      n->prox = *p;
      *p = n;

      return *p;
    }

  return NULL;
}

void *imprimirListaOuFila(Aviao **p){

  Aviao *h = *p;

  if(*p == NULL){ //testa se a lista é nula
    printf("Nao existem avioes para imprimir.\n"); //caso positivo imprime isso e volta para o menu
  }else{ //caso negativo executa o codigo abaixo.
  

  while((h)->prox != NULL){
    printf("%d\n", h->id);
    h = h->prox;
  }

  printf("%d\n", h->id);
  
  }
}

void insereRelatorio(char vetor[100][80], int i, int pos, char action[80]){

  char texto[80];
  char num[3];

  strcpy(texto, "Aviao codigo ");
  sprintf(num, "%d", i);
  strcat(texto, num);
  strcat(texto, action);
  
  strcpy(vetor[pos], texto);  
}

void escreveRelatorio(char vetor[100][80], int pos){
  int i = 0;

  for(i = 0; i < pos; i++){
    printf("%s\n", vetor[i]);
  }
}


/*----------- MAIN -----------*/
int main(){

    Aviao *LDISP = NULL;
    Aviao *LNOAR = NULL;
    Aviao *FDEC = NULL;
    Aviao *FATE = NULL;
    char relatorio[100][80];

    Header EDAero;
    
    EDAero.hFate = FATE;
    EDAero.hFdec = FDEC;
    EDAero.hLdisp = LDISP;
    EDAero.hLNoAr = LNOAR;

    int opcao, i, p, pos;

    //Inicializa LDISP e LNOAR
    for(i = 1 ; i <= 15; i++ ){
        insereLista(&LDISP, i);
        i++;
        insereLista(&LNOAR, i);
    }
	system("cls");
	
    menu();
    scanf("%d",&opcao);
    while (opcao != 0){
        switch (opcao) {
        case 1://OK

          printf("Entre o numero do aviao que deseja inserir na lista: \n");
          scanf(" %d",&i);
          insereLista(&LDISP, i);
          
          system("cls");
          printf("Inserido LDISP.\n");
          
          insereRelatorio(relatorio, i, pos, " inserido em LDISP.");
          pos++;

          break;
        case 2://OK

          printf("Entre o numero do aviao que deseja inserir na lista: \n");
          scanf(" %d",&i);
          insereLista(&LNOAR, i);
          
		  system("cls");
		  printf("Inserido LNOAR.\n");
		  
          insereRelatorio(relatorio, i, pos, " inserido em LNOAR.");
          pos++;

          break;
        case 3://OK

          printf("Entre o numero do aviao que deseja autorizar a decolar: \n");
          scanf(" %d",&i);
          
          printf("Entre a prioridade; 1 - urgente, 0 - normal. \n");
		  scanf(" %d",&p);

          if(p == 1){
          	removerPosLista(&LDISP, i);
          	adicionarInicioFila(&FDEC, i);
          	
          	system("cls");
          	printf("Aviao %d autorizado a decolar com prioridade. \n", i);
          	
            insereRelatorio(relatorio, i, pos, " autorizado a decolar com prioridade (LDISP-FDEC).");
          pos++;
      	  } else {
          		removerPosLista(&LDISP, i);
          		insereFila(&FDEC, i);
          		
          		system("cls");
          		printf("Aviao %d autorizado a decolar. \n", i);
          		
                insereRelatorio(relatorio, i, pos, " autorizado a decolar (LDISP-FDEC).");
          pos++;
			}

          break;
        case 4://OK

          printf("Entre o numero do aviao que deseja autorizar a aterrissar: \n");
          scanf(" %d",&i);
          
          printf("Entre a prioridade; 1 - urgente, 0 - normal. \n");
		  scanf(" %d",&p);
		  
		  if(p == 1){
		  	removerPosLista(&LNOAR, i);
          	adicionarInicioFila(&FATE, i);
          	
          	system("cls");
          	printf("Aviao %d autorizado a aterissar com prioridade. \n", i);


            insereRelatorio(relatorio, i, pos, " autorizado a aterrissar com prioridade (LNOAR-FATE).");
          pos++;
      	  } else {
	        	removerPosLista(&LNOAR, i);
          		insereFila(&FATE, i);
          		
          		system("cls");
          		printf("Aviao %d autorizado a aterissar. \n", i);


                insereRelatorio(relatorio, i, pos, " autorizado a aterrissar (LNOAR-FATE).");
          pos++;
			}

          break;
        case 5://OK

          printf("Aterrisar: \n");
          i = qualAterrissar(&FATE);
          removerFila(&FATE);
          if(i > 0){
          	insereLista(&LDISP, i);
          	system("cls");
          	printf("O aviao %d aterrisou. \n", i);
          	insereRelatorio(relatorio, i, pos, " aterrisou (FATE-LDISP)");
          	pos++;
		  } else {
		  	printf("Sem avioes na fila de aterrisagem.\n");
		  }

          break;
        case 6://OK

          printf("Decolar: \n");
          i = qualDecolar(&FDEC);
          removerFila(&FDEC);
          if(i > 0){
           insereLista(&LNOAR, i);
           system("cls");
           printf("O aviao %d decolou. \n", i);
           insereRelatorio(relatorio, i, pos, " decolou (FDEC-LNOAR)");
           pos++;
      	  } else {
      	  		printf("Sem avioes na fila de decolagem.\n");
			}

          break;
        case 7:
			
			system("cls");
			printf("As proximas aterrissagens sao: \n");
        	imprimirListaOuFila(&FATE);

        	break;
        case 8: //OK

			system("cls");
        	printf("Os avioes decolagens sao: \n");
        	imprimirListaOuFila(&FDEC);

            break;
        case 9: //OK
    
    		system("cls");
        	printf("Os avioes no terminal sao: \n");
        	imprimirListaOuFila(&LDISP);

        	break;
        case 10://OK
			
			system("cls");
        	printf("Os avioes no ar sao: \n");
        	imprimirListaOuFila(&LNOAR);

        	break;
        case 11:
        	
			system("cls");
            printf("\nRelatorio: \n");
            escreveRelatorio(relatorio, pos);
			       
            break;
        case 12://OK

            printf("Entre o numero do aviao que deseja remover de LDISP: \n");
            scanf(" %d",&i);
            removerPosLista(&LDISP, i);
            
            system("cls");
            printf("Removido aviao de LDISP: \n");

            insereRelatorio(relatorio, i, pos, " removido de LDISP.");
          pos++;

            break;
        case 13://OK

            printf("Entre o numero do aviao que deseja remover de LNOAR: \n");
            scanf(" %d",&i);
            removerPosLista(&LNOAR, i);
            
            system("cls");
        	printf("Removido aviao de LNoAr: \n");

            insereRelatorio(relatorio, i, pos, " removido de LNOAR.");
            pos++;

        	break;
        }
        menu();
        scanf("%d",&opcao);
    }

    return 0;
}
