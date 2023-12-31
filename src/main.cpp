#include "heap.hpp"
#include "Palavra.hpp"
#include "hash.hpp"
#include "bloco.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<locale>
#include <codecvt>

using namespace std;
const int numberOfFiles = 2;

char toLowerAccent(char c) {

    int aux = c;

    if (aux == -61)
        return -61;
    else if (aux >= -128 && aux <= -118)
        return (aux + 32);
    else if (aux == -115)
        return (aux + 32);
    else if (aux == -113)
        return (aux + 32);
    else if (aux == -109)
        return (aux + 32);
    else if (aux == -108)
        return (aux + 32);
    else if (aux == -107)
        return (aux + 32);
    else if (aux == -102)
        return (aux + 32);
    else if (aux == -100)
        return (aux + 32);

    return tolower(c);
}

int main() {
    std::setlocale(LC_ALL, "pt_BR.utf8");
    std::wcout.imbue(std::locale());

    tabelaHash hp;
    for (int i = 1; i <= numberOfFiles; i++) {
        tabelaHash hpt;
        string fileName, a, str;
        stringstream ss;
        ss << i;
        ss >> a;
        fileName = "dataset/input";
        fileName.append(a).append(".txt");
        std::cout << "\n\nfileame:" << fileName << "\n\n";
        ifstream file(fileName);
        if (file.is_open()) {
            string strPalavra;
            while (getline(file, str)) {
                if (str.size() > 0) {
                    for (int j = 0;j < (int)str.size();j++) {
                        if (str[j] != '/' && str[j] != '.' && str[j] != ',' && str[j] != '!' && str[j] != '?' && str[j] != ' ' && str[j] != '\n' && str[j] != ';' && str[j] != ':' && str[j] != '-' && str[j] != '"' && str[j] != '\t' && str[j] != '\\' && str[j] != '(' && str[j] != ')' && str[j] != '[' && str[j] != ']' && str[j] != '{' && str[j] != '}' && str[j] != '=' && str[j] != '+' && str[j] != '"') {
                            str[j] = toLowerAccent(str[j]);
                            strPalavra.push_back(str[j]);
                        } else if (str[j] == '-') {
                            if (str[j + 1] == '-' || (j != 0 && str[j - 1] == '-')) {
                                if (strPalavra != "") {
                                    Palavra p(strPalavra);
                                    hpt.inserir(p);
                                    strPalavra = "";
                                }

                            } else {
                                str[j] = toLowerAccent(str[j]);
                                strPalavra.push_back(str[j]);
                            }
                        } else {
                            if (strPalavra != "") {
                                Palavra p(strPalavra);
                                hpt.inserir(p);
                                strPalavra = "";
                            }
                        }
                    }
                    if (strPalavra != "") {
                        Palavra p(strPalavra);
                        hpt.inserir(p);
                        strPalavra = "";
                    }

                }

            }
            file.close();
        } else {
            std::cout << "\n\nFile não encontrado\n\n\n";
        }
        hpt.imprimeCont();
        std::cout << "\n\nHEAP:\n\n";
        hpt.mostraHeap();
        std::cout << "\n\n\n";

    }
    return 0;
}