void Askisi22()
{
	
	TH1F *h2    = new TH1F("dice","Distribution of the sum of 2  dice, thrown 10000 times",13,0,13);
	TH1F *h10   = new TH1F("dice","Distribution of the sum of 10 dice, thrown 10000 times",52,9,61);
	TH1F *h20   = new TH1F("dice","Distribution of the sum of 20 dice, thrown 10000 times",102,19,121);
	TRandom *r1 = new TRandom();
	r1->SetSeed(0);
	double z=0;
	for (int i=0;i<10000;i++)
		{
			for (int j=0;j<2;j++)
			{
				double r2 = r1->Uniform(0.5,6.0);
				
				      // int    x  = (int) (r2); //Transforms r2 into an integer ,does not work as intended due to the rounding of the numbers
				       z = z + r2 ;
					
            }
		
			h2->Fill(z);
			z=0;
		}
	for (int i=0;i<10000;i++)
		{
			for (int j=0;j<10;j++)
			{
				double r2 = r1->Uniform(0.5,6.0);
				
				       z = z + r2 ;
					
            }
		
			h10->Fill(z);
			z=0;
		}
	for (int i=0;i<10000;i++)
		{
			for (int j=0;j<20;j++)
			{
				double r2 = r1->Uniform(0.5,6.0);
				
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
	