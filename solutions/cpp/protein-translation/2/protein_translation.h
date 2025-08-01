#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace protein_translation {    
    [[nodiscard]] std::optional<std::string_view> protein(const std::string_view codon)
    {
        static const std::map<std::string_view, std::string_view> codon_to_protein{
            { "AUG", "Methionine" },
            { "UUU", "Phenylalanine" },
            { "UUC", "Phenylalanine" },
            { "UUA", "Leucine" },
            { "UUG", "Leucine" },
            { "UCU", "Serine" },
            { "UCC", "Serine" },
            { "UCA", "Serine" },
            { "UCG", "Serine" },
            { "UAU", "Tyrosine" },
            { "UAC", "Tyrosine" },
            { "UGU", "Cysteine" },
            { "UGC", "Cysteine" },
            { "UGG", "Tryptophan" }
        };

        return codon_to_protein.find(codon) != std::cend(codon_to_protein) ? std::make_optional(codon_to_protein.at(codon)) : std::nullopt;
    }

    [[nodiscard]] std::vector<std::string> proteins(const std::string_view rna)
    {
        static constexpr std::size_t codon_size = 3;
        const auto codons_quantity = rna.length() / codon_size;

        std::vector<std::string> proteins;
        proteins.reserve(codons_quantity);
        
        for (std::size_t current_codon_index = 0; current_codon_index < rna.length(); current_codon_index += codon_size)
        {
            const std::string_view current_codon = rna.substr(current_codon_index, codon_size);
            const auto current_protein = protein(current_codon);
            
            if(current_protein)
                proteins.emplace_back(current_protein.value());
            else
                return proteins;
        }

        return proteins;
    }
}  // namespace protein_translation

#endif  // PROTEIN_TRANSLATION_H
