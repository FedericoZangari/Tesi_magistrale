#include <iostream>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TAxis.h>
using namespace std;


void plot_fan(){

    TCanvas* c = new TCanvas("c","c");
	TLegend *leg = new TLegend(0.14, 0.59, 0.5, 0.87);
    const int n = 5;
    const int n2 = 3;
    
	double x[n] = {5, 10, 15, 20, 25}; // Ascisse
    double hot[n] = {31.4, 36, 42.4, 49.3, 58.6}; // Ordinate
    double cold[n] = {25.3, 21.2, 20, 20.6, 23}; // Ordinate
    double sensor[n] = {37.8, 34.6, 33.8, 34.3, 37}; // Ordinate
    double ey[n] = {0.5, 0.5, 0.5, 0.5, 0.5}; // Errori su y
    double ex[n] = {0.1, 0.1, 0.1, 0.1, 0.1}; // Errori su x


    
    TGraphErrors *g_hot = new TGraphErrors(n, x, hot, ex, ey);
    TGraphErrors *g_cold = new TGraphErrors(n, x, cold, ex, ey);
    TGraphErrors *g_sensor = new TGraphErrors(n, x, sensor, ex, ey);

   
    
    g_hot->SetTitle("Peltier characterization:  Fan cooling");
    
        g_hot->SetMarkerStyle(8);                           // plot cosmetic
        g_hot->SetMarkerSize(1);
        g_hot->SetLineColorAlpha(1, 0.2);
        g_hot->SetMarkerColorAlpha(kRed, 0.9);

        g_cold->SetMarkerStyle(8);                          
        g_cold->SetMarkerSize(1.2);
        g_cold->SetLineColorAlpha(1, 0.2);
        g_cold->SetMarkerColorAlpha(kBlue, 0.9);

        g_sensor->SetMarkerStyle(8);                           
        g_sensor->SetMarkerSize(1);
        g_sensor->SetLineColorAlpha(1, 0.2);
        g_sensor->SetMarkerColorAlpha(kGreen, 0.9);

       
    
        g_hot->GetXaxis()->SetTitle("Voltage [V]");
        g_hot->GetYaxis()->SetTitle("Temperature [#circ C]");
        g_hot->GetYaxis()->SetRangeUser(15,65);

        g_hot->Draw("A P");
        g_cold->Draw("Psame");
        g_sensor->Draw("Psame");

        leg->AddEntry(g_hot, "Hot side ", "ep");
        leg->AddEntry(g_cold, "Cold side ", "ep");
        leg->AddEntry(g_sensor, "Sensor", "ep");
        leg->AddEntry((TObject*)0, "Heater ON 15 W","");
    //gPad->SetLogy();
    
        
        
    leg->SetTextSize(0.03);
    leg->SetTextFont(42);
    leg->SetBorderSize(0);
    //leg->SetNColumns(2);
    leg->Draw();

    c->SaveAs("cooling_fan.png");
    

}

