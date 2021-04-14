void ask43()
{
double x[6]={1.0,2.0,3.0,4.0,5.0,6.0};
double y[6]={1.0,1.3,0.9,1.8,1.2,2.9};
double sigma[6]={0.1,0.1,0.3,0.1,0.5,0.2};

double x_2[6], x_3[6], x_4[6], sigma_2[6];
double sum_x=0, sum_x2=0, sum_y=0, sum_yx=0, sum_yx2=0, sum_x4=0;
double mean_x, mean_x2, mean_y, mean_yx, mean_yx2, mean_x4;
double var_x, var_x2;
double cov_yx, cov_yx2;
double s_a, s_b, s_c;
double sum_sa=0, sum_sb=0, sum_sc=0;
double sumab=0, sumac=0, sumbc=0;

for(int i=0; i<6;i++)
{
	x_2[i] = x[i]*x[i];
	x_3[i] = x[i]*x[i]*x[i];
	x_4[i] = x[i]*x[i]*x[i]*x[i]; 
	sigma_2[i] = sigma[i]*sigma[i];

	sum_x  = sum_x + x[i];
	sum_x2 = sum_x2 + x_2[i];
	sum_y  = sum_y + y[i];
	sum_yx = sum_yx + y[i]*x[i];
	sum_yx2  = sum_yx2 + y[i]*x_2[i];
	sum_x4 = sum_x4 + x_4[i];
	
	sum_sa = sum_sa + 1/sigma_2[i];
	sum_sb = sum_sb + x_2[i]/sigma_2[i];
	sum_sc = sum_sc + x_4[i]/sigma_2[i];

	sumab = sumab + x[i]/sigma_2[i];
	sumac = sumac +x_2[i]/sigma_2[i];
	sumbc = sumbc +x_3[i]/sigma_2[i];
}

mean_x   = sum_x/6;
mean_x2  = sum_x2/6;
mean_y   = sum_y/6;
mean_yx  = sum_yx/6;
mean_yx2 = sum_yx2/6;
mean_x4  = sum_x4/6;

cov_yx = mean_yx - mean_y*mean_x;
var_x  = mean_x2 - mean_x*mean_x;

cov_yx2 = mean_yx2 - mean_y*mean_x2;
var_x2  = mean_x4  - mean_x2*mean_x2;
//-----------------y=a----------------------------------
double a1 = mean_y;

cout<<"------------y=a--------------"<<endl;
cout<<"a1 = "<<mean_y<< " +- "<< sqrt(1/sum_sa) <<endl;
cout<<" "<<endl;

cout<<"Corellation Matrix"<<endl;
cout<<"| "<<1/sum_sa<<"   0 |"<<endl;
cout<<"| 0   "<<1/sum_sa<<" |"<<endl;

//-----------------y=a+bx------------------------------
double b2 = cov_yx/var_x;
double a2 = mean_y - b2*mean_x;

cout<<"------------y=a+bx--------------"<<endl;
cout<<"a2 = "<<a2<< " +- "<< sqrt(1/sum_sa)<<", "<<"b2 = "<<b2<< " +- "<< sqrt(1/sum_sb)<< endl;
cout<<" "<<endl;

double vab=1/sumab;

cout<<"Corellation Matrix"<<endl;
cout<<"| "<<1/sum_sa<<"   "<<vab<<" |"<<endl;
cout<<"| "<<vab<<"   "<<1/sum_sb<<" |"<<endl;



//-----------------y=a+bx+cx^2-------------------------------------------------
double c3 = cov_yx2/var_x2;
double a3 = mean_y - b2*mean_x - c3*mean_x2;

cout<<"------------y=a+bx+cx^2--------------"<<endl;
cout<<"a3 = "<<a3<< " +- "<< sqrt(1/sum_sa)<<", "<<"b3 = "<<b2<< " +- "<< sqrt(1/sum_sb)<<", " <<"c3 = "<<c3<< " +- "<< sqrt(1/sum_sc)<<endl;
cout<<" " <<endl;

double vac=1/sumac;
double vbc=1/sumbc;

cout<<"Corellation Matrix"<<endl;
cout<<"| "<<1/sum_sa<<"   "<<vab<<"   "<<vac<<" |"<<endl;
cout<<"| "<<vab<<"   "<<1/sum_sb<<"   "<<vbc<<" |"<<endl;
cout<<"| "<<vac<<"   "<<vbc<<"   "<<1/sum_sc<<" |"<<endl;
cout<<endl;
cout<<endl;


//sigma of a, b, c ----------------------------------------------------------------

cout<<" sigma_a_hat = " << sqrt(1/sum_sa)<< endl;
cout<<" sigma_b_hat = " << sqrt(1/sum_sb)<< endl;
cout<<" sigma_c_hat = " << sqrt(1/sum_sc)<< endl;

//-------------minimum chi square-------------------------------------------------

double sum1=0, sum2=0, sum3=0;
double sum11=0, sum22=0, sum33=0;
for(int i=0;i<6;i++)
{
	sigma_2[i] = sigma[i]*sigma[i];
	x_2[i] = x[i]*x[i];

	sum1 = sum1 + ((y[i]-1.51667)*(y[i]-1.51667))/sigma_2[i];

	sum2 = sum2 + ((y[i]-0.50667 - 0.288571*x[i])*(y[i]-0.50667 - 0.288571*x[i]))/sigma_2[i];

	sum3 = sum3 + ((y[i]+ 0.162542 -0.288571*x[i] - 0.044137*x_2[i])*(y[i]+ 0.162542 -0.288571*x[i] - 0.044137*x_2[i]))/sigma_2[i];


//------------------------------

	sum11 = sum11 + ((y[i]-1.46217)*(y[i]-1.46217))/sigma_2[i];

	sum22 = sum22 + ((y[i]-0.639007 - 0.309926*x[i])*(y[i]-0.639007 - 0.309926*x[i]))/sigma_2[i];

	sum33 = sum33 + ((y[i]- 1.0106 +0.0133546*x[i] - 0.051765*x_2[i])*(y[i]- 1.0106 +0.0133546*x[i] - 0.051765*x_2[i]))/sigma_2[i];


}


cout<< " "<<endl;
cout<<"case 1: min chi2 = "<< sum1 << ", min_x2/ndf = "<<sum1/5<< " --fit: " << sum11<<", fit min_x2/ndf = "<<sum11/5<<endl;
cout<<"case 2: min chi2 = "<< sum2 << ", min_x2/ndf = "<<sum2/4<< " --fit: " << sum22<<", fit min_x2/ndf = "<<sum22/4<<endl;
cout<<"case 3: min chi2 = "<< sum3 << ", min_x2/ndf = "<<sum3/3<< " --fit: " << sum33<<", fit min_x2/ndf = "<<sum33/3<<endl;




//-----------------Graph (x,y+-sigma)-------------------------------
TGraphErrors *gr1 = new TGraphErrors (6, x, y, NULL , sigma);
TCanvas *can1 = new TCanvas("can1", "y=a", 900, 600);
gr1->Draw("A*");

TFitResultPtr r0=gr1->Fit("pol2", "S");
TMatrixD cov0 =r0->GetCovarianceMatrix();
cov0.Print();

}




