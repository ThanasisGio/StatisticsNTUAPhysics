void ask44a()
{
TRandom *u = new TRandom();
TRandom *v =new TRandom();
u->SetSeed(0); 
v->SetSeed(0);
double x[10], y[10];
double s[10];

double sum_x=0, sum_xx=0, sum_y=0, sum_yx=0;
double mean_x, mean_xx, mean_y, mean_yx;
double var, cov;
double s_a, s_b, s_c;
double sum_sa=0, sum_sb=0;
double a, b;

for(int i=0; i<10; i++)
	{
		s[i]=0.5;
		x[i]=u->Uniform(0,10);
		y[i]=v->Gaus(x[i]+1, 0.5);
		//cout<<"( "<<x[i]<<", "<<y[i]<<"+/-0.5)"<<endl;
		
		sum_x = sum_x + x[i];
		sum_y = sum_y + y[i];
		sum_xx = sum_xx +x[i]*x[i];
		sum_yx = sum_yx + y[i]*x[i];
	
		sum_sa = sum_sa + 1/(s[i]*s[i]);
		sum_sb = sum_sb + (x[i]*x[i])/(s[i]*s[i]);
	}

mean_x=sum_x/10;
mean_xx=sum_xx/10;
mean_y=sum_y/10;
mean_yx=sum_yx/10;

cov = mean_yx -mean_x*mean_y;
var = mean_xx -mean_x*mean_x;

double sigma_a = sqrt(1/sum_sa);
double sigma_b = sqrt(1/sum_sb);

b = cov/var;
a = mean_y - b*mean_x;
cout<<"a = "<<a<<" +/-"<<sigma_a<<endl;
cout<<"b = "<<b<<" +/-"<<sigma_b<<endl;

TGraphErrors *gr =new TGraphErrors (10, x, y, NULL, s);
TCanvas *can = new TCanvas("can", "can", 900, 600);
gr->Draw("A*");

}
