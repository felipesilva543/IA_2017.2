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

            //Ou exclusivo de linhas
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

            //Ou exclusivo de colunas
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
            int auxEx1 = 1, cont = 1;
            while (auxEx1 <= nAtomos){
                int auxEx2 = auxEx1;
                while(cont < numRai){
                    for(int i = 0; i < (numRai - cont); i++){
                        auxEx2++;
                        sFormulas += "-" + convStr(auxEx1) + " -" + convStr(auxEx2) + " 0";
                        vFormulas.push_back(sFormulas);
                        sFormulas = "";
                    }
                    cont++;
                    auxEx1++;
                    auxEx2 = auxEx1;
                }
                    auxEx1 += 1;
                    cont = 1;
            }
            sFormulas = "";

            //Exclusão de repetição de colunas
            auxEx1 = 1, cont = 1;
            int cont2 = 1;
            while (auxEx1 <= nAtomos){
                int auxEx2 = auxEx1;
                while(cont <= numRai){
                    for(int i = 0; i < (numRai - cont2); i++){
                        auxEx2 += numRai;
                        sFormulas += "-" + convStr(auxEx1) + " -" + convStr(auxEx2) + " 0";
                        vFormulas.push_back(sFormulas);
                        sFormulas = "";
                    }
                    cont++;
                    auxEx1++;
                    auxEx2 = auxEx1;
                }
                    cont2++;
                    cont = 1;
            }
            sFormulas = "";

            //Exclusão de diagonais primarias
            int auxDia = 1, auxDia2 = 0;
            while(auxDia <= nAtomos){
                int col1 = 1, lin1 = 1;
                auxDia2 = auxDia;
                while(col1 <= numRai){
                    for(int i = 0; i < (numRai - lin1); i++ ){
                        auxDia2 += numRai + 1;
                        if(auxDia2 <= nAtomos){
                            sFormulas += "-" + convStr(auxDia) + " -" + convStr(auxDia2) + " 0";
                            vFormulas.push_back(sFormulas);
                            sFormulas = "";
                        }
                    }
                    lin1++;
                    auxDia++;
                    auxDia2 = auxDia;
                    col1++;
                }
            }
            sFormulas = "";

            //Exclusão de diagonais secundárias
            int auxDeContagem = 1;
            auxDia = 2, auxDia2 = 0;
            while(auxDia <= nAtomos){
                int col1 = 1, lin1 = 1;
                auxDia2 = auxDia;
                while(col1 <= numRai){
                    for(int i = 0; i < lin1; i++ ){
                        auxDia2 += numRai - 1;
                        if(auxDia2 <= nAtomos){
                            if(auxDia != ((numRai*auxDeContagem)+1)){
                                sFormulas += "-" + convStr(auxDia) + " -" + convStr(auxDia2) + " 0";
                                vFormulas.push_back(sFormulas);
                                sFormulas = "";
                            }
                        }
                    }
                    auxDia++;
                    lin1++;
                    auxDia2 = auxDia;
                    col1++;
                }
                auxDeContagem++;
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

