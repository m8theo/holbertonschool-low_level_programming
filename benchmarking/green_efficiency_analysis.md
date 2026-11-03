# Analysis of the Effectiveness of Green Tech

## Measurement Methodology

All programs were compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` and run on the same computer (Apple M1) to ensure that the results are comparable. Since there is no direct way to measure how much electricity a program uses, I measured its execution time using `clock()` from the `<time.h>` header, then divided it by `CLOCKS_PER_SEC` to convert it to seconds. 

For `baseline_loop.c` and `comparison_algorithms.c`, I ran each program three times in a row without modifying the code. I then saved the outputs and calculated their average.

The only file I modified is `instrumentation_lab.c`. I added a call to `clock()` right before the first step, and then again after each step, like split times in a race. Note that the start of each stage coincides exactly with the end of the previous one, so `TOTAL` is the sum of `BUILD_DATA`, `PROCESS`, and `REDUCE`. I don't use `printf` in the measured section because I wanted to time only the computation, not the display. I ran into a problem: at first, the program didn't display anything. The file that had been modified hadn't been saved yet, so the old version was still running. I rewrote the file, recompiled it, and voilà—it worked.

## Observed Differences in Performance

**Reference loop (100 million iterations):** 0.126 s, 0.095 s, and 0.094 s, for an average of ~**0.105 s**. The first run was slower than the other two. The computer is performing other tasks in parallel, so the same calculation never takes exactly the same amount of time. 

**Comparison of Methods (50,000 numbers):**

| Method | Average Time |
| --- | --- |
| Naive | ~2.18 s |
| Direct | ~0.00009 s |

Therefore, 2.18 / 0.00009 ≈ 24,000, which makes the naive method about **24,000 times slower**, even though both methods yield the same answer. A quick look at the code makes this perfectly logical. The naive method starts from scratch with each iteration, so it has to examine approximately 1.25 billion values in total (50,000 × 50,001 / 2). The direct method checks only 50,000 of them. That means it's about 25,000 times more work, which is in the same range as what I measured.

**Instrumentation:** `TOTAL` = **0.00068 s**, `BUILD_DATA` ~52%, `PROCESS` ~28%, `REDUCE` ~20%. The most time-consuming step is data preparation.

## Relationship Between Execution Time and Energy Consumption

This project does not measure watts. Execution time is an indirect metric: the longer the processor runs, the more energy it consumes. Based on this concept, the naive method—which kept the processor running for about 2.18 seconds instead of 0.00009 seconds—is clearly the one that wasted the most energy in my tests. In short, a poor method can waste a tremendous amount of time—and therefore a tremendous amount of energy. 

## Limitations of the Experiment

- It's not really a measurement in watts. The execution time is only an estimate, and a processor's electrical power consumption is rarely constant.
- `clock()` is not very accurate for very short durations (0.00009 s, 0.00068 s). These figures are therefore less reliable than the 2.18 s obtained using the naive method.
- I only averaged three runs per program, which is quite a small number: a single run can skew the average (0.126 s for the first baseline run).
- All measurements were taken on a single machine (Apple M1), and the results may differ on another computer.

## Hands-On Engineering Education

Measure before optimizing: without the intermediate timings, I would never have known that data preparation takes up about half the time in `instrumentation_lab.c`. The key is simply to use the right method: switching from the naive method to the direct method reduced the execution time by a factor of about 24,000! A faster program is a program that consumes less energy, and that’s the general idea behind Green Tech.