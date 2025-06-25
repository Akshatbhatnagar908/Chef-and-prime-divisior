# Chef and Prime Divisors

This project solves the "Chef and Prime Divisors" problem efficiently using two different approaches:
1. GCD-Based (Optimal)
2. Sieve-Based Factorization (Educational)

---

## 🧮 Problem Statement

Given two integers `A` and `B`, determine whether **all prime divisors of B also divide A**.

### Input Format
T
A₁ B₁
A₂ B₂
...
Aₜ Bₜ



- `T`: Number of test cases  
- `Aᵢ`, `Bᵢ`: Integers for each test case

### Output Format
For each test case, output `"Yes"` if `A` is divisible by all prime divisors of `B`, otherwise `"No"`.

---

## ✅ Example

### Input:
3
120 75
128 16
7 8
### Output:
Yes
Yes
No

## 🔍 Insight

- All prime divisors of `B` must divide `A`.
- Efficient handling is critical as values can go up to `10^18`.

---

## 🚀 Approaches

---

### 🔸 1. GCD-Based Approach (Optimal)

#### 🧠 Idea:
If `gcd(A, B)` shares prime factors with `B`, remove them iteratively. If `B` becomes `1`, then all of its prime factors divide `A`.

#### 📋 Algorithm:
1. Let `g = gcd(A, B)`
2. While `B != 1`:
   - Compute `g1 = gcd(g, B)`
   - If `g1 == 1`, return `"No"` (B has a prime not in A)
   - Divide `B` by `g1` until it's no longer divisible
3. If `B == 1`, return `"Yes"`

#### ⏱ Time Complexity:
- `gcd()` takes `O(log max(A, B))`
- At most `log B` different prime factors
- Each division step is fast

> ✅ **Total time per test case:** `O((log B)^2)`  
> ✅ Handles `T = 10^4`, `A, B ≤ 10^18` efficiently

#### 🧾 File:
`GCD for chef and prime divisior.cpp`

---

### 🔹 2. Sieve-Based Prime Factorization (Educational)

#### 🧠 Idea:
Precompute all primes up to `1e6` using a sieve, factor `B`, and check if each prime factor divides `A`.

#### 📋 Algorithm:
1. Use the Sieve of Eratosthenes to generate all primes ≤ `1e6`
2. Factorize `B` using this list
3. Check whether each prime factor of `B` divides `A`

#### ⏱ Time Complexity:
- Sieve: `O(n log log n)` (once, n = 1e6)
- Prime factorization: up to `O(√B)` for each test case
- Checking divisibility: `O(k)` where `k` = number of unique prime divisors

> ❌ **Not suitable for very large B (e.g., 10^18)**  
> ✅ Good for small inputs or educational use

#### 🧾 File:
`chef and prime divisor.cpp`

---

## 🧪 Test Example Explained

For input: `120 75`

- Prime divisors of 75 = {3, 5}
- 120 is divisible by 3 and 5 → ✅ Yes

For input: `7 8`

- Prime divisors of 8 = {2}
- 7 is not divisible by 2 → ❌ No

---

## 🛠 How to Compile and Run

### Compile:
```bash
g++ -o prime_divisors "GCD for chef and prime divisior.cpp"
Run:

./prime_divisors
Or with input redirection:

./prime_divisors < input.txt
📁 Files
File Name	Description
GCD for chef and prime divisior.cpp	✅ GCD-based solution (recommended for large inputs)
chef and prime divisor.cpp	Educational sieve-based solution (not optimal)

🏁 License
This project is licensed under the MIT License.

✍️ Author
Designed for competitive programming and mathematical problem-solving with performance in mind.
--

### 🔚 Summary:

- Use **GCD-based** approach in practice due to its superior performance and constant memory usage.
- Keep the **sieve-based** approach for conceptual clarity and educational purposes.


