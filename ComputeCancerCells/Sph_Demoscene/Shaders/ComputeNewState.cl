__constant float4 Healthy = (float4)(0,1,0,1);
__constant float4 Cancer = (float4)(1,0,0,1);
__constant float4 Medecine = (float4)(1,1,0,1);
__constant float4 None = (float4)(0,0,0,1);

__constant int Width = (int)1024;
__constant int Height = (int)640;


bool CountNeighbours(float4 type, const uint x, const uint y, int minimum, __global float4 *Read)
{
	int t = 8 - minimum + 1;
	uint yw = 0;
	yw = ((y - 1) * Width) + x - 1;

	if (any(Read[yw] != type))
		--t;

	if (any(Read[++yw] != type))
		--t;

	if (any(Read[++yw] != type))
		--t;

	yw = ((y) * Width) + x - 1;

	if (any(Read[yw] != type))
		--t;

	if (any(Read[yw + 2] != type))
		--t;

	yw = ((y + 1) * Width) + x - 1;

	if (any(Read[yw] != type))
		--t;

	if (any(Read[++yw] != type))
		--t;

	if (any(Read[++yw] != type))
		--t;

	if (t <= 0)
		return false;
	return true;
}


bool HasNeighbour(float4 type, uint x, uint y, __global float4 *Read)
{
	uint yw = 0;
	if (y > 0)
	{
		yw = ((y - 1) * Width) + x - 1;
		if (x > 0 && all(Read[yw] == type))
		return true;
		if (all(Read[++yw] == type))
		return true;
		if (x < Width - 1 && all(Read[++yw] == type))
		return true;
	}
	yw = ((y) * Width) + x - 1;
	if (x > 0 && all(Read[yw] == type))
	return true;
	if (x < Width - 1 && all(Read[yw + 2] == type))
	return true;
	if (y < Height - 1)
	{
		yw = ((y + 1) * Width) + x - 1;
		if (x > 0 && all(Read[yw] == type))
		return true;
		if (all(Read[++yw] == type))
		return true;
		if (x < Width - 1 && all(Read[++yw] == type))
		return true;
	}
	return false;
}

__kernel void compute(__global float4 *Read, __global float4 *Write)
{
	uint gid = get_global_id(0);
	uint x = gid % Width;
	uint y = gid / Width;
	uint index = gid;
	float4 r = Read[index];

	if (all(r == Healthy) && !(y == 0 || y == Height - 1 || x == 0 || x == Width - 1) && CountNeighbours(Cancer, x, y, 6, Read))
	{
		Write[index] = Cancer;
	}
	else if (all(r == Cancer) && !(y == 0 || y == Height - 1 || x == 0 || x == Width - 1) && CountNeighbours(Medecine, x, y, 6, Read))
	{		uint yw = 0;		yw = ((y - 1) * Width) + x - 1;		if (all(Read[yw] == Medecine))			Write[yw] = Healthy;
		++yw;
		if (all(Read[yw] == Medecine))
			Write[yw] = Healthy;
		++yw;
		if (all(Read[yw] == Medecine))
			Write[yw] = Healthy;
		yw = ((y) * Width) + x - 1;
		if (all(Read[yw] == Medecine))
			Write[yw] = Healthy;
		++yw;		if (all(Read[yw] == Medecine))
			Write[yw] = Healthy;		++yw;		if (all(Read[yw] == Medecine))
			Write[yw] = Healthy;		yw = ((y + 1)* Width) + x - 1;		if (all(Read[yw] == Medecine))
			Write[yw] = Healthy;		++yw;		if (all(Read[yw] == Medecine))
			Write[yw] = Healthy;
		++yw;
		if (all(Read[yw] == Medecine))
			Write[yw] = Healthy;
	}
	else if (all(r == None) && HasNeighbour(Medecine, x, y, Read))
	{
		Write[index] = Medecine;
	}
}