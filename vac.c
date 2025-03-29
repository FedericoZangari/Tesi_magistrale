#include <iostream>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TAxis.h>
using namespace std;


void vac(){

    TCanvas* c = new TCanvas("c","c");
	TLegend *leg = new TLegend(0.38, 0.15, 0.85, 0.45);
    const int n = 11;
    
	double x[n] = {0, 2, 6, 17, 20, 29, 46, 61, 85, 100, 205}; // Ascisse
    double y[n] = {6E-2, 8E-2, 1.35E-1, 2.65E-1, 3.00E-1, 3.85E-1, 5.16E-1, 6.20E-1, 7.32E-1, 7.98E-1, 1.13}; // Ordinate
    double ey[n] = {1E-3, 1E-3, 1E-3, 1E-3, 1E-3, 1E-3, 1E-3, 1E-3, 1E-3, 1E-3, 1E-2}; // Errori su y
    double ex[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Errori su x
    
    TGraphErrors *g = new TGraphErrors(n, x, y, ex, ey);
    
    g->SetTitle("Vacuum leak");
    
        g->SetMarkerStyle(8);                           // plot cosmetic
        g->SetMarkerSize(0.8);
        g->SetLineColorAlpha(1, 0.2);
        g->SetMarkerColorAlpha(kRed, 0.9);
    
        g->GetXaxis()->SetTitle("Time [minutes]");
        g->GetYaxis()->SetTitle("Pressure [mbar]");
        g->GetYaxis()->SetRangeUser(1E-2,1.4);

        g->Draw("A PL");
        

        //leg->AddEntry(g, TString::Format( "Sensor %s" , title[i].c_str()), "ep");
    
    //gPad->SetLogy();
    
        
        
    /*leg->SetTextSize(0.03);
    leg->SetTextFont(42);
    leg->SetBorderSize(0);
    leg->SetNColumns(2);
    leg->Draw();
*/
    c->SaveAs("vac.png");
    

}

