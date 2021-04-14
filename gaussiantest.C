void gaussiantest()
{
TF1 efunc("X","sqrt(2*3.14)*exp((-1/2)*x*x)",-100.,100.);
TH1F*h5=new TH1F("h5","Parameter U = X/Y distribution",1000,-100.,100.);
for (int i=0;i<1000;i++) {h->Fill(X->GetRandom());}
h5->Draw();
}