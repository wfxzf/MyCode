#includestdio.h
int main()
{
	int n,feet,i;
	scanf(%d,&n);
	for(i=0;in;i++)
	{
		scanf(%d,&feet);
		if (feet%2!=0)
		    printf(0 0n);
		else
		   if (feet%4!=0)
		      printf(%d %dn,feet4+1,feet2);
		else
		    printf(%d %dn,feet4,feet2);	 
	}
return 0;	
}