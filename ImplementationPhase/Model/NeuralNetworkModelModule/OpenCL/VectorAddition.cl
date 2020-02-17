__kernel void
vectorAddition(__global float* C, 
          __global float* A, 
          __global float* B)
{  
   int p = get_global_id(0); 
   C[p] = A[p] + B[p];
}