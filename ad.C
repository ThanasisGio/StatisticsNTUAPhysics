void ad()
{
 //Input Variables
int A;
int Z;
double mass;
double spin;
double energylab;
double initialthetalab;
double finalthetalab;
double steplab;

//Ouput Variables
double pi = 3.14159265359;
double meanmass;
double energycm;
double V1;
double ns;
double stepcm;
double steps;
int nofsteps;

//Initialazation of the Variables
A = 12;
Z = 6;
mass = 12.0;
spin = 0.0;
energylab = 10.0;
initialthetalab = 10.0;
finalthetalab = 80.0;
steplab = 10.0;
//---------------------------------------------------------------------------------------------
steps = (finalthetalab-initialthetalab)/steplab
//nofsteps = 8; 

//The Vectors
double thetacm[8];
double f[8];
double dscm[8];
double thetalab[8];
double domega[8];
double dslab[8];

//Calculations
energycm = energylab / 2;
stepcm = steplab * 2;
//---------------------------------------------------------------------------------------------
V1 = 0.001 * 0.04873 * pow(Z, 2) * sqrt(2 *pow( Z ,2 / 3)) ;
meanmass = 931.49 * mass / 2 ;
ns = 0.00729735 * pow(Z,2) * sqrt(meanmass / (2 * energycm)) ;
thetalab[0] = initialthetalab;
thetacm[0] = thetalab[0]*2;
f[0] = pow(1+0.5*V1/energycm,2) / pow(1+V1/energycm+pow(V1/(2*energycm*sin(thetacm[0]*pi/360)),2) ,2);
dscm[0] = f[0] * pow(10,31) * pow(1.44*pow(10,-15)*pow(Z,2)/(4*energycm),2) * (pow(1/sin(thetacm[0]*pi/360),4) + (pow(1/cos(thetacm[0]*pi/360),4) + 2*pow(-1,2*spin)/(2*spin+1) * cos(ns*log(pow(tan(thetacm[0]*pi/360),2)))/pow(sin(thetacm[0]*pi/360)*cos(thetacm[0]*pi/360),2) ) );
cout << thetacm[j] << " " << dscm[j] << endl;
//for(int j=1;j<8;j++)
//{
	//thetacm[j] = thetacm[j-1]+stepcm
	//f[j] = pow(1+0.5*V1/energycm,2) / pow(1+V1/energycm+pow(V1/(2*energycm*sin(thetacm[j]*pi/360)),2) ,2);
   // dscm[j] = f[j] * pow(10,31) * pow(1.44*pow(10,-15)*pow(Z,2)/(4*energycm),2) * (pow(1/sin(thetacm[j]*pi/360),4) + (pow(1/cos(thetacm[j]*pi/360),4) + 2*pow(-1,2*spin)/(2*spin+1) * cos(ns*log(pow(tan(thetacm[j]*pi/360),2)))/pow(sin(thetacm[j]*pi/360)*cos(thetacm[j]*pi/360),2) );
   // cout << thetacm[j] << " " << dscm[j] << endl;
//}
}