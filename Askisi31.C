void Askisi31()
{ 
  TRandom *r1 = new TRandom();
  r1->SetSeed(0);
  double ly[1000]; 
  double  x[1000];
  double tf[1000];
  double lf = 0;
  double l  = 0;
  int f[12] = {8,3,4,1,4,4,6,6,2,4,8,7};
  int y     = 1;
  double ln = 0;
  int   sum = 0;
  int     m = 0;
  for(int j=0;j<12;j++)
  {
	  int z = f[j];
          y = y*z;
		 sum= sum + z;
  }
  m = sum/12;  
  
  for(int i=0;i<1000;i++)
  {
    double n = 0.01*i;	  
	ly[i] = -12*n + sum*log(n+0.01) - 38.26 ; //53
	 x[i] = n+0.01;
	tf[i] = -6.45-0.5*(57/(4.75*4.75))*(n+0.01-4.75)*(n+0.01-4.75);
	//21.19
  }
  TGraph *g    = new TGraph(1000,x,ly);
  TGraph *g2    = new TGraph(1000,x,tf);
  g->SetTitle("ln(L(m));m;ln(L(m))");
  TCanvas *c1 = new TCanvas("c1","ln(L(m))",500,500,700,500);
  //g->GetXaxis()->SetRangeUser(0,10);
  g->Draw();
  g2->SetLineColor(2);
  g2->Draw("Same");
 //--------add legend--------------------------------------------------------------
  TLegend*  legend = new TLegend(0.7,0.7,0.5,0.5);
  legend->AddEntry(g,"ln(L(m))");
  legend->AddEntry(g2,"Parabola Approximation");
  legend->Draw("same");

}
