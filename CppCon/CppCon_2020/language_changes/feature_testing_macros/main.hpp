// Feature Testing Macros

#if __has_include(<optional>)
# include <optional>
# if __cpp_lib_optional
#  define has_optional 1
# endif
#elif __has_include(<experimental/optional>)
# include <experimental/optional>
# if __cpp_lib_experimental_optional
#  define hashas_optional          1
#  define optional_is_experimental 1
# endif
#endif
