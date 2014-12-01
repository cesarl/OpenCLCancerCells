__constant float4 Healthy = (float4)(0,1,0,1);
__constant float4 Cancer = (float4)(1,0,0,1);
__constant float4 Medecine = (float4)(1,1,0,1);
__constant float4 None = (float4)(0,0,0,1);
__constant int w = (int)1024;
__constant int h = (int)640;


long random()
{
	return (42 * 0x5DEECE66DL + 0xBL) & ((1L << 48) - 1);
}


__kernel void compute(__global float4 *Write, int injectPoint)
{
	int gid = get_global_id(0);
	if (injectPoint < 0)
	{
		if (random() % 3 == 0)
			Write[gid] = Healthy;
		else if (random() % 2 == 0)
			Write[gid] = Cancer;
		else
			Write[gid] = Cancer;
	}
	else
	{
		if (gid == injectPoint)
			Write[gid] = Medecine;
	}
}