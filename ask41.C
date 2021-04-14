void ask41(){


double t[10]={1,2,3,4,5,6,7,8,9,10};
double y[10]={69.4,40.8,44.4,27.7,17.1,12.3,7.8,5.9,7.2,3.9};
double sigma[10]={13.9,8.2,8.9,5.5,3.4,2.5,1.6,1.2,1.4,0.8};

//double t_new[10]={1,2,3,4,5,6,7,8,9,10,15};
//d//ouble y_new[10]={69.4,40.8,44.4,27.7,17.1,12.3,7.8,5.9,7.2,3.9, 0.78};

double sigma_2[10], z[10], ez[10], ez_2[10];
double sumt=0, sumtt=0, sumz=0, sumzt=0, sumez=0, suma=0, sumb=0, sumr=0;
double mt=0, mtt=0, mz=0, mzt=0;

for(int i=0;i<10;i++)
{
	z[i]=log(y[i]);
	
	ez[i]  = sigma[i]/y[i];
	ez_2[i]=ez[i]*ez[i];

	sumzt=sumzt + z[i]*t[i];
	sumt=sumt + t[i];
	sumtt=sumtt + t[i]*t[i];
	sumz=sumz + z[i];

	suma = suma + (1/ez_2[i]);
	sumb = sumb + (t[i]*t[i])/ez_2[i];
	sumr = sumr + t[i]/ez_2[i];
}
mt=sumt/10;
mtt=sumtt/10;
mzt=sumzt/10;
mz=sumz/10;

double sigma_a = sqrt(1/suma);
double sigma_b = sqrt(1/sumb);

double cov= mzt - mt*mz;
double vart =mtt- mt*mt;
double b = cov/vart;
double a = mz - (cov*mt)/vart;

double sigma_tau = 0.02/(0.32*0.32);
double sigma_y0 = exp(a)*0.14;

double r1 = 1/sumr;
double p=sigma_a*sigma_b;
double r  = r1/p;
cout<< "r = "<< r <<endl; 

cout<<"b = "<<b<<" +/- " <<sigma_b<<endl;
cout<<"τ = "<< -1/b<<" +/- " <<sigma_tau<<endl;
cout<< " "<<endl;

cout<<"a = "<<a<<" +/- " <<sigma_a<<endl;
cout<<"y0 = "<<exp(a)<<" +/- " <<sigma_y0<<endl;
cout<<" "<<endl;
cout<<"y(15) = "<< exp(a)*exp(b*15)<<endl;


TGraphErrors *gr1 = new TGraphErrors (10, t, z, NULL , ez);
TCanvas *can1 = new TCanvas("can1", "lny-t", 900, 600);
gr1->Draw("A*");

TFitResultPtr r0=gr1->Fit("pol1", "S");
TMatrixD cov0 =r0->GetCovarianceMatrix();
cov0.Print();

/*TGraphErrors *gr2 = new TGraphErrors (10, t, y, NULL , sigma);
TCanvas *can2 = new TCanvas("can2", "y-t", 900, 600);
gr2->Draw("A*");

TFitResultPtr r0=gr2->Fit("expo", "S");
TMatrixD cov0 =r0->GetCovarianceMatrix();
cov0.Print();*/
}

