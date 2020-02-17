__kernel void
leakyRelu(__global float *input,
     __global float *output)
{
    int x = get_global_id(0);
    if (output[x] > 0)
    {
        output[x] = input[x];
    }
    else
    {
        output[x] = 0;
    }
}