#include<stdio.h>
#include<math.h>

#define PERMISSIBLE_ERR 0.00000001
int power(int x,int y);

int main()
{
	int option;
	int x,y,abs_y;   // x is base y is index for integer exponentiation
	int ans;   // To store answer after integer exponentiation
	int prod;  
	float m,n; // m is base and n is index for floating point exponentiation
	float answer;// To store answer after floating point exponentiation
	float logm,deno,nxtterm;
	printf("Enter your choice:\n\n1.Integer Exponentiation\n\n2.Floating Point Exponentiation\n\n");
	scanf("%d",&option);
	switch(option)
	{
		case 1:
			printf("\n\nEnter base and index respectively:\n\n");
			scanf("%d%d",&x,&y);
			ans = 1;
			prod = x;
			abs_y = abs(y);
			while(abs_y!=0)
			{
				if(abs_y%2==1)   //X^13 ---    1101
				{
					ans = ans*prod;
				}
				abs_y = abs_y/2;
				prod = prod*prod;
			}
			if(y>0)
		      printf("\n\nThe answer is %d\n\n",ans);
            else
              printf("\n\nThe answer is %f\n\n",1.0/ans);
			break;
		case 2:
			printf("\n\nEnter base and index respectively:\n\n");
			scanf("%f%f",&m,&n);
			logm = log(m);
			nxtterm = 1;
			deno = 1;
			answer = 0;
			
			while(fabs(nxtterm)>=PERMISSIBLE_ERR)
			{
				answer = answer+nxtterm;
				nxtterm = nxtterm*logm*n/deno;  // a^x = 1+xloga+(xloga)^2/2!
				deno = deno+1;
			}
			
		    printf("\n\nThe answer is %f:\n\n",answer);
            break;
        default:
        	printf("Please enter valid option:\n\n");
        	main();
        	break;
            
    }
    return 0;
}

// Alternate code for binary exponentiation (i.e. integer exponentiation) using recursive approach

   int power(int x,int y)
   {
      int ret_val,half_power;                                 // x^13   x*half_power*half_power
                                                               //   pow(x,6)->pow(x,3)->pow(x,1)->pow(x,0))
      if(y == 0)
        ret_val = 1;
      else if(y%2 == 1)
        {
           half_power = pow(x,y/2);
           ret_val = x*half_power*half_power;
        }
      else
        {
           half_power =pow(x,y/2);
           ret_val = half_power*half_power;
        }
       return ret_val;
   }
        


