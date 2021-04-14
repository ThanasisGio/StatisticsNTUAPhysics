void Askisi25()
{
  TCanvas *c1 = new TCanvas("c1","Correlation of X,Y",500,500,700,500);
  TRandom *u = new TRandom();
  u->SetSeed(0);
  TRandom *v = new TRandom();
  v->SetSeed(0);
  Double_t x[1000];
  Double_t y[1000]; 
  Int_t    n = 1000;  
  for (int i=0;i<1000;i++)
  {
	double r1 = u->Gaus(0,1.3);
	double r2 = v->Gaus(0,0.7);
	x[i] = (r1+r2)/2 ;
	y[i] = (r1-r2)/2 ;
  }
  TGraph  *g = new TGraph(n,x,y);
  g->Draw("ap*");
}