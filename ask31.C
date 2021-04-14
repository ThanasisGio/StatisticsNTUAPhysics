void ask31()
{
  int f[12]  = {8,3,4,1,4,4,6,6,2,4,8,7};
  double sum = 0;
  for (int i=0;i<12;i++)
  {
    sum = sum + f[i]*log(f[i])-f[i];
	
  }
  cout << 'sum' << " " << sum << endl;
}