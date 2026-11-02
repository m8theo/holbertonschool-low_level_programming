# Green Efficiency Analysis

## Measurement Methodology

All programs were compiled with `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long` and executed on the same machine (Apple M1, macOS 27.2), in the same environment, with heavy applications closed. Timing relies on `clock()` from `<time.h>`, which returns the processor time used by the program. Values were converted to seconds with `CLOCKS_PER_SEC` and printed with `%.6f`. Each program was run at least three times in a row to observe variability.

For the instrumentation lab, I placed four consecutive timestamps (t0, t1, t2, t3) around the three phases. Each phase ends exactly where the next one begins, so there are no gaps or overlaps, and TOTAL is the sum of BUILD_DATA, PROCESS and REDUCE. This guarantees that TOTAL is greater than or equal to each sub-measurement. All `printf` calls are placed after the last timestamp, so printing is not included in any measured interval.

## Observed Performance Differences

**Baseline loop.** The 100,000,000 iterations took 0.126109, 0.094643 and 0.094172 seconds, for an average of 0.104975 seconds. The times were close but not identical, which shows that even a deterministic computation has some timing variability.

**Algorithm comparison.** The naive implementation averaged 2.184652 seconds, while the single-pass implementation averaged 0.000087 seconds. The naive version was therefore about 25111 times slower. This matches the structure of the code: for 50,000 elements, the naive nested loop performs about 1.25 billion checks (O(n²)), while the single pass performs only 50,000 (O(n)). The two functions also return different results (625025000 and 25000) because the naive version recounts the even values at every index.

**Instrumentation lab.** In the recorded run, TOTAL was 0.000684 seconds: BUILD_DATA took 0.000357 s (about 52%), PROCESS 0.000193 s (about 28%) and REDUCE 0.000134 s (about 20%). Building the dataset was the most expensive phase in this run.

## Relation Between Runtime and Energy Consumption

Energy is power multiplied by time. If the processor draws a comparable amount of power during both runs, a program that keeps the CPU busy longer consumes more energy. Under that assumption, the naive algorithm would use roughly 25111 times more CPU energy than the single-pass version to process the same data. The measurements also show where the largest gains are: the whole instrumentation lab ran in 0.000684 seconds, while the naive algorithm alone needed 2.184652 seconds. Choosing a better algorithm had a far larger impact than any difference between the phases of a small program.

## Limitations of the Experiment

- No energy was measured in watts; runtime is only an indirect indicator. Real power is not constant, since modern CPUs change frequency and may switch between performance and efficiency cores.
- The instrumentation phases each lasted less than a millisecond. At this scale, `clock()` resolution and system noise can significantly affect the values, so a single run is not enough for strong conclusions.
- Only three runs were made per program, and background processes were not fully controlled.
- The programs were compiled without optimization flags. An optimized build could change both absolute times and ratios.
- `clock()` measures CPU time only, not memory or other hardware energy costs.

## Practical Engineering Takeaway

Measure before optimizing. Algorithmic complexity is the first lever for reducing CPU time, and therefore energy: replacing an O(n²) approach with an O(n) one made the program about 25111 times faster here. Instrumenting each phase then shows where time is actually spent, and repeating measurements on the same machine makes the comparisons reliable.
