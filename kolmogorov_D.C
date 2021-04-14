//---------------1000 iterrations-----------------------------------
void kolmogorov_D(){
 TRandom *r1 = new TRandom();
 TRandom *r2 = new TRandom();
 r1->SetSeed(0);
 r2->SetSeed(0);

 double x_n[20];//random normal
 double n_cdf[20];//normal cdf of ROOT

 double x_u[20];//random uniform
 double u_cdf[20];//uniform cdf of ROOT

TH1F *hd_u = new TH1F("hd_u","hd_u",50, 0, 3);
TH1F *hd_n = new TH1F("hd_n","hd_n",50, 0, 3);

double dmax_n[1000];
double dmax_u[1000];

 for(int j=0; j<1000; j++){
	double d_n=0;
	double d_u=0;
	double d_nmax =-10.0;
	double d_umax = -10.0;
	dmax_n[j]=0;
	dmax_u[j]=0;

	for(int i=0; i<20; i++){//fill arrays RANDOM
		x_n[i]=0;
		x_u[i]=0;
		x_u[i]=r2->Uniform(0,1);
		x_n[i]=r1->Gaus(0,1);
	}

	
	 for (i = 0; i < 20-1; i++)
     {	
 
       // Last i elements are already in place   
       for (j = 0; j < 20-i-1; j++) 
	   {
           if (x_u[j] > x_u[j+1])
		   {
			   double tmp1 = x_u[j];
			       x_u[j] = x_u[j+1];
                   x_u[j+1] = tmp1;
              
		   }
           if (x_n[j] > x_n[j+1])
		   {
			   double tmp2 = x_n[j];
			          x_n[j] = x_n[j+1];
                    x_n[j+1] = tmp2;
              
		   }			  		   
	   }		  
     }
	for(int i=0; i<20; i++){
		n_cdf[i]=0;
		u_cdf[i]=0;

		n_cdf[i]=ROOT::Math::normal_cdf(x_n[i],1,0);//normal cdf ROOT
		u_cdf[i]=ROOT::Math::uniform_cdf(x_u[i], 0, 1, 0);//uniform cdf ROOT

		d_n = TMath::Abs(((i+1)/20.0) - n_cdf[i]);  //   |discrete - cumulative|
		d_u = TMath::Abs(((i+1)/20.0) - u_cdf[i]);

		if(d_n>d_nmax){
			d_nmax=d_n;
			dmax_n[j]=d_nmax;	
		}
		if(d_u>d_umax){
			d_umax=d_u;
			dmax_u[j]=d_umax;
			//cout<<sqrt(20)*dmax_u[j]<<endl;	
		}
 	}
	hd_u->Fill(sqrt(20)*dmax_u[j]);
	hd_n->Fill(sqrt(20)*dmax_n[j]);
 }


//-----------------sqrt(N)*Dmax histograms--------------------------------------------
 TCanvas *can3 = new TCanvas("can3", "can3", 900, 600);
 hd_u->Draw("histo");

 TCanvas *can4 = new TCanvas("can4", "can4", 900, 600);
 hd_n->Draw("histo");

TCanvas *canq = new TCanvas("canq", "canq", 900, 600);
TGraphQQ *qq = new TGraphQQ(20, x_n, 20, x_u);
qq->Draw();


TCanvas *canq2 = new TCanvas("canq2", "canq2", 900, 600);
TGraphQQ *qq2 = new TGraphQQ(20, x_u, 20, x_n);
qq2->Draw();
//sort(x_n, x_n+20);
	//sort(x_u, x_u+20);
}

