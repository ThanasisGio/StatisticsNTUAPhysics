void Askisi21()
{
  TH1D *histogram = new TH1D("histogram","Distribution of u = x/y, x,y following N(0,1) distribution",100,-50.0,50.0);
  TRandom *r1 = new TRandom();
  TRandom *r2 = new TRandom();
  r1->SetSeed(0);
  r2->SetSeed(0);
  
  for(int i=0 ; i<1000 ; i++)
  {
	  double x = r1->Gaus(0,1);
	  double y = r2->Gaus(0,1);
	  double u = x/y ;
	  histogram->Fill(u); 
  }
	histogram->Draw();
}