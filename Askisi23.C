void Askisi23()
{
	TH1F *h     = new TH1F("h","Distribution of the product of 10 variables following the uniform distribution(1,2), for a sample of 10000 repeats",100.,-50.,500.);
	TRandom *r1 = new TRandom();
	r1->SetSeed(0);
	double y=1;
	for (int i=0;i<10000;i++) // for loop for 10000 repeats
		{
			for (int j=0;j<10;j++) // for loop that creates a set of ten random numbers
			{
				double r2 = r1->Uniform(1,2);
				        y = y*r2 ; // the product of the random numbers
						
            }
		
			h->Fill(y); 
			y=1;
		}

    h->Draw();	

}