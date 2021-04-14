void Askisi53c()
{ 
  TH1F *h1 = new TH1F("h1","sqrt(N)Dmax distribution for Uniform ",50, 0, 3);
  TH1F *h2 = new TH1F("h2","sqrt(N)Dmax distribution for Gauss",50, 0, 3);
  TRandom *r1 = new TRandom();
  r1->SetSeed(0);
  TRandom *r2 = new TRandom();
  r2->SetSeed(0);
  double u[20];
  double n[20];
  double u_c[20];//vector for the theoritical cumulative function of uniform distribution--------
  double n_c[20];//vector for the theoritical cumulative function of Normal distribution---------
  double d_n; 
  double d_u;
  double d_nmax =-5.0;
  double d_umax =-5.0;
  double elu ;
  double eln ;
 for(int i;i<10;<i++)
 {	 
//-----Creation of the random vectors and theoritical cumulative functions-----------------------  
  for(int i;i<20;i++)
  { 	
     u[i] = r1->Uniform(0,1);
	 n[i] = r2->Gaus(0,1);
  }
//Sorting algorithm------------------------------------------------------------------------------
for (int i = 0; i < 20-1; i++)
{	
 
       // Last i elements are already in place   
       for (int j = 0; j < 20-i-1; j++) 
	   {
           if (u[j] > u[j+1])
		   {
			   double tmp1 = u[j];
			       u[j] = u[j+1];
                   u[j+1] = tmp1;
              
		   }
           //if (n[j] > n[j+1])
		  // {
			  // double tmp2 = n[j];
			     //     n[j] = n[j+1];
                  //  n[j+1] = tmp2;
              
		  // }			  		   
	   }		  
}
//----Creation of theoritical cumulative functions--------------------------------------
  for(int i=0;i<20;i++)
  {
	// n_c[i]=ROOT::Math::normal_cdf(n[i],1,0);//normal cdf ROOT
     u_c[i]=ROOT::Math::uniform_cdf(u[i], 0, 1, 0);//uniform cdf ROOT
	 //d_n = TMath::Abs(((i+1)/20.0) - n_c[i]);  //   |discrete - cumulative|
	 d_u = TMath::Abs(((i+1)/20.0) - u_c[i]);

	//if(d_n>d_nmax)
	//{
	//	d_nmax=d_n;
	//}
	if(d_u>d_umax)
	{
		d_umax=d_u;
	}
  }
    elu = sqrt(20)*d_umax;
	//eln = sqrt(20)*d_nmax;
	h1->Fill(elu);
	//h2->Fill(eln);
 }
 
//------Create and show the experimental cumulative normalized histograms---------------- 
  TCanvas *c1 = new TCanvas("c1","Uniform",500,500,700,500);
  h1->Draw();
  //TCanvas *c2 = new TCanvas("c2","Gauss",500,500,700,500);
  //h2->Draw();
}