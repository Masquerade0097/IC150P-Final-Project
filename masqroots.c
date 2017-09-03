#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int check(float num)                          //just a function to check for  the correct input
{
	char c;
	scanf("%c",&c);

	if(isalpha((int)c))
		printf("\tYou entered an alphabet. Kindly, retry with valid entry\n");
	else
		printf("\tYou entered a character. Kindly, retry with valid entry\n");
	
	return 0;
}

char signum(float x)
{
	if (x>=0) return '+';
	else return '-';
}



double func(double *p,int degree,double x)                     //calculates the value of the function required in the formmula in main
{
  double fc=0.0;
  int i;

  for(i=0;i<=degree;i++)
  {
    fc=fc+(*p)*pow(x,degree-i);
    p++;
  }
  
  return fc;
}


int fact(int n)
{
  if (n>0) return n*fact(n-1);
  else return 1;
}



double D(int k,int a,double x)               //calculates the derivative of the function required in the formmula in main
{
  if(x!=0 && a>=k)  return fact(a)*pow(x,a-k)/fact(a-k);
  else return 0;  
}


double derv(double *q,int degree,double x,int order)               //calculates the derivative of the function required in the formmula in main
{
  double dv=0.0;
  int i;
  for(i=0;i<=degree;i++)
  {
    dv=dv+(*q)*D(order,degree-i,x);
    q++;
  }
  return dv;
}



int main()
{
	double coeff[1000],t,x1=0.0,roots[100];
	int degree=-1,count=0,i,j=0,k,l=0,flag=1;
	char ch;
	float a,b;
	coeff[0]=0;
	printf("\t**This Programme helps you find roots of a polynomial using a manipulated version of Newton-Raphson Method in a real interval [a,b]**\n");
    

	while (degree<0)
	{
		printf("\tEnter a NON-NEGATIVE INTEGRAL value for the DEGREE of the polynomial: ");
		while(scanf("%d",&degree)!=1)
		{
			printf("\tInvalid Entry. Kindly, retry with valid entry: ");
			while(getchar()!='\n'){}
		}
}

int w[degree];
printf("\tEnter the coefficients...\n");

while(coeff[0]==0 && degree!=0)
{
	printf("\t-->for x^%d (Remember that this coefficient cannot be zero since degree is %d): ", degree,degree);
	while(scanf("%lf",&coeff[0])!=1)
	{
		check(coeff[0]);
	}
}

if (degree==0)
{
	printf("\t-->for x^%d: ",0);
	while(scanf("%lf",&coeff[0])!=1)
	{
		check(coeff[0]);
	}
}

for(i=1;i<=degree;i++)
{
	printf("\t-->for x^%d: ",degree-i);
	while(scanf("%lf",&coeff[i])!=1)
	{
		check(coeff[i]);
	}
}

  while(getchar()!='\n'){}                                 //this clears the buffer accumulated upto pressing enter
  	printf("\tThe input polynomial is:\n");
  printf("\t");
  for(i=0;i<=degree;i++)
  {
  	printf("%c %.2fx^%d ",signum(coeff[i]),fabs(coeff[i]),degree-i);
  }

  printf("\n");
  //while(getchar()!='\n'){};

  /* fflush(stdout);
  fflush(stdin);*/
  printf("\tFor the interval domain [a,b]; enter 'a' followed by 'b': ");
  scanf("%f %f",&a,&b);
  

  while(getchar()!='\n'){}
  	printf("\tSo, you entered [%f,%f].\n",a,b);
  //while(getchar()!='\n'){}
  fflush(stdout);
  fflush(stdin);


  double d=(b-a)/(degree+1), val[degree+2],x=a;
  for (k = 0; k<=degree+1; k++)
  {
  	val[k]= a+d*k;
  //	printf("%lf\t", val[k]);
  }

  while(l<(degree+2))
  {
  		
  	if(derv(&coeff[0],degree,x,1)<=0.00001)
  	{
  		if(func(&coeff[0],degree,x)<=0.00001)
  		{
  			w[j]=2;
  			roots[j]=x;
        //printf("Axk before %f\n", x);
  			j++;
        //  printf("jC is %d\n", j);
           	l++;
           	x=val[l];   // every time a root is encountered this stores the root in roots array and runs the loop again with different value of x to find other roots
         //printf("Axk after %f\n", x);
           	t=0.0;
           	x1=0.0;
           	count=(-1);
        }
        else
        {
			t=0.0;
        	x1=0.0;
        	count=(-1);
        	l++;
          //printf("Bxk before%f\n", x);
           	x=val[l];
          //  printf("Bxk after%f\n", x);
       	}
    }
       else
       {
       	  t=x1;
          x1=(x-(func(&coeff[0],degree,x)/derv(&coeff[0],degree,x,1)));           //this is the newton's formula
       // printf("jB is %d\n", j);
          //printf("Cxk before%f\n", x);
          x=x1;
          //printf("f %f\td %f\tCxk after%f\tc %i\n",func(&coeff[0],degree,x), derv(&coeff[0],degree,x,1), x,count);
          if(count>500)
          {

          	if(j>degree)
          		break;
        	  printf("\tPolynomial started to diverge. So, no roots can be found\n");
          	l++;
            //printf("Dxk before %f\n", x);
          	x=val[l];
            //printf("Dxk after %f\n", x);
          	t=0.0;
          	x1=0.0;
          	count=(-1);

          }     
          if((fabs(t - x1))<=0.00001 && count!=0)
          {
          	w[j]=1;
          	if(j>degree)
          		break;  
       
          	roots[j]=x;

          	j++;
          	l++;
        //  printf("jC is %d\n", j);
           	x=val[l];   // every time a root is encountered this stores the root in roots array and runs the loop again with different value of x to find other roots
         //printf("Exk after%f\n", x);
           	t=0.0;
           	x1=0.0;
           	count=(-1);
           	flag=0;
           	if(derv(&coeff[0],degree,x,1)<=0.00001) w[j]=2;
           	else w[j]=1;
           }
           count++;
       } 
   }

   if(flag==0)
   {
   	printf("\tThe roots are = \t");
     // int p=0;
   	for(j=0;j<degree;j++)
   	{

   		if(j==0 && roots[0]>=a && roots[0]<=b)
   		{
   			printf(" %d %f\n", w[0], roots[0]);
       //p++;
   		}

   		if(fabs(roots[j]-roots[j-1])>0.001 && j!=0 && roots[j]>=a && roots[j]<=b)
   		{
   			printf(" %d %f\n", w[j], roots[j]);
       //p++;
   		}


   	}
   } 
   else
   	printf("\tNo roots found in the interval you entered.\n");

   return 0;

}



















