void Askisi54()
{
  double  x[13] = {-3,-2.5,-2,-1.5,-1,-0.5,0,0.5,1,1.5,2,,2.5,3};
  double x1[12] = {0.0042,0.0186,0.0422,0.0926,0.1456,0.1886,0.1866,0.1514,0.0894,0.0546,0.0176,0.0066};
  double ex1[12]= {0.0009,0.0019,0.0029,0.0043,0.0054,0.0061,0.0061,0.0055,0.0042,0.0033,0.0019,0.0011};
  double x2[12] = {0.0056,0.0214,0.0422,0.0844,0.1296,0.166,0.1736,0.1536,0.1072,0.0626,0.034,0.0136};
  double ex2[12]= {0.0011,0.0021,0.0029,0.0041,0.0051,0.0058,0.0059,0.0055,0.0046,0.0035,0.0026,0.0016};
  double theo[12];
  TH1 *h1 = new TH1D("h1","Histrogram of X1 set of experiemntal measurements",12,x);
  TH1 *h2 = new TH1D("h2","Histrogram of X2 set of experiemntal measurements",12,x);
  TF1 *f  = new TF1("f","TMath::Gaus(x,0,1)",-3,3);
//Creation of histograms----------------------------------------------------------------------------------
  for(int i=0;i<12;i++)
  {
	  h1->SetBinContent(i,x1[i]);
	  h2->SetBinContent(i,x2[i]);
	  h1->SetBinError(i,ex1[i]);
	  h2->SetBinError(i,ex2[i]);
  }
  //for(int j=0;j<12;j++)
  //{
	  //double m = 0;
	  //double n = 0;
	   //theo[0] = f->Integral(-3.0,-2.5);
	   //theo[1] = f->Integral(-2.5,-2);
	  //double diff = x1[j]- theo[j] ;
	  //if(diff>0)
	  //{
		//  m=m+1;
	  //}
	  //if(diff<0)
	  //{
		 // n=n+1;
	//  }
	  //cout<<"theoritical estimation  = "<<theo[0]<<endl;
	  //cout<<"theoritical estimation  = "<<theo[1]<<endl;
  //}

  TCanvas *c1 = new TCanvas("c1","X1 set of measurements",500,500,700,500);
  h1->Draw();
  h1->Fit("gaus");
  TCanvas *c2 = new TCanvas("c2","X2 set of measurements",500,500,700,500);
  h2->Draw();
  h2->Fit("gaus");
  cout<<"------------------------------------------------------------------------ "<<endl;
  TF1 * f1 = h1->GetFunction("gaus");//Get the Chi square of the histogram compared to the fit
  Double_t p1 = f1->GetChisquare();
  cout<<"p1 - value  = "<<p1<<endl;
  cout<<"------------------------------------------------------------------------ "<<endl;
  TF1 * f2 = h2->GetFunction("gaus");
  Double_t p2 = f2->GetChisquare();
  cout<<"p2 - value  = "<<p2<<endl;
}