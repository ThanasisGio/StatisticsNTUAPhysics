{
  double pdf1[12]={0.0042,0.0186,0.0422,0.0926,0.1456,0.1886,0.1866,0.1514,0.0894,0.0546,0.0176,0.0066};
  double pdf2[12]={0.0056,0.0214,0.0422,0.0844,0.1296,0.1660,0.1736,0.1536,0.1072,0.0626,0.0340,0.0136};
  double er1[12]={0.0009,0.0019,0.0029,0.0043,0.0054,0.0061,0.0061,0.0055,0.0042,0.0033,0.0019,0.0011};
  double er2[12]={0.0011,0.0021,0.0029,0.0041,0.0051,0.0058,0.0059,0.0055,0.0046,0.0035,0.0026,0.0016};

  double x1=0;
  double x2=0;

  double th_pdf[12];
  th_pdf[0] = ROOT::Math::normal_cdf( -2.5 , 1 , 0 ) - ROOT::Math::normal_cdf( -3.0 , 1 , 0 );
  th_pdf[1] = ROOT::Math::normal_cdf( -2.0 , 1 , 0 ) - ROOT::Math::normal_cdf( -2.5 , 1 , 0 );
  th_pdf[2] = ROOT::Math::normal_cdf( -1.5 , 1 , 0 ) - ROOT::Math::normal_cdf( -2.0 , 1 , 0 );
  th_pdf[3] = ROOT::Math::normal_cdf( -1.0 , 1 , 0 ) - ROOT::Math::normal_cdf( -1.5 , 1 , 0 );
  th_pdf[4] = ROOT::Math::normal_cdf( -0.5 , 1 , 0 ) - ROOT::Math::normal_cdf( -1.0 , 1 , 0 ); 
  th_pdf[5] = ROOT::Math::normal_cdf( 0.0 , 1 , 0 ) - ROOT::Math::normal_cdf( -0.5 , 1 , 0 );
  th_pdf[6] = ROOT::Math::normal_cdf( 0.5 , 1 , 0 ) - ROOT::Math::normal_cdf( 0.0 , 1 , 0 );
  th_pdf[7] = ROOT::Math::normal_cdf( 1.0 , 1 , 0 ) - ROOT::Math::normal_cdf( 0.5 , 1 , 0 );
  th_pdf[8] = ROOT::Math::normal_cdf( 1.5 , 1 , 0 ) - ROOT::Math::normal_cdf( 1.0 , 1 , 0 );
  th_pdf[9] = ROOT::Math::normal_cdf( 2.0 , 1 , 0 ) - ROOT::Math::normal_cdf( 1.5 , 1 , 0 );
  th_pdf[10] =ROOT::Math::normal_cdf( 2.5 , 1 , 0 ) - ROOT::Math::normal_cdf( 2.0 , 1 , 0 );
  th_pdf[11] =ROOT::Math::normal_cdf( 3.0 , 1 , 0 ) - ROOT::Math::normal_cdf( 2.5 , 1 , 0 );

  for( int i=0 ; i<12 ; i++){
    x1 = x1 + ((pdf1[i]-th_pdf[i])*(pdf1[i]-th_pdf[i]))/(er1[i]*er1[i]);
    x2 = x2 + ((pdf2[i]-th_pdf[i])*(pdf2[i]-th_pdf[i]))/(er2[i]*er2[i]);
  }

  cout << "x1: " << x1 << "-----  " << "x2: " << x2 << endl;

  //  cout << "=================" << endl;
  //  for( int i=0 ; i<12 ; i++){   cout << th_pdf[i] << endl; } 


  double pv1;
  double pv2;
  pv1 = 1 - ROOT::Math::chisquared_cdf( x1 , 12  , 0  );
  pv2 = 1 - ROOT::Math::chisquared_cdf( x2 , 12  , 0  );
 
  cout << "===============" << endl;
  cout << "pv1: " << pv1 << "-----  " << "pv2: " << pv2 << endl;

  //=================== RUN TEST
  //==============================
  
  int d1[12];
  int d2[12];
  int N1p;
  int N1m;
  int N2p;
  int N2m;
  
  for( int i=0 ; i<12 ; i++ ){
    //pdf1
    if( pdf1[i] > th_pdf[i] ){
      d1[i]=1;
      N1p++;
    }
    if( pdf1[i] < th_pdf[i] ){
      d1[i]=-1;
      N1m++;
    }
    //pdf2
    if( pdf2[i] > th_pdf[i] ){
      d2[i]=1;
      N2p++;
    }
    if( pdf2[i] < th_pdf[i] ){
      d2[i]=-1;
      N2m++;
    }
  }

  int r1=1;
  int r2=1;
  for( int i=0 ; i<12 ; i++ ){ // define N+, N- & r
    if( i<11 ){
      if( d1[i] != d1[i+1] ){     
	r1++;
      }
      if( d2[i] != d2[i+1] ){
	r2++;
      }
    }
    if( i==11 ){
      if( d1[i] != d1[i+1] ){     
	//	r1++;
      }
      
    }
  }

 
  cout << "=====================" << endl;
  cout << "=====================" << endl;
  
  for( int i=0 ; i<12 ; i++ ){
    cout << "d1: " << d1[i] << "  d2: " << d2[i] <<  endl;
  }
  cout << "r1 :" << r1 << "  r2 :" << r2 << endl;
  cout << " N1p: " << N1p << " N1m: " << N1m << " N2p: " << N2p << " N2m: " << N2m << endl;

  cout << "=====================" << endl;
  cout << "=====================" << endl;
  cout << "=====================" << endl;
  cout << "=====================" << endl;

  double E1;
  double V1;
  double Z1;
  double E2;
  double V2;
  double Z2;

  E1 = 1 +(2*N1p*N1m)/(N1p+N1m);
  V1 = (2*N1p*N1m*(2*N1p*N1m-N1p-N1m))/( (N1p+N1m)*(N1p+N1m)*(N1p+N1m-1));
  Z1 = (r1-E1)/(sqrt(V1));

  E2 = 1 +(2*N2p*N2m)/(N2p+N2m);
  V2 = (2*N2p*N2m*(2*N2p*N2m-N2p-N2m))/( (N2p+N2m)*(N2p+N2m)*(N2p+N2m-1));
  Z2 = (r2-E2)/(sqrt(V2));

  cout << " Z1= " << Z1 << " Z2= " << Z2 << endl;


  
}
