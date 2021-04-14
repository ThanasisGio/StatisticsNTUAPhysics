void Askisi24()
{
    TH1F *h10   = new TH1F("h10","Distribution of  10000 repetitions",1000 ,0.2,1.2);
	TH1F *h20   = new TH1F("h20","Distribution of  10000 repetitions",1000 ,0.2,1.2);
	TH1F *h50   = new TH1F("h50","Distribution of  10000 repetitions",1000 ,0.2,1.2);
	TH1F *h200  = new TH1F("h200","Distribution of  10000 repetitions",1000 ,0.2,1.2);
	TH1F *h400  = new TH1F("h400","Distribution of  10000 repetitions",1000 ,0.2,1.2);
	TH1F *h500  = new TH1F("h500","Distribution of  10000 repetitions",1000 ,0.2,1.2);
	//TH1F *h1000  = new TH1F("h1000","Distribution of  10000 repetitions",1000 ,0.2,1.2);
	TRandom *u  = new TRandom();
	u->SetSeed(0);
	double    I = 0;
	double    g = 0;
	double    x = 0;
// ----------- for loops Monte Carlo Integrations for 10,20,50 and 200 points -----------------
	for (int i=0;i<10000;i++) //N = 10
	{
		for (int j=0;j<10;j++)
		{
			double  r = u->Uniform(1,2);
			        g = 1/r ;
					x = x + g ;
		
		}
	    I = x/10 ;
		h10->Fill(I);
		I=0;
		g=0;
		x=0;
	}
	for (int i=0;i<10000;i++) // N = 20
	{
		for (int j=0;j<20;j++)
		{
			double  r = u->Uniform(1,2);
			        g = 1/r ;
					x = x + g ;
		
		}
	    I = x/20 ;
		h20->Fill(I);
		I=0;
		g=0;
		x=0;
	}
	for (int i=0;i<10000;i++) // N = 50
	{
		for (int j=0;j<50;j++)
		{
			double  r = u->Uniform(1,2);
			        g = 1/r ;
					x = x + g ;
		
		}
	    I = x/50 ;
		h50->Fill(I);
		I=0;
		g=0;
		x=0;
	}
	for (int i=0;i<10000;i++) // N = 200
	{
		for (int j=0;j<200;j++)
		{
			double  r = u->Uniform(1,2);
			        g = 1/r ;
					x = x + g ;
		
		}
	    I = x/200 ;
		h200->Fill(I);
		I=0;
		g=0;
		x=0;
	}
	//for (int i=0;i<10000;i++) // N = 200
	//{
		//for (int j=0;j<400;j++)
		//{
			//double  r = u->Uniform(1,2);
			  //      g = 1/r ;
				//	x = x + g ;
		//
	//	}
	  //  I = x/400 ;
		//h200->Fill(I);
		//I=0;
		//g=0;
		//x=0;
	//}
	//for (int i=0;i<10000;i++) // N = 200
	//{
		//for (int j=0;j<500;j++)
		//{
			//double  r = u->Uniform(1,2);
			  //      g = 1/r ;
				//	x = x + g ;
		
		//}
	    //I = x/500 ;
		//h200->Fill(I);
		//I=0;
		//g=0;
		//x=0;
	//}
//	for (int i=0;i<10000;i++) // N = 200
	//{
//		for (int j=0;j<1000;j++)
//		{
//			double  r = u->Uniform(1,2);
//			        g = 1/r ;
//					x = x + g ;
//		
//		}
//	    I = x/1000 ;
//		h200->Fill(I);
//		I=0;
//		g=0;
//		x=0;
//	}
//---------- histograms -------------------------------------------------
//---------- Set colors -------------------------------------------------
  h200->SetLineColor(2);h20->SetLineColor(3);
  h50->SetLineColor(4); h10->SetLineColor(6);
//----------Draw the 4 histograms in the same window --------------------
  TCanvas *c1 = new TCanvas("c1","Histograms of Monte Carlo Integration for Ν=10,20,50 and 200 points",500,500,700,500);
  h200->Draw();
  h20->Draw("same");
  h50->Draw("same");
  h10->Draw("same");
 //----------add legend--------------------------------------------------
  TLegend*  legend = new TLegend(0.7,0.7,0.5,0.5);
  legend->AddEntry(h10,"N=10");legend->AddEntry(h20,"N=20");
  legend->AddEntry(h50,"N=50");legend->AddEntry(h200,"N=200");
  legend->Draw("same");
  //-------- Get the mean and rms values from each histogram ---------------------------------------------------
  double m10  = h10->GetMean();double s10 = h10->GetRMS();
  double m20  = h20->GetMean();double s20 = h20->GetRMS();
  double m50  = h50->GetMean();double s50 = h50->GetRMS();
  double m200 = h200->GetMean();double s200 = h200->GetRMS();
  //double m400 = h400->GetMean();double rs400 = h400->GetRMS();
 // double m500 = h500->GetMean();double rs500 = h500->GetRMS();
  //double m1000 = h1000->GetMean();double s1000 = h1000->GetRMS();
 //-Definition of arrays y,z which hold the mean values and rms of the histograms-------------------------------
  double  y[4]={m10,m20,m50,m200}; double dy[4]={s10,s20,s50,s200}; 
  double  z[4]={10,20,50,200};     double dz[4]={0,0,0,0}; 
 //------- Graph of the mean values,rms with respect to N and of the real value of the integral ln2 ------------
  TGraphErrors *vv = new TGraphErrors (4,z,y,dz,dy); 
  vv->SetTitle(" mean value of I;N; I");
  TCanvas *c2 = new TCanvas("c2","Mean values and RMS of Monte Carlo Integration with respect to N ",500,500,700,500);
  vv->Draw("A*");
  TLine *ln2 = new TLine (0,0.69314718,210,0.69314718);
  ln2->SetLineColor(2);
  ln2->Draw("same");
 //----------Graph of s/mean -----------------------------------------------------------------------------------
  //double zz[4]={50,200,400,500};
  double sm[4] = {s10/m10,s20/m20,s50/m50,s200/m200};
  //double sm2[4] = {s50/m50,s200/m200,s400/m400,s500/m500};
  TGraph *f    = new TGraph(4,z,sm);
  f->SetTitle("Standard deviation over mean value with respect to N;N;st-dev/mean");
  TCanvas *c3 = new TCanvas("c3","sigma over mean with respect to N",500,500,700,500);
  f->Draw("A*");
  //TGraph *f2    = new TGraph(4,zz,sm2);
  //f2->SetTitle("Standard deviation over mean value with respect to N 1%");
  //TCanvas *c4 = new TCanvas("c3","sigma over mean with respect to N",500,500,700,500);
  //f2->Draw("A*");
 //-------------------------------------------------------------------------------------------------------------
  
}