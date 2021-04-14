void Askisi32a()
{
	//-------Παράγω ένα μόνο σύνολο Σxi για κάθε Ν και βάσει αυτού κάνω το plot ln(L(θ))
  TRandom *r1 = new TRandom();
  r1->SetSeed(0);
  double n10 = 0;
  double n20 = 0;
  double n50 = 0;
  double ly10[1000];
  double ly20[1000];
  double ly50[1000];
  double  x10[1000];
//-----------------------------------------------------  
  
	  for (int i=0;i<10;i++)
      {
         double r10 = r1->Exp(1);
	     n10 = n10 + r10 ;
	 
      } 
	  double m10 = 10/n10;
	  cout << 'm10' << " " << m10 << endl;
	  
	  for (int j = 0;j<1000;j++)
	  {
		  ly10[j] = 10*log(0.01*j+0.01)-n10*j*0.01 ;
           x10[j] = 0.01*j;		  
	  }
	 
	 TGraph *g10 = new TGraph(1000,x10,ly10);
     g10->SetTitle("lnL(thita) with respect to thita for N=10;thita;lnL(thita)");
     //TCanvas *c1 = new TCanvas("c1","lnL(thita) with respect to thita for N=10",500,500,700,500);
     //g10->Draw("A*"); 
  
  
 //----------------------------------------------------- 
  for (int i=0;i<20;i++)
      {
         double r20 = r1->Exp(1);
	     n20 = n20 + r20 ;
	 
      } 
	  double m20 = 20/n20;
	  cout << 'm20' << " " << m20 << endl;
      
	  for (int j = 0;j<1000;j++)
	  {
		  ly20[j] = 20*log(0.01*j+0.01)-n20*j*0.01 ; 
	  }
	 
	 TGraph *g20 = new TGraph(1000,x10,ly20);
     g20->SetTitle("lnL(thita) with respect to thita;thita;lnL(thita)");
     //TCanvas *c2 = new TCanvas("c2","lnL(thita) with respect to thita for N=20",500,500,700,500);
     //g20->Draw("A*"); 
//-------------------------------------------------------
  
	  for (int i=0;i<50;i++)
      {
         double r50 = r1->Exp(1);
	     n50 = n50 + r50 ;
	 
      } 
	  double m50 = 50/n50;
	  cout << 'm50' << " " << m50 << endl;
     
	 for (int j = 0;j<1000;j++)
	  {
		  ly50[j] = 50*log(0.01*j+0.01)-n50*j*0.01 ; 
	  }
	 
	 TGraph *g50 = new TGraph(1000,x10,ly50);
     g50->SetTitle("lnL(thita) with respect to thita for N=50;thita;lnL(thita)");
     TCanvas *c3 = new TCanvas("c3","lnL(thita) with respect to thita for N=50",500,500,700,500);
	 g50->SetLineColor(2);
	 g20->SetLineColor(3);
	 g10->SetLineColor(4);
     g20->Draw(); 
	 g50->Draw("same");
	 g10->Draw("same");
  
  TLegend*  legend = new TLegend(0.7,0.7,0.5,0.5);
  legend->AddEntry(g10,"N=10");
  legend->AddEntry(g20,"N=20");
  legend->AddEntry(g50,"N=50");
  legend->Draw("same");	 
 //-------------------------------------------------
	  
}