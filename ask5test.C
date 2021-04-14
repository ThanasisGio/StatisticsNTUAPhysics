void ask5test()
{
TH1F *uh  = new TH1F("uh","Distribution of u = x + y ",20,-10,10);
	TRandom *x = new TRandom();
	x->SetSeed(0);
	TRandom *y = new TRandom();
	y->SetSeed(0);
	double u=0;
	for (int i=0;i<1000;i++)
		{
		
			
				u = x->Gaus(0,1)+y->Gaus(0,1);
						
		
			uh->Fill(u);
			u=0;
		}
		
		uh->Draw();
}