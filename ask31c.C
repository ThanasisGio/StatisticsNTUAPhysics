void ask31c()
{
 double ln[1000];
 double  y[1000];
 double  x[1000];
  for (int i=0;i<1000;i++)
  {
    ln[i] = 57*log(((0.01*i+0.01)/4.75));
	 y[i] = 0.5 - 12*4.75*(1 - ((0.01*i+0.01)/4.75));
	 x[i] = 0.01*i+0.01;
  }
  TGraph *g    = new TGraph(1000,x,ln);
  TGraph *g2    = new TGraph(1000,x,y);
  g->SetTitle("Graph;m/ml;y");
  TCanvas *c1 = new TCanvas("c1","Graph",500,500,700,500);
  g->GetXaxis()->SetRangeUser(2,10);
  g->Draw();
  g2->SetLineColor(2);
  g2->Draw("Same");
}