/**************************************************************************
                                 source of particular area
@author:Jialei Shen
@contact: www.jialeishen.com
@latest:2022.05.12
This UDF file aims to setup a source term in a particular area in the 
computational domain. The UDF file includes the following term:
1  source term

guest (1-10): 	dx=+5.82*1 (0-1) dy=+3.36*3 (0-3)
guest (11-20): 				 	 dy=+3.36*3 (0-3)
**************************************************************************/

#include "udf.h"
#include "prop.h"
#define R 0.05
#define POL   6
int pol_num = 6; // number of pollutants/sources

int ini_pol = 0;

real vol[120]; // breathing zone volume for 120 occupants
real exposure[120][POL]; // exposure to 120 pollutants in the breathing zone for 120 occupants

/************************calculate the exposure for all occupants*************************/
DEFINE_ON_DEMAND(exposure_udf)
{
	int i, j;
	Domain *domain;
	Thread *t;
	cell_t c;
	real x[ND_ND];
	FILE *fp_exp;
	printf("Opening file\n");

	fp_exp=fopen("exposure_1_2_1.csv","w");

	domain=Get_Domain(1);

	printf("Start\n");

/***************
	memset(vol, 0.0, sizeof(vol[0]) * 120);
	memset(exposure, 0.0, sizeof(exposure[0][0]) * 120 * POL);
***************/

/***************
	// initialize vol and exposure
	for (i = 0; i < 120; i++)
	{
		vol[i] = 0.;
		for (j = 0; j < pol_num; j++)
		{
			exposure[i][j] = 0.;
			
		}
	}
****************/

	thread_loop_c(t,domain)
	{
		begin_c_loop(c,t)
		{
			C_CENTROID(x,c,t);
/**************************
			if( sqrt( (x[0]-(-2.95+5.82*0))*(x[0]-(-2.95+5.82*0))+(x[1]-(-0.25+3.36*0))*(x[1]-(-0.25+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				/*try
				{*/
					vol[0] += C_VOLUME(c,t);
					// exposure[0][0] += C_YI(c,t,0)*C_VOLUME(c,t);
					//int j = 0;
					for (j = 0; j < pol_num; j++)
					{
						exposure[0][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
					}
				/*}
				catch
				{
					vol[0] = -1;
					//int j = 0;
					for (j = 0; j < pol_num; j++)
					{
						exposure[0][j] = 1;
					}
				}*/
				
			}
			else if( sqrt( (x[0]-(-2.17+5.82*0))*(x[0]-(-2.17+5.82*0))+(x[1]-(0+3.36*0))*(x[1]-(0+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[1] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[1][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
				
			}
			else if( sqrt( (x[0]-(-3.73+5.82*0))*(x[0]-(-3.73+5.82*0))+(x[1]-(0+3.36*0))*(x[1]-(0+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[2] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[2][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+5.82*0))*(x[0]-(-1.68+5.82*0))+(x[1]-(0.67+3.36*0))*(x[1]-(0.67+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[3] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[3][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*0))*(x[0]-(-4.22+5.82*0))+(x[1]-(0.67+3.36*0))*(x[1]-(0.67+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[4] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[4][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+5.82*0))*(x[0]-(-1.68+5.82*0))+(x[1]-(1.49+3.36*0))*(x[1]-(1.49+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[5] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[5][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*0))*(x[0]-(-4.22+5.82*0))+(x[1]-(1.49+3.36*0))*(x[1]-(1.49+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[6] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[6][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+5.82*0))*(x[0]-(-2.17+5.82*0))+(x[1]-(2.16+3.36*0))*(x[1]-(2.16+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[7] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[7][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*0))*(x[0]-(-3.73+5.82*0))+(x[1]-(2.16+3.36*0))*(x[1]-(2.16+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[8] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[8][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*0))*(x[0]-(-2.95+5.82*0))+(x[1]-(2.41+3.36*0))*(x[1]-(2.41+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[9] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[9][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+2.91+5.82*0))*(x[0]-(-2.95+2.91+5.82*0))+(x[1]-(-0.25-1.68+3.36*0))*(x[1]-(-0.25-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[10] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[10][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}


			else if( sqrt( (x[0]-(-2.17+2.91+5.82*0))*(x[0]-(-2.17+2.91+5.82*0))+(x[1]-(0-1.68+3.36*0))*(x[1]-(0-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[11] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[11][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+2.91+5.82*0))*(x[0]-(-3.73+2.91+5.82*0))+(x[1]-(0-1.68+3.36*0))*(x[1]-(0-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[12] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[12][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+2.91+5.82*0))*(x[0]-(-1.68+2.91+5.82*0))+(x[1]-(0.67-1.68+3.36*0))*(x[1]-(0.67-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[13] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[13][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+2.91+5.82*0))*(x[0]-(-4.22+2.91+5.82*0))+(x[1]-(0.67-1.68+3.36*0))*(x[1]-(0.67-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[14] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[14][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+2.91+5.82*0))*(x[0]-(-1.68+2.91+5.82*0))+(x[1]-(1.49-1.68+3.36*0))*(x[1]-(1.49-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[15] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[15][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+2.91+5.82*0))*(x[0]-(-4.22+2.91+5.82*0))+(x[1]-(1.49-1.68+3.36*0))*(x[1]-(1.49-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[16] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[16][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+2.91+5.82*0))*(x[0]-(-2.17+2.91+5.82*0))+(x[1]-(2.16-1.68+3.36*0))*(x[1]-(2.16-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[17] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[17][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+2.91+5.82*0))*(x[0]-(-3.73+2.91+5.82*0))+(x[1]-(2.16-1.68+3.36*0))*(x[1]-(2.16-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[18] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[18][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+2.91+5.82*0))*(x[0]-(-2.95+2.91+5.82*0))+(x[1]-(2.41-1.68+3.36*0))*(x[1]-(2.41-1.68+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[19] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[19][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*1))*(x[0]-(-2.95+5.82*1))+(x[1]-(-0.25+3.36*0))*(x[1]-(-0.25+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[20] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[20][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}


			else if( sqrt( (x[0]-(-2.17+5.82*1))*(x[0]-(-2.17+5.82*1))+(x[1]-(0+3.36*0))*(x[1]-(0+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[21] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[21][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*1))*(x[0]-(-3.73+5.82*1))+(x[1]-(0+3.36*0))*(x[1]-(0+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[22] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[22][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+5.82*1))*(x[0]-(-1.68+5.82*1))+(x[1]-(0.67+3.36*0))*(x[1]-(0.67+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[23] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[23][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*1))*(x[0]-(-4.22+5.82*1))+(x[1]-(0.67+3.36*0))*(x[1]-(0.67+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[24] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[24][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+5.82*1))*(x[0]-(-1.68+5.82*1))+(x[1]-(1.49+3.36*0))*(x[1]-(1.49+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[25] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[25][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*1))*(x[0]-(-4.22+5.82*1))+(x[1]-(1.49+3.36*0))*(x[1]-(1.49+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[26] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[26][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+5.82*1))*(x[0]-(-2.17+5.82*1))+(x[1]-(2.16+3.36*0))*(x[1]-(2.16+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[27] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[27][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*1))*(x[0]-(-3.73+5.82*1))+(x[1]-(2.16+3.36*0))*(x[1]-(2.16+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[28] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[28][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*1))*(x[0]-(-2.95+5.82*1))+(x[1]-(2.41+3.36*0))*(x[1]-(2.41+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[29] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[29][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
*****************************/


			if( sqrt( (x[0]-(-2.95+5.82*1))*(x[0]-(-2.95+5.82*1))+(x[1]-(-0.25+3.36*0))*(x[1]-(-0.25+3.36*0))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[30] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[30][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}


			else if( sqrt( (x[0]-(-2.17+5.82*0))*(x[0]-(-2.17+5.82*0))+(x[1]-(0+3.36*1))*(x[1]-(0+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[31] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[31][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*0))*(x[0]-(-3.73+5.82*0))+(x[1]-(0+3.36*1))*(x[1]-(0+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[32] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[32][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+5.82*0))*(x[0]-(-1.68+5.82*0))+(x[1]-(0.67+3.36*1))*(x[1]-(0.67+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[33] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[33][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*0))*(x[0]-(-4.22+5.82*0))+(x[1]-(0.67+3.36*1))*(x[1]-(0.67+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[34] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[34][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+5.82*0))*(x[0]-(-1.68+5.82*0))+(x[1]-(1.49+3.36*1))*(x[1]-(1.49+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[35] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[35][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*0))*(x[0]-(-4.22+5.82*0))+(x[1]-(1.49+3.36*1))*(x[1]-(1.49+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[36] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[36][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+5.82*0))*(x[0]-(-2.17+5.82*0))+(x[1]-(2.16+3.36*1))*(x[1]-(2.16+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[37] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[37][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*0))*(x[0]-(-3.73+5.82*0))+(x[1]-(2.16+3.36*1))*(x[1]-(2.16+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[38] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[38][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*0))*(x[0]-(-2.95+5.82*0))+(x[1]-(2.41+3.36*1))*(x[1]-(2.41+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[39] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[39][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}


			else if( sqrt( (x[0]-(-2.95+2.91+5.82*0))*(x[0]-(-2.95+2.91+5.82*0))+(x[1]-(-0.25-1.68+3.36*1))*(x[1]-(-0.25-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[40] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[40][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}


			else if( sqrt( (x[0]-(-2.17+2.91+5.82*0))*(x[0]-(-2.17+2.91+5.82*0))+(x[1]-(0-1.68+3.36*1))*(x[1]-(0-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[41] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[41][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+2.91+5.82*0))*(x[0]-(-3.73+2.91+5.82*0))+(x[1]-(0-1.68+3.36*1))*(x[1]-(0-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[42] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[42][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+2.91+5.82*0))*(x[0]-(-1.68+2.91+5.82*0))+(x[1]-(0.67-1.68+3.36*1))*(x[1]-(0.67-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[43] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[43][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+2.91+5.82*0))*(x[0]-(-4.22+2.91+5.82*0))+(x[1]-(0.67-1.68+3.36*1))*(x[1]-(0.67-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[44] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[44][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+2.91+5.82*0))*(x[0]-(-1.68+2.91+5.82*0))+(x[1]-(1.49-1.68+3.36*1))*(x[1]-(1.49-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[45] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[45][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+2.91+5.82*0))*(x[0]-(-4.22+2.91+5.82*0))+(x[1]-(1.49-1.68+3.36*1))*(x[1]-(1.49-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[46] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[46][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+2.91+5.82*0))*(x[0]-(-2.17+2.91+5.82*0))+(x[1]-(2.16-1.68+3.36*1))*(x[1]-(2.16-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[47] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[47][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+2.91+5.82*0))*(x[0]-(-3.73+2.91+5.82*0))+(x[1]-(2.16-1.68+3.36*1))*(x[1]-(2.16-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[48] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[48][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+2.91+5.82*0))*(x[0]-(-2.95+2.91+5.82*0))+(x[1]-(2.41-1.68+3.36*1))*(x[1]-(2.41-1.68+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[49] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[49][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*1))*(x[0]-(-2.95+5.82*1))+(x[1]-(-0.25+3.36*1))*(x[1]-(-0.25+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[50] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[50][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}



			else if( sqrt( (x[0]-(-2.17+5.82*1))*(x[0]-(-2.17+5.82*1))+(x[1]-(0+3.36*1))*(x[1]-(0+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[51] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[51][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*1))*(x[0]-(-3.73+5.82*1))+(x[1]-(0+3.36*1))*(x[1]-(0+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[52] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[52][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+5.82*1))*(x[0]-(-1.68+5.82*1))+(x[1]-(0.67+3.36*1))*(x[1]-(0.67+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[53] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[53][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*1))*(x[0]-(-4.22+5.82*1))+(x[1]-(0.67+3.36*1))*(x[1]-(0.67+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[54] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[54][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+5.82*1))*(x[0]-(-1.68+5.82*1))+(x[1]-(1.49+3.36*1))*(x[1]-(1.49+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[55] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[55][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*1))*(x[0]-(-4.22+5.82*1))+(x[1]-(1.49+3.36*1))*(x[1]-(1.49+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[56] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[56][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+5.82*1))*(x[0]-(-2.17+5.82*1))+(x[1]-(2.16+3.36*1))*(x[1]-(2.16+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[57] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[57][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*1))*(x[0]-(-3.73+5.82*1))+(x[1]-(2.16+3.36*1))*(x[1]-(2.16+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[58] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[58][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*1))*(x[0]-(-2.95+5.82*1))+(x[1]-(2.41+3.36*1))*(x[1]-(2.41+3.36*1))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[59] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[59][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

/***************************
			else if( sqrt( (x[0]-(-2.95+5.82*0))*(x[0]-(-2.95+5.82*0))+(x[1]-(-0.25+3.36*2))*(x[1]-(-0.25+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[60] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[60][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}



			else if( sqrt( (x[0]-(-2.17+5.82*0))*(x[0]-(-2.17+5.82*0))+(x[1]-(0+3.36*2))*(x[1]-(0+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[61] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[61][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
				
			}
			else if( sqrt( (x[0]-(-3.73+5.82*0))*(x[0]-(-3.73+5.82*0))+(x[1]-(0+3.36*2))*(x[1]-(0+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[62] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[62][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+5.82*0))*(x[0]-(-1.68+5.82*0))+(x[1]-(0.67+3.36*2))*(x[1]-(0.67+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[63] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[63][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*0))*(x[0]-(-4.22+5.82*0))+(x[1]-(0.67+3.36*2))*(x[1]-(0.67+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[64] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[64][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+5.82*0))*(x[0]-(-1.68+5.82*0))+(x[1]-(1.49+3.36*2))*(x[1]-(1.49+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[65] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[65][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*0))*(x[0]-(-4.22+5.82*0))+(x[1]-(1.49+3.36*2))*(x[1]-(1.49+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[66] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[66][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+5.82*0))*(x[0]-(-2.17+5.82*0))+(x[1]-(2.16+3.36*2))*(x[1]-(2.16+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[67] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[67][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*0))*(x[0]-(-3.73+5.82*0))+(x[1]-(2.16+3.36*2))*(x[1]-(2.16+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[68] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[68][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*0))*(x[0]-(-2.95+5.82*0))+(x[1]-(2.41+3.36*2))*(x[1]-(2.41+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[69] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[69][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+2.91+5.82*0))*(x[0]-(-2.95+2.91+5.82*0))+(x[1]-(-0.25-1.68+3.36*2))*(x[1]-(-0.25-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[70] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[70][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}


			else if( sqrt( (x[0]-(-2.17+2.91+5.82*0))*(x[0]-(-2.17+2.91+5.82*0))+(x[1]-(0-1.68+3.36*2))*(x[1]-(0-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[71] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[71][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+2.91+5.82*0))*(x[0]-(-3.73+2.91+5.82*0))+(x[1]-(0-1.68+3.36*2))*(x[1]-(0-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[72] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[72][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+2.91+5.82*0))*(x[0]-(-1.68+2.91+5.82*0))+(x[1]-(0.67-1.68+3.36*2))*(x[1]-(0.67-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[73] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[73][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+2.91+5.82*0))*(x[0]-(-4.22+2.91+5.82*0))+(x[1]-(0.67-1.68+3.36*2))*(x[1]-(0.67-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[74] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[74][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+2.91+5.82*0))*(x[0]-(-1.68+2.91+5.82*0))+(x[1]-(1.49-1.68+3.36*2))*(x[1]-(1.49-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[75] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[75][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+2.91+5.82*0))*(x[0]-(-4.22+2.91+5.82*0))+(x[1]-(1.49-1.68+3.36*2))*(x[1]-(1.49-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[76] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[76][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+2.91+5.82*0))*(x[0]-(-2.17+2.91+5.82*0))+(x[1]-(2.16-1.68+3.36*2))*(x[1]-(2.16-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[77] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[77][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+2.91+5.82*0))*(x[0]-(-3.73+2.91+5.82*0))+(x[1]-(2.16-1.68+3.36*2))*(x[1]-(2.16-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[78] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[78][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+2.91+5.82*0))*(x[0]-(-2.95+2.91+5.82*0))+(x[1]-(2.41-1.68+3.36*2))*(x[1]-(2.41-1.68+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[79] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[79][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*1))*(x[0]-(-2.95+5.82*1))+(x[1]-(-0.25+3.36*2))*(x[1]-(-0.25+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[80] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[80][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}


			else if( sqrt( (x[0]-(-2.17+5.82*1))*(x[0]-(-2.17+5.82*1))+(x[1]-(0+3.36*2))*(x[1]-(0+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[81] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[81][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*1))*(x[0]-(-3.73+5.82*1))+(x[1]-(0+3.36*2))*(x[1]-(0+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[82] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[82][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+5.82*1))*(x[0]-(-1.68+5.82*1))+(x[1]-(0.67+3.36*2))*(x[1]-(0.67+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[83] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[83][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*1))*(x[0]-(-4.22+5.82*1))+(x[1]-(0.67+3.36*2))*(x[1]-(0.67+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[84] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[84][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+5.82*1))*(x[0]-(-1.68+5.82*1))+(x[1]-(1.49+3.36*2))*(x[1]-(1.49+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[85] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[85][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*1))*(x[0]-(-4.22+5.82*1))+(x[1]-(1.49+3.36*2))*(x[1]-(1.49+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[86] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[86][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+5.82*1))*(x[0]-(-2.17+5.82*1))+(x[1]-(2.16+3.36*2))*(x[1]-(2.16+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[87] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[87][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*1))*(x[0]-(-3.73+5.82*1))+(x[1]-(2.16+3.36*2))*(x[1]-(2.16+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[88] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[88][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*1))*(x[0]-(-2.95+5.82*1))+(x[1]-(2.41+3.36*2))*(x[1]-(2.41+3.36*2))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[89] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[89][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*0))*(x[0]-(-2.95+5.82*0))+(x[1]-(-0.25+3.36*3))*(x[1]-(-0.25+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[90] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[90][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}


			else if( sqrt( (x[0]-(-2.17+5.82*0))*(x[0]-(-2.17+5.82*0))+(x[1]-(0+3.36*3))*(x[1]-(0+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[91] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[91][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*0))*(x[0]-(-3.73+5.82*0))+(x[1]-(0+3.36*3))*(x[1]-(0+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[92] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[92][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+5.82*0))*(x[0]-(-1.68+5.82*0))+(x[1]-(0.67+3.36*3))*(x[1]-(0.67+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[93] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[93][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*0))*(x[0]-(-4.22+5.82*0))+(x[1]-(0.67+3.36*3))*(x[1]-(0.67+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[94] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[94][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+5.82*0))*(x[0]-(-1.68+5.82*0))+(x[1]-(1.49+3.36*3))*(x[1]-(1.49+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[95] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[95][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*0))*(x[0]-(-4.22+5.82*0))+(x[1]-(1.49+3.36*3))*(x[1]-(1.49+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[96] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[96][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+5.82*0))*(x[0]-(-2.17+5.82*0))+(x[1]-(2.16+3.36*3))*(x[1]-(2.16+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[97] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[97][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*0))*(x[0]-(-3.73+5.82*0))+(x[1]-(2.16+3.36*3))*(x[1]-(2.16+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[98] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[98][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*0))*(x[0]-(-2.95+5.82*0))+(x[1]-(2.41+3.36*3))*(x[1]-(2.41+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[99] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[99][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+2.91+5.82*0))*(x[0]-(-2.95+2.91+5.82*0))+(x[1]-(-0.25-1.68+3.36*3))*(x[1]-(-0.25-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[100] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[100][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}


			else if( sqrt( (x[0]-(-2.17+2.91+5.82*0))*(x[0]-(-2.17+2.91+5.82*0))+(x[1]-(0-1.68+3.36*3))*(x[1]-(0-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[101] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[101][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+2.91+5.82*0))*(x[0]-(-3.73+2.91+5.82*0))+(x[1]-(0-1.68+3.36*3))*(x[1]-(0-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[102] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[102][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+2.91+5.82*0))*(x[0]-(-1.68+2.91+5.82*0))+(x[1]-(0.67-1.68+3.36*3))*(x[1]-(0.67-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[103] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[103][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+2.91+5.82*0))*(x[0]-(-4.22+2.91+5.82*0))+(x[1]-(0.67-1.68+3.36*3))*(x[1]-(0.67-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[104] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[104][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+2.91+5.82*0))*(x[0]-(-1.68+2.91+5.82*0))+(x[1]-(1.49-1.68+3.36*3))*(x[1]-(1.49-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[105] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[105][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+2.91+5.82*0))*(x[0]-(-4.22+2.91+5.82*0))+(x[1]-(1.49-1.68+3.36*3))*(x[1]-(1.49-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[106] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[106][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+2.91+5.82*0))*(x[0]-(-2.17+2.91+5.82*0))+(x[1]-(2.16-1.68+3.36*3))*(x[1]-(2.16-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[107] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[107][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+2.91+5.82*0))*(x[0]-(-3.73+2.91+5.82*0))+(x[1]-(2.16-1.68+3.36*3))*(x[1]-(2.16-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[108] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[108][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+2.91+5.82*0))*(x[0]-(-2.95+2.91+5.82*0))+(x[1]-(2.41-1.68+3.36*3))*(x[1]-(2.41-1.68+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[109] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[109][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*1))*(x[0]-(-2.95+5.82*1))+(x[1]-(-0.25+3.36*3))*(x[1]-(-0.25+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[110] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[110][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}



			else if( sqrt( (x[0]-(-2.17+5.82*1))*(x[0]-(-2.17+5.82*1))+(x[1]-(0+3.36*3))*(x[1]-(0+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[111] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[111][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*1))*(x[0]-(-3.73+5.82*1))+(x[1]-(0+3.36*3))*(x[1]-(0+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{
				vol[112] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[112][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}
			else if( sqrt( (x[0]-(-1.68+5.82*1))*(x[0]-(-1.68+5.82*1))+(x[1]-(0.67+3.36*3))*(x[1]-(0.67+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[113] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[113][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*1))*(x[0]-(-4.22+5.82*1))+(x[1]-(0.67+3.36*3))*(x[1]-(0.67+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[114] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[114][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-1.68+5.82*1))*(x[0]-(-1.68+5.82*1))+(x[1]-(1.49+3.36*3))*(x[1]-(1.49+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[115] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[115][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-4.22+5.82*1))*(x[0]-(-4.22+5.82*1))+(x[1]-(1.49+3.36*3))*(x[1]-(1.49+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[116] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[116][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.17+5.82*1))*(x[0]-(-2.17+5.82*1))+(x[1]-(2.16+3.36*3))*(x[1]-(2.16+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[117] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[117][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-3.73+5.82*1))*(x[0]-(-3.73+5.82*1))+(x[1]-(2.16+3.36*3))*(x[1]-(2.16+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[118] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[118][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

			else if( sqrt( (x[0]-(-2.95+5.82*1))*(x[0]-(-2.95+5.82*1))+(x[1]-(2.41+3.36*3))*(x[1]-(2.41+3.36*3))+(x[2]-9.180)*(x[2]-9.180) ) <= R )      //coordinates of the particular area
			{	
				vol[119] += C_VOLUME(c,t);
				for (j = 0; j < pol_num; j++)
				{
					exposure[119][j] += C_YI(c,t,j+ini_pol)*C_VOLUME(c,t);
				}
			}

**********************/


		}
		end_c_loop(c,t)
	}
	printf("Loop finished\n");

	printf("Calculating average exposure\n");

	for (i = 0; i < 120; i++)
	{

		for (j = 0; j < pol_num; j++)
		{
			if (vol[i] > 0) 
			{
				exposure[i][j] = exposure[i][j] / vol[i];
			}
			else
			{
				exposure[i][j] = 0.;
			}
			
		}
	}
	
	printf("Writing data to csv\n");

	for (i = 0; i < 120; i++)
	{
		printf("Volume %d: %g\n",i,vol[i]);
		fprintf(fp_exp,"%g,",vol[i]);
		for (j = 0; j < pol_num; j++)
		{
			fprintf(fp_exp,"%g,",exposure[i][j]);
		}
		fprintf(fp_exp,"\n");
	}
	printf("Finished\n");
	fclose(fp_exp);
}


/************************write volume*************************/
/**************
DEFINE_ON_DEMAND(volume_udf)
{
	int i;
	FILE *fp_vol;
	fp_vol=fopen("vol_1.csv","w");
		
	printf("Writing volume to csv\n");

	for (i = 0; i < 120; i++)
	{
		fprintf(fp_vol,"%g\n",vol[i]);
	}

	printf("Finished\n");
	fclose(fp_vol);
}
**************/
