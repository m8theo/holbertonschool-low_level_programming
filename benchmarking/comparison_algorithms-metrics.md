# comparison_algorithms metrics

## Compilation
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long comparison_algorithms.c -o comparison_algorithms`

## Raw outputs

### Run 1
```
(coller la sortie exacte)
```

### Run 2
```
(coller la sortie exacte)
```

### Run 3
```
(coller la sortie exacte)
```

## Results

| Run | Naive (s) | Single-pass (s) |
|-----|-----------|-----------------|
| 1   | ...       | ...             |
| 2   | ...       | ...             |
| 3   | ...       | ...             |
| **Average** | **...** | **...** |

## Relative difference
The naive implementation is approximately **X times slower** than the single-pass implementation
(average naive / average single-pass = ... / ... ≈ X).

## Observation
The naive version performs about n²/2 ≈ 1.25 billion checks (O(n²)),
while the single-pass version performs n = 50,000 checks (O(n)).
