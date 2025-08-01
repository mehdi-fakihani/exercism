#include "rna_transcription.h"

#include <algorithm>

namespace rna_transcription {

    std::string to_rna(const std::string& dna)
    {
        std::string rna {dna};
        std::for_each(rna.begin(),rna.end(),[](char& nucleotide){nucleotide = to_rna(nucleotide);});
        return rna;
    }

    char to_rna(const char &nucleotide)
    {
        switch(nucleotide)
        {
            case 'A':
                return 'U';
            case 'T':
                return 'A';
            case 'C':
                return 'G';
            case 'G':
                return 'C';
        }
    }

}  // namespace rna_transcription
