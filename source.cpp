#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<cassert>
#include<random>
#include<math.h>
using namespace std;

struct PRNG
{
	mt19937 engine;
};

void initGenerator( PRNG& generator )
{
	 
	random_device device;
	generator.engine.seed( device() );

}

unsigned random( PRNG& generator, unsigned minValue, unsigned maxValue )
{
	assert( minValue < maxValue );
	uniform_int_distribution<unsigned> distribution( minValue, maxValue );
	return distribution( generator.engine );
}

float getRandomFloat( PRNG& generator, float minValue, float maxValue)
{

	assert( minValue < maxValue );
	uniform_real_distribution<float> distribution( minValue, maxValue );
	return distribution( generator.engine );
}

void frequencyBitTest( bool * bits, const int len )
{
	double Sn = 0;
	for ( int i = 0; i < len; i++ )
	{
	
		if( int(bits[i]) == 1 ) Sn += ( 1 / sqrt( len ) );
		else Sn -= ( 1 / sqrt( len ) );

	}
	double Pvalue = erfc( Sn / sqrt( 2 ) );
	cout << endl << Pvalue;
}

void frequencyBitTest( bool * bits, const int len )
{
	double Sn = 0;
	for ( int i = 0; i < len; i++ )
	{
	
		if( int(bits[i]) == 1 ) Sn += ( 1 / sqrt( len ) );
		else Sn -= ( 1 / sqrt( len ) );

	}
	double Pvalue = erfc( Sn / sqrt( 2 ) );
	cout << endl << Pvalue;
}

void longestOne( bool* bits, const int len )
{

	int v1 = 0, v2 = 0, v3 = 0, v4 = 0;
	for ( int i = 0; i < 128/8; i++ )
	{
		int cur_long = 0, total_long = 0;
		for ( int j = 0; j < 8; j++ )
		{
			if ( bits[j] == 0 )
			{
				if ( cur_long > total_long ) total_long = cur_long;
				cur_long = 0; 
			}
			if ( bits[j] == 1 ) cur_long += 1;

		}
		if ( total_long <= 1 ) v1++;
		else if ( total_long == 2 ) v2++;
		else if ( total_long == 3 ) v3++;
		else v4++;
	}
	double pi[4];
	pi[0] = 0.2148; pi[1] = 0.3672; pi[2] = 0.2305; pi[3] = 0.1875;
	double Xi_2 = 0;
	for( int i = 0; i < 3; i++ )
	{
		if( i == 0 ) Xi_2 += ( v1 - 16 * pi[i] ) * ( v1 - 16 * pi[i] ) / 16 * pi[i];
		if( i == 1 ) Xi_2 += ( v2 - 16 * pi[i] ) * ( v2 - 16 * pi[i] ) / 16 * pi[i];
		if( i == 2 ) Xi_2 += ( v3 - 16 * pi[i] ) * ( v3 - 16 * pi[i] ) / 16 * pi[i];
		if( i == 3 ) Xi_2 += ( v4 - 16 * pi[i] ) * ( v4 - 16 * pi[i] ) / 16 * pi[i];

	}
	cout << endl << Xi_2;
	//double Pvalue = igamc(3 / 2, Xi_2 / 2);
}

int main()
{
	bool* bits = new bool[128];
	const int len = 128;
	PRNG generator; 
	initGenerator( generator );
	for ( int i = 0; i < len; ++i )
	{
		bits[i - 1] = random( generator, 0, 1 );
		cout << bits[i - 1];
	}
	frequencyBitTest( bits, len );
    sameBitsTest( bits, len );
    longestOne( bits, len );
	return 0;
}