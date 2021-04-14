#include <iostream>
#include "TMath.h"
#include "TH2.h"
#include "TH1F.h"
#include "TROOT.h"
#include "TMath.h"
#include "TRandom.h"
#include "TRandom3.h"
#include "TSystem.h"
#include "TDirectory.h"
#include "Math/Math.h"
#include "Math/SpecFuncMathCore.h"


void Ask2(int N)
{
	TH1F *dice  = new TH1F("dice","Distribution of the sum of N dice, thrown 10000 times",5*N+2,N-1,6*N+1);
	TRandom *r1 = new TRandom();
	r1->SetSeed(0);
	int z=0;
	for (int i=0;i<10000;i++)
		{
			for (int j=0;j<N;j++)
			{
				double r2 = r1->Uniform(1,6.0);
				int    x  = (int) (r2);
				       z = z + x ;
						//cout<<z<<endl;
            }
		
			dice->Fill(z);
			z=0;
		}
//dice->SetTitle("Distribution of the sum of ");
//dice->GetYaxis()->SetTitle("pdf of "+[N]);
//dice->GetXaxis()->SetTitle("Sum of dice throw of "+[N]);
//dice->SetLineColor(N+1);
	dice->Scale(1/(dice->Integral()));
    dice->Draw();	

}