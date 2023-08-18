#include "heap.hpp"
#include "Palavra.hpp"
#include "hash.hpp"
#include <iostream>
#include <vector>
using namespace std;
#define k 4;
int main(){
    
   // int x[8] = {7,6,5,4,3,2,1,9};
   int contpessoas=0;
    Palavra p("Carlos"),p2("joao"),p3("y"),p4("aaaa");
    contpessoas=4;
    
    for(int i=0;i<10;i++){
        p.add();
        if(i>0){
            p2.add();
        }
        if(i>1){
            p3.add();
        }
        if(i>2){
            p4.add();
        }
    }
    int y=k;
    Palavra vp[y]={p,p2,p3,p4};
 
   for(int i=0;i<contpessoas;i++){
    vp[i].imprime();

   }
   cout << "\n\n";
   heap h(contpessoas,vp);
   h.imprime();
    cout << "\n\n\n";

    Palavra o("lsdsdasda");
    for(int i=0;i<30;i++){
        o.add();
    }
    h.addPalavra(o);

    cout <<"\n\n\n";
    h.imprime();
    cout <<"\n\n\n";
    tabelaHash a;
    a.teste();
    cout <<"\n\n\n";
    /*heap h(4,vp);
    cout << "\n\n";
    h.imprime();
    cout << "\n\n";
    cout << "\n\n";*/


}