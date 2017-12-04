// Copyright (c) 2017, Pacific Biosciences of California, Inc.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted (subject to the limitations in the
// disclaimer below) provided that the following conditions are met:
//
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//  * Redistributions in binary form must reproduce the above
//    copyright notice, this list of conditions and the following
//    disclaimer in the documentation and/or other materials provided
//    with the distribution.
//
//  * Neither the name of Pacific Biosciences nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
// GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY PACIFIC
// BIOSCIENCES AND ITS CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL PACIFIC BIOSCIENCES OR ITS
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
// USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
// OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
// SUCH DAMAGE.

// Author: Derek Barnett

#pragma once

#include <cstddef>
#include <map>
#include <string>
#include <tuple>

#include <boost/optional.hpp>

namespace PacBio {
namespace GenomicConsensus {

struct Variant
{
public:
    std::string refName;
    size_t refStart;
    size_t refEnd;
    std::string refSeq;
    std::string readSeq1;
    char refPrev;
    char readPrev;

    boost::optional<std::string> readSeq2 = boost::none;
    boost::optional<size_t> frequency1 = boost::none;
    boost::optional<size_t> frequency2 = boost::none;
    boost::optional<size_t> coverage = boost::none;
    boost::optional<size_t> confidence = boost::none;
    boost::optional<std::map<std::string, std::string> > annotations = boost::none;

public:
    Variant(const std::string& _refName, const size_t _refStart, const size_t _refEnd,
            const std::string& _refSeq, const std::string& _readSeq1, const char _refPrev,
            const char _readPrev)
        : refName{_refName}
        , refStart{_refStart}
        , refEnd{_refEnd}
        , refSeq{_refSeq}
        , readSeq1{_readSeq1}
        , refPrev{_refPrev}
        , readPrev{_readPrev}
    {
    }

    Variant() = default;
    Variant(const Variant&) = default;
    Variant(Variant&&) = default;
    Variant& operator=(const Variant&) = default;
    Variant& operator=(Variant&&) = default;
    ~Variant() = default;

public:
    void Annotate(const std::string& key, const std::string& value)
    {
        annotations->insert(std::make_pair(key, value));
    }

    bool IsHeterozygous() const { return (bool)readSeq2; }

    bool operator<(const Variant& other) const
    {
        return std::tie(refName, refStart, refEnd, readSeq1) <
               std::tie(other.refName, other.refStart, other.refEnd, other.readSeq1);
    }
};

}  // namespace GenomicConsensus
}  // namespace PacBio
