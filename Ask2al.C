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


void Ask2al(int N)
{
	TH1F *dice  = new TH1F("dice","Distribution of the sum of N dice, thrown 10000 times",5*N+2,N-1,6*N+1);
	TRandom *r1 = new TRandom();
	r1->SetSeed(0);
	double    z = 0.0;
	for (int i=0;i<10000;i++)
		{
			for (int j=0;j<N;j++)
			{
				double r2 = r1->Uniform(1,6);
				       z = z + r2 ;
            }
		
			dice->Fill(z);
			z=0;
		}

	
    dice->Draw();	

}