using System;

public class Sampling
{
	void SampleWithoutReplacement
	(
	    int populationSize,    // size of set sampling from
	    int sampleSize,        // size of each sample
	    vector<int> & samples  // output, zero-offset indicies to selected items
	)
	{
	    // Use Knuth's variable names
	    int& n = sampleSize;
	    int& N = populationSize;

	    int t = 0; // total input records dealt with
	    int m = 0; // number of items selected so far
	    double u;

	    while (m < n)
	    {
		u = GetUniform(); // call a uniform(0,1) random number generator

		if ( (N - t)*u >= n - m )
		{
		    t++;
		}
		else
		{
		    samples[m] = t;
		    t++; m++;
		}
	    }
	}
	static public void Main()
	{
	}
}
