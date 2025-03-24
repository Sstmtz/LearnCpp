// cppcon.cppm
export module cppcon;

namespace CppCon {
    auto GetWeclomeHelper() {
        return "Weclome to CppCon 2020!";
    }

    export auto GetWelcome() {
        return GetWeclomeHelper();
    }

} // namespace CppCon
