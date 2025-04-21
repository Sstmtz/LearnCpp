// shared_from_this

// To convert `this` into a `shared_ptr`
// - Class derives from `enable_shared_from_this`
// - Object is already managed by a shared_ptr
// - return this->shared_from_this();
