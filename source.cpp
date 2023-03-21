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