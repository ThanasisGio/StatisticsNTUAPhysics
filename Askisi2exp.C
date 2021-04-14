void Askisi2exp()
{
	TH1F *h2    = new TH1F("h2", "Distribution of the sum of 2  variables following the exponential Distribution, thrown 10000 times",48,-1,10);
	TH1F *h10   = new TH1F("h10","Distribution of the sum of 10 variables following the exponential Distribution, thrown 10000 times",104,0,40);
	TH1F *h20   = new TH1F("h20","Distribution of the sum of 20 variables following the exponential Distribution, thrown 10000 times",204,0,50);
	TRandom *r1 = new TRandom();
	r1->SetSeed(0);
	double z=0;
	for (int i=0;i<10000;i++)
		{
			for (int j=0;j<2;j++)
			{
				double r2 = r1->Exp(1.0);
				
				       
				       z = z + r2 ;
					
            }
		
			h2->Fill(z);
			z=0;
		}
	for (int i=0;i<10000;i++)
		{
			for (int j=0;j<10;j++)
			{
				double r2 = r1->Exp(1.0);
				
				       z = z + r2 ;
					
            }
		
			h10->Fill(z);
			z=0;
		}
	for (int i=0;i<10000;i++)
		{
			for (int j=0;j<20;j++)
			{
				double r2 = r1->Exp(1.0);
				
				       z = z + r2 ;
					
            }
		
			h20->Fill(z);
			z=0;
		}
	TCanvas *c2  = new TCanvas("c2","Histogram of the Distribution of the sum of 2   dice, thrown 10000 times",500,500,700,500);
	h2->Draw();
	TCanvas *c10 = new TCanvas("c10","Histogram of the Distribution of the sum of 10  dice, thrown 10000 times",500,500,700,500);
	h10->Draw();
	TCanvas *c20 = new TCanvas("c20","Histogram of the Distribution of the sum of 20  dice, thrown 10000 times",500,500,700,500);
	h20->Draw();
}
	