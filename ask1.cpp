{
  TH1D *histo = new TH1D("histo","Distribution of x/y, both following N(0,1);x/y;counts",120,-30.0,30.0);
  TRandom *rnd1 = new TRandom();
  TRandom *rnd2 = new TRandom();
  rnd1->SetSeed(0);
  rnd2->SetSeed(0);
  
  for(int i=0 ; i<1000 ; i++){
    histo->Fill(rnd1->Gaus(0,1)/rnd2->Gaus(0,1));
  }

   histo->Draw();
  
   /*  histo->Scale(1/histo->Integral());
  
  TCanvas *c = new TCanvas("askhsh1","",0,0,700,500);
  histo->SetLineWidth(2);
  histo->Draw();


  TF1 *f1 = new TF1("f1","[0]/(3.14159*(1+([1]*x)^2))",-30.0,30.0);
  f1->SetParameters(1,1);
  f1->Draw("same");

  histo->Fit("f1");
  
  TFile f("histos.root","recreate");
  c->Write();
  histo->Write();
   */
}
