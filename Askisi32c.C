void Askisi32c()
{
  TRandom *r1 = new TRandom();
  r1->SetSeed(0);
  TH1F *h10 = new TH1F("h10","Distribution of thita ml for N = 10, 1000 repetitions",60 ,0,3);
  TH1F *h20 = new TH1F("h20","Distribution of thita ml for N = 20, 1000 repetitions",60 ,0,3);
  TH1F *h50 = new TH1F("h50","Distribution of thita ml for N = 50, 1000 repetitions",60 ,0,3);
  double n10 = 0;
  double n20 = 0;
  double n50 = 0;
 //---------------------------------------------------------------------------------------------------------- 
  for(int j=0;j<1000;j++)
  {    
	  for (int i=0;i<10;i++)
      {
         double r10 = r1->Exp(1);
	            n10 = n10 + r10 ;
	 
      } 
	  double m10 = 10/n10;
	  h10->Fill(m10);
	  n10 = 0;
	  m10 = 0;
  }
  TCanvas *c1 = new TCanvas("c1","Distribution of thita ml for N = 10, 1000 repetitions",500,500,700,500);
  h10->Draw();
 //------------------------------------------------------------------------------------------------------------
  for(int j=0;j<1000;j++)
  {    
	  for (int i=0;i<20;i++)
      {
         double r20 = r1->Exp(1);
	            n20 = n20 + r20 ;
	 
      } 
	  double m20 = 20/n20;
	  h20->Fill(m20);
	  n20 = 0;
	  m20 = 0;
  }
  TCanvas *c2 = new TCanvas("c2","Distribution of thita ml for N = 20, 1000 repetitions",500,500,700,500);
  h20->Draw();
 //------------------------------------------------------------------------------------------------------------ 
 for(int j=0;j<1000;j++)
  {    
	  for (int i=0;i<50;i++)
      {
         double r50 = r1->Exp(1);
	            n50 = n50 + r50 ;
	 
      } 
	  double m50 = 50/n50;
	  h50->Fill(m50);
	  n50 = 0;
	  m50 = 0;
  }
  TCanvas *c3 = new TCanvas("c3","Distribution of thita ml for N = 50, 1000 repetitions",500,500,700,500);
  h50->Draw();
 //------------------------------------------------------------------------------------------------------------ 
}