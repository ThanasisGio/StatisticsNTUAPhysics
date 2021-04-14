void Askisi54b()
{
  double  x[13] = {-3,-2.5,-2,-1.5,-1,-0.5,0,0.5,1,1.5,2,,2.5,3};
  double x1[12] = {0.0042,0.0186,0.0422,0.0926,0.1456,0.1886,0.1866,0.1514,0.0894,0.0546,0.0176,0.0066};
  double ex1[12]= {0.0009,0.0019,0.0029,0.0043,0.0054,0.0061,0.0061,0.0055,0.0042,0.0033,0.0019,0.0011};
  double x2[12] = {0.0056,0.0214,0.0422,0.0844,0.1296,0.166,0.1736,0.1536,0.1072,0.0626,0.034,0.0136};
  double ex2[12]= {0.0011,0.0021,0.0029,0.0041,0.0051,0.0058,0.0059,0.0055,0.0046,0.0035,0.0026,0.0016};
  double theo[12];
  double d1[12];
  double d2[12];
  double p1 = 0;
  double p2 = 0;
  double m1 = 0;
  double n1 = 0;
  double r1 = 0;
  double m2 = 0;
  double n2 = 0;
  double r2 = 0;
  TH1 *h1 = new TH1D("h1","Histrogram of X1 set of experiemntal measurements",12,x);
  TH1 *h2 = new TH1D("h2","Histrogram of X2 set of experiemntal measurements",12,x);
  TH1 *h3 = new TH1D("h2","theoritical ",12,x);
  TF1 *f  = new TF1("f","TMath::Gaus(x,0,1)",-3,3);
//Creation of histograms----------------------------------------------------------------------------------
  for(int i=0;i<12;i++)
  {
	  h1->SetBinContent(i+1,x1[i]);
	  h2->SetBinContent(i+1,x2[i]);
	  h1->SetBinError(i+1,ex1[i]);
	  h2->SetBinError(i+1,ex2[i]);
  }
  for(int j=0;j<12;j++)
  {
	  theo[j] = -ROOT::Math::normal_cdf( x[j] , 1 , 0 ) + ROOT::Math::normal_cdf( x[j+1] , 1 , 0 );

	  h3->SetBinContent(j+1,theo[j]);
	  cout<<"theoritical estimation  = "<<theo[j]<<endl;
  }
  for(int j=0;j<12;j++)
  {
	  double diff1 = x1[j]- theo[j] ;
	  double diff2 = x2[j]- theo[j] ;
	  d1[j] = diff1;
	  //d2[j] = diff2;
      double  chi1 = diff1*diff1/(ex1[j]*ex1[j]);
	    p1   = p1 + chi1;
	  double  chi2 = diff2*diff2/(ex2[j]*ex2[j]);
	    p2   = p2 + chi2;
	  if(diff1>0)
	  {
		  m1=m1+1;
	  }
	  if(diff1<0)
	  {
		  n1=n1+1;
	  }
	  if(diff2>0)
	  {
		  m2=m2+1;
	  }
	  if(diff2<0)
	  {
		  n2=n2+1;
	  }
  //cout<<"d["<<j<<"]"<<"="<<d1[j]<<endl;
 }
  double rmin1 = 1 + 2*(n1*n1)/(m1+n1);
  cout<<"rmin1 ="<<rmin1<<endl;
  TCanvas *c1 = new TCanvas("c1","X1 set of measurements",500,500,700,500);
  h1->Draw();
  //TCanvas *c2 = new TCanvas("c2","X2 set of measurements",500,500,700,500);
 // h2->Draw("same");
  //TCanvas *c3 = new TCanvas("c3","theoritical",500,500,700,500);
  h3->Draw("same");
  cout<<"------------------------------------------------------------------------ "<<endl;
  cout<<"statistic 1  = "<<p1<<endl;
  cout<<"------------------------------------------------------------------------ "<<endl;
  cout<<"statistic 2  = "<<p2<<endl;
  TF1 * f = new TF1("f","TMath::Gaus(x,0,1)",-3.0,3.0);
  //double final = h1->Chisquare(f,"R ");
  //cout<<"final ="<<final<<endl;
  Double_t res[12];
  h3->Chi2Test(h1,"UW P",res);
  cout<<"------------------------------------------------------------------------ "<<endl;
  h3->Chi2Test(h2,"UW P",res);
  double th_pdf[0] = ROOT::Math::normal_cdf( -2.5 , 1 , 0 ) - ROOT::Math::normal_cdf( -3.0 , 1 , 0 );
  cout<<"th0  = "<<th_pdf[0]<<endl;
}