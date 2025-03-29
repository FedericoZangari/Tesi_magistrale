#include <iostream>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TAxis.h>
using namespace std;


void plot_peltier(){

    TCanvas* c = new TCanvas("c","c");
	TLegend *leg = new TLegend(0.62, 0.39, 0.9, 0.69);
    const int n = 5;
    const int n2 = 3;
    
	double x[n] = {5, 10, 15, 20, 25}; // Ascisse
    double hot[n] = {33.9, 45, 56.1, 61.2, 69}; // Ordinate
    double cold[n] = {22.7, 21.9, 22.8, 23.3, 22.5}; // Ordinate
    double ey[n] = {0.5, 0.5, 0.5, 0.5, 0.5}; // Errori su y
    double ex[n] = {0.1, 0.1, 0.1, 0.1, 0.1}; // Errori su x

    double x2[n2] = {10, 15, 20}; // Ascisse
    double hot2[n2] = {42.4, 55, 67.3}; // Ordinate
    double cold2[n2] = {10.5, 10.6, 11.3}; // Ordinate
    double ey2[n2] = {0.5, 0.5, 0.5}; // Errori su y
    double ex2[n2] = {0.1, 0.1, 0.1}; // Errori su x
    
    TGraphErrors *g_hot = new TGraphErrors(n, x, hot, ex, ey);
    TGraphErrors *g_cold = new TGraphErrors(n, x, cold, ex, ey);

    TGraphErrors *g_hot2 = new TGraphErrors(n2, x2, hot2, ex, ey);
    TGraphErrors *g_cold2 = new TGraphErrors(n2, x2, cold2, ex, ey);
    
    g_hot->SetTitle("Peltier characterization");
    
        g_hot->SetMarkerStyle(8);                           // plot cosmetic
        g_hot->SetMarkerSize(1);
        g_hot->SetLineColorAlpha(1, 0.2);
        g_hot->SetMarkerColorAlpha(kRed, 0.9);

        g_cold->SetMarkerStyle(22);                          
        g_cold->SetMarkerSize(1.5);
        g_cold->SetLineColorAlpha(1, 0.2);
        g_cold->SetMarkerColorAlpha(kRed, 0.9);

        g_hot2->SetMarkerStyle(8);                           
        g_hot2->SetMarkerSize(1);
        g_hot2->SetLineColorAlpha(1, 0.2);
        g_hot2->SetMarkerColorAlpha(kBlue, 0.9);

        g_cold2->SetMarkerStyle(22);                          
        g_cold2->SetMarkerSize(1.5);
        g_cold2->SetLineColorAlpha(1, 0.2);
        g_cold2->SetMarkerColorAlpha(kBlue, 0.9);
    
        g_hot->GetXaxis()->SetTitle("Voltage [V]");
        g_hot->GetYaxis()->SetTitle("Temperature [#circ C]");
        g_hot->GetYaxis()->SetRangeUser(5,70);

        g_hot->Draw("A P");
        g_cold->Draw("Psame");
        g_hot2->Draw("Psame");
        g_cold2->Draw("Psame");
        
        leg->AddEntry(g_hot2, "Hot side (1 Peltier)", "ep");
        leg->AddEntry(g_cold2, "Cold side (1 Peltier)", "ep");
    
        leg->AddEntry(g_hot, "Hot side (2 Peltier)", "ep");
        leg->AddEntry(g_cold, "Cold side (2 Peltier)", "ep");
        
    //gPad->SetLogy();
    
        
        
    leg->SetTextSize(0.03);
    leg->SetTextFont(42);
    leg->SetBorderSize(0);
    //leg->SetNColumns(2);
    leg->Draw();

    c->SaveAs("cooling_peltier.png");
    

}

