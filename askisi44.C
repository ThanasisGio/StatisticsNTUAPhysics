void askisi44a()
{
  TRandom *u = new TRandom();
  TRandom *v = new TRandom();
  u->SetSeed(0);
  v->SetSeed(0);
  double     x [10];
  double     y [10];
  double sigma [10];
  double sum_x  = 0;
  double sum_y  = 0;
  double sum_xx = 0;
  double sum_yy = 0;
  double sum_xy = 0;
  double mean_x;
  double mean_xx;
  double mean_y;
  double mean_xy;
  double cov_xy;
  double varx;
  double a;
  double b;
  double sa;
  double sb;
  double sum_sa[10];
  double sum_sb[10];
//-----------for loop--------------------------------------------------------------------------------------------
  for(int i=0;i<10;i++)
  {
        x[i] = u->Uniform(0,10);
	double m = x[i] + 1;
        y[i] = v->Gaus(m,0.5);
	sigma[i] = 0.5;
	sum_x    = sum_x + x[i];
	sum_y    = sum_y + y[i];
	sum_xx   = sum_xx + x[i]*x[i];
	sum_yy   = sum_yy + y[i]*y[i];
	sum_xy   = sum_xy + x[i]*y[i];
	sum_sa[i]   = sum_sa + 1/(sigma[i]*sigma[i]);
	sum_sb[i]   = sum_sb + (x[i]*x[i])/(sigma[i]*sigma[i]);
	
  }
 //---------------------------------------------------------------------------------------------------------------
  mean_x  = sum_x/10; 
  mean_xx = sum_xx/10; 
  mean_y  = sum_y/10; 
  mean_yy = sum_yy/10; 
  mean_xy = sum_xy/10;
     varx = mean_xx - mean_x*mean_x;  
   cov_xy = mean_xy - mean_x*mean_y;
	    b = cov_xy/varx;
		a = mean_y - b*mean_x; 
	   sa = 1/sqrt(sum_sa);
	   sb = 1/sqrt(sum_sb);
  cout<<"a = "<<a<<" +/-"<<sa<<endl;
  cout<<"b = "<<b<<" +/-"<<sb<<endl;
 //--------Draw Graph---------------------------------------------------------------------------------------------
  TGraphErrors *graph = new TGraphErrors (10,x,y,NULL,sigma);
  graph->SetTitle("Scatter plot of 10 x,y points with linear correlation;x;y");
  TCanvas *c1 = new TCanvas("c1","Scatter plot of 10 x,y points with linear correlation",500,500,700,500);
  graph->Draw("A*");  

}