void Askisi51()
{
  TRandom *r = new TRandom();
  r->SetSeed(0);
  Double_t b = TMath :: ErfInverse(-0.9);
  Double_t c = TMath :: ErfInverse(0.9);
  double x[100];
  double x1[100];
  double x2[100];
  for(int i=0;i<100;i++)
  { 
	double m = r->Uniform(10,30);
	   x1[i] = m + sqrt(2)*b;
	   x2[i] = m + sqrt(2)*c;
	   x[i]  = m;
  
  }
  TGraph *g1    = new TGraph(100,x,x1);
  TGraph *g2    = new TGraph(100,x,x2);
  g1->SetTitle("Confidence belt;x;m");
  TCanvas *c1 = new TCanvas("c1","m",500,500,700,500);
  //g->GetXaxis()->SetRangeUser(0,10);
  g1->Draw();
  g2->SetLineColor(2);
  g2->Draw("Same");
}