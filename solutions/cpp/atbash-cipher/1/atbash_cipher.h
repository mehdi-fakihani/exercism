#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H

#include <cctype>
#include <map>
#include <optional>
#include <string>
#include <string_view>

namespace atbash_cipher {    
    static const std::map<char, char> encoding_table{
            { 'a' , 'z' },
            { 'b' , 'y' },
            { 'c' , 'x' },
            { 'd' , 'w' },
            { 'e' , 'v' },
            { 'f' , 'u' },
            { 'g' , 't' },
            { 'h' , 's' },
            { 'i' , 'r' },
            { 'j' , 'q' },
            { 'k' , 'p' },
            { 'l' , 'o' },
            { 'm' , 'n' },
            { 'n' , 'm' },
            { 'o' , 'l' },
            { 'p' , 'k' },
            { 'q' , 'j' },
            { 'r' , 'i' },
            { 's' , 'h' },
            { 't' , 'g' },
            { 'u' , 'f' },
            { 'v' , 'e' },
            { 'w' , 'd' },
            { 'x' , 'c' },
            { 'y' , 'b' },
            { 'z' , 'a' }
        };
    
    [[nodiscard]] std::optional<char> encode(const char character)
    {
        if (std::isdigit(character))
            return character;

        const char lower_case_letter = std::tolower(character);
        const bool is_a_valid_letter = encoding_table.find(lower_case_letter) != std::cend(encoding_table);
        return is_a_valid_letter ? std::make_optional(encoding_table.at(lower_case_letter)) : std::nullopt;
    }

    [[nodiscard]] std::string atbash_cipher(const std::string_view message, const bool encoding = true)
    {
        std::string result;
        result.reserve(message.length());

        for (std::size_t reading_count = 0, writing_count = 0; reading_count < message.length(); ++reading_count)
        {
            const std::optional<char> encoded_character = encode(message[reading_count]);
            
            if (!encoded_character)
                continue;
            
            if (encoding && writing_count != 0 && writing_count % 5 == 0)
            {
                result += ' ';
            }

            result += encoded_character.value();
            ++writing_count;
        }

        return result;
    }
    
    [[nodiscard]] std::string encode(const std::string_view message)
    {
        return atbash_cipher(message);
    }

    [[nodiscard]] std::string decode(const std::string_view ciphered_message)
    {
        return atbash_cipher(ciphered_message, false);
    }
}  // namespace atbash_cipher

#endif  // ATBASH_CIPHER_H