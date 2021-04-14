void kolmogorov(){
 TRandom *r1 = new TRandom();
 TRandom *r2 = new TRandom();
 r1->SetSeed(0);
 r2->SetSeed(0);

 double x_n[20];//random normal
 double n_cdf[20];//normal cdf of ROOT

 double x_u[20];//random uniform
 double u_cdf[20];//uniform cdf of ROOT

 for(int i=0; i<20; i++){//fill arrays RANDOM
	x_n[i]=0;
	x_u[i]=0;
	x_u[i]=r2->Uniform(0,1);
	x_n[i]=r1->Gaus(0,1);
		//cout<<x_n[i]<<endl;
	}
	//sort(x_n, x_n+20);
	//sort(x_u, x_u+20);
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
 TH1F *h_ncdf = new TH1F(" ", " ", 19, x_n);//rebinned
 TH1F *h_ucdf = new TH1F(" ", " ", 19, x_u);//rebinned

double d_n , d_u;
double d_nmax =-5.0;
double d_umax = -5.0;

 for(int i=0; i<20; i++){
	n_cdf[i]=0;
	u_cdf[i]=0;

	n_cdf[i]=ROOT::Math::normal_cdf(x_n[i],1,0);//normal cdf ROOT
	u_cdf[i]=ROOT::Math::uniform_cdf(x_u[i], 0, 1, 0);//uniform cdf ROOT

	h_ncdf->Fill(x_n[i],(i+1)/20.0);//fill binned histo NORMAL
	h_ucdf->Fill(x_u[i], (i+1)/20.0);//fill binned histo UNIFORM

	d_n = TMath::Abs(((i+1)/20.0) - n_cdf[i]);  //   |discrete - cumulative|
	d_u = TMath::Abs(((i+1)/20.0) - u_cdf[i]);

	if(d_n>d_nmax){d_nmax=d_n;}
	if(d_u>d_umax){d_umax=d_u;}

 }


 cout<<"Dmax_normal = "<<d_nmax<<endl;
 cout<<"Dmax_uniform = "<<d_umax<<endl;


//--------normal cdfs over x------------------------------------
 TCanvas *can1 = new TCanvas("can1", "can1", 900, 600);
 TGraph *gn1 = new TGraph(20, x_n, n_cdf);
 TLegend *leg1 = new TLegend(0.9, 0.6, 0.5, 0.9);
 h_ncdf->SetTitle("Theoritical & Discrete Comulative dist for X~N(0,1);x;F(x)");
 gn1->SetLineColor(2);
 h_ncdf->GetXaxis()->SetRangeUser(x_n[0]-0.5, x_n[19]+1);
 h_ncdf->SetLineColor(4);
 leg1->AddEntry(h_ncdf, "Discrete cdf", "l");
 leg1->AddEntry(gn1, "Theoritical cdf", "l");
 h_ncdf->Draw("histo");
 gn1->Draw("sameLP*");
 leg1->Draw();


//--------uniform cdfs over x ----------------------------------------
 TCanvas *can2 = new TCanvas("can2", "can2", 900, 600);
 TGraph *gu1 = new TGraph(20, x_u, u_cdf);
 TLegend *leg2 = new TLegend(0.9, 0.6, 0.5, 0.9);
 gu1->SetLineColor(2);
 h_ucdf->SetLineColor(4);
 h_ucdf->GetXaxis()->SetRangeUser(x_u[0]-0.5, x_u[19]+1);
 h_ucdf->SetTitle("Theoritical & Discrete Comulative dist for X~Uniform(0,1);x;F(x)");
 leg2->AddEntry(h_ucdf, "Discrete cdf", "l");
 leg2->AddEntry(gu1, "Theoritical cdf", "l");
 h_ucdf->Draw("histo");
 gu1->Draw("sameLP*");
 leg2->Draw();
}

