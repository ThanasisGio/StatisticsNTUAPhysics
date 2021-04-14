void testsort()
{
  TH1F *h1 = new TH1F("h1","Distribution of sqrt(N)Dmax of Gauss Distribution",50, 0, 3);
  TRandom *r = new TRandom();
  r->SetSeed(0);
  double n[10];
  double n_c[10];
  double d_nmax =-5.0;
  for(int i=0;i<10;i++)
  {
    for(int j=0;j<10;j++)
	{
	  n[i] = r->Gaus(0,1);
	}
	for (i = 0; i < 10-1; i++)
    {	
 
       // Last i elements are already in place   
       for (j = 0; j < 10-i-1; j++) 
	   {
           if (n[j] > n[j+1])
		   {
			   double tmp2 = n[j];
			          n[j] = n[j+1];
                    n[j+1] = tmp2;
              
		   }			  		   
	   }		  
     }
	 for(int i=0;i<10;i++)
  {
	 n_c[i]=ROOT::Math::normal_cdf(n[i],1,0);//normal cdf ROOT
	 d_n = TMath::Abs(((i+1)/10.0) - n_c[i]);  //   |discrete - cumulative
	if(d_n>d_nmax)
	{
		d_nmax=d_n;
	}
	h1->Fill(sqrt(10)*d_nmax);
  }
  }
  TCanvas *c1 = new TCanvas("c1","Gauss",500,500,700,500);
  h1->Draw();
  
}