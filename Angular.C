void Angular()
{
//=============================================================================================================
//Integers for the for loops
int i ;
int j ;
int k ;
int m ;
int n ;

//=============================================================================================================
//Variables needed for the calculations

double steps      ;          
double stepsr     ;     
int    nofsteps   ;    
int    nofstepsr  ;   

//-------------------------------------------------------------------------------------------------------------
//Input variables

double A               ;   // The atomic number of the nucleus
double Z               ;   // The Z of the nucleus
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
cout << "Please enter the mass and atomic number (A,Z respectively) of the nucleus " <<endl;
cin >> A >> Z;
//--------------------------------------------------------------------------------------------------------------

//Finds the right j and mass, πρέπει να ανοίγει πρώτα το αρχείο, και να ορίσω τ διανύσματα atomic,nofprotons,s,m που αντιστοιχούν στις στήλες του αρχείου

For (int i = 2; i<315;i++)
{
   If (A = atomic(i))             // Detects the A of the isotope
   {
       If (Z = nofprotons(i))     // Detects the Z of the isotope
       {  
		 spin = s(i);
         mass = m(i);
       }
    }
}
//-------------------------------------------------------------------------------------------------------------
cout << "Please enter the beam energy in MeV, the initial and final detection angle as well as the step in degrees in that order, in the LAB frame of reference " <<endl;
cin >> energylab >> initialthetalab >> finalthetalab >> steplab ;

//=============================================================================================================
//If clauses to check if the user s inputs are logical
If (energylab < 0)
 {   
    cout << "Warning: The beam energy cannot be negative or zero. The beam energy is set by default at 0.01 MeV" << endl;
    energylab = 0.001 ;
 }

If (energylab = 0)
 {
    cout << "Warning: The beam energy cannot be negative or zero. The beam energy is set by default at 0.01 MeV" << endl;
    energylab = 0.001;
 }

//-------------------------------------------------------------------------------------------------------------
// 0<initialtheta<90
If (initialthetalab < 0.001 )
 {
   cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The initial detection angle is set by default at 0.001 degrees " << endl;
   initialthetalab = 0.001 ;
 }  
If ( initialthetalab = 0 )
 {
        cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The detection angle is set by default at 0.001 degrees " << endl;
        initialthetalab = 0.001;
 }		
If (initialthetalab > 89.98 )
 {
    cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The detection angle is set by default at 85 degrees " << endl;
    initialthetalab = 85;
 }	
If ( initialthetalab = 89.98 ) 
 { 
    cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The detection angle is set by default at 85 degrees " << endl;
    initialthetalab = 85;
 }	
 
 If ( finalthetalab > 89.98 ) 
 { 
    cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The detection angle is set by default at 89.98 degrees " << endl;
    finalthetalab = 89.98;
 }	
 
//------------------------------------------------------------------------------------------------------------
//finalthetalab<initialthetalab
If ( finalthetalab < initialthetalab ) 
 {
   cout << "Warning: The final angle of detection cannot be less than the initial angle. The final detection angle is set by default to be equal with the initial detection angle." << endl;
   finalthetalab = initialthetalab ;
 }
//------------------------------------------------------------------------------------------------------------
If (steplab < 0.001)
 {  
   steplab = 0.001;
   cout << "Warning: The step cannot be less than 0.001 degrees.The step is set by default at 0.001 degrees" << endl;
 }
//=============================================================================================================

initialthetacm = initialthetalab * 2;
finalthetacm = finalthetalab * 2;
stepcm = steplab * 2;
steps = (finalthetacm - initialthetacm) / stepcm ;
nofsteps = (int) steps ;

//--------------------------------------------------------------------------------------------------------------

double thetacm[nofsteps]    ;      // The detection angle in the CM system (degrees)
double thetalab[nofsteps]   ;      // The detection angle in the LAB system (degrees)
double domega[nofsteps]     ;      // d(solid angle lab)/d(solid angle cm)
double f[nofsteps]          ;      // The Andersen screening factor
double dscm[nofsteps]       ;      // The Mott cross section in the CM system (mb/sr)
double dslab[nofsteps]      ;      // The Mott cross section in the LAB system (mb/sr)
double srp[nofsteps]        ;      // The Rutherford cross section for the projectile for the detection angle theta in the LAB system ( mb/sr)
double srr[nofsteps]        ;      // The Rutherford cross section for the recoil for the detection angle theta in the LAB system ( mb/sr)
double srtotal[nofsteps]    ;      // The total Rutherford cross section for the detection angle theta, sum of srp and srr, in the LAB system ( mb/sr)
double filab[nofsteps]      ;      // 90-theta
double sfi[nofsteps]        ;      // The Rutherford cross section for the projectile for the detection angle 90-theta in the LAB system ( mb/sr)

//--------------------------------------------------------------------------------------------------------------

energycm = energylab / 2 ;
coulombcm = (2 * 1151722.15426385 * Z ^ (2)) / (2 * A ^ (1 / 3)) * 0.000001 ;
coulomblab = coulombcm * 2 ;
V1 = 0.001 * 0.04873 * Z ^ (2) * Sqr(2 * Z ^ (2 / 3)) ;
meanmass = 931.49 * mass / 2 ;
ns = 0.00729735 * (Z ^ (2)) * Sqr(meanmass / (2 * energycm)) ;

//---------------------------------------------------------------------------------------------------------------------------------
//Calculating the first entries in the columns for the mott scattering

f(1) = (1 + 0.5 * (V1 / energycm)) ^ (2) / (1 + (V1 / energycm) + (V1 / (2 * energycm * Sin(initialthetacm * Pi / 360))) ^ (2)) ^ (2);
dscm(1) = (10 ^ 31) * f * (1.44 * 10 ^ (-15) * Z ^ (2) / (4 * energycm)) ^ (2) * ((1 / Sin(initialthetacm * Pi / 360)) ^ (4) + (1 / Cos(initialthetacm * Pi / 360)) ^ (4) + (2 * (-1) ^ (2 * spin) / (2 * spin + 1)) * (Cos(ns * WorksheetFunction.Ln(Tan(initialthetacm * Pi / 360) ^ (2))) / (Sin(initialthetacm * Pi / 360) ^ (2) * Cos(initialthetacm * Pi / 360) ^ (2))));
domega(1) = (1 + Cos(initialthetacm * Pi / 180)) / (2 + 2 * Cos(initialthetacm * Pi / 180)) ^ (3 / 2);
dslab(1) = dscm / domega;

//------------------------
//Rutherford LAB system

ffi = (1 + 0.5 * (V1 / energycm)) ^ (2) / (1 + (V1 / energycm) + (V1 / (2 * energycm * Sin((180 - thetacm) * Pi / 360))) ^ (2)) ^ (2);
srp(1) = 5.1837436 * 10 ^ 6 * (Z ^ (2) / (energylab * 10 ^ (3))) ^ (2) * (4 * Cos(initialthetalab * Pi / 180) / Sin(initialthetalab * Pi / 180) ^ (4)) * f;
sfi(1) = 5.1837436 * 10 ^ 6 * (Z ^ (2) / (energylab * 10 ^ (3))) ^ (2) * (4 * Cos((90 - initialthetalab) * Pi / 180) / Sin((90 - initialthetalab) * Pi / 180) ^ (4)) * ffi;
srr(1) = 4 * sfi * (Sin((90 - initialthetalab) * Pi / 180) ^ 2 * Cos((90 - initialthetalab) * Pi / 180) * Cos(initialthetalab * Pi / 180)) / Sin(2 * (90 - initialthetalab) * Pi / 180) ^ 2;
srtotal(1) = srp + srr;

//------------------------
//Rutherford CM system

srpcm(1) = srp(1) * domega(1);
srrcm(1) = srr(1) * domega(1);
srtotalcm(1) = srtotal(1) * domega(1);

//------------------------
// εντολές για να γραφτούν οι τιμές στη πρώτη θέση των διανυσμάτων
thetalab(1) = initialthetalab


//---------------------------------------------------------------------------------------------------------------------------------
//2For loop to create the MOTT scattering columns
For (j = 2;j<nofsteps;j++)
 {
    If ( thetacm(j-1) < finalthetacm )
	{
       thetacm(j) = thetacm(j-1) + stepcm ;
          f(j) = (1 + 0.5 * (V1 / energycm)) ^ (2) / (1 + (V1 / energycm) + (V1 / (2 * energycm * sin(thetacm(j) * Pi / 360))) ^ (2)) ^ (2);
          ffi = (1 + 0.5 * (V1 / energycm)) ^ (2) / (1 + (V1 / energycm) + (V1 / (2 * energycm * Sin((180 - thetacm(j)) * Pi / 360))) ^ (2)) ^ (2);
          dscm(j) = (10 ^ 31) * f(j) * (1.44 * 10 ^ (-15) * Z ^ (2) / (4 * energycm)) ^ (2) * ((1 / sin(thetacm(j) * Pi / 360)) ^ (4) + (1 / cos(thetacm(j) * Pi / 360)) ^ (4) + (2 * (-1) ^ (2 * spin) / (2 * spin + 1)) * (Cos(ns *ln(tan(thetacm(j) * Pi / 360) ^ (2))) / (sin(thetacm(j) * Pi / 360) ^ (2) * cos(thetacm(j) * Pi / 360) ^ (2))));
          thetalab(j) = thetacm(j) / 2;
          domega(j) = (1 + cos(thetacm(j) * Pi / 180)) / (2 + 2 * cos(thetacm(j) * Pi / 180)) ^ (3 / 2);
          dslab(j) = dscm(j) / domega(j);
          //------------------------
          //Rutherford LAB system
          srp(j) = 5.1837436 * 10 ^ 6 * (Z ^ (2) / (energylab * 10 ^ (3))) ^ (2) * (4 * cos(thetalab(j) * Pi / 180) / sin(thetalab(j) * Pi / 180) ^ (4)) * f(j) ;
          sfi(j) = 5.1837436 * 10 ^ 6 * (Z ^ (2) / (energylab * 10 ^ (3))) ^ (2) * (4 * cos((90 - thetalab(j)) * Pi / 180) / sin((90 - thetalab(j)) * Pi / 180) ^ (4)) * ffi;
          srr(j) = 4 * sfi(j) * (sin((90 - thetalab(j)) * Pi / 180) ^ 2 * cos((90 - thetalab(j)) * Pi / 180) * cos(thetalab(j) * Pi / 180)) / sin(2 * (90 - thetalab(j)) * Pi / 180) ^ 2;
          srtotal(j) = srp(j) + srr(j);
          //------------------------
          //Rutherford CM system
          srpcm(j) = srp(j) * domega(j);
          srrcm(j) = srr(j) * domega(j);
          srtotalcm(j) = srtotal(j) * domega(j);
          //------------------------
          // εντολές για να γράφονται αυτά που θέλουμε στο αρχείο txt
		cout << thetalab(j) << " " << dslab(j) << endl;
    }
    //else
      // {
	    //  Exit For ;
	  // }
 }
//===================================================================================================================================

//If clause to see if the energies exceed the coulomb barrier
 If (energylab > coulomblab)
 {   
	 cout << "Warning: The beam energy exceeds the Coulomb Barrier" << endl;
 }
//===============================================================================================================================
 
}