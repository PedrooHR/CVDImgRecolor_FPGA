
# **HW-Version 1**
This version contains modifications in the kernel. The external loop is unroll by factor 8, the internal can't be unrolled as it does not satisfy dependencies, each loop has a factor 8, so the data bandwidth of 512 is achieved.

## **Results**:

### Experiment Setup:
Experiments are drive in the aws instance and personal PC
* AWS instace: Intel(R) Xeon(R) CPU E5-2686 v4 @ 2.30GHz + UltraScale+ VU9P FPGA
* Personal PC: Intel Core i5 9300H @2.4 GHz - 4.1 GHz Turbo + GTX 1650 4GB (Runs *CPU* and *GPU* tests)

| Input Image | Size | CPU Time (aws) | FPGA Time (aws) | CPU (Personal PC) | GPU Time (Personal PC) |
| - | - | - | - | - | - |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
|   |   |   |   |   |   |
