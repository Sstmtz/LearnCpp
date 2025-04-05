// Instantiation

// Class template example
template <class T, class U>
class pair {
    T m0;
    U m1;

public:
    pair() {}

    pair(T v0, U v1) : m0(v0), m1(v1) {}

    T first() const {
        return m0;
    }

    T second() const {
        return m1;
    }
};

// pair<int, data>
// class pairIi4dataE { // Compiler's internal name for pair<int, data>
//     int  m0;
//     data m1;
//
// public:
//     pairIi4dataE();
//     pairIi4dataE(int v0, data v1);
//     int  first() const;
//     data second() const;
// };

// pair<int[10], data>
// class pairIA10_i4dataE {
//     int  m0[10];
//     data m1;
//
// public:
//     pairIA10_i4dataE();
//     pairIA10_i4dataE(int v0[10], data v1));
//     int(first())[10] const; // ERROR
//     data second() const;
// };
