void ask44()
{
TRandom *u = new TRandom();
TRandom *v =new TRandom();
u->SetSeed(0); 
v->SetSeed(0);
double x[20], y[20];
double s[20];

double sum_x=0, sum_xx=0, sum_y=0, sum_yx=0;
double mean_x, mean_xx, mean_y, mean_yx;
double var, cov;
double s_a, s_b, s_c;
double sum_sa=0, sum_sb=0;
double a, b;
double x2min=0;

TH1F *ha = new TH1F("ha", "ha", 120, 0.5, 1.5);
TH1F *hb = new TH1F("hb", "hb", 120, 0.9, 1.1);
//TH1F *hatr = new TH1F("hatr", "hatr", 100, -500 , 500 );
//TH1F *hbtr = new TH1F("hbtr", "hbtr", 100, -500, 500);

TH1F *hatr = new TH1F("hatr", "hatr", 125, -5 , 5);
TH1F *hbtr = new TH1F("hbtr", "hbtr", 125, -5, 5);
TH1F *h_x2min = new TH1F("h_x2min","Distribution of X_{min}^{2}",125,0,50);

for(int j=0; j<10000;j++)
{
	for(int i=0; i<20; i++)
	{
		s[i]=0.1;
		x[i]=u->Uniform(0,10);
		y[i]=v->Gaus(x[i]+1, 0.1);
		
		sum_x = sum_x + x[i];
		sum_y = sum_y + y[i];
		sum_xx = sum_xx +x[i]*x[i];
		sum_yx = sum_yx + y[i]*x[i];
	
		sum_sa = sum_sa + 1/(s[i]*s[i]);
		sum_sb = sum_sb + (x[i]*x[i])/(s[i]*s[i]);
	}

mean_x=sum_x/20;
mean_xx=sum_xx/20;
mean_y=sum_y/20;
mean_yx=sum_yx/20;

cov = mean_yx -mean_x*mean_y;
var = mean_xx -mean_x*mean_x;

double sigma_a = sqrt(1/sum_sa);
double sigma_b = sqrt(1/sum_sb);

double b = cov/var;
double a = mean_y - b*mean_x;

double atr = (a-1)/(100*sigma_a);
double btr = (b-1)/(100*sigma_b);
ha->Fill(a);
hb->Fill(b);
hatr->Fill(atr);
hbtr->Fill(btr);

//-------------------x2min histo----------------------------------------------------------
double x2min=0;
for(int i=0;i<20;i++)
{
	x2min = x2min + ((y[i]-a-b*x[i])*(y[i]-a-b*x[i]))/(s[i]*s[i]);

}
h_x2min->Fill(x2min);

sum_x=0;
sum_xx=0;
sum_y=0;
sum_yx=0;

}
TCanvas *c1 = new TCanvas("can1", "can1", 900, 600);
ha->Draw();

TCanvas *c2 = new TCanvas("can2", "can2", 900, 600);
hb->Draw();

TCanvas *c3 = new TCanvas("can3", "can3", 900, 600);
hatr->Draw();

TCanvas *c4 = new TCanvas("can4", "can4", 900, 600);
hbtr->Draw();

TCanvas *c5 = new TCanvas("can5", "can5", 900, 600);
h_x2min->Scale(1/(h_x2min->Integral()));
h_x2min->Draw();


TFile f("ask4.root","recreate");
h_x2min->Write();

}
