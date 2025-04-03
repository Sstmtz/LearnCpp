// C++14: Constraints fot Non-Type Template Parameters

constexpr bool isPrime(int val) {
    for (int i = 2; i <= val / 2; ++i) {
        if (val % i == 0) {
            return false;
        }
    }
    return val > 1; // 2 and 3 are primes, 0 and 1 not
}

template <auto Val>
    requires(isPrime(Val))
class C1 {
    // ...
};

template <auto Val>
concept IsPrime = Val > 0 && isPrime(Val);

template <auto Val>
    requires IsPrime<Val>
class C2 {
    // ...
};

int main() {
    C1<6> c1; // ERROR: constraint not satisfied
    C1<7> c2; // OK

    C2<6> c3; // ERROR: concept IsPrime not satisfied
    C2<7> c4; // OK
}
