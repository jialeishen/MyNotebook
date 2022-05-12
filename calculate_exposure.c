/**************************************************************************
                                 source of particular area
@author:Jialei Shen
@e-mail:shenjialei1992@163.com
@latest:2016.09.19
This UDF file aims to setup a source term in a particular area in the 
computational domain. The UDF file includes the following term:
1  source term

guest (1-10): 	dx=+5.82*1 (0-1) dy=+3.36*3 (0-3)
guest (11-20): 				 	 dy=+3.36*3 (0-3)
**************************************************************************/

#include "udf.h"
#include "prop.h"
#define R 0.05
#define POL 24

int pol_num = 24; // number of pollutants/sources
real vol[120]; // breathing zone volume for 120 occupants
real exposre[120][POL]; // exposure to 120 pollutants in the breathing zone for 120 occupants

/************************calculate the exposure for all occupants*************************/
DEFINE_ON_DEMAND(exposure_udf)

{
	Domain *domain;
	Thread *t;
	cell_t c;
	real x[ND_ND];
	FILE *fp_exp;
	fp_exp=fopen("exposure_1.csv","w");
	domain=Get_Domain(1);

	thread_loop_c(t,domain)
	{
		begin_c_loop(c,t)
		{
			C_CENTROID(x,c,t);
			if( sqrt( (x[0]-(-2.95+5.82*0))*(x[0]-(-2.95+5.82*0))+(x[1]-(-0.25+3.36*0))*(x[1]-(-0.25+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				/*try
				{*/
					vol[0] += C_VOLUME(c,t);
					// exposre[0][0] += C_YI(c,t,0)*C_VOLUME(c,t);
					int j;
					for (j = 0; j < pol_num; j++)
					{
						exposre[0][j] += C_YI(c,t,j)*C_VOLUME(c,t);
					}
				/*}
				catch
				{
					vol[0] = -1;
					int j;
					for (j = 0; j < pol_num; j++)
					{
						exposre[0][j] = 1;
					}
				}*/
				
			}
			else if( sqrt( (x[0]-(-2.17+5.82*0))*(x[0]-(-2.17+5.82*0))+(x[1]-(0+3.36*0))*(x[1]-(0+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				/*try
				{*/
					vol[1] += C_VOLUME(c,t);
					int j;
					for (j = 0; j < pol_num; j++)
					{
						exposre[1][j] += C_YI(c,t,j)*C_VOLUME(c,t);
					}
				/*}
				catch
				{
					vol[1] = -1;
					int j;
					for (j = 0; j < pol_num; j++)
					{
						exposre[1][j] = 1;
					}
				}*/
				
			}
			else if( sqrt( (x[0]-(-3.73+5.82*0))*(x[0]-(-3.73+5.82*0))+(x[1]-(0+3.36*0))*(x[1]-(0+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				/*try
				{*/
					vol[2] += C_VOLUME(c,t);
					int j;
					for (j = 0; j < pol_num; j++)
					{
						exposre[2][j] += C_YI(c,t,j)*C_VOLUME(c,t);
					}
				/*}
				catch
				{
					vol[2] = -1;
					int j;
					for (j = 0; j < pol_num; j++)
					{
						exposre[2][j] = 1;
					}
				}*/
			}
		}
		end_c_loop(c,t)
	}
	int i;
	for (i = 0; i < 120; i++)
	{
		int j;
		for (j = 0; j < pol_num; j++)
		{
			exposre[i][j] = exposre[i][j] / vol[i];
		}
	}
	
	// write data to file
	char v = "";
	int i;
	for (i = 0; i < 120; i++)
	{
		v += vol[i] + ",";
	}
	v += "\n";
	fprintf(fp_exp, v);

	char e = "";
	int i;
	for (i = 0; i < 120; i++)
	{
		int j;
		for (j = 0; j < pol_num; j++)
		{
			e += exposre[i][j] + ",";
		}
		e += "\n";
	}
	
	fprintf(fp_exp,e);
	fclose(fp_exp);
}
