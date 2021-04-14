void Ask53()
{
  TRandom *r1 = new TRandom();
  r1->SetSeed(0);
  TRandom *r2 = new TRandom();
  r2->SetSeed(0);
  double u[20];
  double n[20];
  double cu = 0;
  double cn = 0;
  double y[20] = {1/20,2/20,3/20,4/20,5/20,6/20,7/20,8/20,9/20,10/20,11/20,12/20,13/20,14/20,15/20,16/20,17/20,18/20,19/20,1};
  //long long arxi = 20;
  //long long ind[20];
//-----fill the vectors with random numbers from the desired distribution--------------  
  for(int i;i<20;i++)
  { 	
     u[i] = r1->Uniform(0,1);
	 n[i] = r2->Gaus(0,1);
  }
//Sorting algorithm--------------------------------------------------------------------
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
cout << "------------------------------------------------------" <<endl;
//-----Print the sorted vector of the Gauss distribution-------------------------------
for(int m;m<20;m++)
{
	cout << "n[" <<n[m]<<"]" <<endl;
	
}
//-------Creation of assymetric histograms----------------------------------------------
TH1 *h1 = new TH1D("h1","Cumulative Distribution of Uniform Distribution",19,u);
TH1 *h2 = new TH1D("h2","Cumulative Distribution of Normal Distribution ",19,n);
//-----Histogram fill loop--------------------------------------------------------------
  for( a = 0;a<20;a++)
  {
    for( b = 0;b<a+1;b++)
    {
		double tmp1 = u[a];
	    h1->Fill(tmp1);
        double tmp2 = n[a];
	    h2->Fill(tmp2);
	}
  }
//-------y creation loop----------------------------------------------------------------  
  //for(int j;j<20;j++)
  //{
	//a = a + 1/20;
	//y[j] = a;
    	
  //}
//------Create and show the experimental cumulative normalized histograms---------------- 
  TCanvas *c1 = new TCanvas("c1","Uniform",500,500,700,500);
  h1->Draw();
  //h1->Scale(1/h1->Integral());
  TCanvas *c2 = new TCanvas("c2","Gauss",500,500,700,500);
  h2->Draw();
  //h2->Scale(1/h2->Integral());
}