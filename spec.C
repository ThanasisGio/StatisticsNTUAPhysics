void spec(){

 TTree *tree[7];
 TGraph *gr[7];
 TString deg[7]={"-15deg", "-10deg", "-5deg", "0deg", "5deg", "10deg","15deg"};
 TString s[7]={"600s", "300s", "300s", "300s","300s", "300s", "600s"};
 TCanvas *c[7];

 float counts;
 float ch;
 double integral[7];//counts-->integration between channels 1500-2000
 double a[7];//counts/min
 double eN[7];//error of counts
 double ea[7];//error of counts/min
 double d[7] = {-15.0, -10.0, -5.0, 0.0, 5.0, 10.0, 15.0};  //degrees for TGraphErrors (counts/min)-Deg
 double ed[7];//error of degrees

 TFile *outf = TFile::Open("spectrum.root", "RECREATE");
 outf->cd();

 for(int j=0;j<7;j++){
 	TString file = "/home/annazach/Documents/organologia/rutherford/"+deg[j]+"_"+s[j]+".txt";
	tree[j] = new TTree("tree", "");
 	tree[j]->ReadFile(file,"ch:counts");
 	tree[j]->SetBranchAddress("ch",&ch);
 	tree[j]->SetBranchAddress("counts", &counts);
 	gr[j] = new TGraph(tree[j]->GetEntries());
 	for(int i=0; i<tree[j]->GetEntries(); i++){
		tree[j]->GetEntry(i);
		gr[j]->SetPoint(i, ch, counts);		
		if(s[j]=="600s"){gr[j]->SetPoint(i, ch, counts/2);}
 	}
 	c[j] = new TCanvas(deg[j]+"_"+s[j],deg[j]+"_"+s[j],900, 600);
 	c[j]->cd(1);
 	gr[j]->SetMarkerColor(4);
 	gr[j]->SetLineColor(4);
 	gr[j]->SetTitle(deg[j]+"_"+s[j]);
 	gr[j]->GetXaxis()->SetTitle("channel");
 	gr[j]->GetYaxis()->SetTitle("counts");
 	gr[j]->Draw("APL");
 	gr[j]->Write();

	integral[j] = gr[j]->Integral(1500,2500);
	eN[j] = sqrt(integral[j]);
	ed[j] = 2.5;

	if(deg[j]=="-15deg" || deg[j]=="15deg"){
		a[j]  = integral[j]/10;
		ea[j] = eN[j]/10;
	}
	else{
		a[j] =  integral[j]/5;
		ea[j] = eN[j]/5;
	}
	cout<<deg[j]<<" Counts=  "<<integral[j]<<"+/-"<<eN[j]<<"   Counts/min = "<<a[j]<<"+/-"<<ea[j]<<endl;
 }

 TCanvas *can = new TCanvas("c", "c", 900, 600);
 TGraphErrors *g = new TGraphErrors(7, d, a, ed, ea); 

 TF1 *func = new TF1("func", "[0]/(pow(sin(0.017453*(x-[1]/2)),4))",-20, 20);//my function 
 func->SetParameter(0, 0.01);
 func->SetParameter(1, 0.01);

 TF1 *gaus = new TF1("gaus", "gaus", -20, 20);//gauss

 g->Fit("func","R");//fit with my function 
 //g->Fit("gaus", "R");//fit with gauss

 func->GetParameter(0);
 func->GetParameter(1);
 g->GetFunction("func")->SetLineColor(2);
 gStyle->SetOptFit(001);
 g->SetMarkerColor(4);
 g->GetYaxis()->SetTitle("Counts/min");
 g->GetXaxis()->SetTitle("deg");
 g->SetTitle("Distribution of Counts per min over degrees");
 g->Draw("AP*");
 outf->Close();
}
