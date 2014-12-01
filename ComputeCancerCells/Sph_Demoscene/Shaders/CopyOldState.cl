__constant float2 Healthy = (float2)(0,1);
__constant float2 Cancer = (float2)(1,0);
__constant float2 Medecine = (float2)(1,1);
__constant float2 None = (float2)(0,0);

__kernel void compute(__global float4 *Read, __global float4 *Write, volatile __global uint *Counter)
{
	int gid = get_global_id(0);
	Write[gid] = Read[gid];
	if (all(Read[gid].lo == Healthy))
		atomic_add(&Counter[0], 1);
	if (all(Read[gid].lo == Cancer))
		atomic_add(&Counter[1], 1);
	if (all(Read[gid].lo == Medecine))
		atomic_add(&Counter[2], 1);
}