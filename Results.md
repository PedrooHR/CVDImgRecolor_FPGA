
# **HW-Version 1**
This version contains modifications in the kernel. The external loop is unroll by factor 8, the internal can't be unrolled as it does not satisfy dependencies, each loop has a factor 8, so the data bandwidth of 512 is achieved.

## **Results**:

### Experiment Setup:
Experiments are drive in the aws instance and personal PC
* AWS instace: Intel(R) Xeon(R) CPU E5-2686 v4 @ 2.30GHz + UltraScale+ VU9P FPGA
* Personal PC: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz + GTX 1650 4GB (Runs *CPU* and *GPU* tests)
* **Obs:** The CPU code is single threaded, so the i5 CPU processor has better single-thread perfomance than the Xeon CPU 
* **Obs:** All results are shown in seconds.
* **Obs:** Results for deuteranopes.

| Input Image | Size      | CPU Time (aws) | FPGA Time (aws) | Speed Up   | Original Image | CVD Perception | Result Image (FPGA)| 
| ----------- | --------- | -------------- | ----------------| ---------- | -------------- | -------------- | ------------------ |
| testeimg1   | 500x501   | 4.3478         | 1.9841          |  2.19x     | <img width="100px" src="resources/imgs/testeimg1.jpg">  | <img width="100px" src="resources/cvd-sim/testeimg1.jpg">  | <img width="100px" src="results/hw-version1/results/testeimg1.jpg">  |             
| testeimg2   | 224x225   | 1.0604         | 0.5385          |  1.97x     | <img width="100px" src="resources/imgs/testeimg2.jpg">  | <img width="100px" src="resources/cvd-sim/testeimg2.jpg">  | <img width="100px" src="results/hw-version1/results/testeimg2.jpg">  |             
| testeimg3   | 1280x960  | 21.8649        | 9.0861          |  2.41x     | <img width="100px" src="resources/imgs/testeimg3.jpg">  | <img width="100px" src="resources/cvd-sim/testeimg3.jpg">  | <img width="100px" src="results/hw-version1/results/testeimg3.jpg">  |             
| testeimg4   | 481x321   | 2.8231         |                 |            | <img width="100px" src="resources/imgs/testeimg4.jpg">  | <img width="100px" src="resources/cvd-sim/testeimg4.jpg">  | |               
| testeimg5   | 268x166   | 0.8928         | 0.4852          |  1.84x     | <img width="100px" src="resources/imgs/testeimg5.jpg">  | <img width="100px" src="resources/cvd-sim/testeimg5.jpg">  | <img width="100px" src="results/hw-version1/results/testeimg5.jpg">  |             
| testeimg6   | 347x262   | 1.6795         |                 |            | <img width="100px" src="resources/imgs/testeimg6.jpg">  | <img width="100px" src="resources/cvd-sim/testeimg6.jpg">  | |              
| testeimg7   | 254x254   | 1.1986         | 0.6368          |  1.88x     | <img width="100px" src="resources/imgs/testeimg7.jpg">  | <img width="100px" src="resources/cvd-sim/testeimg7.jpg">  | <img width="100px" src="results/hw-version1/results/testeimg7.jpg">  |             
| testeimg8   | 220x220   | 0.9513         | 0.5174          |  1.84x     | <img width="100px" src="resources/imgs/testeimg8.jpg">  | <img width="100px" src="resources/cvd-sim/testeimg8.jpg">  | <img width="100px" src="results/hw-version1/results/testeimg8.jpg">  |             
| testeimg9   | 320x316   | 1.8261         | 0.9125          |  2.00x     | <img width="100px" src="resources/imgs/testeimg9.jpg">  | <img width="100px" src="resources/cvd-sim/testeimg9.jpg">  | <img width="100px" src="results/hw-version1/results/testeimg9.jpg">  |            
| testeimg10  | 554x600   | 5.5283         | 2.5889          |  2.14x     | <img width="100px" src="resources/imgs/testeimg10.jpg"> | <img width="100px" src="resources/cvd-sim/testeimg10.jpg"> | <img width="100px" src="results/hw-version1/results/testeimg10.jpg"> |             
| testeimg11  | 200x198   | 0.7911         | 0.4498          |  1.76x     | <img width="100px" src="resources/imgs/testeimg11.jpg"> | <img width="100px" src="resources/cvd-sim/testeimg11.jpg"> | <img width="100px" src="results/hw-version1/results/testeimg11.jpg"> |             
| testeimg12  | 320x315   | 1.8078         | 0.9072          |  1.99x     | <img width="100px" src="resources/imgs/testeimg12.jpg"> | <img width="100px" src="resources/cvd-sim/testeimg12.jpg"> | <img width="100px" src="results/hw-version1/results/testeimg12.jpg"> |             
| testeimg13  | 200x200   | 0.7979         | 0.4594          |  1.74x     | <img width="100px" src="resources/imgs/testeimg13.jpg"> | <img width="100px" src="resources/cvd-sim/testeimg13.jpg"> | <img width="100px" src="results/hw-version1/results/testeimg13.jpg"> |             
| testeimg14  | 320x315   | 1.9063         | 0.9141          |  2.09x     | <img width="100px" src="resources/imgs/testeimg14.jpg"> | <img width="100px" src="resources/cvd-sim/testeimg14.jpg"> | <img width="100px" src="results/hw-version1/results/testeimg14.jpg"> |             
| testeimg15  | 313x320   | 1.8424         | 0.9034          |  2.04x     | <img width="100px" src="resources/imgs/testeimg15.jpg"> | <img width="100px" src="resources/cvd-sim/testeimg15.jpg"> | <img width="100px" src="results/hw-version1/results/testeimg15.jpg"> |             
| testeimg16  | 328x296   | 1.7687         | 0.8833          |  2.00x     | <img width="100px" src="resources/imgs/testeimg16.jpg"> | <img width="100px" src="resources/cvd-sim/testeimg16.jpg"> | <img width="100px" src="results/hw-version1/results/testeimg16.jpg"> |             
| testeimg17  | 6000x4000 | 438.4492       | 175.8575        |  2.49x     | <img width="100px" src="resources/imgs/testeimg17.jpg"> | <img width="100px" src="resources/cvd-sim/testeimg17.jpg"> | <img width="100px" src="results/hw-version1/results/testeimg17.jpg"> |             

**Discussions**: 
* The average speed up is 2.02x. It is a increase, but not as expected. The is a dependency between the inner and external loop that makes the pipeline goes sequential even if there are multiple instances to cumputate. I believe the best option here would be using multiple compute units. But it was not achievable by matters of time in this week.
