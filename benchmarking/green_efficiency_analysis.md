# Green Efficiency Analysis

## Measurement Methodology

To compare the efficiency of two algorithms, I measured the execution time of a naive algorithm and a single-pass algorithm. Each program was run three times, and the runtime was recorded for every execution.

The results were the following:

Run 1  
Naive algorithm time: 2.149481 seconds  
Single-pass algorithm time: 0.000092 seconds  

Run 2  
Naive algorithm time: 2.182079 seconds  
Single-pass algorithm time: 0.000080 seconds  

Run 3  
Naive algorithm time: 2.151648 seconds  
Single-pass algorithm time: 0.000079 seconds  

After collecting the results, I calculated the average runtime for each algorithm. The naive algorithm had an average runtime of **2.1611 seconds**, while the single-pass algorithm had an average runtime of **0.000084 seconds**.

## Observed Performance Differences

The measurements show a very large difference between the two algorithms. The naive algorithm consistently took a little more than **2 seconds** to complete, while the single-pass algorithm finished in about **0.00008 seconds**.

Using the averages, the relative performance difference can be estimated:

Relative difference = 2.1611 / 0.000084 ≈ **25,727**

This means the naive algorithm is roughly **25,000 times slower** than the single-pass algorithm. The results were also consistent across the three runs, which suggests the difference comes from the way the algorithms are implemented rather than random variation.

## Relation Between Runtime and Energy Consumption

Programs that run longer usually consume more energy because the CPU stays active for a longer time. In this experiment, the naive algorithm runs for about **2.16 seconds**, while the single-pass algorithm runs for only **0.000084 seconds**.

Because the naive version uses much more processing time, it likely consumes more energy. Even though the program itself is small, the difference shows how inefficient algorithms can waste computing resources.

## Limitations of the Experiment

One limitation is that the experiment only measured runtime and not the actual energy used by the computer. Runtime gives a good idea of efficiency, but it does not measure power consumption directly.

Another limitation is that the tests were done on one machine. Background processes or system activity could slightly affect the results.

## Practical Engineering Takeaway

This experiment shows that algorithm design has a big impact on performance. The single-pass algorithm is much faster because it avoids unnecessary work.

For developers, this means choosing efficient algorithms is important not only for speed but also for reducing wasted computing resources. Even small improvements in efficiency can make a big difference when programs run many times.
