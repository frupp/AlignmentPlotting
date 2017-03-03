#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TString.h"
#include <iostream>
#include <vector>


/*



// Zu implementieren: Vektor aus Hist-Pointern
// Prinzip: Histogramm initialisieren, füllen, Hist-Pointer darauf setzen und in Vektor schreiben
// Ursprünglichen Hist-Vektor verschieben und löschen
// 
// Prozedur für alle Hist-Teile wiederholen
// ->Zugriff auf einzelne Histogramme mithilfe des Pointer-Vektors, 
// 


*/




// Zusatzfunktionen : Teile von einem Alignment parallel darstellen & zusammen ausgeben

std::vector<double> getBoundaries(const TString& variable) { // Grenzen fuer die einzelnen Variablen einlesen
    std::vector<double> boundaries;
    
    if( variable == "r" ) {
        boundaries.push_back(2.);
        boundaries.push_back(6.);
        boundaries.push_back(10.);
        boundaries.push_back(14.);
        boundaries.push_back(18.);
        // + andere werte
    } else if( variable == "phi" ) {
        double pi = 3.14;
        boundaries.push_back(- pi);
        boundaries.push_back(- pi /2.);
        boundaries.push_back(0.);
        boundaries.push_back(pi /2.);
        boundaries.push_back(pi);
    }
    return boundaries;
}


// Plotfunktion, in der der ganze Plotvorgang stattfindet

void plotVariable(const TString& fileName, const TString& variablex, const TString& variabley, int nbins  /*, double min, double max*/) {
    std::vector<double> boundaries = getBoundaries(variablex);
    
    TFile f (fileName, "READ");
    TTree* tree = 0;
    f.GetObject("alignTree", tree);
    
    int level = -1;
    int sublevel = -1;
    
    
    
    
    
    // th1... (ist eingebaut)
    TH1D* hist = new TH1D("hist", "plot", nbins, -(0.1), 0.1);
    hist->SetDirectory(0);
    
    TH1D* hist1 = new TH1D("hist1", "plot", nbins, -(0.1), 0.1);
    hist1->SetDirectory(0);
    
    TH1D* hist2 = new TH1D("hist2", "  plot", nbins, -(0.1), 0.1);
    hist2->SetDirectory(0);
    
    TH1D* hist3 = new TH1D("hist3", "plot", nbins, -(0.1), 0.1);
    hist3->SetDirectory(0);
    // const unsigned int nBoundaries = boundaries.size()-1;
    
    float varnumx = 0.;
    float varnumy = 0.;
    int counter = -1;
    tree->SetBranchAddress(variablex, &varnumx);
    tree->SetBranchAddress(variabley, &varnumy);
    tree->SetBranchAddress("level", &level);
    tree->SetBranchAddress("sublevel",&sublevel);
    // std::cout << varnumx << "here the initial values " << varnumy << endl;
    
    for(int i = 0; i < 4; ++i){
        // std::cout << boundaries[i] << " ist aktuelle grenze und  " << boundaries[i+1] << endl;
        counter = 0;
        for(int iE = 0; iE < tree->GetEntries(); iE++){
            
            tree->GetEntry(iE);
            if(level!=1 || sublevel!=1 || varnumx < boundaries[i] || varnumy > boundaries[i+1]) continue;
            
            
            if(i==0) hist->Fill(varnumy);
            else if(i==1) hist1->Fill(varnumy);
            else if(i==2) hist2->Fill(varnumy);
            else if(i==3) hist3->Fill(varnumy);
        }
        //std::cout << "In der Schleife!" << endl;
    }
    
    hist->SetLineColor(1);
    hist1->SetLineColor(2);
    hist2->SetLineColor(3);
    hist3->SetLineColor(4);
    
    hist->Draw();
    hist1->Draw("same");
    hist2->Draw("same");
    hist3->Draw("same");
    
    
    
    
}


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
    plotVariable("designGT_vs_realigned.Comparison_commonTracker_autoRange.root", varx, vary, 20);
   
  
  
  
  
  

}








