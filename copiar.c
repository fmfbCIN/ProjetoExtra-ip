#define PI 3.14
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" {
#include "extApi.h"
}

void funcao(float digito){
     float numj3[] = {-PI / 35,PI / 45, PI / 20, PI / 20, PI / 150,PI / 45, PI / 30, -PI / 55,0,PI / 200}
	float numj2[] = {-PI / 4,-PI / 4, -PI / 4, -PI / 4, -PI / 4.5,-PI / 4,-PI / 4, -PI / 4.5,-PI / 4,-PI / 4}
	float numj1[] = {-PI / 11, -PI / 15, -PI / 11, -PI / 10, -PI / 15, -PI / 11, -PI / 9.5,-PI / 15,-PI / 11,-PI / 9.5}
	float backj2[] = {-PI / 3.75, -PI / 3.8, -PI / 3.6, -PI / 3.55, -PI / 3.8, -PI / 3.70,-PI / 3.6,-PI / 3.9,-PI / 3.75,-PI / 3.65}

	float t1[] = {1000, 1000, 2000, 3000, 4000, 2000, 3000, 2000, 2000, 2000}
	float t2[] = {1000, 3000, 2000, 1000, 5000, 1000, 5000, 2000, 2000, 3000}
	float t3[] = {1000, 3000, 2000, 2000, 2000, 1000, 3000, 2000, 1000, 2000}
	float t4[] = {1000, 3000, 2000, 2000, 2000, 2000, 2000, 2000, 2000, 2000}

    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)numj3[digito], (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(t1[digito]);


    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)numj2[digito], (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(t2[digito]);


    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)numj1[digito], (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(t3[digito]);


    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)backj2[digito], (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(t4[digito]);
}

int main(int argc, char* argv[]){

    int handler = 0;


    int clientID = simxStart((simxChar*) "127.0.0.1", 19999, true, true, 2000, 5);

    extApi_sleepMs(500);


    if (clientID == -1) {
        printf("Erro conectando ao Coppelia!\n");
        return 0;
    } else {
        printf("Conectado ao Coppelia!\n");
    }

    //Definir ponto central para movimentação do robô (em cima do número 5)
    simxChar handlerName[150] = "/base_link_respondable[0]/joint_3";
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(1000);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)PI/45, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(2000);


    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat) -PI/4, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(12000);
    
    
    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI/11, (simxInt)simx_opmode_oneshot_wait);
    extApi_sleepMs(3000);
    	

    	int digito;
        char numero[6];
        int cont;
        int tam;
        FILE* arq;
        arq = fopen("votos.txt", "r");
        if (arq == NULL) {
            printf("Falha ao acessar o arquivo");
            exit (1);
        }
        else if (arq != NULL) {
            printf("Sucesso ao acessar o arquivo");
            while (!feof(arq)) {
                fscanf(arq, " %[^\n]\n", numero);
                tam = strlen(numero);
                for (cont = 0; cont < tam; cont++) {
                    	digito = numero[cont] - 48;
                    	funcao(digito);
                    }
                    //VOLTANDO PARA O PONTO DEFINIDO

                    strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 4, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(4000);


                    strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 11, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);


                    strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                    simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                    simxSetJointTargetPosition(clientID, handler, (simxFloat)PI/45, (simxInt)simx_opmode_oneshot_wait);
                    extApi_sleepMs(2000);
                    if (cont == tam-1) {
                        //CONFIRMANDO VOTO
                        strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                        simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                        simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 70, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(6000);


                        strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                        simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                        simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 8, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(6000);


                        strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                        simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                        simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 8, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(6000);


                        strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                        simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                        simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 3.55, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(7000);

                        //VOLTANDO PARA O PONTO DEFINIDO
                        strcpy(handlerName, "/base_link_respondable[0]/joint_2");
                        simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                        simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 4, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(4000);


                        strcpy(handlerName, "/base_link_respondable[0]/joint_1");
                        simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                        simxSetJointTargetPosition(clientID, handler, (simxFloat)-PI / 11, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(2000);


                        strcpy(handlerName, "/base_link_respondable[0]/joint_3");
                        simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
                        simxSetJointTargetPosition(clientID, handler, (simxFloat)PI / 45, (simxInt)simx_opmode_oneshot_wait);
                        extApi_sleepMs(2000);
                    }
                }
            }
            fclose(arq);
            //VOLTANDO PARA A POSIÇÃO INICIAL
            strcpy(handlerName, "/base_link_respondable[0]/joint_3");
            simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);


            strcpy(handlerName, "/base_link_respondable[0]/joint_2");
            simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(15000);


            strcpy(handlerName, "/base_link_respondable[0]/joint_1");
            simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(3000);


            strcpy(handlerName, "/base_link_respondable[0]/joint_2");
            simxGetObjectHandle(clientID, handlerName, &handler, (simxInt)simx_opmode_oneshot_wait);
            simxSetJointTargetPosition(clientID, handler, (simxFloat)0, (simxInt)simx_opmode_oneshot_wait);
            extApi_sleepMs(2000);

        }

    simxFinish(clientID);

    return(0);
}
