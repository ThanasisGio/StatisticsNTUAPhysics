//=============================================================================================================
//If clauses to check if the user s inputs are logical
if (energylab < 0)
 {   
    cout << "Warning: The beam energy cannot be negative or zero. The beam energy is set by default at 0.01 MeV" << endl;
    energylab = 0.001 ;
 }

if (energylab = 0)
 {
    cout << "Warning: The beam energy cannot be negative or zero. The beam energy is set by default at 0.01 MeV" << endl;
    energylab = 0.001;
 }

//-------------------------------------------------------------------------------------------------------------
// 0<initialtheta<90
if(initialthetalab < 0.001)
 {
   cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The initial detection angle is set by default at 0.001 degrees " << endl;
   initialthetalab = 0.001 ;
 }  
if(initialthetalab = 0)
 {
        cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The initial detection angle is set by default at 0.001 degrees " << endl;
        initialthetalab = 0.001;
 }		
if(initialthetalab > 89.98)
 {
    cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The initial detection angle is set by default at 85 degrees " << endl;
    initialthetalab = 85;
 }	
if(initialthetalab = 89.98) 
 { 
    cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The detection angle is set by default at 85 degrees " << endl;
    initialthetalab = 85;
 }	
 
 if(finalthetalab > 89.98) 
 { 
    cout << "Warning: Due to Kinematics constraints Mott Scattering is only possible for angles between 0 - 90 degrees with 0 and 90 degrees being mathematical poles. The detection angle is set by default at 89.98 degrees " << endl;
    finalthetalab = 89.98;
 }	
 
//------------------------------------------------------------------------------------------------------------
//finalthetalab<initialthetalab
if(finalthetalab < initialthetalab) 
 {
   cout << "Warning: The final angle of detection cannot be less than the initial angle. The final detection angle is set by default to be equal with the initial detection angle." << endl;
   finalthetalab = initialthetalab ;
 }
//------------------------------------------------------------------------------------------------------------
if(steplab < 0.001)
 {  
   steplab = 0.001;
   cout << "Warning: The step cannot be less than 0.001 degrees.The step is set by default at 0.001 degrees" << endl;
 }
//=============================================================================================================
