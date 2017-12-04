#ifndef NRAINHAS
#define NRAINHAS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string convStr(int i){
    stringstream ss;
    ss << i;
    return ss.str();
}

class NRainhas{
    string nR;
public:
    NRainhas(string _valor) {
        nR = _valor;
    }
    void gegarArquivo(){
        ofstream f_out;
        vector<string> vFormulas;
        string sFormulas("");
        int numRai = stoi(nR);
        int nAtomos = numRai*numRai;
        string txt = "rainhas" + nR ;

            f_out.open(txt+".cnf");
            if(! f_out.good())
                cout << "Não foi possivel abrir o arquivo!\n";
            else cout << "Arquivo criado!\n";

            //Posicionando Linhas
            int quebraLinha = 0;
            for(int i = 0; i <= nAtomos; i++){
                if(quebraLinha == numRai){
                    sFormulas += "0";
                    quebraLinha = 0;
                    vFormulas.push_back(sFormulas);
                    sFormulas = "";
                }
                sFormulas += convStr(i+1) + " ";
                quebraLinha++;
            }
            sFormulas = "";

            //Posicionando Colunas
            int auxColuna = 1;
            int auxColuna2 = 0;
            while(auxColuna <= numRai){
                auxColuna2 = auxColuna;
                sFormulas += convStr(auxColuna2) + " ";
                for(int i = 0; i < numRai-1; i++ ){
                    auxColuna2 += numRai;
                    sFormulas += convStr(auxColuna2) + " ";
                }
                sFormulas += "0";
                vFormulas.push_back(sFormulas);
                sFormulas = "";
                auxColuna++;
            }
            sFormulas = "";

            //Exclusão de repetição de linhas
            int auxExLin = 1, cColLi = 1;
            while (auxExLin <= nAtomos){
                int auxExLin2 = auxExLin;
                while(cColLi < numRai){
                    for(int i = 0; i < (numRai - cColLi); i++){
                        auxExLin2++;
                        sFormulas += "-" + convStr(auxExLin) + " -" + convStr(auxExLin2) + " 0";
                        vFormulas.push_back(sFormulas);
                        sFormulas = "";
                    }
                    cColLi++;
                    auxExLin++;
                    auxExLin2 = auxExLin;
                }
                    auxExLin += 1;
                    cColLi = 1;
            }
            sFormulas = "";

            //Exclusão de repetição nas colunas
            int auxExCol = 1, cColu = 1;
            int cLinha = 1;
            while (auxExCol <= nAtomos){
                int auxExCol2 = auxExCol;
                while(cColu <= numRai){
                    for(int i = 0; i < (numRai - cLinha); i++){
                        auxExCol2 += numRai;
                        sFormulas += "-" + convStr(auxExCol) + " -" + convStr(auxExCol2) + " 0";
                        vFormulas.push_back(sFormulas);
                        sFormulas = "";
                    }
                    cColu++;
                    auxExCol++;
                    auxExCol2 = auxExCol;
                }
                    cLinha++;
                    cColu = 1;
            }
            sFormulas = "";

            //Exclusão de repetição nas diagonais primarias
            int auxDiaPri = 1, auxDiapri2 = 0;
            while(auxDiaPri <= nAtomos){
                int coluna = 1, linha = 1;
                auxDiapri2 = auxDiaPri;
                while(coluna <= numRai){
                    for(int i = 0; i < (numRai - linha); i++ ){
                        auxDiapri2 += numRai + 1;
                        if(auxDiapri2 <= nAtomos){
                            sFormulas += "-" + convStr(auxDiaPri) + " -" + convStr(auxDiapri2) + " 0";
                            vFormulas.push_back(sFormulas);
                            sFormulas = "";
                        }
                    }
                    linha++;
                    auxDiaPri++;
                    auxDiapri2 = auxDiaPri;
                    coluna++;
                }
            }
            sFormulas = "";

            //Exclusão de repetição nas diagonais secundárias
            int auxPriCol = 1;
            int auxDiaSec = 2, auxDiaSec2 = 0;
            while(auxDiaSec <= nAtomos){
                int coluna = 1, linha = 1;
                auxDiaSec2 = auxDiaSec;
                while(coluna <= numRai){
                    for(int i = 0; i < linha; i++ ){
                        auxDiaSec2 += numRai - 1;
                        if(auxDiaSec2 <= nAtomos){
                            if(auxDiaSec != ((numRai*auxPriCol)+1)){
                                sFormulas += "-" + convStr(auxDiaSec) + " -" + convStr(auxDiaSec2) + " 0";
                                vFormulas.push_back(sFormulas);
                                sFormulas = "";
                            }
                        }
                    }
                    auxDiaSec++;
                    linha++;
                    auxDiaSec2 = auxDiaSec;
                    coluna++;
                }
                auxPriCol++;
            }
            sFormulas = "";

            //Guardar em arquivo
            f_out << "p cnf " << nAtomos << " " << vFormulas.size() << endl;
            for(string ele : vFormulas){
                f_out << ele << endl;
            }

            f_out.close();
    }

};


#endif // NRAINHAS

