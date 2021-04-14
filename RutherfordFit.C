void RutherfordFit()
{
//Change the arrays accordingly	
  double theta[7]  = {-15,-10,-5,0,5,10,15};
  double errort[7];
  double counts[7] = {751,2852,9721,16039,15655,8180,3375};
  double errorc[7];
//Error fill loop 
  for(int i=0;i<7;i++)
  { 
     errort[i] = 2.5;
	 double c  = counts[i];
	 errorc[i] = sqrt(c);
  
  } 
//Fitting Function-------------------------------------------------------------------------------------------------------------------------------
//Change the limits of the function accordingly
//0.008727 = Pi()/(2*180) normalization
  TCanvas *c1 = new TCanvas("c1","Elastic scattering",500,500,700,500);
  TF1 *rutherford = new TF1("rutherford","[0]/(sin((x-[1])*3.141593/360)*sin((x-[1])*3.141593/360)*sin((x-[1])*3.141593/360)*sin((x-[1])*3.141593/360))",0,1);  
  TGraphErrors *g1      = new TGraphErrors(7,theta,counts,errort,errorc);
  g1->Fit(rutherford);
  g1->GetYaxis()->SetTitle("Counts/min");
  g1->GetXaxis()->SetTitle("theta(degrees)");
  g1->SetTitle("Distribution of Counts per min over degrees");
  g1->Draw("*AP");
}