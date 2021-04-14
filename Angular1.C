void Angular1()
{
//=============================================================================================================
//Integers for the for loops
//int i ;
int j ;
//int k ;
//int m ;
//int n ;

//=============================================================================================================
//Variables needed for the calculations

double steps      ;          
double stepsr     ;     
int    nofsteps   ;    
int    nofstepsr  ;   

//-------------------------------------------------------------------------------------------------------------
//Input variables

int A               ;   // The atomic number of the nucleus
int Z               ;   // The Z of the nucleus
double energylab       ;   // The beam energy in the LAB system
double initialthetalab ;   // The initial detection angle in the LAB system (degrees)
double finalthetalab   ;   // The final detection angle in the LAB system (degrees)
double steplab         ; 

//-------------------------------------------------------------------------------------------------------------
//Output parameters

double spin             ; // The J of the nucleus
double mass             ; // The mass of the nucleus in amu
double initialthetacm   ; // The initial detection angle in the CM system (degrees)
double finalthetacm     ; // The final detection angle in the CM system (degrees)
double stepcm           ;
double energycm         ; // The beam energy in the CM system
double coulombcm        ; // The Coulomb Barrier in the CM system
double coulomblab       ; // The Coulomb Barrier in the LAB system
double meanmass         ; // The Mean mass of the system in MeV
double V1               ; // A parameter needed for the calculation of the Andersen screening
double ns               ; // The Somerfeld parameter
double Pi               ;

//=============================================================================================================
//Initialization of the parameters

Pi = 3.14159265359 ; 

//--------------------------------------------------------------------------------------------------------------
//cout << "Please enter A,Z,J,mass,energylab,initialthetalab,finalthetalab,steplab of the nucleus " <<endl;
//cin >> A >> Z >> spin >> mass >> energylab >> initialthetalab >> finalthetalab >> steplab ;
//--------------------------------------------------------------------------------------------------------------

//Finds the right j and mass, πρέπει να ανοίγει πρώτα το αρχείο, και να ορίσω τ διανύσματα atomic,nofprotons,s,m που αντιστοιχούν στις στήλες του αρχείου

//For (int i = 2; i<315;i++)
//{
 //  If (A = atomic(i))             // Detects the A of the isotope
  // {
   //    If (Z = nofprotons(i))     // Detects the Z of the isotope
    //   {  
	//	 spin = s(i);
     //    mass = m(i);
     //  }
    //}
//}
//-------------------------------------------------------------------------------------------------------------
//cout << "Please enter the beam energy in MeV, the initial and final detection angle as well as the step in degrees in that order, in the LAB frame of reference " <<endl;
//cin >> energylab >> initialthetalab >> finalthetalab >> steplab ;

A = 12;
Z = 6;
spin = 0.0;
mass = 12.0;
energylab = 10.0;
initialthetalab = 20.0;
finalthetalab = 80.0 ;
steplab = 10.0 ;
initialthetacm = initialthetalab * 2;
finalthetacm = finalthetalab * 2;
stepcm = steplab * 2;
steps = (finalthetacm - initialthetacm) / stepcm ;
nofsteps = 1000 ; //(int) steps ;

//--------------------------------------------------------------------------------------------------------------

double thetacm[10]    ;      // The detection angle in the CM system (degrees)
double thetalab[10]   ;      // The detection angle in the LAB system (degrees)
double domega[10]     ;      // d(solid angle lab)/d(solid angle cm)
double f[10]          ;      // The Andersen screening factor
double dscm[10]       ;      // The Mott cross section in the CM system (mb/sr)
double dslab[10]      ;      // The Mott cross section in the LAB system (mb/sr)
double srp[10]        ;      // The Rutherford cross section for the projectile for the detection angle theta in the LAB system ( mb/sr)
double srr[10]        ;      // The Rutherford cross section for the recoil for the detection angle theta in the LAB system ( mb/sr)
double srtotal[10];
double srpcm[10]        ;      // The Rutherford cross section for the projectile for the detection angle theta in the LAB system ( mb/sr)
double srrcm[10]        ;      // The Rutherford cross section for the recoil for the detection angle theta in the LAB system ( mb/sr)
double srtotalcm[10]    ;      // The total Rutherford cross section for the detection angle theta, sum of srp and srr, in the LAB system ( mb/sr)
double filab[10]      ;      // 90-theta
double sfi[10]        ;      // The Rutherford cross section for the projectile for the detection angle 90-theta in the LAB system ( mb/sr)
double ffi[10]  ;
//--------------------------------------------------------------------------------------------------------------

energycm = energylab / 2 ;
coulombcm = (2 * 1151722.15426385 * Z ** (2)) / (2 * A ** (1 / 3)) * 0.000001 ;
coulomblab = coulombcm * 2 ;
V1 = 0.001 * 0.04873 * pow(Z, 2) * sqrt(2 *pow( Z ,2 / 3)) ;
meanmass = 931.49 * mass / 2 ;
ns = 0.00729735 * pow(Z,2) * sqrt(meanmass / (2 * energycm)) ;

//---------------------------------------------------------------------------------------------------------------------------------
//Calculating the first entries in the columns for the mott scattering
thetalab[0] = initialthetalab;
thetacm[0] = 2*thetalab[0];
f[0] = pow(1 + 0.5 * (V1 / energycm), 2) / pow(1 + (V1 / energycm) + pow(V1 / (2 * energycm * sin(thetacm[0] * Pi / 360)), 2), 2);
ffi[0] = pow(1 + 0.5 * (V1 / energycm), 2) / pow(1 + (V1 / energycm) + pow(V1 / (2 * energycm * sin((180 - thetacm[0]) * Pi / 360)), 2), 2);
dscm[0] = pow(10,31.0) * f[0] * pow(1.44 * pow(10,-15.0) * pow(Z,2.0)/(4 * energycm), 2.0) * (pow(1/sin(thetacm[j] * Pi/360),4.0)+pow(1/cos(thetacm[0] * Pi / 360), 4.0) + (2 *pow (-1.0,2 * spin) / (2 * spin + 1)) * (cos(ns * log(pow(tan(thetacm[0] * Pi / 360),2))) / pow(sin(thetacm[0] * Pi / 360), 2) * pow(cos(thetacm[0] * Pi / 360), 2)));
domega[0] = (1 + cos(thetacm[0] * Pi / 180)) / pow(2 + 2 * cos(thetacm[0] * Pi / 180), (3 / 2));
dslab[0] = dscm[0] / domega[0];
//------------------------
//Rutherford LAB system
//srp[0] = 5.1837436 * pow(10,6) * (pow(Z,2) / pow(energylab * pow(10,3), 2) * (4 * cos(thetalab[0] * Pi / 180) /pow( sin(thetalab[0] * Pi / 180), 4) * f[0] ;
//sfi[0] = 5.1837436 * pow(10,6) * (pow(Z,2) / pow(energylab * pow(10,3), 2) * (4 * cos((90 - thetalab[0]) * Pi / 180) / pow(sin((90 - thetalab[0]) * Pi / 180), 4) * ffi[0];
//srr[0] = 4 * sfi[0] * (pow(sin((90 - thetalab[0]) * Pi / 180), 2) * cos((90 - thetalab[0]) * Pi / 180) * cos(thetalab[0] * Pi / 180)) / pow(sin(2 * (90 - thetalab[0]) * Pi / 180), 2);
//srtotal[0] = srp[0] + srr[0];
//------------------------
//Rutherford CM system
//srpcm[0] = srp[0] * domega[0];
//srrcm[0] = srr[0] * domega[0];
//srtotalcm[0] = srtotal[0] * domega[0];


//---------------------------------------------------------------------------------------------------------------------------------
//2For loop to create the MOTT scattering columns
for (int j=1;j<10;j++)
{
    //if (thetacm[j] > finalthetacm)
	//{
       thetacm[j] = thetacm[j-1] + stepcm ;
          f[j] = pow(1 + 0.5 * (V1 / energycm), 2) / pow(1 + (V1 / energycm) + pow(V1 / (2 * energycm * sin(thetacm[j] * Pi / 360)), 2), 2);
          ffi[j] = pow(1 + 0.5 * (V1 / energycm), 2) / pow(1 + (V1 / energycm) + pow(V1 / (2 * energycm * sin((180 - thetacm[j]) * Pi / 360)), 2), 2);
          dscm[j] = pow(10,31.0) * f[j] * pow(1.44 * pow(10,-15.0) * pow(Z,2.0)/(4 * energycm), 2.0) * (pow(1/sin(thetacm[j] * Pi/360),4.0)+pow(1/cos(thetacm[j] * Pi / 360), 4.0) + (2 *pow (-1.0,2 * spin) / (2 * spin + 1)) * (cos(ns * log(pow(tan(thetacm[j] * Pi / 360),2))) / pow(sin(thetacm[j] * Pi / 360), 2) * pow(cos(thetacm[j] * Pi / 360), 2)));
          thetalab[j] = thetacm[j] / 2;
          domega[j] = (1 + cos(thetacm[j] * Pi / 180)) / pow(2 + 2 * cos(thetacm[j] * Pi / 180), (3 / 2));
          dslab[j] = dscm[j] / domega[j];
          //------------------------
          //Rutherford LAB system
          //srp[j] = 5.1837436 * pow(10,6) * (pow(Z,2) / pow(energylab * pow(10,3), 2) * (4 * cos(thetalab[j] * Pi / 180) /pow( sin(thetalab[j] * Pi / 180), 4) * f[j] ;
          //sfi[j] = 5.1837436 * pow(10,6) * (pow(Z,2) / pow(energylab * pow(10,3), 2) * (4 * cos((90 - thetalab[j]) * Pi / 180) / pow(sin((90 - thetalab[j]) * Pi / 180), 4) * ffi[j];
          //srr[j] = 4 * sfi[j] * (pow(sin((90 - thetalab[j]) * Pi / 180), 2) * cos((90 - thetalab[j]) * Pi / 180) * cos(thetalab[j] * Pi / 180)) / pow(sin(2 * (90 - thetalab[j]) * Pi / 180), 2);
          //srtotal[j] = srp[j] + srr[j];
          //------------------------
          //Rutherford CM system
          //srpcm[j] = srp[j] * domega[j];
          //srrcm[j] = srr[j] * domega[j];
          //srtotalcm[j] = srtotal[j] * domega[j];
          //------------------------
          // εντολές για να γράφονται αυτά που θέλουμε στο αρχείο txt
		cout << thetalab[j] << " " << dslab[j] << endl;
    //}
    //else
      // {
	    //  Exit For ;
	  // }
 }
//===================================================================================================================================

//If clause to see if the energies exceed the coulomb barrier
 //If (energylab > coulomblab)
 //{   
	// cout << "Warning: The beam energy exceeds the Coulomb Barrier" << endl;
// }
//===============================================================================================================================
 
}