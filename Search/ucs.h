#ifndef UCS_H
#define UCS_H

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "enum.h"
#include "grafo.h"
#include "state.h"
#include "node.h"

//Classe para ordenação dos elementos da fila com prioridade
class CompCusto{
public:
    bool operator()(Node no1, Node no2){
        return no1.getCustoDeCaminho() > no2.getCustoDeCaminho();
    }
};

class Uniform_Cost_Search
{
public:
    Uniform_Cost_Search(){}

    vector<Node> UCS(State _origem, State _destino, Grafo grafo){

        //Inicializando no raiz do grafo
        Node noInit;
        noInit.setAction(Action(_origem, _destino));
        noInit.setCustoDeCaminho(0);
        noInit.setPai(nullptr);
        noInit.setState(State(_origem.getState()));
        //Finalizando no raiz do grafo

        // DECRARANDO BORDA, ORDENA PELO MENOR CUSTO DOS ELEMENTO
        priority_queue<Node, vector<Node>, CompCusto > borda;
        vector<Node> resp;

        //Verificando se o estado inicial é o destido, se sim retorna o resultado
        if(noInit.getStateNode().getState() == _destino.getState()){
            return resp;
        }
        //fim_verif_

        //Se não for add na borda
        borda.push(noInit);

        //Declarando explorados
        bool viewed[TAM_MAPA];
        for(int i = 0; i <  TAM_MAPA; i++){
            viewed[i] = false;
        }
        //fim_dec_expl

        while (true) {
            //Verificando se borda está vazia, se sim, lança uma exceção de erro
            if(borda.empty()){
                throw string("Falha pois borda está vazia!\n");
            }
            //fim_Verif_

            //Pegando o que esta da borda, no top
            noInit = borda.top();

            //Retirando da borda
            borda.pop();

            // Verifica se nó corrente é a solução
            if((noInit.getStateNode().getState()) == _destino.getState()){
                return resp;
            }

            //Setando que o nó foi explorado
            int localAtual = noInit.getStateNode().getState();
            if(!viewed[localAtual]){
                cout << "Visitando " << localAtual << "..." << endl;
                resp.push_back(noInit);
                viewed[localAtual] = true;
            }
            //fim_Tirando

            int COLUNA;
            for(COLUNA = 0; COLUNA < TAM_MAPA; COLUNA++){
                if(grafo.getPeso(localAtual, COLUNA)){
                    Node newNo = Node(State(COLUNA), &noInit, Action(localAtual, COLUNA), (noInit.getCustoDeCaminho() + grafo.getPeso(localAtual, COLUNA)));
                    if(!viewed[newNo.getStateNode().getState()]){//falta verificar se o objeto n esta na borda
                        borda.push(newNo);
                    }
                    else{

                        //Fila uxiliar que vai receber os valores da borda, enquanto verifico a repetição
                        priority_queue<Node, vector<Node>, CompCusto >  filaAux;
                        /*Enquanto borda não estiver vazia, se o no corrente for o msm que
                          ta na borda e custo tiver menor, troca-los */
                        while(!borda.empty()){
                            Node noAux = borda.top();
                            borda.pop();
                            if(noAux.getStateNode().getState() == newNo.getStateNode().getState()){
                                if(newNo.getCustoDeCaminho() < noAux.getCustoDeCaminho()){
                                    filaAux.push(newNo);
                                }
                                filaAux.push(noAux);
                            }else{
                                filaAux.push(noAux);
                            }
                        }
                        //Passando da fila auxiliar para a borda
                        swap(filaAux,borda);
                    }
                }
            }
        }
    }
};

#endif // UCS_H
