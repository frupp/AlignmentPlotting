#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TString.h"
#include <iostream>
#include <vector>
#include "plotting.h"


/*



// Zu implementieren: Vektor aus Hist-Pointern
// Prinzip: Histogramm initialisieren, füllen, Hist-Pointer darauf setzen und in Vektor schreiben
// Ursprünglichen Hist-Vektor verschieben und löschen
// 
// Prozedur für alle Hist-Teile wiederholen
// ->Zugriff auf einzelne Histogramme mithilfe des Pointer-Vektors, 
// 


*/





// Plotfunktion, in der der ganze Plotvorgang stattfindet



// Untersucht, ob plotvariablen gültig sind, also tatsächlich gültige größen
bool checkd(const TString& zeug){
    if(zeug == "dr") return true;
    if(zeug == "dphi") return true;
    return false;
}

bool check(const  TString& zeug){
    if(zeug == "r") return true;
    if(zeug == "phi") return true;
    return false;
}


void bastelplot() {
  

    TString varx;
    TString vary;
    int numbin = -1;
    double binwidth = 0.;
    do {
        std::cout << "Welchen y-wert plotten?(dr dphi etc)" << endl;
        std::cin >> vary;
        
    } while (!checkd(vary));
    do {
        std::cout << "Gegen welchen Wert? (r phi etc)" << endl;
        std::cin >> varx;
        
    } while (!check(varx));
  
  //std::cout << "Wie breit?" << endl;
  //std::cin >> binwidth;
  //std::cout << "Wie viele bins?" << endl;
  //std::cin >> numbin;
    /*Plotting* plotObject = new */Plotting("designGT_vs_realigned.Comparison_commonTracker_autoRange.root", varx, vary, 15, -0.1, 0.1);
    
  
  
  
  
  

}









