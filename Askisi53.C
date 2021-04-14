void Askisi53()
{
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
//-----Creation of the random vectors and theoritical cumulative functions-----------------------  
  for(int i;i<20;i++)
  { 	
     u[i] = r1->Uniform(0,1);
	 n[i] = r2->Gaus(0,1);
  }
//Sorting algorithm------------------------------------------------------------------------------
for (i = 0; i < 20-1; i++)
{	
 
       // Last i elements are already in place   
       for (j = 0; j < 20-i-1; j++) 
	   {
           if (u[j] > u[j+1])
		   {
			   double tmp1 = u[j];
			       u[j] = u[j+1];
                   u[j+1] = tmp1;
              
		   }
           if (n[j] > n[j+1])
		   {
			   double tmp2 = n[j];
			          n[j] = n[j+1];
                    n[j+1] = tmp2;
              
		   }			  		   
	   }		  
}
//-----Print the sorted vector of the uniform distribution-----------------------------
for(int k;k<20;k++)
{
	cout << "u[" <<u[k]<<"]" <<endl;
	
}
cout << "-----------------------------------------------------------------------------" <<endl;
//-----Print the sorted vector of the Gauss distribution-------------------------------
for(int m;m<20;m++)
{
	cout << "n[" <<n[m]<<"]" <<endl;
	
}
//-------Creation of assymetric histograms----------------------------------------------
TH1 *h1 = new TH1D("h1","Cumulative Distribution of Uniform Distribution",19,u);
TH1 *h2 = new TH1D("h2","Cumulative Distribution of Normal Distribution ",19,n);
//-----Histogram fill loop--------------------------------------------------------------
  for(int a = 0;a<20;a++)
  {
    
		h1->Fill(u[a],(a+1)/20.0);
		h2->Fill(n[a],(a+1)/20.0);
	
  }
//----Creation of theoritical cumulative functions--------------------------------------
  for(int i=0;i<20;i++)
  {
	 n_c[i]=ROOT::Math::normal_cdf(n[i],1,0);//normal cdf ROOT
     u_c[i]=ROOT::Math::uniform_cdf(u[i], 0, 1, 0);//uniform cdf ROOT
	 d_n = TMath::Abs(((i+1)/20.0) - n_c[i]);  //   |discrete - cumulative|
	 d_u = TMath::Abs(((i+1)/20.0) - u_c[i]);

	if(d_n>d_nmax)
	{
		d_nmax=d_n;
	}
	if(d_u>d_umax)
	{
		d_umax=d_u;
	}
  }
 cout<<"Dmax_normal = "<<d_nmax<<endl;
 cout<<"Dmax_uniform = "<<d_umax<<endl;  
 //Fitting Functions---------------------------------------------------------------------
  //TF1 *fu = new TF1("fu","[0]*x+[1]",0,1);
  //TF1 *fn = new TF1("fn","[0]*TMath::Erf((x-[1])/[2])",0,1);
//------Create and show the experimental cumulative normalized histograms---------------- 
  TCanvas *c1 = new TCanvas("c1","Uniform",500,500,700,500);
  h1->Draw();
  TGraph *g1  = new TGraph(20,u,u_c);
  g1->Draw("same");
  TCanvas *c2 = new TCanvas("c2","Gauss",500,500,700,500);
  h2->Draw();
  //TCanvas *c3 = new TCanvas("c3","Uniform",500,500,700,500);
  TGraph *g2    = new TGraph(20,n,n_c);
  //g2->Fit(fu);
  g2->Draw("same");
}