
#include <stdio.h>
int main()
{
	double a, b, c;
	scanf("%lf %lf %lf",&a,&b,&c);
	if (a + b >c && a + c > b && b + c > a)
	{
		if (a == b&&b == c)
			printf("equilateral triangle");
		else if ((a == b && a != c) || (a == c&&a != b) || (b == c&&b != c))
			printf("isosceles triangle");
		else if (a != b && b != c && a != c)
			printf("common triangle");


	}
	else
		printf("not a triangle");
	return 0;

}
