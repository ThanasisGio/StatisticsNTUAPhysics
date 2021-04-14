void ask4(int N)
{
    TH1F *h  = new TH1F("h","Distribution of  10000 repetitions",1000 ,0.,2.);
	TRandom *u = new TRandom();
	u->SetSeed(0);
	double    I = 0;
	double    g = 0;
	double    x = 0;
	for (int i=0;i<10000;i++)
	{
		for (int j=0;j<N;j++)
		{
			double  r = u->Uniform(1,2);
			        g = 1/r ;
					x = x + g ;
		
		}
	    I = x/N ;
		h->Fill(I);
		I=0;
		g=0;
		x=0;
	}
  h->Draw();
  double m = h->GetMean();
  double s = h->GetRMS();
}