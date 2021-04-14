void Askisi52()
{
  TRandom *r1 = new TRandom();
  r1->SetSeed(0);
  TRandom *r2 = new TRandom();
  r2->SetSeed(0);
  Double_t b = TMath :: ErfInverse(-0.9);
  Double_t c = TMath :: ErfInverse(0.9);
  double x[100];
  double x1[100];
  double x2[100];
  double sum = 0;
  double    nx[1000];
  double   dnx[1000];
  double xmean[1000];
  double dxmean[1000];
  int a = 0;
  for(int i=0;i<100;i++)
  { 
	double m = r1->Uniform(10,30);
	   x1[i] = m + 2*sqrt(2)*b;
	   x2[i] = m + 2*sqrt(2)*c;
	   x[i]  = m;
  
  }
  for(int i=0;i<1000;i++)
  {	 
     nx[i] = i;
     dnx[i] = 0;	 
    for(int j=0;j<16;j++)
    {
       double mean = r2->Gaus(20,4);
	   sum         = sum + mean;
    }
    xmean[i] = sum/16 ;
	dxmean[i] = 2;
    sum = 0;
	if (xmean[i]>22)
	{
	   a = a + 1;
	}
	if (xmean[i]<18)
	{
	   a = a + 1;
	}
  }
  double per = a/10;
  cout << per <<" % "<< endl;

  TGraph *g1    = new TGraph(100,x,x1);
  TGraph *g2    = new TGraph(100,x,x2);
  //TGraphErrors *g3    = new TGraphErrors(1000,nx,xmean,dnx,dxmean);
  TGraph *g4    = new TGraph(1000,nx,xmean);
  g1->SetTitle("Confidence belt;x;m");
  TCanvas *c1 = new TCanvas("c1","m",500,500,700,500);
  g1->SetLineColor(2);
  g1->Draw();
  g2->SetLineColor(2);
  g2->Draw("Same");
  TLine *est = new TLine (20.5,5,20.5,26);
  est->SetLineColor(3);
  est->Draw("same");
  //g3->SetTitle("Experimental mean value vs true mean value;iteration;m");
  //TCanvas *c3 = new TCanvas("c3","iterations",500,500,700,500);
  //g3->Draw("AP");
  g4->SetTitle("Experimental mean value vs true mean value;iteration;m");
  TCanvas *c4 = new TCanvas("c4","iterations",500,500,700,500);
  g4->Draw("*AP");
  TLine *truemean = new TLine (0,20,1000,20);
  truemean->SetLineColor(2);
  truemean->Draw("same");
  TLine *lowerlimit = new TLine (0,18,1000,18);
  lowerlimit->SetLineColor(3);
  lowerlimit->Draw("same");
  TLine *upperlimit = new TLine (0,22,1000,22);
  upperlimit->SetLineColor(4);
  upperlimit->Draw("same");
  
}
