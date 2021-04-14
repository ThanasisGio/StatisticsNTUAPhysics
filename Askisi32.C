void Askisi32()
{
	//------Ειναι λάθος γτ παιρνω καθε φορα καινουργιο Σxi ενω θελουμε να ειναι σταθερο, δες Askisi32a για το σωστο-----
  TRandom *r1 = new TRandom();
  r1->SetSeed(0);
  double n10 = 0;
  double n20 = 0;
  double n50 = 0;
  double ly10[10];
  double ly20[10];
  double ly50[10];
  double  x10[10] = {1,2,3,4,5,6,7,8,9,10};

//-----------------------------------------------------  
  for(int j=1;j<11;j++)
  {
	  for (int i=0;i<10;i++)
      {
         double r10 = r1->Exp(1);
	     n10 = n10 + r10 ;
	 
      } 
	  double m10 = 10/n10;
	  ly10[j] = 10*log(j)-n10*j ; 
	  n10 = 0; // μηδενιζω το η10 ωστε καθε φορα ν παιρνω καινουργιο
	  
  }
  TGraph *g10 = new TGraph(10,x10,ly10);
  g10->SetTitle("lnL(thita) with respect to thita for N=10;thita;lnL(thita)");
  TCanvas *c1 = new TCanvas("c1","lnL(thita) with respect to thita for N=10",500,500,700,500);
  g10->Draw("A*");
 //----------------------------------------------------- 
  for(int j=1;j<11;j++)
  {
	  for (int i=0;i<20;i++)
      {
         double r20 = r1->Exp(1);
	     n20 = n20 + r20 ;
	 
      } 
	  double m20 = 20/n20;
	  ly20[j] = 20*log(j)-n20*j ; 
	 //εδω δν μηδενιζω το η20 με αποτέλεσμα απλώς να προστίθεται σε καθε επανάληψη 
  }
  TGraph *g20 = new TGraph(10,x10,ly20);
  g20->SetTitle("lnL(thita) with respect to thita for N=20;thita;lnL(thita)");
  TCanvas *c2 = new TCanvas("c2","lnL(thita) with respect to thita for N=20",500,500,700,500);
  g20->Draw("A*");
//-------------------------------------------------------
  for(int j=1;j<11;j++)
  {
	  for (int i=0;i<50;i++)
      {
         double r50 = r1->Exp(1);
	     n50 = n50 + r50 ;
	 
      } 
	  double m50 = 50/n50;
	  ly50[j] = 50*log(j)-n50*j ; 
	 
  }
  TGraph *g50 = new TGraph(10,x10,ly50);
  g50->SetTitle("lnL(thita) with respect to thita for N=50;thita;lnL(thita)");
  TCanvas *c3 = new TCanvas("c3","lnL(thita) with respect to thita for N=50",500,500,700,500);
  g50->Draw("A*");
  
 //------------------------------------------------------ 
}