#include "nucleotide_count.h"

namespace nucleotide_count {

counter::counter(const std::string &DNASequence) : nucleotideCounts { {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} }
{
    for(const auto& nucleotide : DNASequence)
        if(nucleotideCounts.find(nucleotide) == nucleotideCounts.end())
            throw std::invalid_argument("Invalid DNA Sequence");
        else
            nucleotideCounts[nucleotide]++;
}

std::map<char, int> counter::nucleotide_counts() const
{
    return nucleotideCounts;
}

int counter::count(const char nucleotide) const
{
    switch(nucleotide)
    {
        case 'A':
        case 'T':
        case 'C':
        case 'G':
            return nucleotideCounts.at(nucleotide);
        default:
            throw std::invalid_argument("Invalid nucleotide");
    }
}



}  // namespace nucleotide_count
