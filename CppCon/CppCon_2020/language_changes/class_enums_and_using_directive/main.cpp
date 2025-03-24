
// class enums and using Directive

#include <string_view>
enum class CardTypeSuit {
    Club,
    Diamonds,
    Hearts,
    Spades
};

std::string_view GetString(CardTypeSuit const cardTypeSuit) {
    switch (cardTypeSuit) {
        case CardTypeSuit::Club    : return "Clubs";
        case CardTypeSuit::Diamonds: return "Diamonds";
        case CardTypeSuit::Hearts  : return "Hearts";
        case CardTypeSuit::Spades  : return "Spades";
    }
}

std::string_view GetString2(CardTypeSuit const cardTypeSuit) {
    switch (cardTypeSuit) {
        // C++20, you can use `using enum`
        // the you can remove the prefix
        using enum CardTypeSuit;
        case Club    : return "Clubs";
        case Diamonds: return "Diamonds";
        case Hearts  : return "Hearts";
        case Spades  : return "Spades";
    }
}

int main() {
    return 0;
}
