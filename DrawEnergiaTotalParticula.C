void DrawEnergiaTotalParticula(){
	TFile *ficheiro= new TFile("EnergiaFinal.root","READ");

	TCanvas *cs = new TCanvas("Energia total depositada por particulas", "Energia total depositada por particulas");		
	
	TH1D *pioes=(TH1D*)ficheiro->Get("Pioes");
	TH1D *muoes=(TH1D*)ficheiro->Get("Muoes");
	TH1D *outras=(TH1D*)ficheiro->Get("Outras Particulas");

	THStack *hs = new THStack("hs","Energia depositada por particulas;Energia (keV); log(Tempo(ns))");
	hs->Add(pioes);
	hs->Add(muoes);
	hs->Add(outras);
	hs->Draw("nostack");


	auto legend = new TLegend(0.7,0.7,0.9,0.9);
	TLegendEntry *ds=legend->AddEntry("muoes","Muoes","l");
	ds->SetLineColor(2);

	ds=legend->AddEntry("pioes","Pioes","l");
	ds->SetLineColor(1);

	ds=legend->AddEntry("outras","Outras","l");
	ds->SetLineColor(3);
    
	legend-> Draw();
    

	gPad->SetLogy();

	cs->SaveAs("/home/rosas/Desktop/TrabalhoTECII/Graficos/alinea3/Histograma Soma ETotal Particula.png");
	ficheiro->Close();


}
