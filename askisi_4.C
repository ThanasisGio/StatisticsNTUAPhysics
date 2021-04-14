void askisi_4(int N)
{
  TH1D *hist10 = new TH1D("hist10","N=10;Integral;counts",120,0.5,0.9);
  TH1D *hist20 = new TH1D("hist20","N=20;Integral;counts",120,0.5,0.9);
  TH1D *hist50 = new TH1D("hist50","N=50;Integral;counts",120,0.5,0.9);
  TH1D *hist200= new TH1D("hist200","N=200;Integral;counts",120,0.5,0.9);

  TRandom *rnd = new TRandom();

  double sum10=0; double sum20=0; double sum50=0; double sum200=0;

  for (int i=0; i<10000; i++) // number of iterations
    {
      for(int j=0; j<10; j++)//-------------------------N=10------------------------
	{
	  sum10 = sum10 + 1/(rnd->Uniform(1,2));
	}
      hist10->Fill(sum10/10);
      sum10=0;

      for(int j=0; j<20; j++)//------------------------N=20--------------------------
	{
	  sum20 = sum20 + 1/(rnd->Uniform(1,2));
	}
      hist20->Fill(sum20/20);
      sum20=0;
      for(int j=0; j<50; j++)//------------------------N=50-------------------------
	{
	  sum50 = sum50 + 1/(rnd->Uniform(1,2));
	}
      hist50->Fill(sum50/50);
      sum50=0;
      for(int j=0; j<200; j++)//------------------------N=200--------------------------
	{
	  sum200 = sum200 + 1/(rnd->Uniform(1,2));
	}
      hist200->Fill(sum200/200);
      sum200=0;
    }

  hist200->Draw();
  hist20->Draw("same");
  hist50->Draw("same");
  hist10->Draw("same");

  TLegend*  legend = new TLegend(0.7,0.7,0.5,0.5);
  legend->AddEntry(hist10,"N=10");
  legend->AddEntry(hist20,"N=20");
  legend->AddEntry(hist50,"N=50");
  legend->AddEntry(hist200,"N=200");
  legend->Draw("same");

  //-----------------------------------------------------------mu(N)

  double m10 = hist10->GetMean();  double rm10  = hist10->GetRMS();//---- mean values & st. deviations 
  double m20 = hist20->GetMean();  double rm20  = hist20->GetRMS(); 
  double m50 = hist50->GetMean();  double rm50  = hist50->GetRMS();
  double m200= hist200->GetMean(); double rm200 = hist200->GetRMS();

  double y[4] ={m10,m20,m50,m200}; double x[4]={10,20,50,200}; // coordinates of scattered to be points
  double dy[4]={rm10,rm20,rm50,rm200}; double dx[4]={0,0,0,0}; // errors (only on mean values - y-axis)

  TGraphErrors *vv = new TGraphErrors (4,x,y,dx,dy); // error recognition by class
  vv->SetTitle("Mean value of I with respect to N;N;mean value of I");
  vv->Draw("A*");

  //------------------------plot of the real integral value
  TLine *loga = new TLine (0,0.69314718,210,0.69314718);
  loga->Draw("same");


  //------------------------sigma over mu
  //double x2[4] = {10,20,50,200} 
  double fr[4] = {rm10/m10, rm20/m20, rm50/m50, rm200/m200};
  TGraph *frac = new TGraph(5,x,fr);
  frac->SetTitle("Standard deviation over mean value with respect to N;N;st_dev/mean_vale");

  frac->Draw("A*");
  // loga->Draw("same");

  TF1 *g = new TF1 ("g", "[0]+1/([1]*x)",0,350);
  g->SetParameters(2,1);
  frac->Fit("g");
  g->Draw("same");

  TFile n("askisi_4.root", "recreate");
  hist200->Write();
  hist20->Write();
  hist50->Write();
  hist10->Write();

  

      
      

      
    

}
