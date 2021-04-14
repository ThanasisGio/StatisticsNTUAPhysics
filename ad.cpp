void ad(int A,int Z, double mass, double spin, double energylab, double initialthetalab, double finalthetalab, double steplab)
{
 //Input Variables
//double mass;
//double spin;

//===========================================================================================
//If clauses for the user s inputs

if(energylab<=0)
{
	cout<<" The beam energy cannot be less or equal to zero. It is reset at 0.001 MeV "<<endl;
	energylab = 0.001;
	
}

if (initialthetalab <=0)
{
	cout << " Due to Kinematics, Mott Scattering is only possible for the angular distribution 0<theta<90, where theta is the detection angle. The initial detection angle is reset by default at 0.5 degrees" << endl;
	initialthetalab = 0.5;
}

if (initialthetalab >=90)
{
	cout << " Due to Kinematics, Mott Scattering is only possible for the angular distribution 0<theta<90, where theta is the detection angle. The initial detection angle is reset by default at 85 degrees" << endl;
	initialthetalab = 85.0;
}

if (finalthetalab >=90)
{
	cout << " Due to Kinematics, Mott Scattering is only possible for the angular distribution 0<theta<90, where theta is the detection angle. The final detection angle is reset by default at 89 degrees" << endl;
	finalthetalab = 89.0;
}

if(initialthetalab > finalthetalab)
{
	cout<<"The initial detection angle cannot be greater than the final detection angle."<<endl;
	finalthetalab = initialthetalab;
}



//============================================================================================
//Ouput Variables
double pi = 3.14159265359;
double meanmass;
double energycm;
double finalthetacm;
double initialthetacm;
double V1;
double ns;
double stepcm;
double steps;
int nofsteps;

//============================================================================================
//Calculations

//Number of steps and the vectors
steps = (finalthetalab-initialthetalab)/steplab ;
nofsteps = (int) steps ;  
nofsteps = nofsteps + 1; // Για κάποιο λόγο στρογγυλλοποιεί πάντα προς τα κάτω
Double_t thetacm[1000];
Double_t f[1000];
Double_t dscm[1000];
Double_t thetalab[1000];
Double_t domega[1000];
Double_t dslab[1000];

//Initialazation of the variables and parameters
initialthetacm = 2*initialthetalab;
finalthetacm = finalthetalab;
energycm = energylab / 2.0;
stepcm = steplab * 2.0 ;
V1 = 0.001 * 0.04873 * pow(Z, 2.0) * sqrt(2 *pow( Z ,0.667)) ;
meanmass = 931.49 * mass / 2 ;
ns = 0.00729735 * pow(Z,2.0) * sqrt(meanmass / (2 * energycm)) ;
thetalab[0] = initialthetalab;
thetacm[0] = initialthetalab*2;
f[0] = pow(1+0.5*V1/energycm,2.0) / pow(1+V1/energycm+pow(V1/(2*energycm*sin(thetacm[0]*pi/360)),2.0) ,2);
dscm[0] = f[0] * pow(10,31.0) * pow(1.44*pow(10,-15.0)*pow(Z,2)/(4*energycm),2.0) * (pow(1/sin(thetacm[0]*pi/360),4.0) + (pow(1/cos(thetacm[0]*pi/360),4.0) + 2*pow(-1.0,2*spin)/(2*spin+1) * cos(ns*log(pow(tan(thetacm[0]*pi/360),2.0)))/pow(sin(thetacm[0]*pi/360)*cos(thetacm[0]*pi/360),2.0) ) );
domega[0] = (1+cos(thetacm[0]*pi/180))/pow(2+2*cos(thetacm[0]*pi/180),1.5);
dslab[0] = dscm[0]/domega[0];
cout << thetalab[0] << " " << dslab[0] << endl;

//For loop for the calculations for the Mott Scattering
for(int j=1;j<nofsteps;j++)
{
	thetacm[j] = thetacm[j-1]+ stepcm ;
	thetalab[j] = thetacm[j]/2;
	if(thetalab[j]<=finalthetalab)
	{
		//Mott CM system
		f[j] = pow(1+0.5*V1/energycm,2) / pow(1+V1/energycm+pow(V1/(2*energycm*sin(thetacm[j]*pi/360)),2) ,2);
        dscm[j] = f[j] * pow(10,31) * pow(1.44*pow(10,-15)*pow(Z,2)/(4*energycm),2) * (pow(1/sin(thetacm[j]*pi/360),4) + (pow(1/cos(thetacm[j]*pi/360),4) + 2*pow(-1,2*spin)/(2*spin+1) * cos(ns*log(pow(tan(thetacm[j]*pi/360),2)))/pow(sin(thetacm[j]*pi/360)*cos(thetacm[j]*pi/360),2) ) );
        //Mott LAB system
		domega[j] = (1+cos(thetacm[j]*pi/180))/pow(2+2*cos(thetacm[j]*pi/180),1.5);
	    dslab[j] = dscm[j]/domega[j];
	    cout << thetalab[j] << " " << dslab[j] << endl;
	}
}
}