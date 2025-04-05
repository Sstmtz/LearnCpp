// Instantiation

// Function template example
template <class T>
void swap_pointed_to(T *a, T *b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

// swap_pointed_to<double>
void swap_pointed_toIdEvPT_S1_(double *a, double *b) {
    double temp = *a;
    *a = *b;
    *b = temp;
}
