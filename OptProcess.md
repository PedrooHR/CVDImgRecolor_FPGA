## A look at the Kernel Optimizations


### First Optimization Batch (HW-Version 1)
* This report shows the times of the kernel and compute units of one kernel call.
* Input was a 16 x 16 image (with 25 Elastic Maps nodes) - Essentialy a 16x16x25 loop.

| Optimization                     | Kernel Time (ms) | CU Time (ms) | Cumulative<br>Speed Up | Observations    |
| -------------------------------- | ---------------- | ------------ | ---------------------- | --------------- |
| Standard                         | 0.028            | 0.026        | 1.00x / 1.00x          | No observations |
| Loop Unroll + Different Ports    | 0.006            | 0.004        | 4.67x / 6.50x          | The factor needs to be 8 since the input sizes are 64 bytes | 
| Different Memory Banks (3 banks) | 0.006            | 0.004        | 4.67x / 6.50x          | The in2 is only read once (does not change), so we probably don't need different memory banks |


### Second Optimization Batch (HW-Version 2 - By matters of time wasn't complete)
* This report shows the times of the kernel and compute units of one kernel call.
* Input was a 16 x 16 image (with 100 Elastic Maps nodes) - Essentialy a 16x16x100 loop.

| Optimization                     | Kernel Time (ms) | CU Time (ms) | Cumulative<br>Speed Up | Observations    |
| -------------------------------- | ---------------- | ------------ | ---------------------- | --------------- |
| Standard (From Optimizations 1)  | 0.172            | 0.169        | 1.00x / 1.00x          | No observations |
| More input buffers + diff Banks  | 0.998            | 0.990        | 0.17x / 0.17x          | Memory Dependency Violation | 
| Multiple Compute Units           |                  |              |       /                | Couldn't made it in time - Work in progress |

## About the actual algorithm
* The recolor algorithm has 7 kernel calls. (7 epochs, more than that cause Elastic Map nodes to overlap each other)
* The image sizes are much higher.
* The total number of Elastic Maps nodes is 100.
