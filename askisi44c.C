void askisi44c()
{
  TH1F *ha     = new TH1F("ha", "ha", 120, 0.5, 1.5);
  TH1F *hb     = new TH1F("hb", "hb", 120, 0.9, 1.1);
  TH1F *hatrue = new TH1F("hatrue", "hatrue", 120, 0.5, 1.5);
  TH1F *hbtrue = new TH1F("hbtrue", "hbtrue", 120, 0.9, 1.1);
  TRandom *u = new TRandom();
  TRandom *v = new TRandom();
  u->SetSeed(0);
  v->SetSeed(0);
  double     x [10];
  double     y [10];
  double sigma [10];
  double sum_x  = 0;
  double sum_y  = 0;
  double sum_yy = 0;
  double sum_xx = 0;
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
  double sum_sa = 0;
  double sum_sb = 0;
  double atrue;
  double btrue;
//-----------for loop--------------------------------------------------------------------------------------------
 for(int j=0;j<10000;j++)
 {
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
	
	sum_sa   = sum_sa + 1/(sigma[i]*sigma[i]);
	sum_sb   = sum_sb + (x[i]*x[i])/(sigma[i]*sigma[i]);
	
  }
 
  mean_x  = sum_x/10; 
  mean_xx = sum_xx/10; 
  mean_y  = sum_y/10; 
  mean_yy = sum_yy/10; 
  mean_xy = sum_xy/10;
  
     varx = mean_xx -mean_x*mean_x;  
   cov_xy = mean_xy -mean_x*mean_y;
   
	    b = cov_xy/varx;
		a = mean_y - b*mean_x; 
	   sa = sqrt(1/sum_sa);
	   sb = sqrt(1/sum_sb);
  atrue = (a-1)/(sa);
  btrue = (b-1)/(sb); 
  ha->Fill(a);
  hb->Fill(b);
  hatrue->Fill(atrue);
  hbtrue->Fill(btrue);
  //a=0;
  //b=0;
  //atrue=0;
  //btrue=0;
 }
 TCanvas *c1 = new TCanvas("can1", "can1", 900, 600);
 ha->Draw();

 TCanvas *c2 = new TCanvas("can2", "can2", 900, 600);
 hb->Draw();

 TCanvas *c3 = new TCanvas("can3", "can3", 900, 600);
 hatrue->Draw();

 TCanvas *c4 = new TCanvas("can4", "can4", 900, 600);
 hbtrue->Draw();
}