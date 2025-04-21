// 2. Narrowing Conversions

// Many conversions can potentially lose information.
// - C++03 doesn't provide any protection against accidentally using a lossy
//   conversion during initialization:

float f = 1000000.5;
int i = f;   // discards fractional part of f
short s = i; // value might not fit in a short

// Even a conversion from integer to floating-point might lose part of the value:
int i = INT_MAX;
float f = i; // might lose precision

// If sizeof(int) == sizeof(float), then `f` has fewer significant digits than `i`.
