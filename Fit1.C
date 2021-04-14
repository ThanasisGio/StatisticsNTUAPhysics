void Fit1()
{
//Change the arrays accordingly	
  double theta[3]  = {15,10,5};
  double errort[3];
  double counts[3] = {751,2852,9721};
  double errorc[3];
  double rutherford[3];
//Error fill loop 
  for(int i=0;i<3;i++)
  { 
     errort[i] = 2.5;
	 double c  = counts[i];
	 errorc[i] = sqrt(c);
  
  } 
//Fitting Function-------------------------------------------------------------------------------------------------------------------------------
//Change the limits of the function accordingly
//0.008727 = Pi()/(2*180) normalization
  TCanvas *c1 = new TCanvas("c1","Elastic scattering",500,500,700,500);
  TF1 *rutherford = new TF1("rutherford","[0]/(sin((x-[1])*3.141593/360)*sin((x-[1])*3.141593/360)*sin((x-[1])*3.141593/360)*sin((x-[1])*3.141593/360))",-15,0);  
  TGraphErrors *g1      = new TGraphErrors(3,theta,counts,errort,errorc);
  g1->Fit(rutherford);
  g1->Draw("*AP");
}