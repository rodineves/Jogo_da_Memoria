#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>
#include<time.h>  //biblioteca pra gerar num aleat�rio
#include<windows.h> //biblioteca pro sleep()

void clique_enter();
void apagar_tela();
void regras();
int escolher_dificuldade();
char jogar_novamente();

int main(){
	setlocale(LC_ALL,"Portuguese");
	
	int dificult, erros, acertos, pontos;
	int chute, cont, cont2;
	int v[9], verif[10];
	int i, j;
	int aux, aux2 = 0, auxRam, aux3;   //aux : se o chute ta certo ; aux2: se o num. repetiu ; aux3: pra caso errar, sair do switch mas continuar.//
	char op;
	
	regras();
	
	do{  // se quer reiniciar o game //
		do{	   //caso ele n digite nenhuma das op��es.//  
			
			dificult = escolher_dificuldade();
			
			switch(dificult){
				
				case 1:
					aux3 = 1; // pra passar pro proximo chute
					cont = 2; // usa no caso de repetir o num digitado
					cont2 = 0; // se ele perder no chute 1, n l� os chutes seguintes
					pontos = 0;
					
					printf("\n        Voc� escolheu a dificuldade 'Normalzin'. Ent�o, clique no ENTER para apresentar os n�meros que dever�o\n");
					printf("        ser decorados. Logo ap�s o contador a seguir:\n\n\n");
					
					clique_enter();
					
					printf("                            ");
						for(i = 5; i >= 1; i--){
							
							printf("%d...", i);   //contagem pra come�ar o game.
				        	Sleep(800); 
				        
				    	}
					printf("GOOOO!!!!!");
					
					Sleep(800);
					apagar_tela();
					Sleep(1000);
					
			        printf("\n\n\n\n                      [");
					srand(time(NULL));				
					
					for(i = 0 ; i < 9 ; i++){	// Ver se os numeros random n v�o repetir //		
						v[i] = rand() % 50;
						auxRam = 0;
							for(j = 0 ; j < i && auxRam == 0 ; j++){
								if(v[i] == v[j]){
									auxRam = 1;
								}
							}
							if(auxRam == 1)
								i--;			
					}
					
					for(i = 0 ; i < 3 ; i++ ){	
						printf("  | %d |  ", v[i]);	// imprime os numeros aleatorios. //
					}
										
					printf("]");
					
					Sleep(8000);
					apagar_tela();
					
					printf("\n\tVamos ver quantos numeros voce decorou. Voce tem 3 chances.\n\n");
					acertos = 2;
					j = 0; // sera usado pra 
					
					if(aux3 == 1){	// inicio do chute 1: //
						erros = 3;  
						do{	
							aux = 0;
							printf("\tDigite um dos n�meros que apareceu acima: ");
							scanf("%d", &chute);
							verif[j] = chute;
								for(i = 0 ; i < 3 ; i++){
									if(chute == v[i]){
										aux++;
										break;
									} 
								}
							
							if(aux == 1){
								printf("\n\t\t--> ACERTOU! Falta %d n�meros\n\n", acertos);
								aux3++;
								pontos++;
								acertos--;
							} else {
								
								if(aux == 0){
									erros--;
									
										if(erros == 0){   //pra � imprimir o de baixo quando as chances acabar.
											break;
										}
									printf("\n\t\tPoxa, voc� errou, tu tens %d chances. Tente novamente...\n\n", erros);
								}				
							}		
						} while (aux != 1 && erros != 0);  // fim do primeiro chute. //
						
						if(erros == 0){  // se a pessoa perder no chute 1: //
							system("cls");
							cont2++;
							printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � nada boa :(\n", pontos); Sleep(2000);
							printf("\tBut don't give up, you're brazzillian!!!\n\n"); Sleep(1000);
							printf("\tEstes foram os n�meros que devieriam ter sidos decorados:");
							
								for(i = 0 ; i < 3 ; i++ ){	
									printf(" | %d | ", v[i]);
								}
							
							printf("\n");
						}	// fim do se a pessoa perder no chute 1. //
					}
				
					if(cont2 == 0){  //pra caso errar no chute 1, � passar pra c�
									
						do{  // chute dois em diante
							erros = 3;  
							if(aux3 == cont++){
								chute = 0;	
								verif[++j] = 0;
								do{
									do{      // se ele repetir o numero digitado //		
										aux2 = 0;
										verif[j] = 0;
										aux = 0;
										printf("\tDigite um dos n�mero que apareceu acima: ");
										scanf("%d", &chute);		
											for(i = 0 ; i < cont - 2 ; i++){   // conferir se ja digitou o n�mero
												if(chute == verif[i]){
													printf("\n\t\t--> Voc� j� digitou esse n�mero. Try again...\n\n");
													aux2++;
												} 
											}
										verif[j] = chute;					
									} while (aux2 == 1);
									for(i = 0 ; i < 3 ; i++){
										if(chute == v[i]){
											aux++;
											break;
										} 
									}
									if(aux == 1){	
										printf("\n\t\t--> ACERTOU! Falta %d n�meros\n\n", acertos);
										aux3++;
										pontos++;
										acertos--;
									} else {
										if(aux == 0){	
											erros--;
												if(erros == 0){
													break;
												}
											printf("\n\t\t--> Poxa, voc� errou, tu tens %d chances. Tente novamente...\n\n", erros);		
										}				
									}		
								} while (aux != 1 && erros != 0); 
						
								if(erros == 0){ // se a pessoa perder
								
									system("cls");
									cont = cont - 2;
									
									if(pontos <= 0){	
										printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � nada boa :(\n\n"); Sleep(2000);		
									}
									
									if(pontos > 0 && pontos <= 2){
										printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � t�o boa :(\n\n", pontos); Sleep(2000);	
									}
									
									if(pontos >= 3){
										printf("\n\n\tSuas chances acabaram. Voc� fez %d pontos, ent�o sua mem�ria at� boa, mas da pra melhorar :)\n\n", pontos); Sleep(2000);	
									}
									
									printf("\tBut don't give up, you're brazzillian!!!\n\n"); Sleep(1000);
									printf("\tEstes s�o os n�meros que devieriam ter sidos decorados:");
										
										for(i = 0 ; i < 3 ; i++ ){	
											printf(" | %d | ", v[i]);
										}
										
									Sleep(1000);
									printf("\n\n");
									
								} // fim do se a pessoa perder					
							}
						} while(aux3 == cont &&  aux3 < 4  &&  erros != 0  ); // repete at� a pessoa perder ou ganhar
					}
					
					if(aux3 == 4){ //se usuario ganhar
						system("cls"); Sleep(800);
						printf("\n\t UHUUUULLL, voc� conseguiu acertar todos os n�meros, voc� tem uma mem�ria muito boa, PARABEENS!!\n");
					}
					
				break;					
				
				case 2:
				
					aux3 = 1; // pra passar pro proximo chute
					cont = 2; // usa no caso de repetir o num digitado
					cont2 = 0; // se ele perder no chute 1, n l� os chutes seguintes
					pontos = 0;
					
					printf("\n        Voc� escolheu a dificuldade 'Marromeno'. Ent�o, clique no ENTER para apresentar os n�meros que dever�o\n");
					printf("        ser decorados. Logo ap�s o contador a seguir:\n\n\n");
					
					clique_enter();
					
					printf("                            ");
					
						for(i = 5; i >= 1; i--){
							printf("%d...", i);   //contagem pra come�ar o game.
				        	Sleep(800); 
				        
				    	}
					printf("GOOOO!!!!!");
					
					Sleep(800);
					system("cls");
					Sleep(1000);
					
			        printf("\n\n\n\n                      [");
					srand(time(NULL));	
								
					for(i = 0 ; i < 9 ; i++){	// Ver se os numeros random n v�o repetir //				
						v[i] = rand() % 50;
						auxRam = 0;
							for(j = 0 ; j < i && auxRam == 0 ; j++){
								if(v[i] == v[j]){
									auxRam = 1;
								}
							}
							
							if(auxRam == 1)
								i--;					
					}
					
					for(i = 0 ; i < 5 ; i++ ){	
						printf("  | %d |  ", v[i]);	// imprime os numeros aleatorios. //
					}
										
					printf("]");
					
					Sleep(8000);
					apagar_tela();
					
					printf("\n\tVamos ver quantos numeros voce decorou. Voce tem 3 chances.\n\n");
					acertos = 4;
					j = 0; // sera usado pra 
					
				
					if(aux3 == 1){	// inicio do chute 1: //
						erros = 3;  
						do{	
							aux = 0;
							printf("\tDigite um dos n�meros que apareceu acima: ");
							scanf("%d", &chute);
							verif[j] = chute;
							
								for(i = 0 ; i < 5 ; i++){
									if(chute == v[i]){
										aux++;
										break;	
									} 
								}
							
							if(aux == 1){
								printf("\n\t\t--> ACERTOU! Falta %d n�meros\n\n", acertos);
								aux3++;
								pontos++;
								acertos--;
							} else {
								if(aux == 0){	
									erros--;
										if(erros == 0){   //pra � imprimir o de baixo quando as chances acabar.
											break;
										}
									printf("\n\t\t--> Poxa, voc� errou, tu tens %d chances. Tente novamente...\n\n", erros);
								}				
							}		
						} while (aux != 1 && erros != 0);  // fim do primeiro chute. //
				
						if(erros == 0){  // se a pessoa perder no chute 1: //
							system("cls");
							cont2++;
							printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � nada boa :(\n", pontos); Sleep(2000);
							printf("\tBut don't give up, you're brazzillian!!!\n\n"); Sleep(1000);
							printf("\tEstes foram os n�meros que devieriam ter sidos decorados:");
								for(i = 0 ; i < 5 ; i++ ){	
									printf(" | %d | ", v[i]);
								}
							printf("\n");
						}	// fim do se a pessoa perder no chute 1. //
					}
				
					if(cont2 == 0){  //pra caso errar no chute 1, � passar pra c�
						do{  // chute dois em diante
							erros = 3;  
							
							if(aux3 == cont++){
								chute = 0;	
								verif[++j] = 0;
								
								do{	
									do{      // se ele repetir o numero digitado //
										aux2 = 0;
										verif[j] = 0;
										aux = 0;
										printf("\tDigite um dos n�mero que apareceu acima: ");
										scanf("%d", &chute);		
							
											for(i = 0 ; i < cont - 2 ; i++){   // conferir se ja digitou o n�mero
												if(chute == verif[i]){
													printf("\n\t\t--> Voc� j� digitou esse n�mero. Try again...\n\n");
													aux2++;
												} 
											}
										verif[j] = chute;	
															
									} while (aux2 == 1);
									
									for(i = 0 ; i < 5 ; i++){
										
										if(chute == v[i]){
											aux++;
											break;
										} 
									}
									
									if(aux == 1){
										
										printf("\n\t\t--> ACERTOU! Falta %d n�meros\n\n", acertos);
										aux3++;
										pontos++;
										acertos--;
										
									} else {
										if(aux == 0){
												
											erros--;
												if(erros == 0){
													break;
												}
											printf("\n\t\t--> Poxa, voc� errou, tu tens %d chances. Tente novamente...\n\n", erros);		
										}				
									}		
									
								} while (aux != 1 && erros != 0); 
								
						
								if(erros == 0){ // se a pessoa perder
									system("cls");
									cont = cont - 2;
									
									if(pontos <= 0){
										printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � nada boa :(\n\n"); Sleep(2000);
									}
									
									if(pontos > 0 && pontos < 3){
										printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � t�o boa :(\n\n", pontos); Sleep(2000);
									}
									
									if(pontos >= 3 && pontos < 5){
										printf("\n\n\tSuas chances acabaram. Voc� fez %d pontos, ent�o sua mem�ria at� boa, mas da pra melhorar :)\n\n", pontos); Sleep(2000);
									}
									
									printf("\tBut don't give up, you're brazzillian!!!\n\n"); Sleep(1000);
									printf("\tEstes s�o os n�meros que devieriam ter sidos decorados:");
										
										for(i = 0 ; i < 5 ; i++ ){	
											printf(" | %d | ", v[i]);
										}
										
									Sleep(1000);
									printf("\n\n");
									
								} // fim do se a pessoa perder					
							}
							
						} while(aux3 == cont &&  aux3 < 6  &&  erros != 0  ); // repete at� a pessoa perder ou ganhar
					}
					
					if(aux3 == 6){ //se usuario ganhar
						system("cls"); Sleep(1000);
						printf("\n\t UHUUUULLL, voc� conseguiu acertar todos os n�meros, parab�ns, voc� tem uma mem�ria muito boa, PARABEENS!!");
					}
					
				break;
		
				case 3:
					
					aux3 = 1; // pra passar pro proximo chute
					cont = 2; // usa no caso de repetir o num digitado
					cont2 = 0; // se ele perder no chute 1, n l� os chutes seguintes
					pontos = 0;
					printf("\n     Voc� escolheu a dificuldade 'Calma vei'. ent�o clique em ENTER que os valores aparecer�o depois do contador:\n\n");
					getch();	
					
					printf("                            ");
							
						for(i = 5; i >= 1; i--){	
							printf("%d...", i);   //contagem pra come�ar o game.
					       	Sleep(800); 
					   	}
				   	
					printf("GOOOO!!!!!");
					Sleep(800);
					system("cls");
					Sleep(800);
						
				    printf("\n\n\n\n                      [");
				        
					srand(time(NULL));				
						
					for(i = 0 ; i < 9 ; i++){	// Ver se os numeros random n v�o repetir //			
						v[i] = rand() % 50;
						auxRam = 0;	
						for(j = 0 ; j < i && auxRam == 0 ; j++){
							if(v[i] == v[j]){
								auxRam = 1;
							}
						}
						if(auxRam == 1)
							i--;					
					}
					
					for(i = 0 ; i < 7 ; i++ ){	
						printf("  | %d |  ", v[i]);	// imprime os numeros aleatorios. //
					}
											
					printf("]");
						
					Sleep(7000);
					system("cls");
						
					printf("\n\tVamos ver quantos numeros voce decorou. Voce tem 3 chances.\n\n");
					acertos = 6;
						
					j = 0;

					if(aux3 == 1){	// inicio do chute 1: //
						erros = 3;  
						
						do{		
							aux = 0;
							printf("\tDigite um dos n�meros que apareceu acima: ");
							scanf("%d", &chute);
							verif[j] = chute;
							
							for(i = 0 ; i < 7 ; i++){
								if(chute == v[i]){
									aux++;
									break;
								} 
							}
							if(aux == 1){
								printf("\n\t\tACERTOU! Falta %d n�meros\n\n", acertos);
								aux3++;
								pontos++;
								acertos--;
							} else {
								if(aux == 0){	
									erros--;
									
										if(erros == 0){   //pra � imprimir o de baixo quando as chances acabar.
											break;
										}
									
									printf("\n\t\tPoxa, voc� errou, tu tens %d chances...\n\n", erros);		
								}				
							}		
						} while (aux != 1 && erros != 0);  // fim do primeiro chute. //
				
						if(erros == 0){  // se a pessoa perder no chute 1: //
							
							system("cls");
							cont2++;
							printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � nada boa :(\n", pontos); Sleep(2000);
							printf("\tBut don't give up, you're brazzillian!!!\n\n"); Sleep(1000);
							printf("\tEstes foram os n�meros que devieriam ter sidos decorados:");
							
								for(i = 0 ; i < 7 ; i++ ){	
									printf(" | %d | ", v[i]);
								}
							
							printf("\n");
						}	// fim do se a pessoa perder no chute 1. //
					}
				
					if(cont2 == 0){  //pra caso errar no chute 1, � passar pra ca		
						do{  // chute dois em diante
							erros = 3;  
							if(aux3 == cont++){
								chute = 0;	
								verif[++j] = 0;
								do{
									do{      // se ele repetir o numero digitado //
										aux2 = 0;
										verif[j] = 0;
										aux = 0;
										printf("\tDigite um dos n�mero que apareceu acima: ");
										scanf("%d", &chute);		
											for(i=0 ; i < cont - 2 ; i++){		
												if(chute == verif[i]){		
													printf("\n\t\t--> J� digitou esse n�mero. Try again...\n\n");
													aux2++;		
												} 
											}	
										verif[j] = chute;	
															
									} while (aux2 == 1);
									
									for(i = 0 ; i < 7 ; i++){
										if(chute == v[i]){	
											aux++;
											break;
										} 
									}
									
									if(aux == 1){
										printf("\n\t\t--> ACERTOU! Falta %d n�meros\n\n", acertos);
										aux3++;
										pontos++;
										acertos--;
										
									} else {
										if(aux == 0){		
											erros--;	
												if(erros == 0){
													break;
												}	
											printf("\n\t\t--> Poxa, voc� errou, tu tens %d chances...\n\n", erros);			
										}				
									}		
									
								} while (aux != 1 && erros != 0); 
						
								if(erros == 0){ // se a pessoa perder
								
									system("cls");
									cont = cont - 2;
									
									if(pontos <= 0){
										printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � nada boa :(\n"); Sleep(2000);
									}
									
									if(pontos > 0 && pontos <= 3){
										printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � t�o boa :(\n", pontos); Sleep(2000);
									}
									
									if(pontos > 3 && pontos < 7){
										printf("\n\n\tSuas chances acabaram. Voc� fez %d pontos, ent�o sua mem�ria at� boa, mas da pra melhorar :) :(\n", pontos); Sleep(2000);
									}
									
									printf("\tBut don't give up, you're brazzillian!!!\n\n"); Sleep(1000);
									printf("\tEstes s�o os n�meros que devieriam ter sidos decorados:");
										
										for(i = 0 ; i < 7 ; i++ ){	
											printf(" | %d | ", v[i]);
										}
										
									Sleep(800);
									printf("\n");
									
								} // fim do se a pessoa perder					
							}
							
						} while(aux3 == cont &&  aux3 < 8  &&  erros != 0  );
					}
					
					if(aux3 == 8){ //se usuario ganhar
						system("cls"); Sleep(1000);
						printf("\n\t UHUUUULLL, voc� conseguiu acertar todos os n�meros, voc� tem uma mem�ria muito boa!! PARABEENS!!");
					}
					
					
				break;
		
				case 4:
					
					aux3 = 1; // pra passar pro proximo chute
					cont = 2; // usa no caso de repetir o num digitado
					cont2 = 0; // se ele perder no chute 1, n l� os chutes seguintes
					
					printf("\n     Voc� escolheu a dificuldade 'PERAI P�'. Agora clique no ENTER que os valores aparecer�o depois do contador:");
					getch();
					
					printf("                            ");
						
					for(i = 5; i >= 1; i--){
						printf("%d...", i);   //contagem pra come�ar o game.
				       	Sleep(800); 
				        
				   	}
					printf("GOOOO!!!!!");
					Sleep(800);
					system("cls");
					Sleep(800);
						
				    printf("\n\n\n\n                      [");
					srand(time(NULL));				
						
					for(i = 0 ; i < 9 ; i++){	// Ver se os numeros random n v�o repetir //				
						v[i] = rand() % 50;
						auxRam = 0;
								
							for(j = 0 ; j < i && auxRam == 0 ; j++){
									
								if(v[i] == v[j]){
									auxRam = 1;
								}	
							}
							if(auxRam == 1)
								i--;			
					        			
					}
					for(i = 0 ; i < 9 ; i++ ){	
						printf("  | %d |  ", v[i]);	// imprime os numeros aleatorios. //
					}
											
					printf("]");
						
					Sleep(6000);
					system("cls");
						
					printf("\n\tVamos ver quantos numeros voce decorou. Voce tem 3 chances.\n\n");
					acertos = 8;
						
					j = 0;

					if(aux3 == 1){	// inicio do chute 1: //
						erros = 3;  
						do{	
							aux = 0;
							printf("\tDigite um dos n�meros que apareceu acima: ");
							scanf("%d", &chute);
							verif[j] = chute;
							
							for(i = 0 ; i < 9 ; i++){
								if(chute == v[i]){
									aux++;
									break;
								} 
							}
							if(aux == 1){
								printf("\n\t\t--> ACERTOU! Falta %d n�meros\n\n", acertos);
								aux3++;
								pontos++;
								acertos--;
							} else {
								if(aux == 0){	
									erros--;
										if(erros == 0){   //pra � imprimir o de baixo quando as chances acabar.
											break;
										}
									printf("\n\t\tPoxa, voc� errou, tu tens %d chances. Tente novamente...\n\n", erros);		
								}				
							}		
						} while (aux != 1 && erros != 0);  // fim do primeiro chute. //
				
						if(erros == 0){  // se a pessoa perder no chute 1: //
							system("cls");
							cont2++;
							printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � nada boa :(\n", pontos); Sleep(2000);
							printf("\tBut don't give up, you're brazzillian!!!\n\n"); Sleep(1000);
							printf("\tEstes foram os n�meros que devieriam ter sidos decorados:");
								for(i = 0 ; i < 9 ; i++ ){	
									printf(" | %d | ", v[i]);
								}
							printf("\n");
						}	// fim do se a pessoa perder no chute 1. //
					}
					
					if(cont2 == 0){  //pra caso errar no chute 1, � passar pra ca	
						do{  // chute dois em diante
							erros = 3;  
							if(aux3 == cont++){
								chute = 0;	
								verif[++j] = 0;
								do{
									do{      // se ele repetir o numero digitado //
										
										aux2 = 0;
										verif[j] = 0;
										aux = 0;
										printf("\tDigite um dos n�mero que apareceu acima: ");
										scanf("%d", &chute);		
											for(i = 0 ; i < cont - 2 ; i++){		
												if(chute == verif[i]){		
													printf("\n\t\tVoc� j� digitou esse n�mero. Try again...\n\n");
													aux2++;		
												} 
											}	
										verif[j] = chute;	
															
									} while (aux2 == 1);
									
									for(i = 0 ; i < 9 ; i++){
										if(chute == v[i]){
											aux++;
											break;
										} 
									}
									
									if(aux == 1){
										printf("\n\t\t--> ACERTOU! Falta %d n�meros\n\n", acertos);
										aux3++;
										pontos++;
										acertos--;
									} else {
										if(aux == 0){		
											erros--;
												if(erros == 0){
													break;
												}
											printf("\n\t\tPoxa, voc� errou, tu tens %d chances. Tente novamente...\n\n", erros);			
										}				
									}		
									
								} while (aux != 1 && erros != 0); 
						
								if(erros == 0){ // se a pessoa perder
								
									system("cls");
									cont = cont - 2;
									
									if(pontos <= 0){
										printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � nada boa :(\n"); Sleep(2000);
									}
									
									if(pontos > 0 && pontos <= 4){	
										printf("\n\n\tSuas chances acabaram. Voc� fez ao total %d pontos, ent�o sua mem�ria n�o � t�o boa :(\n", pontos); Sleep(2000);
									}
									
									if(pontos > 4 && pontos < 9){
										printf("\n\n\tSuas chances acabaram. Voc� fez %d pontos, ent�o sua mem�ria at� boa, mas da pra melhorar :) :(\n", pontos); Sleep(2000);
									}
									
									printf("\tBut don't give up, you're brazzillian!!!\n\n"); Sleep(1000);
									printf("\tEstes s�o os n�meros que devieriam ter sidos decorados:");
										
										for(i = 0 ; i < 9 ; i++ ){	
											printf(" | %d | ", v[i]);
										}
										
									Sleep(1000);
									printf("\n");
								} // fim do se a pessoa perder					
							}
							
						} while(aux3 == cont &&  aux3 < 8  &&  erros != 0  );
					}
							
				break;	
								
				default:
					printf("\n\t\t\tVoc� n�o digitou nenhuma das op��es, tente novamente...");
					Sleep(1800);
					system("cls");			
				break;		
			}	
				
		} while (dificult != 1 && dificult != 2 && dificult != 3 && dificult != 4 );
			
		do{	
			op = jogar_novamente();
		} while(op != 's' && op != 'n' );
			
	} while(op == 's');

	return 0;
}

void clique_enter(){
	char c;
	do{
		c = getch();
	} while(c != 13);
}
void apagar_tela(){
	system("cls");
}

void regras(){
	printf("\n\n\n\n             Ol�, seja bem-vindo(a) ao joguinho da mem�ria! Clique no ENTER do seu teclado para come�ar...\n\n\n");
	clique_enter();
	
	printf("       O jogo ser� simples, as regras s�o as seguintes:\n\n");	
	printf("      -> Ser�o apresentados alguns n�meros, por alguns segundos, na tela.\n\n");	
	printf("      -> Ap�s os n�meros sumirem, voc� ter� que informar quais os n�meros que apareceram na tela, um de cada vez.\n\n");
	printf("      -> Para informar o n�mero, digite o n�mero de sua escolha e clique em ENTER logo em seguida.\n\n");	
	printf("      -> Ap�s 3 erros consecutivos, o jogo termina informando quantos pontos voc� fez.\n\n");
	printf("      -> Ao acertar todos os n�meros o jogo termina informando quantos pontos voc� fez e se voc� tem boa mem�ria.\n\n");
	
	printf("\n\n                Regras ditas, clique ENTER para escolher uma dificuldade.\n");
	
	printf("                Para escolher a dificuldade, digite o n�mero que aparece mais � direita:");
		
	clique_enter();
	apagar_tela();
}

int escolher_dificuldade(){
	int dificult;
	printf("\n\n\n\t                   __________________________________________________________________\n");
	printf("\t                  |                                                                  |\n");
	printf("\t                  |  Dificuldade: Normalzin (3 n�meros, 8 segundos)--------------- 1 |\n");
	printf("\t                  |                                                                  |\n");
	printf("\t                  |  Dificuldade: Marromeno (5 n�meros, 7 segundos )-------------- 2 |\n");
	printf("\t                  |                                                                  |\n");
	printf("\t                  |  Dificuldade: Calma vei (7 n�meros, 6 segundos)--------------- 3 |\n");
	printf("\t                  |                                                                  |\n");
	printf("\t                  |  Dificuldade: PERAI P� (9 n�meros, 5 segundos)---------------- 4 |\n");
	printf("\t                  |__________________________________________________________________|\n\n");
	printf("\t                                 Digite aqui a dificuldade: ");
	scanf("%d", &dificult);
	return dificult;
}

char jogar_novamente(){
	
	char op;
	printf("\n\tVoc� deseja jogar novamente? Se sim, digite 's', se n�o, digite 'n' : ");
	fflush(stdin);
	scanf("%c", &op);
		
	if(op == 's'){
		printf("\n\tOK, vamos recome�ar...\n"); Sleep(1000); system("cls");
	} else {
		if(op =='n'){
			printf("\n\tOK, muito obrigado por jogar meu joguinho :D\n");
			printf("\tQuem puder ajudar o criador do joguinho so mandar aquele PIX maroto pra chave: 111.222.333-66 ksksksk\n");
		} else {
			printf("\t\nVoc� n�o digitou nenhuma das op��es, try again...\n");
		}	
	}
	return op;
}

