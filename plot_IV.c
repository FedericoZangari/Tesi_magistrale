#include <iostream>
using namespace std;

TGraphErrors* ReadFillGraph(string filename){

    double v, i, i_err;
	string line;
    int k = 0;

    TGraphErrors* g = new TGraphErrors();

    ifstream f;
    f.open(filename.c_str(), ios::in);          // open data file
    if(!f){
		        cout << "error: cannot open file" << endl;
		        exit(0);
	}

    getline(f,line);        // remove header line

    while (getline(f, line)) {      // read data from file
        stringstream ss(line);
        string token;

        getline(ss, token, ',');       // get data separated with ','
        v = stod(token);
        getline(ss, token, ',');
        i = abs(1E6 * stod(token)) ;
        getline(ss, token, ',');
        i_err = 1E6 * stod(token);
        
        g->SetPoint(k,v,i);                                 // fill TGraph
        g->SetPointError(k, 0.0, i_err);

        k++;
        
    }
    if(f.eof()){
			cout << "End of file reached" << endl;
            f.close();
	}

    return g;
}



void plot_IV(){
	TCanvas* c = new TCanvas("c","c");
	TLegend *leg = new TLegend(0.38, 0.15, 0.85, 0.45);
    int N = 12;
	
	vector<string> title = {"W7T39450P01",
                            "W7T39450P02",
                            "W7T39450P03",
                            "W7T39450P04",
                            "W7T39450P06",
                            "W7T39450P08",
                            "W7T39450P10",
                            "W7T39450P11",
                            "W7T39450P12",
                            "W7T39450P13",
                            "W7T39450P14",
                            "W7T39450P15"};

    vector<string> title1;
    for(int i = 0; i < N; i++){
        title1.push_back("./RUN74/_" + title[i] + ".txt");
    }
    
    for(int i = 0; i < N; i++){
        TGraphErrors* g = ReadFillGraph(title1[i]);
    
        g->SetMarkerStyle(8);                           // plot cosmetic
        g->SetMarkerSize(0.7);
        g->SetLineColorAlpha(1, 0.1);
        if(i == 1 ) g->SetMarkerColorAlpha(kRed, 0.9);
        if(i == 7 ) g->SetMarkerColorAlpha(kRed+2, 0.9);
        if(i == 9 ) g->SetMarkerColorAlpha(kRed-7, 0.9);
        if(i == 11 ) g->SetMarkerColorAlpha(kRed-2, 0.9);
        if(i !=1 && i != 7 && i != 9 && i != 11) g->SetMarkerColorAlpha(kSpring+i, 0.7);
    
        g->SetTitle("IV curves");
        g->GetXaxis()->SetTitle("V_{bias} [V]");
        g->GetYaxis()->SetTitle("Leakage current [#muA]");
        g->GetYaxis()->SetRangeUser(1E-4,1);

        if(i == 0) g->Draw("A RX PL");
        else g->Draw("same RX PL");

        leg->AddEntry(g, TString::Format( "Sensor %s" , title[i].c_str()), "ep");
    }
    gPad->SetLogy();
    
        
        
    leg->SetTextSize(0.03);
    leg->SetTextFont(42);
    leg->SetBorderSize(0);
    leg->SetNColumns(2);
    leg->Draw();

    c->SaveAs("IV_12_tiles_lumiTracker.png");
    

}